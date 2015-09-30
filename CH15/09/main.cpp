/*
 * 15.09 File Filter
 *
 * Provides an abstract base class for filtering a file.  Three
 * derived classes are created to provide specific functionality.
 */

#include <iostream>
#include <fstream>
#include "AbstractFileFilter.h"
#include "EncryptionFilter.h"
#include "CopyFilter.h"
#include "UpperCaseFilter.h"

using namespace std;

void doCopy(const AbstractFileFilter &filter, char* srcFile, char* destFile)
{
	ifstream in(srcFile);
	ofstream out(destFile);
	filter.doFilter(in, out);
	in.close();
	out.close();
}

int main()
{
	char srcFile[] = "/home/squall/test.txt";

	cout << "Using the copy filter." << endl;
	CopyFilter cpFilter;
	char copyDest[] = "/home/squall/test-copy.txt";
	doCopy(cpFilter, srcFile, copyDest);

	cout << "Using the upper case filter." << endl;
	UpperCaseFilter upperFilter;
	char upperDest[] = "/home/squall/test-upper.txt";
	doCopy(upperFilter, srcFile, upperDest);

	cout << "Using the encryption filter." << endl;
	EncryptionFilter encrytpionFilter(17);
	char encryptedDest[] = "/home/squall/test-encrypted.txt";
	doCopy(encrytpionFilter, srcFile, encryptedDest);

	return 0;
}
