#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int getWordCount(string text, int n);
int getCharCount(string text, int n);
int getSentenceCount(string text, int n);
int readabilityIndex(int numWords, int numChar, int numSent);

int main()
{
    string text = get_string("Text: ");
    int strLength = strlen(text);
    //printf("Length: %i\n", strLength);

    int charCnt = getCharCount(text, strLength); // get letters count

    int wordCnt = getWordCount(text, strLength); // get word count

    int sentCnt = getSentenceCount(text, strLength); // get sentences count

    int index = readabilityIndex(wordCnt, charCnt, sentCnt); // Get readability index

    // printf("Letters: %i\n", charCnt);
    // printf("Words: %i\n", wordCnt);
    // printf("Sentences: %i\n", sentCnt);
    // // printf("Grade %i\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }

    return 0;
}

int getWordCount(string text, int n)
{
    int cnt = 0; // Counter to store the word character count
    for (int i = 0; i < n; i++)
    {
        if (isspace(text[i])) // Spaces marks end of words
        {
            cnt++; // Increase by 1 when you see a white space
        }
    }

    return cnt + 1;
}

int getCharCount(string text, int n)
{
    int cnt = 0; // Counter to store the word character count

    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i])) // Check if char is alphabet
        {
            cnt++; // Increase by 1 when you see a non-white space
        }
    }
    return cnt;
}

int getSentenceCount(string text, int n)
{
    int cnt = 0; // Counter to store the word character count
    for (int i = 0; i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') // Indication of end of sentences
        {
            cnt++; // Increase by 1 when you see a . or ! or ?
        }
    }
    return cnt;
}

int readabilityIndex(int numWords, int numChar, int numSent)
{
    float L = ((float)numChar / (float)numWords) * 100;
    float S = ((float)numSent / (float)numWords) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    //printf("index : %f",round(index));

    return (int)round(index);
}