#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER 3

void read_input(char input[])
{
    printf("Enter a move: e.g. A3, B1 or enter q to quit.\n");

    if (fgets(input, BUFFER + 1, stdin))  // Make sure to use BUFFER+1 for null terminator
    {
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n')
        {
            input[len - 1] = '\0';
        }
    }
    else
    {
        printf("Error reading input.\n");
    }
}

int play(char input[], char grid[3][3], char player)
{
    char row;
    int column;
    
    for (int i = 0; i < strlen(input); i++)
    {
        input[i] = toupper(input[i]);
    }

    if ((input[0] == 'A' || input[0] == 'B' || input[0] == 'C') && (input[1] - '0' >= 1 && input[1] - '0' <= 3))
    {
        row = input[0];
        column = input[1] - '0'; // Convert character to integer

        switch (row)
        {
            case 'A': (grid[0][column - 1] == ' ') ? (grid[0][column - 1] = player) : printf("Selected cell is full.\n"); break;
            case 'B': (grid[1][column - 1] == ' ') ? (grid[1][column - 1] = player) : printf("Selected cell is full.\n"); break;
            case 'C': (grid[2][column - 1] == ' ') ? (grid[2][column - 1] = player) : printf("Selected cell is full.\n"); break;
        }
        return 0; // Move successful
    }
    else
    {
        printf("Invalid input.\n");
        return -1; // Invalid move
    }
}

void print_grid(char grid[3][3])
{
    for (int i = 0, asci = 65; i < 3; i++)
    {
        printf("%c %c %c %c\n", asci++ ,grid[i][0], grid[i][1], grid[i][2]);
    }
    printf("  1 2 3\n");
}

void reset_grid(char grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = ' '; // Initialize to space instead of '\0'
        }
    }
}   

void check_win(char grid[3][3]) 
{
    // 1. Check rows for a win
    for (int row = 0; row < 3; row++) 
    {
        if (grid[row][0] == grid[row][1] && 
            grid[row][1] == grid[row][2] && 
            grid[row][0] != ' ') 
        { // Make sure the cell is not empty
            printf("%c wins!\n", grid[row][0]);
            exit(EXIT_SUCCESS);
        }
    }
    // 2. Check columns for a win
    for (int col = 0; col < 3; col++) 
    {
        if (grid[0][col] == grid[1][col] && 
            grid[1][col] == grid[2][col] && 
            grid[0][col] != ' ') 
        { // Make sure the cell is not empty
            printf("%c wins!\n", grid[0][col]);
            exit(EXIT_SUCCESS);
        }
    }
    // 3. Check diagonals for a win
    if (grid[0][0] == grid[1][1] && 
        grid[1][1] == grid[2][2] && 
        grid[0][0] != ' ') 
    {
        printf("%c wins!\n", grid[0][0]);
        exit(EXIT_SUCCESS);
    }
    if (grid[0][2] == grid[1][1] && 
        grid[1][1] == grid[2][0] && 
        grid[0][2] != ' ') 
    {
        printf("%c wins!\n", grid[0][2]);
        exit(EXIT_SUCCESS);
    }
    printf("No winner yet.\n");
}

int main(void)
{
    char grid[3][3];
    reset_grid(grid);  // Initialize grid
    char input[BUFFER + 1];

    char player1 = 'X', player2 = 'O';
    char current_player = player1;
    
    printf("===== Welcome to Tic-Tac-Toe! =====\n");
    print_grid(grid); // Print initial grid
    
    while (1)
    {
        printf("Player %c, make your move:\n", current_player);
        read_input(input);
        
        if (input[0] == 'q' || input[0] == 'Q')
        {
            exit(EXIT_SUCCESS);
        }

        if (play(input, grid, current_player) == 0) 
        {
            print_grid(grid);  // Show the updated grid after each move
            check_win(grid);   // Check for a win after each valid move

            // Switch players
            current_player = (current_player == player1) ? player2 : player1;
        }
    }

    return 0;
}
