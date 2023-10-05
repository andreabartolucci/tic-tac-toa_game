#include <iostream>
#include <vector>
#include "ttt.hpp"

std::vector<char> board = {' ', ' ', ' ', 
                            ' ', ' ', ' ',
                            ' ', ' ', ' '};

int player = 2; //player 2 start
char mark = '0'; //initialize with player 2 mark
int number_turn = 1; //initialize numer of turn at 1

void draw() {
    std::cout << "     |     |      \n";
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    std::cout << "     |     |      \n";
    std::cout << "\n";
}

void introduction() {
  std::cout << "Press [Enter] to begin: \n";
  std::cin.ignore();
  std::cout << "\n";
  std::cout << "===========\n";
  std::cout << "Tic-Tac-Toe\n";
  std::cout << "===========\n\n";

  std::cout << "Player 1) ✖\n";
  std::cout << "Player 2) 0\n\n";

  std::cout << "Here's the 3 x 3 grid:\n\n";

  std::cout << "     |     |      \n";
  std::cout << "  1  |  2  |  3   \n";
  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";
  std::cout << "  4  |  5  |  6   \n";
  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";
  std::cout << "  7  |  8  |  9   \n";
  std::cout << "     |     |      \n\n";

  draw();
}


bool is_winner() {
 
 bool winner;
 
  // loop on rows
 for (int row = 0; row<=6; row = row + 3) {
  winner = true;
  // loop on cols
  for (int col = 1; col<=2; col++) {
    //check if winner
    if ( (board[row + col] == ' ') || (board[row + col] != board[row + col - 1]) ) {
      winner = false;
      // std::cout << "row " << row << "\n";
    } 
  }
  }

  // loop on cols
  for (int col = 0; col<=2; col++) {
    winner = true;
    // loop on rows
    for (int row = 3; row<=6; row = row + 3) {
      //check if winner
      if ( (board[row + col] == ' ') || (board[row + col] != board[row + col - 3]) ) {
        winner = false;
      } 
    }
    }

    // loop on diagonals 0-4-8, 2-4-6
    winner = false;
    if ( (board[0] != ' ') && (board[0] == board[4]) && (board[4] == board[8]) ) {
      winner = true;
    } else if ( (board[2] != ' ')  && (board[2] == board[4]) && (board[4] == board[6]) ) {
      winner = true;
    }
  
  return winner;
}


void change_player() {
  if (player == 1) {
    player = 2;
    mark = '0';
  } else {
    player = 1;
    mark = 'X';
  }
  std::cout << "\nPlayer " << player << " turn\n";
}


void set_position_and_update_board() {
  int position;
  int forbidden_position = true;
  while (forbidden_position == true) {
    std::cout << "Choose the cell where to place " << mark << ":\n";
    std::cin >> position;
    if (board[position - 1] == ' ') {
      board[position - 1] = mark;
      forbidden_position = false;
    } else {
      std::cout << "Invalid position, choose a new one\n";
    }
  }
}

void take_turn() {
  bool won = false;
  std::cout << "\nStart taking turns!\n";
  while (won == false && number_turn <=9) {
    change_player();
    set_position_and_update_board();
    draw();
    won = is_winner();
    number_turn++;
 }
}

void end_game() {
  bool won = is_winner();
  if (won == true) {
    std::cout << "The winner is player\n" << player;
  } else {
    std::cout << "The match ended in tie\n";
  }
  
}

