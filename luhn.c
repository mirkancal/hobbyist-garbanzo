//Luhn algorithm implementation by @mirkancal
#include <stdio.h>

int main(void){
    long long int creditCardNumber;
    long long int cardNumberCopy;

    printf("Number: ");
    scanf("%lld", &creditCardNumber);
    cardNumberCopy = creditCardNumber;

    int sum = 0;
    int count = 0;
    string cardType;

    while(cardNumberCopy != 0) {
        count++;
        int digit = cardNumberCopy % 10;
        cardNumberCopy = cardNumberCopy / 10;

        if(count % 2 == 1) {
            sum = sum + digit;
        } else if(digit < 5) {
            sum = sum + 2 * digit;
        } else {
            sum = sum + 2 * digit - 9;
        }

    }

    if (sum % 10 == 0){
        // Check AMEX
        if (count == 15){
            if ((creditCardNumber / (long long) 10E12) == 34 ||
                (creditCardNumber / (long long) 10E12) == 37)
            {
                cardType = "AMEX";
            } else{
                cardType = "INVALID";
            }
        }
        else if (count == 16)
        {
            // Check Mastercard
            if ((creditCardNumber / (long long) 10E13) >= 51 &&
                (creditCardNumber / (long long) 10E13) <= 55)
            {
                cardType = "MASTERCARD";
            }
                // Check some Visas
            else if ((creditCardNumber / (long long) 10E14) == 4)
            {
                cardType = "VISA";
            }
            else
            {
                cardType = "INVALID";
            }
        }
            // Check Visa
        else if (count == 13){
            if ((creditCardNumber / (long long) 10E11) == 4){
                cardType = "VISA";
            } else{
                cardType = "INVALID";
            }
        } else{
            cardType = "INVALID";
        }
    } else{
        cardType = "INVALID";
    }

    // Print result
    printf("%s\n", cardType);

    return 0;
}
