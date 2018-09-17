#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    // ensure correct number of command-line args
    if (argc > 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // get key
    int k = abs(atoi(argv[1]));

    // ask for text
    printf("plaintext: ");
    string text = get_string();
    int n = strlen(text);

    // convert text
    for (int i = 0; i < n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (text[i] - 'a' + k) % 26 + 'a';
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (text[i] - 'A' + k) % 26 + 'A';
        }
    }

    // print encrypted text
    printf("ciphertext: %s\n", text);
    return 0;
}
