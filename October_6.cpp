/* October 6 */

#include <iostream>
#include <fstream>
using namespace std

int main() {
	// declaring an ifstream opens the file
	ifstream file("suite.txt");
	string s;
	while (file >> s) {
		cout << s << endl;
	}
	// file is closed here
}

// File Stream Objects -------------------------------------------

#include <fstream> // use file stream objects
ifstream // to read a file
ofstream // to write a file

// all operations supported by cin are also supported by ifstream
// all operations supported by cout are also supported by ofstream

// 			  ----- student 
//  Person <-|
//			  ----- instructor
// 
//  istream <- ifstream
//  ostream <- ofstream

// I/O of Strings ----------------------------------------------

// can attach a stream to a string object
// to read from /write to a string

#include <sstream> // using string stream objects
istringstream // to read from a string
ostringstream // to write to a string

// Example

int hi = 10, lo =0;
ostringstream ss;

ss << "Please enter a number between " << lo << " and " << hi;

string s = ss.str();
cout << s << endl;


// Example
int n;
while (true) {
	cout << "Enter a number " << endl;
	string s; 
	cin >> s; 
	istringstream ss(s);

	if (ss >> n) {
		cout << n << endl;
		break;
	}

	cout << "Not a number " << endl;
}

// Example

string s;
while (cin >> s) {
	istringstream ss(s);

	int n;
	if (ss >> n) cout << n << endl;
}

// C++ String revisit ------------------------------------------------

// strings in C
	// array of chars 
	// terminated by \0
	// need explicit memory managemnet
	// easy to err
char s[] = "hello"

// C++ provides string objects
	// grow and shrink as needed
	// safer to manipulate
string s = "hello"

// String operations ----------------------------------------------

s1 == s2			// equality
s1 != s2			// inequality
s1 <= s2			// comparison (lexicographic order)
s1.length()			// length
s1[0], ..., s1[i]	// extract individual characterss
s3 = s1 + s2;		// concatenation, can also use += 

// Default function paramters --------------------------------------

// a function parameter can have a default value
	// if no value is specified, the default value is used
	// otherwise, the user-specified value is used

// example of default parameters

void printSuiteFile(string name="suite.txt") {
	// stream initialization must be given a C-style string
	ifstream file(name);
	string s;
	while (file >> s) cout << s << endl;
}

int main() {
	printSuiteFile("suite2.txt");
	printSuiteFile();
}

// Overloading ----------------------------------------------

// in C++, functions with different parameter lists can share the same name!

// overlads must differ in # or types of args
	// may not differ on just the return type

// examples: << and >> are overloaded




