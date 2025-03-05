#include <cs50.h>
#include <stdio.h>
#include <math.h>

int every_other_digit(long credit_card);
int multiplyAndSum(int last_digit);
int number_of_digits(long credit_card);
bool isValidAmex(long credit_card, int numDigit);
bool isValidMasterCard(long credit_card, int numDigit);
bool isValidVisa(long credit_card, int numDigit);

int main(void)
{
    long credit_card = get_long("Credit Card: ");
    int sum_every_other_digit = every_other_digit(credit_card);
    int numDigits = number_of_digits(credit_card);
    bool amex = isValidAmex(credit_card, numDigits);
    bool master = isValidMasterCard(credit_card, numDigits);
    bool visa = isValidVisa(credit_card, numDigits);

    if (sum_every_other_digit % 10 != 0)
    {
        printf("INVALID\n");
        return 1;
    }

    if (amex)
    {
        printf("AMEX\n");
    }
    else if (master)
    {
        printf("MASTERCARD\n");
    }
    else if (visa)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

bool isValidAmex(long credit_card, int numDigit)
{
    int first_two_digits = credit_card / 10000000000000; // Extract first 2 digits for 15-digit numbers
    return (numDigit == 15 && (first_two_digits == 34 || first_two_digits == 37));
}

bool isValidVisa(long credit_card, int numDigit)
{
    if (numDigit == 13)
    {
        int first_digit = credit_card / 1000000000000; // First digit of 13-digit Visa
        return (first_digit == 4);
    }
    else if (numDigit == 16)
    {
        int first_digit = credit_card / 1000000000000000; // First digit of 16-digit Visa
        return (first_digit == 4);
    }
    return false;
}

bool isValidMasterCard(long credit_card, int numDigit)
{
    int first_two_digits = credit_card / 100000000000000; // First two digits of a 16-digit number
    return (numDigit == 16 && (first_two_digits >= 51 && first_two_digits <= 55));
}

int number_of_digits(long credit_card)
{
    int count = 0;
    while (credit_card > 0)
    {
        count++;
        credit_card /= 10;
    }
    return count;
}

int every_other_digit(long credit_card)
{
    int sum = 0;
    bool isAlternateDigit = false;

    while (credit_card > 0)
    {
        int last_digit = credit_card % 10;

        if (isAlternateDigit)
        {
            sum += multiplyAndSum(last_digit);
        }
        else
        {
            sum += last_digit;
        }

        isAlternateDigit = !isAlternateDigit;
        credit_card /= 10;
    }

    return sum;
}

int multiplyAndSum(int last_digit)
{
    int product = last_digit * 2;
    return (product / 10) + (product % 10); // Sum digits of product
}
