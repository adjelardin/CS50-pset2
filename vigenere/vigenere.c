#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./vigenere key\n");
        return 1;
    }

    // get key
    string key = argv[1];
    int j = 0;
    int keylen = strlen(key);

    // adjust key
    for (int i = 0; i < keylen; i++)
    {
        if (key[i] >= 'a' && key[i] <= 'z')
        {
            key[i] -= 'a';
        }
        else if (key[i] >= 'A' && key[i] <= 'Z')
        {
            key[i] -= 'Z';
        }
    }

    // ask for plain text
    printf("plaintext: ");
    string text = get_string();
    int n = strlen(text);

    // convert text
    for (int i = 0; i < n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (text[i] - 'a' + key[j]) % 26 + 'a';
            j = (j + 1) % keylen;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (text[i] - 'A' + key[j]) % 26 + 'A';
            j = (j + 1) % keylen;
        }
    }

    // print encrypted text
    printf("ciphertext: %s\n", text);
    return 0;
}
