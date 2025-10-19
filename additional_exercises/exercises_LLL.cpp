#include <iostream>
#include <random>

using namespace std;

/* Exercises: write the following for the class below, recursively:
 1. (*) 	display all evens
 2. (**) 	remove all odds
 3. (**) 	copy the list to a new list
 4. (*) 	sum up the list
 5. (*) 	sum up every other element in the list
 6. (*) 	return the max element in the list
 7. (***) 	return the sum of the two largest elements (duplicate max elements
 			count as separate values)
 8. (**) 	display the list in reverse

 NOTE: difficulty is displayed by the number of stars, from 1 to 3 ascending.
*/

class List {
	// NOTE: some functions have already been written for you
	
	// -prototypes go here---------------------------
	private:
		struct Node {
			int data;
			Node *next;
		};

		Node *head;
	public:
		List();
		~List();

		void display() const;
	// ----------------------------------------------
};




int main()
{
	List integers;

	// -function calls-------------------------------
	integers.display();
	// ----------------------------------------------

	return 0;
}





// -implementations----------------------------------
// -predefined function implementations- - - - - - - 
List::List()
{
	head = nullptr;

	// change these to change how the list generates
	size_t SIZE_MIN = 8;
	size_t SIZE_VAR = 8;
	int DATA_MIN = 0;
	int DATA_VAR = 10;

	random_device rd;

	size_t size = SIZE_MIN + rd() % (SIZE_VAR);
	
	for (size_t i = 0; i < size; ++i) {
		Node *new_node = new Node;
		new_node->data = DATA_MIN + rd() % DATA_VAR;
		new_node->next = head;
		head = new_node;
	}
}

List::~List()
{
	while (head) {
		Node *current = head;
		head = head->next;
		delete current;
	}
}

void List::display() const
{
	for (Node *curr=head; curr; curr=curr->next) {
		cout << curr->data;
		if (curr->next) {
			cout << " -> ";
		}
	}

	cout << endl;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - 

// write your own function implementations here

// --------------------------------------------------
