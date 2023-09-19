#include <iostream>

using namespace std;
char currentPlayer = 'X';
int prompt;

char board[3][3] = {
    {'-', '-', '-'},
    {'-', '-', '-'},
    {'-', '-', '-'},
};

void displayBoard()
{
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            // Print the cell content
            std::cout << board[row][col];
            if (col < 2)
            {
                std::cout << " | ";
            }
        }

        if (row < 2)
        {
            std::cout << std::endl
                      << "" << std::endl;
        }
        else
        {
            std::cout << std::endl;
        }
    }
}

bool isMoveValid(int row, int col)
{
    // Check if the specified row and column are within the bounds of the board
    if (row >= 0 && row < 3 && col >= 0 && col < 3)
    {
        // Check if the cell is empty (not already occupied)
        if (board[row][col] == '-')
        {
            // The move is valid
            std::cout << "Valid move \n";

            return true;
        }
    }

    // If any of the conditions above is not met, the move is invalid
    std::cout << "Invalid move";

    return false;
}

bool checkWin()
{
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i)
    {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-')
        {
            return true; // Row i has a winning combination
        }

        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-')
        {
            return true; // Column i has a winning combination
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-'))
    {
        return true; // Either diagonal has a winning combination
    }

    // No winning combinations found
    return false;
}

bool isBoardFull()
{
    // Iterate through the entire board
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            // If any cell is empty, the board is not full
            if (board[row][col] == '-')
            {
                return false;
            }
        }
    }

    // If no empty cells are found, the board is full
    return true;
}

void switchPlayer()
{
    if (currentPlayer == 'X')
    {
        currentPlayer = 'O';
    }
    else
    {
        currentPlayer = 'X';
    }
}

int main(int argc, char **argv)
{
    bool gameIsOver = false;
    while (!gameIsOver)
    {
        displayBoard();
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;
        row = row - 1;
        col = col - 1;
        if (isMoveValid(row, col))
        {
            board[row][col] = currentPlayer;
            if (checkWin())
            {
                displayBoard();
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                cout << "Press Enter to Continue";
                system("pause");
                gameIsOver = true;
            }
            else if (isBoardFull())
            {
                displayBoard();
                std::cout << "It's a draw!" << std::endl;
                gameIsOver = true;
            }
            else
            {
                // Switch to the other player
                switchPlayer();
            }
        }
        else
        {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    return 0;
}