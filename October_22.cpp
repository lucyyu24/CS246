/* October 22 */


// Dangling Pointer -----------------------------------------

// n -> 1 -> 2 ->
//      ^
//     n2

// Destructor -----------------------------------------------
// Assignment Operator --------------------------------------

int main() {
	Student billy (10, 20, 30); // constructor taking three arguments
	Student s = billy; // copy constructor
	Student s; // default constructor
	s = billy; // copy, but not constructing 
}
// Bad Case --------------------------------------------------

struct Node {

	Node &operator=(const Node &other) {
		data = other.data; 
		delete next; // if n = n, then next is deleted aleady, can't execute next line
		next = new  Node(*other.next); // dangerous; if next = 0, can't dereference
		return *this; 
	}
};

int main() {
	Node n (1, new Node(2, new Node(3,0)));
	Node n1 (4,0);
	n1 = n; 
	// n = n1;
	n = n; // (*other.next) is gone 
}

// Resolved dangerous statement ------------------------------

struct Node {

	Node &operator=(const Node &other) {
		if (this == other) return *this;
		data = other.data; 
		delete next; 
		next = other.next ? new Node(*other.next) : 0; 
		return *this; 
	}
};

int main() {
	Node n (1, new Node(2, new Node(3,0)));
	Node n1 (4,0);
	n1 = n; 
	n = n; 
}

// Even Better ------------------------------------------------

struct Node {

	Node &operator=(const Node &other) {
		if (this == other) return *this;
		data = other.data; 

		Node *tmp = next; 
		next = other.next ? new Node(*other.next) : 0; // value of next cannot be changed in case of exception
		delete tmp; 

		return *this; 
	}
};

int main() {
	Node n (1, new Node(2, new Node(3,0)));
	Node n1 (4,0);
	n1 = n; 
	n = n; 
}

// Rule of Three ----------------------------------------------

// if you need to write a custom version of any one of copy constructor, 
// operator =, and destructor

// then you usually need to write a custom version of all three

// Note on operator = -----------------------------------------

// operator = is a member function (defined in the class), not a stand-alone function

// when a operator is declared as a member function, the LHS argument is this pointer

