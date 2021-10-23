#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 201

typedef struct
{
    char letter;
    int count;
} pair_t;

int findIndexOfLetterInCounter(const char letter, const pair_t *counter);
int resetCounter(pair_t *counter, const int length);
int sortCounter(const void *a, const void *b);
int sortStr(const void *a, const void *b);

int main()
{
    int cases;

    scanf("%d", &cases);
    getchar();

    char string[MAX];
    pair_t counter[MAX];

    while (cases--)
    {
        resetCounter(counter, MAX);
        int nextPushIndex = 0;

        scanf("%[^\n]s", string);
        getchar();

        const int length = strlen(string);
        for (int i = 0; i < length; i++)
        {
            if (string[i] >= 'A' && string[i] <= 'Z')
            {
                string[i] = string[i] + 32;
            }
        }

        for (int i = 0; i < length; i++)
        {
            if (string[i] >= 'a' && string[i] <= 'z')
            {
                const int indexOf = findIndexOfLetterInCounter(string[i], counter);
                if (indexOf == -1)
                {
                    counter[nextPushIndex].letter = string[i];
                    counter[nextPushIndex].count = 1;
                    nextPushIndex++;
                }
                else
                {
                    counter[indexOf].count++;
                }
            }
        }

        qsort(counter, MAX, sizeof(pair_t), sortCounter);

        int maxCount = counter[0].count;

        char maxLetters[nextPushIndex];

        int nextMaxLetter = 0;

        for (int i = 0; i < nextPushIndex; i++)
        {
            if (counter[i].count > maxCount)
            {
                maxCount = counter[i].count;
            }
        }

        for (int i = 0; i < nextPushIndex; i++)
        {
            if (counter[i].count == maxCount)
            {
                maxLetters[nextMaxLetter++] = counter[i].letter;
            }
        }
        maxLetters[nextMaxLetter] = '\0';

        char temp;
        for (int i = 0; i < nextMaxLetter; ++i)
        {
            for (int j = i + 1; j < nextMaxLetter; ++j)
            {
                if (maxLetters[i] > maxLetters[j])
                {
                    temp = maxLetters[i];
                    maxLetters[i] = maxLetters[j];
                    maxLetters[j] = temp;
                }
            }
        }

        puts(maxLetters);
    }

    return 0;
}

int findIndexOfLetterInCounter(const char letter, const pair_t *counter)
{
    for (int i = 0; i < MAX; i++)
    {
        if (counter[i].letter == letter)
        {
            return i;
        }
    }
    return -1;
}

int resetCounter(pair_t *counter, const int length)
{
    for (int i = 0; i < length; i++)
    {
        counter[i].letter = 0;
        counter[i].count = 0;
    }
}

int sortCounter(const void *a, const void *b)
{
    return ((pair_t *)b)->count - ((pair_t *)a)->count;
}