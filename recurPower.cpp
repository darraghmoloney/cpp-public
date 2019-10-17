/*  This program takes in two numbers as user input and calls a recursive function
*   to calculate the number raised to the power (exponent).
*
*   It is based on a Khan Academy JavaScript challenge, but adapted for C++.
*/

#include <iostream>

//The function takes in ints but must return a double
//for the case of negative powers
double recurPower(int num, int power) {

    //base case x^0 is 1
    if(power == 0) {
        return 1.0;
    }

    //if power is negative, return
    //recursive of 1 / x^-1
    if(power < 0) {
        int negPower = power * -1;
        return 1.0 / recurPower(num, negPower);
    }
    
    //if power is odd, return
    //recursive of x * x^n-1
    if(power % 2 == 1) {
        return static_cast<double>(num) * recurPower(num, (power-1));
    }

    //if power is even, return
    //x^(n/2) * x^(n/2)
    if(power % 2 == 0) {
        //temp var to only calculate once
        //for efficiency
        double temp = recurPower(num, (power/2));
        return temp * temp;
    } 

}

int main() {

    bool choice = true;
    do {
        std::cout << "Enter the number and the exponent.\n";
        std::cout << ":";

        int num1 = 0;
        int num2 = 0;

        std::cin >> num1;
        std::cin >> num2;

        std::cout << num1 << "^" << num2 << " is " << recurPower(num1, num2) 
            << ".\n";

        std::cout << "Try again? y/n: ";
        char again;
        std::cin >> again;
        
        if(again == 'N' || again == 'n') {
            choice = false;
        }


    } while(choice);
    
    return 0;
}
