#include <iostream>

int result;
int containsFive;
int test;
int rem;

int dontGiveMeFive (int start, int end) {

int length = (end-start)+1;

  for (int i=start; i<=end; i++) {

    //create new test variable because i needs to loop from start to end integers.
    test = i;

    //handle negative numbers by changing sign
    if (test < 0) {
	test = test * -1;
    }

    //skips unnecessary  test of zero
    while (test > 0) {

      //if the remainder after dividing by 10 is 5, the last digit is 5.
      rem = test % 10;

      if (rem == 5) {
        containsFive++;
        //must only find 5 one time and move to next number
        break;
      }

      //move up to the next decimal place by dividing by 10.
      test = test / 10;
    }

  }

  result = length - containsFive;

  return result;
}






int main()
{
  int x;
  int y;

  std::cout << "Please enter the start number: ";
  std::cin >> x;
  std::cout << "Please enter the end number: ";
  std::cin >> y;

  dontGiveMeFive(x, y);

std::cout << "The number of numbers containing 5 is " << containsFive << ".\n";
std::cout << "The length of numbers without 5 is " << result << ".\n";


}
