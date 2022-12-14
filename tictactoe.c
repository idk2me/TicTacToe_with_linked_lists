// Make a simple tic-tac-toe game in C with user input as n. n*n defines the grid's dimensions and it can only be in between 2 and 50
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_grid(int n, char grid_dimensions[n][n]);
bool is_grid_full(int n, char grid_dimensions[n][n]);
void update_grid(int n, char grid[n][n], int turnInt);
bool check_column(int n, char grid_dimensions[n][n]);
bool check_row(int n, char grid_dimensions[n][n]);
bool check_diagonals(int n, char grid_dimensions[n][n]);

int main()
{
    int n;
    bool game_over = false;
    char player1 = 'X';
    char player2 = 'O';
    int turn = 1;

    // struct Grid *grid;
    printf("Enter grid width: ");
    scanf("%d", &n);

    if(n < 2 || n > 50)
    {
        printf("Please enter a number between 2 and 50.\n");
        printf("Enter grid width: ");
        scanf("%d", &n);
    }

    char grid[n][n];
    for(int row = 0; row < n; row++)
    {
        for(int column = 0; column < n; column++)
        {
            grid[row][column] = '-';
        }
    }

    bool is_stalemate = is_grid_full(n, grid);

    while(game_over == false)
    {
        print_grid(n, grid);
        update_grid(n, grid, turn);
        if(check_row(n, grid)) game_over = true;
        if (check_column(n, grid) == true) game_over = true;
        if(check_diagonals(n, grid) == true) game_over = true;
        if(is_grid_full(n, grid) == true) game_over = true;
        turn++;
    }

    if(is_grid_full(n, grid) == true && check_column(n, grid) == false && check_row(n, grid) == false && check_diagonals(n, grid) == false) printf("It is a draw!");
    else if(turn % 2 == 0) printf("Player X wins!");
    else if(turn % 2 == 1)
    {
        printf("Player O wins!");
    } else printf("It is a draw!");

    return 0;
}

void print_grid(int n, char grid_dimensions[n][n])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%c ", grid_dimensions[i][j]);
        }
        printf("\n");
    }
}

bool is_grid_full(int n, char grid_dimensions[n][n])
{
    
    int row = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid_dimensions[i][j] != '-') row++;
        }
        if(row == (n*n)) return true;
    }
    return false;
}

void update_grid(int n, char grid[n][n], int turnInt)
{
    int row, column;
    char turn = 'X';
    printf("\n");
    printf("Enter row and column values: \n");
    // printf("\n");
    scanf("%d %d", &row, &column);
    if(grid[(row - 1)][(column - 1)] == 'X' || grid[(row - 1)][(column - 1)] == 'O')
    {
        printf("This position is already taken. Please enter another position.");
        scanf("%d", &row);
        scanf("%d", &column);
    }
    // Set turn to 'O' if the turnInt is odd, otherwise set it to 'X'
    if(turnInt % 2 == 1) {
        turn = 'X';
    } else {
        turn = 'O';
    }

    // Update the grid with the current player's symbol
    grid[(row-1)][(column-1)] = turn;
}

bool check_column(int n, char grid_dimensions[n][n])
{
    for(int i = 0; i < n; i++)
    {
        int column = 0;
        for(int j = 0; j < n; j++)
        {
            if(grid_dimensions[j][i] == 'X') column++;
            else if(grid_dimensions[j][i] == 'O') column--;
        }
        if(column == n) {
            printf("Player X wins!");
            return true;
        }
        else if(column == -n) {
            printf("Player O wins!");
            return true;
        }
    }

    return false;
}

bool check_row(int n, char grid_dimensions[n][n])
{
    for(int i = 0; i < n; i++)
    {
        int rowX = 0;
        int rowO = 0;
        for(int j = 0; j < n; j++)
        {
            if(grid_dimensions[i][j] == 'X') rowX++;
            else if(grid_dimensions[i][j] == 'O') rowO++;
        }
        if(rowX == n) {
            printf("Player X wins!");
            return true;
        }
        else if(rowO == n) {
            printf("Player O wins!");
            return true;    
        }
    }

    return false;
}

bool check_diagonals(int n, char grid_dimensions[n][n])
{
    // Check the first diagonal (top-left to bottom-right)
    char diagonal1 = grid_dimensions[0][0];
    bool diagonal1_filled = true;
    for (int i = 0; i < n; i++) {
        if (grid_dimensions[i][i] == '-') {
            diagonal1_filled = false;
            break;
        } else if (grid_dimensions[i][i] != diagonal1) {
            diagonal1_filled = false;
            break;
        }
    }

    // Check the second diagonal (top-right to bottom-left)
    char diagonal2 = grid_dimensions[0][n - 1];
    bool diagonal2_filled = true;
    for (int i = 0; i < n; i++) {
        if (grid_dimensions[i][n - i - 1] == '-') {
            diagonal2_filled = false;
            break;
        } else if (grid_dimensions[i][n - i - 1] != diagonal2) {
            diagonal2_filled = false;
            break;
        }
    }

    // Return true if one of the diagonals is filled with the same symbol ('X' or 'O')
    return (diagonal1_filled && diagonal1 == 'X') || (diagonal2_filled && diagonal2 == 'X')
        || (diagonal1_filled && diagonal1 == 'O') || (diagonal2_filled && diagonal2 == 'O');
}