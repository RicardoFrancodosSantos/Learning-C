#include <cs50.h>
#include <stdio.h>
#include <math.h>


int every_other_digit (long credit_card);
int multiplyAndSum (int last_digit);
int number_of_digits (long credit_card);
bool isValidAmex (long credit_card, int numDigit);

int main(void)

{

  long credit_card = get_long("Credit Card: ");
  int sum_every_other_digit = every_other_digit(credit_card);
  int numDigits = number_of_digits(credit_card);
  bool amex = isValidAmex (credit_card, numDigits);
  printf("%i\n", numDigits);
  if (sum_every_other_digit % 10 != 0) {
     printf("INVALID\n");
     return 1;
  }

  else if (amex == true) {
    printf("AMEX\n");
  }

}

bool isValidAmex (long credit_card, int numDigit) {
   int first_two_digits = credit_card / pow (10,13);
   if ((numDigit = 15) & (first_two_digits = 34) || (first_two_digits = 37)){
   return true;
  }
    else {
     return false;
    }
}


int number_of_digits (long credit_card) {
  int count = 0;
  while (credit_card > 0) {
    count = count + 1;
    credit_card = credit_card / 10;
  }
  return count;
}
int every_other_digit (long credit_card){
  int sum = 0;
  bool isAlternateDigit = false;
  while (credit_card > 0) {
        if (isAlternateDigit == true) {
          int last_digit = credit_card % 10;
          int product = multiplyAndSum(last_digit);
          sum = sum + product;
        }

        else {
          int last_digit = credit_card % 10;
          sum = sum + last_digit;
        }
        isAlternateDigit = !isAlternateDigit;
        credit_card = credit_card / 10;
   }

   return  sum;
}

   int multiplyAndSum (int last_digit) {
       int multiply = last_digit * 2;
       int sum = 0;
       while (multiply > 0) {
          int last_digit_multiply = multiply % 10;
          sum = sum + last_digit_multiply;
          multiply = multiply / 10;
       }
       return  sum;
   }




