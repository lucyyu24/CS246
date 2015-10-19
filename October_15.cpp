/* October 15 */


// #ifdef -----------------------------------------------

// also #ifndef

// Separate compilation ---------------------------------

// split programs into composable modules

// interface -- type definitions and function prototypes
	// usually in .h files

// implementation -- full definition of functions
	// usually in .cc files


// compiling separately
g++ -c file1.cc // to get obj files
g++ file1.o file2 // to link

-c // means compile only, does not link

// Multiple definitions ---------------------------------

// what if we put a variable in a .h file?
	// solution: use extern in the .h file and put the
	// variable in a .cc file

// what if we include a .h file twice? 
	// solution: #include guard 

#ifndef __VECTOR_H_
#define __VECTOR_H_

struct Vector {
	int x, y;
};

#endif

// Rules ------------------------------------------------

// always put #include guards in .h files

// never put using namespace std; in .h files
	// use std::cin, std::out, etc., in .h files

// Introduction to classes ------------------------------

// A class is essentially a struct type that can contain functions (member functions/methods)
	// we will use the keyword class later

// An object is an instance of a class
	// objects normally have fields

struct Student {
	int mt, assgn, final;
	float grade() {
		return assgn *0.4 + mt*0.2 + final *0.4;
	}
};

Student s = {60,70,80};
cout << s.grade() << endl; 

// this pointer -----------------------------------------

 // methods take a hidden parameter called this
	// a pointer to the object upon which the method was invoked
	// so we can use this pointer inside methods

// Introduction to constructors -------------------------

// good to include a method for initialization
	// a constructor

// advantages of constructors
	// default parameters
	// overloading

struct Student {
	int mt, assgn, final;
	float grade() {
		return this->assgn *0.4 + this->mt*0.2 + this->final *0.4;
	}

	Student(int assgn=0, int mt=0, int final=0) {
		this->assgn = assgn; 
		this->mt = mt;
		this->final = final; 
	}
};

Student s(60,70,80);
cout << s.grade() << endl;

Student billy = Student(80,70,90);
cout << billy.grade() << endl;

// heap allocation
Student* alice = new Student(80,70,90);
cout << alice->grade() << endl; 


// Default constructor ----------------------------------

// every class has a default constructor (no args)
	// it calls default constructors on members that have them

// built-in default goes away if a constructor is provided

// you can do this if you don't have a constructor
struct Vector {
	int x,y;
};

Vector v1;

