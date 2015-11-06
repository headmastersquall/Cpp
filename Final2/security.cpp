#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
#include <thread>
#include <termios.h>
#include <unistd.h>
#include <openssl/sha.h>
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

#include "security.hpp"

using namespace std;

void delay()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

string generate_uuid()
{
	boost::uuids::random_generator generator;
	return to_string(generator());
}

string getPassPhrase()
{
	// This code was found at http://bit.ly/1LXA6Hn
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    string s;
    getline(cin, s);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return s;
}

string sha512(const char* input)
{
	// This code was found at
	// http://www.askyb.com/cpp/openssl-sha512-hashing-example-in-cpp/
    unsigned char digest[SHA512_DIGEST_LENGTH];

    SHA512_CTX ctx;
    SHA512_Init(&ctx);
    SHA512_Update(&ctx, input, strlen(input));
    SHA512_Final(digest, &ctx);

    char mdString[SHA512_DIGEST_LENGTH*2+1];
    for (int i = 0; i < SHA512_DIGEST_LENGTH; i++)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

    return string(mdString);
}
