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
        string plainText = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plainText); i < n; i++){
            int castedChar = (int) plainText[i];
            if(isalpha(castedChar)) {
                if(islower(castedChar)) {
                    if(122-key < castedChar) {
                        printf("%c", (char)((castedChar+key)%122+96));
                    } else {
                        printf("%c", (char)(castedChar+key));
                    }
                } else {
                    if(90-key < castedChar) {
                        printf("%c", (char)((castedChar+key)%90+64));
                    }
                    else {
                        printf("%c", (char)(castedChar+key));
                    }
                }
            } else {
                printf("%c", plainText[i]);
            }
        }
    printf("\n");
    }
    return 0;
}
