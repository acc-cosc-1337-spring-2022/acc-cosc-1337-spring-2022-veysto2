#include<iostream>
#include "dna.h"
using std::swap; using std::cout; using std::cin;

/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/




/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/



/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string

*/

/*
write the function code for the factorial and gcd functions using 
a loop of your choice.  Do not use a recursive solution to solve 
this problem.
*/

//find factorial

int factorial(int num) 
{
    int sum = 1;  
    while (num > 0)
    {
        sum = sum * num;
        num--;
    }
    return sum;  
}

//find greatest common divisor

int gcd(int num1,int num2)
{
    while(num1 > 0)
    {
         if(num1 < num2) 
         {
            swap(num1,num2);
         }
         num1 = num1 - num2;
    }
    return num2;
}

// Exit promt

void promt_user()
{
    auto end = 'n';
    do
    {
        cout<<"Are you sure you want to exit(y or n)?: \n";
        cin>>end;
        if(end == 'y')
            break;
        else
        {
            run_menu();
        }
        
    } 
    while(end == 'y');
}    

// display menu
void display_menu()
{
     cout<<"1-Factorial\n";
     cout<<"2-Greatest Common Divisor\n";
     cout<<"3-Exit\n";
}   

void run_menu()
{
    auto option = 0;
    do
    {
       display_menu();
       cout<<"Enter option number: ";
       cin>>option;

       handle_menu_option(option); 
    } 
    while (option != 3);
}

void handle_menu_option(int option)
{
    switch(option)
    {
    case 1:
        input_factorial();
        break;
    case 2:
        input_gcd();
        break;
    case 3:
        promt_user();
        break;
    default:
        cout<<"Invalid option\n";
    }
}

//input_factorial 
void input_factorial()
{
    int num1, sum;
    cout<<"Enter a number between 1-15: ";
    cin>>num1;
    sum = factorial(num1);
    cout<<"The factorial of your number is "<<sum<<"\n";
}

//input_gcd
void input_gcd()
{
    int num1, num2, ans;
    cout<<"Enter two integer numbers to find the Greatest Common Divisor:\n";
    cout<<"Enter first number: \n";
    cin>>num1;
    cout<<"Enter second number: \n";
    cin>>num2;
    ans = gcd(num1,num2);
    cout<<"The answer is: "<<ans<<"\n";
}
