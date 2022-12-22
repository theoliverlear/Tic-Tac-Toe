#include <iostream>
#include <vector>

void introduction() {
    std::cout << "Welcome to the tic-tac-toe game!\n";
}

void reset_board(std::vector<std::vector<int>> board) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0;j < board[i].size(); j++) {
            board[i][j] = 0;
        }
    }
}
int determine_winner(std::vector<std::vector<int>> board) {
    if(board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1) {
        return 1;
    }
    else if(board[1][0] == 1 && board[1][1] == 1 && board[2][1] == 1) {
        return 1;
    }
    else if(board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1) {
        return 1;
    }
    else if(board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1) {
        return 1;
    }
    else if(board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1) {
        return 1;
    }
    else if(board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1) {
        return 1;
    }
    else if(board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
        return 1;
    }
    else if(board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) {
        return 1;
    }

    else if(board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 2) {
        return 2;
    }
    else if(board[1][0] == 2 && board[1][1] == 2 && board[2][1] == 2) {
        return 2;
    }
    else if(board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 2) {
        return 2;
    }
    else if(board[0][0] == 2 && board[1][0] == 2 && board[2][0] == 2) {
        return 2;
    }
    else if(board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 2) {
        return 2;
    }
    else if(board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 2) {
        return 2;
    }
    else if(board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) {
        return 2;
    }
    else if(board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2) {
        return 2;
    } else {
        return 0;
    }
}

bool is_winner(std::vector<std::vector<int>> board) {
    if(determine_winner(board) == 0) {
        return false;
    } else {
        return true;
    }
}

void declare_winner(std::vector<std::vector<int>> board) {
    int winner = determine_winner(board);
    if(winner == 1) {
        std::cout << "Congratulations to player " << winner <<"! You won!\n";
    } else if(winner == 2) {
        std::cout << "Congratulations to player " << winner <<"! You won!\n";
    }
}

bool is_taken(std::vector<std::vector<int>> board, int row, int column) {
    if(board[row][column] == 1 || board[row][column] == 2) {
        std::cout << "That spot is taken. Please choose another.\n";
            return true;
            } else {
                return false;
            }
}

bool is_filled_up(std::vector<std::vector<int>> board) {
    std::vector<std::vector<bool>> is_filled_board = {{false, false, false},
                                                      {false, false, false},
                                                      {false, false, false}};
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0;j < board[i].size(); j++) {
            if(board[i][j] == 1 || board[i][j] == 2) {
                is_filled_board[i][j] = true;
            } else {
                is_filled_board[i][j] = false;
            }
        }
    }
    for(int i = 0; i < is_filled_board.size(); i++) {
        for(int j = 0;j < is_filled_board[i].size(); j++) {
            if(is_filled_board[i][j] == false) {
                return false;
            }
        }
    }
    return true;
}
void end_game(std::vector<std::vector<int>> board) {
    declare_winner(board);
    std::cout << "Thank you for playing the tic-tac-toe game.\n";

}
bool is_draw(std::vector<std::vector<int>> board) {
    if(is_filled_up(board)) {
        return true;
    } else {
        return false;
    }
}
void declare_draw(std::vector<std::vector<int>> board) {
    std::cout << "Draw! There is no winner.\n";
}
void print_board(std::vector<std::vector<int>> board) {
    std::cout << " " << board[0][0] <<" | " << board[0][1] <<" | " << board[0][2] << " \n";
    std::cout << "-----------\n";
    std::cout << " " << board[1][0] <<" | " << board[1][1] <<" | " << board[1][2] << " \n";
    std::cout << "-----------\n";
    std::cout << " " << board[2][0] <<" | " << board[2][1] <<" | " << board[2][2] << " \n";
}

void take_turn(std::vector<std::vector<int>> board) {
    int row = 0;
    int column = 0;
    while(is_winner(board) == false){
        std::cout << "Player #1's turn.\n";
        std::cout << "Choose row:\n";
        std::cin >> row;
        std::cout << "Choose column:\n";
        std::cin >> column;
        while (is_taken(board, row, column) == true) {
            std::cout << "Choose row:\n";
            std::cin >> row;
            std::cout << "Choose column:\n";
            std::cin >> column;
        }
        board[row][column] = 1;
        std::cout << "Thank you.\n";
        print_board(board);
        if (is_winner(board)) {
            end_game(board);
            break;
        } else if(is_draw(board)) {
            declare_draw(board);
            end_game(board);
            break;
        }
        is_draw(board);
        std::cout << "Player #2's turn.\n";
        std::cout << "Choose row:\n";
        std::cin >> row;
        std::cout << "Choose column:\n";
        std::cin >> column;
        while (is_taken(board, row, column) == true) {
            std::cout << "Choose row:\n";
            std::cin >> row;
            std::cout << "Choose column:\n";
            std::cin >> column;
        }
        board[row][column] = 2;
        std::cout << "Thank you.\n";
        print_board(board);
        if (is_winner(board)) {
            end_game(board);
            break;
        }
        else if(is_draw(board)) {
            declare_draw(board);
            end_game(board);
            break;
        }

    }

}
void start_game(std::vector<std::vector<int>> board) {
    introduction();
    reset_board(board);
    print_board(board);
    take_turn(board);
}
int main() {
    std::vector<std::vector<int>> board = {{0, 0, 0},
                                           {0, 0, 0},
                                           {0, 0, 0}};
    start_game(board);
}