#include <stdio.h>
int cardtype(int count, int num[]);
int main()
{

    long int cardn;
    int num[16];
    int s1 = 0, s2 = 0, count = 0;
    int digit, mul, t;

    // Ask user to enter the card number

    printf("Enter card number: ");
    scanf("%ld", &cardn);

    // store the individual digits into a variable and count the number of digits

    while (cardn > 0)
    {
        digit = cardn % 10;
        num[count] = digit;
        cardn /= 10;
        count++;
    }

    // Validate the length
    // and end the program if the length is less than 13 or more than 16

    if (count < 13 || count > 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Identify Card Type

    cardtype(count, num); // calling function and passing arguments

    // luhn's algorithm

    for (int i = 0; i < count; i++)
    {
        if (i % 2 == 1)
        {
            mul = num[i] * 2; // doublinng every other digit from second-to-last

            if (mul > 9)
            {
                s1 = s1 + mul - 9; // If the product is greater than 9 i.e. double digit, subtract nine
            }
            else
            {
                s1 += mul;
            }
        }

        else
        {
            s2 += num[i]; // Sum the digits that weren't multiplied by 2
        }
    }

    // Check Validity

    if ((s1 + s2) % 10 == 0)
    {
        printf("Validity(Luhn's Algorithm): VALID\n");
    }
    else
    {
        printf("Validity(Luhn's Algorithm): INVALID\n");
    }
    printf("\n");

    return 0;
}

// function to indentify card type

int cardtype(int count, int num[])
{
    if ((num[count - 1]) == 4 && (count == 13 || count == 16))
    {
        printf("Brand/Network: VISA\n");
    }
    else if (num[count - 1] == 3 && (num[count - 2] == 4 || num[count - 2] == 7) && count == 15)
    {
        printf("Brand/Network: AMEX\n");
    }
    else if (num[count - 1] == 5 && num[count - 2] >= 1 && num[count - 2] <= 5)
    {
        printf("Brand/Network: MASTERCARD\n");
    }
    else if (num[count - 1] == 6 && count == 16)
    {
        printf("Brand/Network: DISCOVER\n");
    }
    else
    {
        printf("INVALID Length and/or Brand/Network\n");
        return 0;
    }
}
