/* October 13 */

// Dynamic memory allocation in C++ -----------

struct Node {
	int data;
	Node *next;
};

Node *np = new Node;
..
delete np;

// use new/delete in C++

// Allocating arrays -----------------------------

type *p = new type[length]; // allocation
delete [] p			// deallocation
delete[] // to delete arrays 
delete // to delete non-arrays

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	// arr on stack, pointing to heap memory
	int * arr = new int [n];
	for (int i = 0; i < n; ++i) {
		arr[i] i*i;
		cout << arr[i] << endl;
	}
	delete [] arr;
	return 0; 
}

// allocation: stack vs. heap ----------------------

// local variables allocated on the stack
	// they disappear when the stack is popped

// heap-allocated data lives on when the stack is popped

// allocations: examples ---------------------------

Node getNode() {	// expensive - n is copied on return
	Node n;
	return n; 
}

Node *getNode() {	// unsage - n is dead on return
	Node n; 
	return &n;
}

Node *getNode() {	// do this
	Node *np = new Node;
	return np; 
}

// operator overloading ---------------------------

#include <iostream>
using namespace std;

struct Vector {
	int x, y;
};


Vector operator+(const Vector &v2, const Vector &v2) {
	Vector v; 
	v.x = v1.x + v2.x; 
	v.y = v1.y + v2.y;
}

Vecotr operator*(const int k, const Vector &v1) {
	Vector v;
	v.x = k * v1.x;
	v.y = k * v1.y;
	return v;
}

int main() {
	Vector v1, v2;
	v1.x = 1;
	v1.y = 1;
	v2.x = 2;
	v2.y = 2;

	Vector v3 = v1 + v2;
	Vector v4 = v1 * 5;
	Vector v5 = 7 * v2;

	cout << v3.x << ", "  << v3.y << endl;
	cout << v4.x << ", "  << v4.y << endl;
	cout << v5.x << ", "  << v5.y << endl;
	return 0; 
}

// overloading i/o operators

struct Grade {
	int theGrade;
};

ostream &operator<<(ostream &out, const Grade &g) {
	out << g.theGrade << "%";
	return out;
}

istream &operator>>(istream &in, Grade &g) {
	in >> g.theGrade;
	if (g.theGrade < 0) g.theGrade = 0;
	if (g.theGrade > 100) g.theGrade = 100; 
	return in;
}

// Preprocessing ---------------------------------------

// transform the program before compilation

// preprocessor directives - lines beginning with #

#include <iostream>	// search in include dir
#include "file.h"	// search in current dir

// #define ----------------------------------------------

// set a preprocessor variables
	// use #define VAR VALUE
	
#define FLAG
#define MAX 10
...
int x[MAX]
...

// to define constants, use const definitions
// #define is not recommended over this ^ 

// constants defined with #define can be useful for conditional compilation
	// together with #if, #elif, and #endif

// special case: #if 0

// conditional compilation
#define os UNIX
#if os == UNIX
	int main () {}
#elif os == WINDOWS
	int winmain () {

	}

#endif
