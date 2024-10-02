#ifndef HANGMAN_HELPER
#define HANGMAN_HELPER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define ALPHABET_COUNT 26

char* get_random_word(char filename[])
{
    FILE *file;
    char word[MAX_WORD_LENGTH];
    char random_word[MAX_WORD_LENGTH];
    int word_count;
    
    file = fopen(filename, "r");

    if (file == NULL)
    {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    while (toupper(fscanf(file, "%99s", word) == 1))
    {
        word_count++;

        if (rand() % word_count == 0)
        {
            snprintf(random_word, MAX_WORD_LENGTH, "%s", word);
        }
    }

    fclose(file);

    if (word_count == 0)
    {
        printf("No words in file.\n");
        exit(EXIT_FAILURE);
    }

    size_t length = strlen(random_word);

    char *str = (char *)malloc((length + 1) * sizeof(char));
    if (str == NULL)
    {
        perror("Failed to allocate memory.");
        return NULL;
    }

    strcpy(str, random_word);

    return str;
}

char get_character(void)
{
    char c;
    printf("Enter your character of choice: ");
    
    scanf("%1s", &c);

    return c;
}

void play_round(char *str, char *copy_str, char (*get_character)(void))
{
    
}

#endif // HANGMAN_HELPER