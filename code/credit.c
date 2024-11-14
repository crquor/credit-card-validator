#include <cs50.h>
#include <stdio.h>

int main(void)
{

    long cardn, copy;
    int i, count = 0, digit, c;
    int mul, digit1, s1 = 0, s2 = 0, s3;
    int num[16]; // to store individual digits of the card number

    // Ask user to enter the card number
    cardn = get_long("Enter card number: "); // get card number from the user
    copy = cardn;

    // count number of digits in the card number
    while (copy > 0)
    {
        count++;
        copy /= 10;
    }
    c = count;
    if (c > 16 || c < 13)
    {
        printf("INVALID\n");
        return 0;
    }

    // store individual digits into a variable
    count--;
    while (count >= 0)
    {
        digit = cardn % 10;
        num[count] = digit;
        cardn /= 10;
        count--;
    }

    // Identify Card type

    if ((num[0] == 4) && (c == 13 || c == 16))
    {

        printf("VISA\n");
    }

    else if ((num[0] == 3) && (num[1] == 4 || num[1] == 7) && (c == 15))
    {
        printf("AMEX\n");
    }

    else if ((num[0] == 5) && (num[1] >= 1 && num[1] <= 5) && (c == 16))
    {
        printf("MASTERCARD\n");
    }

    else
    {
        printf("INVALID\n");
        return 0;
    }

    // luhn's algorithm
    c--; // decrement counter by 1 because the digits are stored from num[0] to num[Total digits in
         // card number-1]
    while (c >= 0)
    {

        // sum of alt digits
        if (c % 2 == 1) // to get second-to-last digit and every other digit
        {
            mul = num[c] * 2;
            if (mul > 9)
            {
                s1 = s1 + mul - 9;
            }
            else
            {
                s1 += mul;
            }
        }

        else
        {
            s2 = s2 + num[c]; // adding the digits that weren't multiplied by 2
        }

        c--;
    }
    s3 = s1 + s2;
    // check and print whether the given number is valid or not by finding if last digit of sum is zero or not
    if (s3 % 10 == 0)
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
