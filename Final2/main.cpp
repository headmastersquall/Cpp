#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <functional>

#include "exception.hpp"
#include "security.hpp"

using namespace std;

const string APP_NAME = "tauth";
const string LOGIN_DB = "authenticated-users";
const string USER_DATABASE = "users";
const string PASSWORD_DATABASE = "passwords";
const int DEFAULT_TOKEN_LIFESPAN = 5;

struct LoginData
{
	string userName;
	string token;
	int expirationDate;
};

struct User
{
	string userName;
	string realName;
	string email;
	string accessLevel;
};

struct PasswordData
{
	string userName;
	string salt;
	string passwordHash;
};



/*
 * This group of functions is responsible for reading data from files and
 * loading data structures.
 */
User loadUser(string line)
{
	stringstream ss(line);
	User user;
	getline(ss, user.userName, '|');
	getline(ss, user.realName, '|');
	getline(ss, user.email, '|');
	getline(ss, user.accessLevel, '|');
	return user;
}

LoginData loadLoginData(const string &line)
{
	stringstream ss(line);
	string expiration;
	LoginData login;
	getline(ss, login.userName, '|');
	getline(ss, login.token, '|');
	getline(ss, expiration, '|');
	login.expirationDate = atoi(expiration.c_str());
	return login;
}

LoginData getLoginDataFromPred(function<bool(string)> pred)
{
	fstream loginDatabase;
	loginDatabase.open(LOGIN_DB.c_str(), ios::in);
	if (loginDatabase.fail())
	{
		LoginData login;
		return login;
	}
	string line;
	while (!loginDatabase.eof())
	{
		getline(loginDatabase, line);
		if (pred(line))
		{
			return loadLoginData(line);
		}
	}
	LoginData login;
	return login;
}

LoginData getLoginDataFromUserName(const string &userName)
{
	return getLoginDataFromPred([&userName](string line) {
		return line.find(userName + "|") != string::npos;
	});
}

LoginData getLoginDataFromToken(const string &token)
{
	return getLoginDataFromPred([&token](string line) {
		return line.find("|" + token + "|") != string::npos;
	});
}

PasswordData loadPasswordData(string line)
{
	stringstream ss(line);
	PasswordData pw;
	getline(ss, pw.userName, '|');
	getline(ss, pw.salt, '|');
	getline(ss, pw.passwordHash, '|');
	return pw;
}

PasswordData getPasswordData(string userName)
{
	fstream pwDatabase;
	pwDatabase.open(PASSWORD_DATABASE.c_str(), ios::in);
	if (pwDatabase.fail())
	{
		throw Exception("Unable to open password database");
	}
	string line;
	while (!pwDatabase.eof())
	{
		getline(pwDatabase, line);
		if (line.find(userName) == 0)
		{
			return loadPasswordData(line);
		}
	}
	delay();
	PasswordData pw;
	return pw;
}

bool isLoggedIn(const string &token)
{
	LoginData data = getLoginDataFromToken(token);
	time_t now = time(0);
	return data.userName.size() > 0 && data.expirationDate > now;
}

User getUserData(const string &token)
{
	if (!isLoggedIn(token))
	{
		throw Exception("User data is only available to logged in users");
	}
	fstream userDatabase;
	userDatabase.open(USER_DATABASE.c_str(), ios::in);
	if (userDatabase.fail())
	{
		throw Exception("Unable to open user database");
	}
	LoginData loginData = getLoginDataFromToken(token);
	string line;
	while (!userDatabase.eof())
	{
		getline(userDatabase, line);
		User user = loadUser(line);
		if (user.userName == loginData.userName)
		{
			return user;
		}
	}
	delay();
	User user;
	return user;
}

string getUserDataAsJson(const User &user)
{
	if (user.userName.size() == 0)
	{
		throw Exception("No user data available");
	}
	stringstream ss;
	ss << "{ \"username\":\"" << user.userName << "\", "
	   << "\"realname\":\"" << user.realName << "\", "
	   << "\"email\":\"" << user.email << "\", "
	   << "\"accesslevel\":\"" << user.accessLevel << "\" }" << endl;
	return ss.str();
}



/*
 * These functions are responsible for writing to and updating files.
 */

void writeUserToDatabase(const string userName, const string realName, const string email, const string accessLevel)
{
	fstream userDatabase;
	userDatabase.open(USER_DATABASE.c_str(), ios::out | ios::app);
	userDatabase << userName << "|" << realName << "|" << email << "|" << accessLevel << endl;
	userDatabase.close();
}

string hashPasword(const string &pw, const string &salt)
{
	return sha512((salt + pw).c_str());
}

void writePasswordToDatabase(const string userName, const string pw)
{
	string salt = generate_uuid();
	string saltedHash = hashPasword(pw, salt);
	fstream pwDatabase;
	pwDatabase.open(PASSWORD_DATABASE.c_str(), ios::out | ios::app);
	pwDatabase << userName << "|" << salt << "|" << saltedHash << endl;
	pwDatabase.close();
}

void setPassword(const string userName)
{
	cout << "Enter password: ";
	string pw1 = getPassPhrase();
	cout << endl;
	cout << "Re enter your password: ";
	string pw2 = getPassPhrase();
	cout << endl;
	if (pw1 == pw2)
	{
		writePasswordToDatabase(userName, pw1);
	}
	else
	{
		cout << "Passwords do not match" << endl;
		setPassword(userName);
	}
}

bool doesUserExist(const string userName)
{
	fstream userDatabase;
	userDatabase.open(USER_DATABASE.c_str(), ios::in);
	if (userDatabase.fail())
	{
		return false;
	}
	string line;
	while (!userDatabase.eof())
	{
		getline(userDatabase, line);
		if (line.find(userName) == 0)
		{
			return true;
		}
	}
	return false;
}

void addUser(const string &userName)
{
	if (doesUserExist(userName))
	{
		throw Exception("User " + userName + " already exists");
	}

	string realName, email, accessLevel;
	cout << "Enter your real name: ";
	getline(cin, realName);

	cout << "Enter your email address: ";
	getline(cin, email);

	cout << "Enter your access level? ";
	getline(cin, accessLevel);
	writeUserToDatabase(userName, realName, email, accessLevel);
	setPassword(userName);
}

void removeLines(const string &fileName, std::function<bool(string)> pred)
{
	const string tmpFileName = "db.tmp";
	fstream dbFile;
	fstream tmpFile;
	string line;

	dbFile.open(fileName.c_str(), ios::in | ios::out);
	tmpFile.open(tmpFileName.c_str(), ios::out);
	if (dbFile.fail())
	{
		// File doesn't exist.
		return;
	}

	while (!dbFile.eof())
	{
		getline(dbFile, line);
		if (line.size() > 0 &&
			!pred(line))
		{
			tmpFile << line << endl;
		}
	}

	dbFile.close();
	tmpFile.close();

	remove(fileName.c_str());
	rename(tmpFileName.c_str(), fileName.c_str());
}

void removeUser(const string &userName)
{
	if (doesUserExist(userName))
	{
		auto hasUserName = [&userName](string line) {
			return line.find(userName + "|") == 0;
		};

		removeLines(USER_DATABASE, hasUserName);
		removeLines(PASSWORD_DATABASE, hasUserName);
	}
}

void logout(const string &token)
{
	removeLines(LOGIN_DB, [&token](const string &line) {
		return line.find("|" + token + "|") != string::npos;
	});
}

void addToLoginDatabase(const string &userName, const string &token, const int &expiration)
{
	fstream loginDatabase;
	loginDatabase.open(LOGIN_DB.c_str(), ios::out | ios::app);
	loginDatabase << userName << "|" << token << "|" << expiration << endl;
	loginDatabase.close();
}

string login(const string &userName, const int tokenLifespan)
{
	cout << "Enter password:";
	string pw = getPassPhrase();
	cout << endl;

	PasswordData pwData = getPasswordData(userName);
	string hash = hashPasword(pw, pwData.salt);
	if (!doesUserExist(userName) ||
		hash != pwData.passwordHash)
	{
		delay();
		throw Exception("Authentication Failed");
	}

	time_t now = time(0);
	int expirationDate = now + (tokenLifespan * 60);
	string newToken = generate_uuid();

	LoginData currentLogin = getLoginDataFromUserName(userName);
	if (currentLogin.userName.size() > 0 &&
		currentLogin.expirationDate > now)
	{
		return currentLogin.token;
	}

	addToLoginDatabase(userName, newToken, expirationDate);
	return newToken;
}

void removeExpiredTokens()
{
	time_t now = time(0);
	removeLines(LOGIN_DB, [&now](const string &line) {
		LoginData data = loadLoginData(line);
		return now > data.expirationDate;
	});
}



/*
 * Informational functions.
 */
void validate(const string &token)
{
	auto loginData = getLoginDataFromToken(token);
	time_t now = time(0);
	if (loginData.userName.size() > 0 &&
		loginData.expirationDate > now)
	{
		cout << "The token is valid" << endl;
	}
	else
	{
		delay();
		cout << "Invalid or expired token" << endl;
	}
}

void showUsage()
{
	cout << "Usage: " << APP_NAME << " command..." << endl;
}

void showHelp()
{
	showUsage();
	cout << endl;
	cout << "Commands available:" << endl;
	cout << "    add         Create a new user" << endl;
	cout << "    login       Log a user in with provided credentials. An optional" << endl;
	cout << "                --duration n can be provided to set the token life-span." << endl;
	cout << "    logout      Expire the provided token" << endl;
	cout << "    remove      Remove an existing user" << endl;
	cout << "    user-data   Get meta data for the user who owns the given token" << endl;
	cout << "    validate    Verify the provided token" << endl;
	cout << endl;
	cout << "All commands take either a user name or a token as a parameter." << endl;
}

string getUserName(const int argc, char* argv[])
{
	if (argc < 3)
	{
		throw Exception("No user name provided");
	}
	return argv[2];
}

string getToken(const int argc, char* argv[])
{
	if (argc < 3)
	{
		throw Exception("No token provided");
	}
	return argv[2];
}

int getTokenLifespan(const int argc, char* argv[])
{
	int lifespan = DEFAULT_TOKEN_LIFESPAN;
	for (int i = 0; i < argc; i++)
	{
		if (string(argv[i]) == "--duration")
		{
			if (argc > i + 1)
			{
				lifespan = atoi(argv[i + 1]);
			}
			else
			{
				throw Exception("No duration provided");
			}
		}
	}
	return lifespan;
}



/*
 * Here is when we start the "main" portion of the program and figure out
 * what the user is wanting to do, then execute that function.
 */
void runCommand(const int argc, char* argv[])
{
	string command(argv[1]);
	if (command == "add")
	{
		addUser(getUserName(argc, argv));
	}
	else if (command == "login")
	{
		cout << login(getUserName(argc, argv), getTokenLifespan(argc, argv)) << endl;
	}
	else if (command == "logout")
	{
		logout(getToken(argc, argv));
	}
	else if (command == "remove")
	{
		removeUser(getUserName(argc, argv));
	}
	else if (command == "user-data")
	{
		cout << getUserDataAsJson(getUserData(getToken(argc, argv)));
	}
	else if (command == "validate")
	{
		validate(getToken(argc, argv));
	}
	else if (command == "help" || command == "-h")
	{
		showHelp();
	}
	else
	{
		cout << "Unknown command " << command << endl;
		showUsage();
	}
}

int main(const int argc, char* argv[])
{
	try
	{
		if (argc == 1)
		{
			showUsage();
			cout << "Use '" << APP_NAME << " help' for command listing" << endl;
		}
		else
		{
			removeExpiredTokens();
			runCommand(argc, argv);
		}
	}
	catch (const Exception &ex)
	{
		cout << ex.getMessage() << endl;
	}
	return 0;
}
