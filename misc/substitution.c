#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* encryptText(char* plaintextPtr, char key[]);

int main(int argc, char * argv[])
{
    if(argc != 2){ // num of c-line arguments is not 1 
        printf("Usage: ./substitution key");
        return 0;
    }
    
    char key[26];
    strcpy(key, argv[1]); // store inputed cipher key from the user in variable key
    if(strlen(key) != 26){ // ensure that the key covers the alphabet, i.e. 26 characters
        printf("Key must contain 26 characters.");
        return 0;
    }

    // at this point we know that we have a valid key with correct usage

    char plaintext[1024];
    char* plaintextPtr = plaintext;
    printf("plaintext: "); 
    fgets(plaintext, 1024, stdin); // store plaintext input from the user

    char* ciphertext = encryptText(plaintextPtr, key);
    printf("ciphertext: %s", *ciphertext);

}


char* encryptText(char* plaintextPtr, char key[]){

    char cipher[1024];
    char* cipherPtr = cipher;

    while(*plaintextPtr != '\n')
    {
        if(isalpha(*plaintextPtr) != 0) { // is a letter to convert

            char currentChar = tolower(*plaintextPtr);
            int position = currentChar - 97; // position of letter in the alphabet
            char replacement = key[position];

            if(isupper(*plaintextPtr)){
                *cipherPtr = toupper(replacement);
            }
            else{
                *cipherPtr = tolower(replacement);
            }

            plaintextPtr++;
        }
        else{
            *cipherPtr = *plaintextPtr;
            plaintextPtr++;
        }
    }

    return cipherPtr;
}