#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[]){
    //Check argc to get exactly 2 parameters
    if(argc!=2){
        printf("Usage: ./caesar k\n");
        return 1;
    } else {
        int key = atoi(argv[1])%26;
        string plaintext = get_string("plaintext: ");

        printf("ciphertext: ");
        for (int i = 0, n = strlen(plaintext); i < n; i++){
                //check if the letter is uppercase or lowercase then convert
                if islower(plaintext[i])
                    printf("%c", (((plaintext[i] + key) - 97) % 26) + 97);
                else if isupper(plaintext[i])
                    printf("%c", (((plaintext[i] + key) - 65) % 26) + 65);
                //if neither then just print whatever it is
                else
                    printf("%c", plaintext[i]);
            }
            printf("\n");
            return 0;
    }
}
