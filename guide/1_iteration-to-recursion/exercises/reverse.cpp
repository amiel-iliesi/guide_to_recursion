#include <iostream>
#include <cstring> //strlen(..)

using std::cout, std::endl;

// make a recursive function that does the same thing as this one!
void print_reverse_iterative(const char* message);



int main() {
	print_reverse_iterative("Hello, World!");
	
	// uncomment this one when you're ready to test it out!
//	print_reverse_recursive("Hello, World!");

	return 0;
}



void print_reverse_iterative(const char* message) {
	int size = strlen(message);

	for (int i = size-1; i >= 0; --i) {
		cout << message[i];
	}

	cout << endl;
}
