// Programmer: Hariswar Baburaj
// Date: 02/28/2024
// File: Homework4.cpp
// Assignment: HW4
// Purpose: Make a Tic Tac Toe game that follows the criteria from the document.

#include <iostream>
#include <string>
using namespace std;

// Descreption: It prints out the welcome message.
// Pre: none
// Post: prints welcome message.
void printWelcomeMessage();

// Descreption: It displays the menu.
// Pre: none
// Post: prints all the sizes of the board(menu) or to quit.
void displayMenu();

// Descreption: Creates a string representation of a tic tac toe board given size.
// Pre: Maked the size to be a number between three and nine.
// Post: initializes the board after the users input
string initializeBoard(const int size);

// Descreption: This function prints out the board that the user's chose.
// Pre: Implements board to be a string variable type and makes sure the size has to be bewteen 3 and 9.
// Post: prints out the board type.
void printBoard(const string &board, const int size);

// Descreption: This updates the board everytime based on the inputs.
// Pre: The playersymbol needs to SS or TT and the board will be as a string variable and the size must be between 3 and 9.
// Post: Updates the board based on the sections of each cell for both players.
void updateBoard(string &board, const int size, const int chosenCell, const string &playerSymbol);

// Descreption: This function checks all the possible ways to see which player has won(rows, diagonals and columns).
// Pre: The board needs to be string type and size has to be between 3 and 9.
// Post: It returns true if any one of player has gotten a full row, column and diagonal.
bool checkWin(const string &board, const int size, const string &playerSymbol);

// Descreption: This checks if there is a tie between two players.
// Pre: The overall turns can not be negative integer must be positive integer less than or equal to the size the board based on users input.
// Post: It returns true if it is a tie between players.
bool checkTie(string board, int overall_turns, const int size);
// Descreption: This prints out the good bye message.
// Pre: none
// Post: prints good bye message.
void printGoodbyeMessage();

int main()
{
  // stores all the important variables that needed for the game.
  string player1, player2;
  string player1_symbol = "SS";
  string player2_symbol = "TT";
  string board;
  int options, size, chosenCell;
  bool validResponse = false;
  bool stillPlaying = true;
  int overall_turns = 0;

  printWelcomeMessage();
  cout << "Enter the first name of player1: ";
  getline(cin, player1);
  cout << "Enter the first name of player2: ";
  getline(cin, player2);
  displayMenu();
  cout << "Select an option from above: ";
  cin >> options;

  // This gets the board size based on the selection of the user.
  do
  {
    overall_turns = 0;
    if ((options <= 0) || (options > 8))
    {
      printGoodbyeMessage();
      break;
    }
    else
    {
      switch (options)
      {
      case 1:
        size = 3;
        validResponse = true;
        board = initializeBoard(size);
        break;
      case 2:
        size = 4;
        validResponse = true;
        board = initializeBoard(size);
        break;
      case 3:
        size = 5;
        validResponse = true;
        board = initializeBoard(size);
        break;
      case 4:
        size = 6;
        validResponse = true;
        board = initializeBoard(size);
        break;
      case 5:
        size = 7;
        validResponse = true;
        board = initializeBoard(size);
        break;
      case 6:
        size = 8;
        validResponse = true;
        board = initializeBoard(size);
        break;
      case 7:
        size = 9;
        validResponse = true;
        board = initializeBoard(size);
        break;
      case 8:
        cout << "Goodbye!" << endl;
        printGoodbyeMessage();
        validResponse = true;
        stillPlaying = false;
        return 0;
      default:
        cout << "Please choose the correct option" << endl;
        break;
      }
    }
    while (!validResponse)
      ;
    if (!stillPlaying)
    {
      break;
    }

    // Game loop
    printBoard(board, size);
    do
    {
      // Player 1 turn
      cout << player1 << " (SS), choose a cell: ";
      cin >> chosenCell;

      // If a player 1 chose a number that is not in the range of the board size. It asks them again
      while (chosenCell > (size * size) || chosenCell <= 0)
      {
        cout << "Cell is invalid." << endl;
        cout << player1 << "(SS), choose a cell agin: ";
        cin >> chosenCell;
      }
      // Check if cell is valid
      while (((board[chosenCell * 2 - 1] == 'S') &&
              (board[chosenCell * 2 - 2] == 'S')) ||
             ((board[chosenCell * 2 - 1] == 'T') &&
              (board[chosenCell * 2 - 2] == 'T')))
      {
        cout << "The cell has already been chosen.";
        cout << player1 << "(SS), choose a cell: ";
        cin >> chosenCell;
      }

      overall_turns += 1;
      // updates the board and print it out
      updateBoard(board, size, chosenCell, player1_symbol);
      printBoard(board, size);

      // If a player has won or there is a tie, end the game
      if (checkWin(board, size, player1_symbol) ||
          checkTie(board, overall_turns, size))
      {
        break;
      }

      // Player 2 turn
      cout << player2 << " (TT), choose a cell: ";
      cin >> chosenCell;

      // If a player 2 chose a number that is not in the range of the board size. It asks them again
      while (chosenCell > (size * size) || chosenCell <= 0)
      {
        cout << "Cell is invalid." << endl;
        cout << player2 << "(TT), choose a cell again: ";
        cin >> chosenCell;
      }
      // If player 2 chose a cell that is already taken. It would tell him to pick another cell.
      while (((board[chosenCell * 2 - 1] == 'S') &&
              (board[chosenCell * 2 - 2] == 'S')) ||
             ((board[chosenCell * 2 - 1] == 'T') &&
              (board[chosenCell * 2 - 2] == 'T')))
      {
        cout << "The cell has already been chosen. Choose a different cell." << endl;
        cout << player2 << "(TT), choose a cell: ";
        cin >> chosenCell;
      }

      overall_turns += 1;
      updateBoard(board, size, chosenCell, player2_symbol);
      printBoard(board, size);
    } while (!checkWin(board, size, player2_symbol) &&
             (!checkWin(board, size, player1_symbol)) &&
             !checkTie(board, overall_turns, size));

    // Prints out which player won or if it was a ties
    if (checkWin(board, size, player1_symbol))
    {
      cout << "Congratulations " << player1 << "! You won!" << endl;
    }
    else if (checkWin(board, size, player2_symbol))
    {
      cout << "Congratulations " << player2 << "! You won!" << endl;
    }
    else
    {
      if (checkTie(board, overall_turns, size))
      {
        cout << "It's a tie!" << endl;
      }
    }

    // Displays menu after the player has one and aks them to play again.
    displayMenu();
    cin >> options;

  } while (stillPlaying);
}

void printWelcomeMessage()
{
  cout << "Welcome to Dynamic Tic-Tac-Toe Missouri S&T Edition!" << endl;
}
void displayMenu()
{
  // Displays all the board options that is available to choose.
  cout << "Choose the size of the Tic-Tac-Toe board or Quit:" << endl;
  cout << "1. 3x3 Board" << endl;
  cout << "2. 4x4 Board" << endl;
  cout << "3. 5x5 Board" << endl;
  cout << "4. 6x6 Board" << endl;
  cout << "5. 7x7 Board" << endl;
  cout << "6. 8x8 Board" << endl;
  cout << "7. 9x9 Board" << endl;
  cout << "8. Quit the program" << endl;
}
string initializeBoard(const int size)
{
  // Initializes the board based on the size that has been chosen by the users.
  string createboard;
  int total_cell = size * size;
  for (int i = 1; i <= total_cell; i++)
  {
    if (i < 10)
    {
      createboard += "0";
      createboard = createboard + to_string(i);
    }
    else
    {
      createboard = createboard + to_string(i);
    }
  }
  return createboard;
}
void printBoard(const string &board, const int size)
{
  cout << "Current Board:" << endl;
  // it prints the board after the input has been chosen.
  for (int i = 0; i < (size * 2); i += 2)
  {
    for (int j = 0; j < (size * 2); j += 2)
    {
      cout << board[i * size + j] << board[i * size + j + 1] << " ";
    }
    cout << endl;
  }
}
void updateBoard(string &board, const int size, const int chosenCell,
                 const string &playerSymbol)
{
  // This update boards everytime player 1 and player chose the cell.
  int cellindex1 = (chosenCell * 2) - 2;
  int cellindex2 = (chosenCell * 2) - 1;
  board[cellindex1] = playerSymbol[0];
  board[cellindex2] = playerSymbol[1];
}
bool checkWin(const string &board, const int size, const string &playerSymbol)
{
  string winner = "";
  // Iterate through each element up to size.
  for (int i = 0; i < size; i++)
  {
    // Links the player's symbol to the 'winner' string.
    winner += playerSymbol;
  }
  // Check Rows
  for (int i = 0; i < size; i++)
  {
    string rows;
    // Check the rows based on different board size.
    rows = board.substr(i * size * 2, size * 2);
    if (rows == winner)
    {
      return true;
    }
  }
  // Check Columns
  for (int i = 0; i < size; i++)
  {
    string columns = "";
    for (int j = 0; j < size; j++)
    {
      // Check the Columns based on different board size.
      columns += board.substr(j * size * 2 + i * 2, 2);
    }

    if (columns == winner)
    {
      return true;
    }
  }
  // Check each Diagonals
  string diagonal1 = "";
  string diagonal2 = "";

  for (int i = 0; i < size; i++)
  {
    // Check both colums based on different board size.
    diagonal1 += board.substr(i * size * 2 + i * 2, 2);
    diagonal2 += board.substr(i * size * 2 + (size - 1 - i) * 2, 2);
  }
  if (diagonal1 == winner || diagonal2 == winner)
  {
    return true;
  }
  return false;
}

bool checkTie(string board, int overall_turns, const int size)
{
  // Checks if the game is a tie based on board size and user's inputs.
  if (overall_turns == size * size)
  {
    return true;
  }
  return false;
}
void printGoodbyeMessage()
{
  cout << "Thanks for playing! See you again soon." << endl;
}