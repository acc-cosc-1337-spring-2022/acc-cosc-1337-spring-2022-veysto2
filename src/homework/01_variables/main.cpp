//write include statements
#include<iostream>
#include "variables.h"

//write namespace using statement for cout
using std::cin, std::cout;


int main()
{
	int num; 
	cout << "Enter a number: "; 
	cin >> num; 

	int result; 
    result = multiply_numbers(num); 
    cout << "The product of " << num << " times 5 is: " << result << "\n";

	int num1 = 4; 
	result = multiply_numbers(num1); 
	cout << "The product of " << num1 << " times 5 is: " << result << "\n"; 

	return 0;
}
