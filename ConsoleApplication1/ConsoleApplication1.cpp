// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;
// Print out the menu of choices for the user to select from
void printMenu() {
	cout << "Please Select which operation to perform:" << endl;
	cout << "\t1. Factorial" << endl;
	cout << "\t2. Arithmetic Series" << endl;
	cout << "\t3. Geometric Series" << endl;
	cout << "\t4. Exit" << endl;
	cout << "Your Selection: ";
}
int factorial(int num) {
	// I recommend writing your factorial code here
	int i = 0;
	int sum = 1;
	int ognum = num;
	while (i < ognum) { //while loop loops through and multiplies sums
		sum = sum * (num);
		num = num - 1; //changing the num each time
		i++; //this ensures an infinite loop doesn't occur
	}
	return sum;
}
int arithmetic(int start, int diff, int num) {
	// I recommend writing your arithmetic series code here
	int sum = 0;
	int i = 0;

	while (i < num) { 
		sum = sum + start;
		start = start + diff; //changing start each time
		i++;
	}
	return sum;

}
int geometric(int num, int mult, int power) {
	// I recommend writing your geometric series code here
	int sum = 0;
	int i = 0;
	int presum = 0;
	while (i < power) {
		presum = num * std::pow(mult, i);
		sum = presum + sum;
		i++;
	}
	return sum;
}
int main() {
	int choice;
	char again;
	int num;
	int num2;
	int num3;

	do {
		printMenu();
		std::cin >> choice;
		// Quit if user chooses to exit (or any invalid choice)
		if (choice > 3 || choice < 1) {
			return 0;
		}
		else if (choice == 1) { //this contains an extra while loop to make sure no negative numbers pass through
			cout << "Enter a number:";
			std::cin >> num;
			while (num < 0) {
				cout << "Please enter a number above zero:";
				std::cin >> num;
			}
			cout<<factorial(num)<<endl;

		}
		else if (choice == 2) {

			cout << "Enter a starting number:"; //ask the user for 3 inputs
			std::cin >> num;
			cout << "Enter a number to add each time:";
			std::cin >> num2;
			cout << "Enter the number of elements in the series:";
			std::cin >> num3;
			cout<<arithmetic(num, num2, num3)<<endl;
		}
		else if (choice == 3) {
			cout << "Enter a starting number:"; //I ran into an issue with cin multiple times with the error "cin is ambiguous" I fixed it by adding std:: before each cin
			std::cin >> num;
			cout << "Enter a number to multiply each time:";
			std::cin >> num2;
			cout << "Enter the number of elements in the series:";
			std::cin >> num3;
			cout<<geometric(num, num2, num3)<<endl;
		}
		cout << "Go Again? [Y/N] ";
		std::cin >> again;
	} while (again == 'y' || again == 'Y');
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
