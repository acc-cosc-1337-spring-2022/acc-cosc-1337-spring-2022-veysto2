//write include statements 


/*
Write code for void function display_vector that accepts parameter const reference vector of strings.
The function will iterate through the vector and display a string per line.
*/


/*
Write code for void function update_vector_element that accepts parameter reference vector of strings,
a string vector search_value, and a string replace_value.
The function will iterate through the vector and search for the search_value and if found will
replace the vector element with the replace_value.
*/

// function to return the gc content
#include "sequence.h"

double get_gc_content(const string &dna)
{
    double content = 0.0;
    int len = 0;
    int num = 0;

    // loop through the DNA string and count the G and C
     while(dna[num] != '\0')
     {
         if (dna[num] == 'G' || dna[num] == 'C')
         {
             content += 1;
         }
         num += 1;
         len += 1; 
     }
    // return the GC / length ratio
    return content / len; 
}

// function to reverse the string DNA

string get_reverse_string(string dna)
{
    string rev = "";
    for (int letter = dna.length()-1; letter >= 0; letter--)
    {
        rev += dna[letter];
    }
    return rev;
}

// function to get the complement of the string DNA

string get_dna_complement(string dna)
{
    string letter = get_reverse_string(dna);
    string complement = "";
    for (int num = 0; num < letter.length(); num++) 
    {
        if (letter[num] == 'A') 
        {
            complement +='T';
        }

        else if(letter[num] == 'T')
        {
            complement += 'A';
        }

        else if(letter[num] == 'G') 
        {
            complement += 'C';
        }

        else if(letter[num] == 'C') 
        {
            complement += 'G';
        }

    }
    return complement;
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
    cout<<"1-Get GC Content\n";
    cout<<"2-Get DNA Complement\n";
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
{   string dna;
    double content = get_gc_content(dna);
    string complement = get_dna_complement(dna);
    
    switch(option)
    {
    case 1:
        cout << "Enter a DNA String: ";
        cin >> dna;
        get_gc_content(dna);
        cout << "GC content: " << content;       
        break;
    case 2:
        cout << "Enter a DNA String: ";
        cin >> dna;
        get_dna_complement(dna);        
        cout << "Complement: " << complement;
        break;
    case 3:
        promt_user();
        break;
    default:
        cout<<"Invalid option\n";
    }
}