/* October 20 */


// More on Initialization -----------------------------------------

// what if a struct contains constants or references?

struct MyStruct {
	const int myConst;
	int &myRef;
};

// initializaters are allowed for fields in the latest version
// each instance should get its own myConst and myRef

int z;

struct MyStruct {
	const int myConst = 5;
	int &myRef = z; 
};

// initialization in constructor
// can't do this, it's too late

struct MyStruct {
	const int myConst;
	int &myRef;

	MyStruct (int c, int &r) {
		myConst = c;
		&myRef = r; 
	}
};

// steps of object creation ---------------------------------------

// 1. space for the object is allocated
// 2. default constructors are called for members (field initialization is here)
// 3. constructor body runs

// Initialization List ---------------------------------------------

struct MyStruct {
	const int myConst;
	int &myRef;

	// Initialization before the constructor runs
	MyStruct (int c, int &r): myConst(c), myRef(r) {}
};

// fiels are initialized in the order in which they are declared in the class
// even if the initialization list orders them differently 

struct Student {
	int assns, mt, final;

	Student (int assns, int mt, int final) : assns(assns), mt(mt), final(final) {
		this->assns = 1;
		this->mt = 2;
		this->final = 3; 
	}
};

int main() {
	Student s(10,20,30);
	// s is now 1,2,3
}

// Copy Constructor ------------------------------------------------

int main() {
	Student billy(10,20,30);
	Student bobby = billy; // a copy of billy is created
}

// more on constructors --------------------------------------------

// every class comes with
	// a default constructor (calls default ctors on indiviidual fields)
		// lost you define your own
	// a copy constructor (just copies all fields)
	// a copy assignment operator
	// a destructor

// write copy constructor -------------------------------------------

// can build your own copy constructor 
	// e.g., Student (const Student &other)

// the built-in copy constructor can be incorrect
	// shallow copy vs. deep copy


Student (const Studnet &other) : assns(other.assns), mr(other.mt), final(other.final) {
	cout << "in copy constructor" << endl;
}

// Shallow copy -----------------------------------------------------

int main() {
	Node *n = new Node (1, new Node(2, new Node(3,0))); // linked list
	Node m = *n; // will create m on stack, next points to node 2
	Node *p = new Node (*n); // same as above

	n->next->data = 7; 
	// when node 2 changes it's data value, so will m and p
}

// Deep copy --------------------------------------------------------

// you must implement your own constructor to do this

Node (const Node &other) : data(other.data), next(other.next ? new Node(*(other.next)) : 0) { // recursion
	cout << "In copy constructor." << endl;
}

int main() {
	Node *n = new Node (1, new Node(2, new Node(3,0)));
	Node m = *n;
	Node *p = new Node (*n);

	n->next->data = 7; 
	// does not change the data value in the second node of m and p
}

// more on copy ctor ------------------------------------------------

// copy constructor is called
	// whenever an object is initialized with another object
	// whenever an object is passed by value
	// whenever an object is returned by a function

// single-parameter constructors ------------------------------------

// single-parameter constructors create implicit conversions
	// can be dangerous

// good idea - disable the implicit conversion by declaring the constructor explicit


// single-paramter constructor --------------------------------------

struct Node {
	int data;
	Node *next;
	Node (int data) : data(data), next(0) {}
	// explicit Node(int data): data(data), next(0) {}
	// prevent conversion ^ 
	
	int f(Node n)) {
		cout << "Got a node" << endl;
	}

	int f(int i) {
		cout << "Got an integer" << endl;
	}
};


int main() {
	Node n(4);
	Node n2 = 7; // implicit conversion from int to Node

	f(n2); // 
	f(10); // 
}




