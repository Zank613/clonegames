#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define ALPHABET_COUNT 26

// Gets a random word from a word text file.
char* get_random_word(char filename[])
{
    FILE *file;
    char word[MAX_WORD_LENGTH];
    char random_word[MAX_WORD_LENGTH];
    int word_count = 0; // Initialize word count to 0
    
    file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL)); // Seed the random number generator

    while (fscanf(file, "%99s", word) == 1) // Scan each word from the file
    {
        word_count++;

        // Reservoir sampling technique to get a random word
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
    char *str = (char *)malloc((length + 1) * sizeof(char)); // Allocate memory for the word
    if (str == NULL)
    {
        perror("Failed to allocate memory.");
        return NULL;
    }

    strcpy(str, random_word); // Copy the randomly selected word

    return str;
}

// Gets input from the user.
char get_character(void)
{
    char c;
    printf("Enter your character of choice: ");
    
    scanf(" %c", &c); // Space before %c to skip leading whitespace

    return c;
}

// Plays one round of the game.
void play_round(char *str, char *copy_str)
{
    int lives = strlen(str) - 2; // Lives based on word length
    char user_input;
    int word_guessed = 0;

    while (lives > 0 && !word_guessed) // Continue until word is guessed or lives run out
    {
        printf("\nCurrent status: %s\n", copy_str);
        printf("Lives remaining: %d\n", lives);
        user_input = get_character();

        int correct_guess = 0;
        
        // Check if the guessed character is in the word
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (user_input == str[i] && copy_str[i] != str[i]) // Avoid overwriting already guessed letters
            {
                copy_str[i] = str[i];
                correct_guess = 1;
            }
        }

        if (!correct_guess) // If the guess was wrong
        {
            lives--;
            printf("Incorrect guess. Try again!\n");
        }
        else
        {
            printf("Correct guess! Keep it up!\n");
        }

        // Check if the entire word is guessed
        if (strcmp(str, copy_str) == 0)
        {
            word_guessed = 1;
            printf("\nCongratulations! You've guessed the word: %s\n", str);
        }
    }

    if (!word_guessed)
    {
        printf("\nYou've run out of lives! The word was: %s\n", str);
    }
}

// Resets the copied word that stores the guessed characters.
void reset_round(char *copy_str, size_t length)
{
    for (int i = 0; i < length; i++)
    {
        copy_str[i] = '_'; // Replace all characters with underscores
    }
    copy_str[length] = '\0'; // Null-terminate the string
}

// Allocates memory for a string of a given length.
char *allocate_memory_char(size_t length)
{
    char *str = (char *)malloc((length + 1) * sizeof(char)); // +1 for the null terminator
    if (str == NULL)
    {
        perror("Failed to allocate memory.");
        exit(EXIT_FAILURE);
    }
    return str;
}

// Starting menu for the game.
void starting_menu(char *filename)
{
    char *str = NULL;
    char *copy_str = NULL;
    
    printf("==== Welcome to Hangman ====\n");
    printf("Press Enter to start or Q to quit.\n");

    char user_str[2]; // To store user input
    fgets(user_str, sizeof(user_str), stdin); // Read user input

    if (user_str[0] == 'Q' || user_str[0] == 'q') // If the user wants to quit
    {
        exit(EXIT_SUCCESS);
    }

    str = get_random_word(filename); // Get the random word from the file
    size_t length = strlen(str);

    copy_str = allocate_memory_char(length); // Allocate memory for the guessed word
    reset_round(copy_str, length); // Reset the word with underscores
    play_round(str, copy_str); // Play the round

    // Free allocated memory
    free(str);
    free(copy_str);
}

#endif // HANGMAN_H
