/* October 1

GRT Bus Test Cases -------------------------------

34+2 > 35 and "No More Space"

35-2 > 33 
+3 > 35 and "No More Space"

5-6 > "Error 6 is greater than the number of passengers"

n+0 > n

33+2 > 35

2-2 > 0 

0 - 0 > 0 

*/ 
// Notes on Hello world -------------------------

main 	// the main function must return int
printf 	// such c elements still available, prefer C++ I/O
std 	// name space using
// return status code to the shell
g++ program.cc -o program // compiling C++ programs

// C++ I/O --------------------------------------

// C++ provides I/O stream objects
cout 	// for printing to stdout
cin 	// for reading from stdin
cerr 	// for printing to stderr

// I/O operator
<< 		// "put to" output
>> 		// "get from" input

// examples
cout << x	// put x to stdout
cerr << x	// put x to stderr
cin >> x	// get x from stdin

// Example 1 ------------------------------------

#include <iostream>
using namespace std; 

int main() {
	int x=1,y=2; // if cin fails, then these values (1,2) will persist
				 // e.g., input: "5 a" > 7
	cin >> x >> y; // cin >> ignore whitespace
	cout << x+y << endl; 
}

// Detecting Failures of cin -----------------------

cin.fail() // if the read failed, cin.fail() will be true
cin.eof()  // if end-of-file is reached, cin.eof() and cin.fail() will be true

// Example 2 ----------------------------------------

int main() {
	int i; 
	while (true) {
		cin >> i;
		if (cin.fail()) break; // non-integer input = fail
		cout << i << endl;
	}
}

// Implicit conversion to void * -------------------

if (cin) 	// implicit conversion from cin to void * 
!cin.fail() // the condition is true
cin.fail()  // the condition is false; pointer = null

// Example 3 ----------------------------------------

int main() {
	int i; 
	while (true) {
		cin >> i;
		if (!cin) break; 
		cout << i << endl;
	}
}

// Stream Operator >> ------------------------------

// when the LHS is cin, >> is the "get from" operator
// inputs: cin (istream) and data (several types)
// output: returns cin (istream)

cin >> x >> y >> z; // cascading reads and writes

cin >> x;			// these statements are equivalent to above statement
cin >> y;
cin >> z; 

// Example 4 ----------------------------------------

int main() {
	int i; 
	while (true) {
		if (!(cin >> i)) break;
		cout << i << endl; 
	}
}

// Example 5 ----------------------------------------

int main() {
	int i; 
	while (cin >> i) {
		cout << i << endl; 
	}
}

// More cin Functions ---------------------------------

// if no arguments provided, then default values will be used

cin.clear()  // clear the fail bit
cin.ignore() // ignore the current input char
			 // ignore(number of chars to ignore, delimiter)
			 // default values: (1, EOF)

// Example 6 -------------------------------------------

// read all integers and echo on stdout until eof, skip non-integer input

int main(){
	int i;
	while (true) {
		if (!(cin >> i)) {
			if (cin.eof()) break; 
			else {
				cin.clear();
				cin.ignore();
			}
 		} else {
 			cout << i << endl; 
 		}
	}
}

// C++ String ------------------------------------------

// C++ provides type std::string for working with strings

// Example 7 -------------------------------------------

// read in a string

#include <iostream>
#include  <string>
using namespace std; 

int main(){
	string s;
	cin >> s; // read in a string; stops at whitespace
	cout << s << endl; 
}

int main(){
	string s;
	getline(cin, s); // reads entire line, stops at newline character
	cout << s << endl; 
}

// IO manipulators ----------------------------------

hex 			
showpoint
setprecision()

#include <iomanip>

int i = 95; 
float price = 2.50;

cout << i << endl;		// 95
cout << price << endl; // 2.5

cout << hex << i << endl; // 95 in hex
cout << showpoint << setprecision(3) << price << endl; // 2.50; setprecision counts dots! (2+1)





