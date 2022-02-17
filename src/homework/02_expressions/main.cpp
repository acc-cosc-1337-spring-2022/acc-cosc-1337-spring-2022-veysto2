//write include statements
#include <iostream>
#include "expressions.h"

//write namespace using statement for cout
using std::cout;
using std::cin;


int main()
{
	double meal_amount = 0,
 		tip_rate =0,
 		tip_amount = 0,
 		tax_amount = 0,
 		total = 0;

 	cout<<"Enter the cost of the meal: \n";
 	cin>>meal_amount;
 	
	get_sales_tax_amount (meal_amount);
 	tax_amount = meal_amount * .0675;

 	cout<<"Enter the tip rate: \n";
 	cin>>tip_rate;

 	get_tip_amount (meal_amount, tip_rate);
 	tip_amount = meal_amount * tip_rate;

 	total = meal_amount + tax_amount + tip_amount;

 	cout<<"Meal Amount: "<<meal_amount<<"\n";
 	cout<<"Sales Tax: "<<tax_amount<<"\n";
 	cout<<"Tip Amount: "<<tip_amount<<"\n";
 	cout<<"Total: "<<total<<"\n";
 	
	return 0;
}

