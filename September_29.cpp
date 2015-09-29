/* September 29 

Testing --------------------------------------

essential part of program development

ongoing process; start before coding, not just at the end

test cases and test suites

testing is NOT debugging
	testing takes place BEFORE debugging (will be helpful)

testing cannot guarantee correctness
	only prove the existence of faults

developer and tester should be different people (not in this course)

Human vs. Machine Testing ---------------------

human testing - read code to find flaws
	code inspection
	walkthrough

machine testing - run programs on test inputs and check outputs against specs (expected outputs)
	need to design and plan testing carefully

*-box testing ---------------------------------

black-box testing -- no knowledge of program implementation

white-box testing -- full knowledge of program implementation

grey-box testing -- partial knowledge of program implementation

start with black-box testing
	check various classes (types) of inputs
	check boundaries beteween ranges (edge cases)
	check multiple simultaneous boundaries (corner cases)
	guess at likely errors
	extreme cases

supplement with white-box testing
	check all logical paths through the program
	make sure every function runs

Strategies of testing ---------------------------

Functional testing -- ensure program executes correctly

Regression testing -- ensure program changes do NOT break old test cases

Performance testing -- program runs efficiently

Volume testing -- can the program handle small and large inputs?

Introduction to C++ -----------------------------

OOP + low-level memory manipulation

powerful and complex */ 

// Hello World Example ---------------------------

// C++
#include <iostream>  				// stream-based
using namespace std; 				// prevent naming collisions
									// making standard library names usable to us

int main () {
	cout << "Hello world" << endl; 	// cout (c-out) defined in standard library; endl (end-line)
	return 0; 
}

// C
# include <stdio.h> 				// file-based

int main() {
	printf("Hello world\n");
	return 0; 
}

// compile code w/ bash
// gcc helloworld.c -o hello_c
// g++ helloworld.cpp -o hello_cpp 

