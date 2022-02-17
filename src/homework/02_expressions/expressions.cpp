#include "expressions.h"

//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}

//write code for multiply_numbers function here
//function returns product of num1 and num2

/*multiply tax_rate and meal_amount and return their
product.*/
double get_sales_tax_amount(double meal_amount)
{
	double tax_rate = .0675;
	return tax_rate * meal_amount;
}

/*create a double value-return function prototype named 
get_tip_amount with two double parameters: meal_amount and tip_rate.*/
double get_tip_amount(double meal_amount, double tip_rate)
{
	return meal_amount * tip_rate;
}



