# Tic-Tac-Toe

A simple command-line based Tic-Tac-Toe game implemented in C. This game is for two players, where each player takes turns to mark a cell on a 3x3 grid. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row wins the game.

## Features
- Two-player mode.
- Grid is displayed after each move.
- Input validation ensures only valid moves are accepted.
- Win detection for rows, columns, and diagonals.
- Players can exit the game anytime by typing "exit".
  
## How to Play
- The game is played on a 3x3 grid.
- Player 1 is represented by 'X' and Player 2 is represented by 'O'.
- On their turn, players should input their move in the form of `A1`, `B3`, etc., where the letter corresponds to the row and the number to the column.
- The rows are labeled 'A', 'B', and 'C', while the columns are numbered '1', '2', and '3'.
- A player wins by placing three of their marks ('X' or 'O') in a horizontal, vertical, or diagonal line.
- If all cells are filled and no player has won, the game ends in a draw.
- Players can type `exit` to quit the game at any time.

## Sample Input/Output
===== Welcome to Tic-Tac-Toe! ===== X X O A
B
C
1 2 3 Player X, make your move: A1 X
A X
B
C
1 2 3 Player O, make your move: B2 X
A X
B O
C
1 2 3

## Building and Running
1. Clone or download this repository.
2. Open your terminal/command prompt and navigate to the project directory.
3. Compile the program using a C compiler. Example using `gcc`:
   ```bash
   gcc -o main main.c
4. Requirements C compiler (e.g., GCC or Clang)
