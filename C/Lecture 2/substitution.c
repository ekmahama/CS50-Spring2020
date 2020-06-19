#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool duplicateChar(string key);
int checkKeyValid(string key);

int main(int argc, char *argv[])
{
    string key = argv[1];
    if (argc < 2 || argc > 2) // Check if appropriate number of input given
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (checkKeyValid(key) == 1) // Check if key is invalid
    {
        return 1;
    }
    
    //printf("Key is valid\n");

    string plaintext = get_string("plaintext: "); // Prompt user for plaintext
    int sz = strlen(plaintext);
    char encipherArr[sz];                         // Create an array for cipher text
    string keyMap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Key map for cipher keys

    for (int i = 0, n = sz; i < n; i++)
    {
        for (int j = 0, m = strlen(key); j < m; j++)
        {
            if (toupper(plaintext[i]) == keyMap[j]) // Get index for plaintext letter
            {
                encipherArr[i] = key[j]; // Replace plain text letter by its corresponding key
            }
        }
    }

    // Maintain upper case and lower case
    for (int i = 0; i < sz; i++)
    {
        if (islower(plaintext[i])) // Check if plaintext letter is lowecase
        {
            encipherArr[i] = tolower(encipherArr[i]); // set ciphertext letter to lower case
        }
        else
        {
            encipherArr[i] = toupper(encipherArr[i]); // set ciphertext letter to upper case
        }
    }

    // keep non-alphabet as it is
    for (int i = 0; i < sz; i++)
    {
        if (!isalpha(plaintext[i])) // Check if non-alpha
        {
            encipherArr[i] = plaintext[i]; // Keep non-alphabets the same
        }
    }

    // Print cipher text output
    printf("ciphertext: ");
    for (int i = 0; i < sz; i++)
    {
        printf("%c", encipherArr[i]);
    }
    printf("\n");

    return 0;
}

bool duplicateChar(string key)
{
    // A function to check for duplicate letters
    bool duplicate = false;
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (key[i] == key[j])
            {
                duplicate = true; // If duplicate found, set this to true
                break;
            }
        }
    }
    return duplicate;
}

int checkKeyValid(string key)
{
    if (strlen(key) < 26 || strlen(key) > 26) // check is key has 26 letters
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i])) // Check if key contains only alpha characteters
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    if (duplicateChar(key))
    {
        printf("Key must contain 26 unique characters.\n"); // Check if key has duplicate
        return 1;
    }
    else
    {
        return 0;
    }
}
