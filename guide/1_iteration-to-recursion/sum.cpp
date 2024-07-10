#include <iostream>

using std::cout, std::endl;

// -- FUNCTION PROTOTYPES --
// NOTE: both of these functions make the *same result*
int sum_iterative(int start, int stop, int increment);
int sum_recursive(int start, int stop, int increment);

// -- MAIN --
int main() {
	// feel free to change these values to see the calculations change
	const int START = 1, STOP = 10, STEP = 2;
	constexpr int END = STOP - ((STOP - START) % STEP);

	cout << "the iterative sum is "
		 << START << " + " << START + STEP << " + ... + " << END << " = " << sum_iterative(START, STOP, STEP) << endl;

	cout << "the recursive sum is "
		 << START << " + " << START + STEP << " + ... + " << END << " = " << sum_recursive(START, STOP, STEP) << endl;
	
	return 0;
}

// -- FUNCTION IMPLEMENTATIONS -- 
int sum_iterative(int start, int stop, int increment) {
	int sum = 0;

	for (int i = start; i <= stop; i += increment) {
		sum += i;
	}

	return sum;
}

int sum_recursive(int start, int stop, int increment) {
	if (start <= stop) {
		return start + sum_recursive(start + increment, stop, increment);
	}
	else { // base case: (start > stop)
		return 0;
	}
}
