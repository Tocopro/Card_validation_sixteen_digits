// library selected for the use in the program
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/* Initialization of variables for string numbers storing the 16 digit card number
 * Initialization of variable for position or index of the card 16-digit number
 * Initialization of variable for storing the check sum total to verify the card */
string numbers ;
int position = 1;
int checkSumTotal = 0;
/*first function the user is prompted to enter the sixteen-digit number
 * the control goes to the main function to verify the number entered is legitimate
 * *  all sixteen digits or the digits are any number between 0 -- 9
 * */
void my_function()
{
    cout << "Enter All Credit Card Numbers: ";
    cin >> numbers;
}
/* the function calculates the total using luhn logarithm and adds the total for
 * each step to the variable that holds all the total
 *
 * */
void display()
{
    for(char j: numbers)
    {
        /* the numbers in the even indexes are multiplied by two then split
         * into two digits if there are bigger than 9 then added to the
         * main total
         * or if less than 10 are added to the total 
         * */        
        if(position % 2 == 0)
        {
            if(((j * 1) * 2) > 9)
            {
                checkSumTotal += (((j * 1) - 48) * 2) % 10;
                checkSumTotal += (((j * 1) -48) * 2) / 10;
            }
        }
        // the odd index numbers are added to the total
        else
        {
            checkSumTotal += ((j * 1) - 48);
        }
        position++;
    }
}
/*
 * the function prints out the resul of the luhn algorithm to verify the card number
 * or invalidate the card number
 * */
void print_out()
{
    cout << checkSumTotal << " Check Sum Total \n";
    if (checkSumTotal % 10 == 0)
    {
        cout << "The Card is Valid:";
    }
    else
    {
        cout << "The Card is Invalid:";
    }
}
/* the main function calls the other functions in a controlled method
 * the main function also validates the digits entered or invalidates the digits if
 * there are not between 0 and 9.
 * when invalidated the control pushes the user back to the start by calling the function.
 * */
int main() {
    my_function();
    cout << numbers << " Length " << numbers.length() << "\n";
    if(numbers.length() != 16)
    {
        cout << "Invalid Credit Card Number";
    }
    for(char c: numbers)
    {
        if (c < 48 or c > 57)
        {
            cout << "Invalid Digit \n";
            my_function();
        }

    }
    /*the card number is reversed from the end becomes the beginning and the front becomes the 
     * end for easier calculation using the loop method
     * */
    reverse(numbers.begin(), numbers.end());
    cout << "Reversed Numbers " << numbers << "\n";
    // the display and print out functions are called.
    display();
    print_out();

    return 0;
    }