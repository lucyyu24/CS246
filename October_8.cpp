/* October 8 */

// avoid using recursions
// as they can cause segmentation faults

// Declaration vs. Definition ------------------------------------

// declaration - only asserts the existence of entity
// definition - full definition of the entity

// an entity can be declared several times, but defined only once

// 1. preprocessing 	#include<...>
// 2. compilation 		object declaration 
// 3. linking 			definition ?

// Pointers -----------------------------------------------------

// a pointer contains the memory address of a value

// Arrays -------------------------------------------------------

// array: series of elements of the same type

type name[length] // declare an array

a == &a[0] // the name is a shorthand for the address of the first element

int a[] = {1, 2, 3, 4, 5}

// Structs -------------------------------------------------------

// struct: unit to group variables of various data types together

struct Node {
	int data;
	Node *next;
};

struct Node {
	int data;
	Node next; // incorrect
};

// Constants ----------------------------------------------------

const int maxGrade = 100; // use const to declare constants

// const definitions must be initialized

// declare constants whenever possible

const int *p = &n; 	// pointer to a constant
	// p can be reassigned
	// *p cannot be reassigned

int *const p = &n;  // constant pointer to variable
	// cannot change where p points
	// can change the data p points to

// Parameter passing 1 ------------------------------------------

void inc_value(int n) {
	n = n + 1;
}

void inc_pointer(int *n) {
	*n = *n + 1;
}

void inc_ref (int &n) {
	n = n + 1; 
}

int main() {
	int x = 5;
	inc_value(x);
	inc_pointer(&x);
	inc_ref(x);

}

// Paramter passing 2 ------------------------------------------

// why cin >> x and not cin >> (&x) ?
// answer: C++ provides pointer-like type: reference

// Parameter passing 3 -----------------------------------------

// references are like constant pointers with automatic dereferencing

int y = 10; 
int &z = y; // z is a ref to y 
z = 12;		// not *z = 12 
int *p = &z; // p points to y 

// in all cases, z behaves exactly like y 

// Parameter passing 4 -----------------------------------------

// things cannot be done with references
	// leave them uninitialized
	// create a pointer to a reference (int &*x)
	// create a reference to a reference (int &&x)
	// create an array of references (int &r[])

// we can pass references as function parameters

// Parameter passing 5 -----------------------------------------

cin >> x // works because >> takes x by reference

istream & operator >> (istream &in, int &n)

// Parameter passing 6 -----------------------------------------

// pass-by-value copies the argument
	// copying big arguments is expensive

// prefer pass-by-reference over pass-by-value for anything larger than an int

int f(Big &b) {}

int f(const Big &b) {}

// Parameter passing 7 -----------------------------------------

// pass-by-reference vs. pass-by-const-reference

int f(int &n) {}
int g(const int &n) {}

g(5); // error, can't change value of 5
f(5); // OK










