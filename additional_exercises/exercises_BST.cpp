#include <iostream>
#include <algorithm>
#include <random>
#include <queue>
#include <utility>

using namespace std;

/* Exercises: write the following for the class below, recursively:
 1.  (*) 	display in reverse
 2.  (*) 	sum all elements
 3.  (**) 	remove all even elements
 4.  (**) 	make a copy to a new tree
 5.  (***) 	make a copy of only the even elements to a new tree
 6.  (***) 	display every other element in order
 7.  (**) 	remove a requested node (EG: integers.remove(6);), return a boolean
 			indicating status
 8.  (*) 	return a count of all elements
 9.  (**) 	return a count of all elements greater than a given value
 10. (*) 	return the max element in the tree
 11. (**) 	return the second max element in the tree

 NOTE: difficulty is displayed by the number of stars, from 1 to 3 ascending.
*/

class Tree {
	// NOTE: some functions have already been written for you
	
	// -prototypes go here---------------------------
	private:
		struct Node {
			int data;
			Node *left;
			Node *right;
		};

		Node *root;

		void insert(int data, Node *& curr);
		void clear(Node *& curr);
		void display(const Node *curr, const Node *max) const;
		const Node *find_max(const Node* curr) const;
	public:
		Tree();
		~Tree();

		void insert(int data);
		void display(bool verbose=false) const;
	// ----------------------------------------------
};







int main()
{
	Tree integers;

	// -function calls-------------------------------
	integers.display();
	integers.display(true); //verbose = true
	// ----------------------------------------------

	return 0;
}








// -implementations----------------------------------
// -predefined function implementations- - - - - - - 
// (you can safely ignore this whole section, left in case you were curious)
Tree::Tree()
{
	root = nullptr;

	random_device rd;

	//NOTE: tweak size of tree generated here--------
	size_t SIZE_MIN = 8;
	size_t SIZE_VAR = 8;
	// ----------------------------------------------

	size_t size = SIZE_MIN + rd() % (SIZE_VAR);

	vector<int> data_to_insert;
	data_to_insert.reserve(size);
	for (size_t i = 0; i < size; ++i) {
		data_to_insert.push_back(i);
	}

	mt19937 gen {rd()};
	ranges::shuffle(data_to_insert, gen);

	for (int n: data_to_insert) {
		insert(n);
	}
}

Tree::~Tree()
{
	clear(root);
}

void Tree::clear(Node *& curr)
{
	if (!curr) {
		return;
	}
	else {
		clear(curr->left);
		clear(curr->right);
		delete curr;
		curr = nullptr;
	}
}

void Tree::insert(int data)
{
	insert(data, root);
}

void Tree::insert(int data, Node *&curr)
{
	if (!curr) {
		curr = new Node;
		curr->data = data;
		curr->left = nullptr;
		curr->right = nullptr;
	}
	else if (data <= curr->data) {
		insert(data, curr->left);
	}
	else {
		insert(data, curr->right);
	}
}

void Tree::display(bool verbose) const
{
	if (verbose) {
		queue<pair<const Node *, size_t>> to_display;

		if (root) {
			to_display.push({root, 0});
		}
		
		bool display_depth = true;

		while (not to_display.empty()) {
			const Node* curr = to_display.front().first;
			size_t depth = to_display.front().second;
			to_display.pop();

			if (display_depth) {
				cout << '[' << depth << "]: ";
				display_depth = false;
			}

			cout << curr->data;

			if (curr->left) {
				to_display.push({curr->left, depth+1});
			} 
			if (curr->right) {
				to_display.push({curr->right, depth+1});
			} 

			// if there's another
			if (not to_display.empty()) {
				if (to_display.front().second == depth) { // ...and it's on the same depth as the previous
					cout << ", ";
				}
				else {
					display_depth = true; //...otherwise, next loop should prefix depth info
					cout << endl;
				}
			}
		}
	}
	else {
		const Node *max = find_max(root);
		display(root, max);
	}
	cout << endl;
}

void Tree::display(const Node *curr, const Node *max) const
{
	if (!curr) {
		return;
	}
	else {
		display(curr->left, max);

		cout << curr->data;
		if (curr != max) {
			cout << ", ";
		}

		display(curr->right, max);
	}
}

const Tree::Node* Tree::find_max(const Node* curr) const
{
	if (!curr) {
		return nullptr;
	}
	else if (!curr->right) {
		return curr;
	}
	else {
		return find_max(curr->right);
	}
}
// - - - - - - - - - - - - - - - - - - - - - - - - - 

// write your own function implementations here

// --------------------------------------------------
