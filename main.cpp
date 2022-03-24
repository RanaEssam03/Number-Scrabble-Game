// Assignment_1 
// Rana Essam Ibrahim
// ID : 20210133
// Game_3 : Number_Scrabble

#include <iostream>
#include <vector>
using namespace std;

//to create the game board as an array
void game_board(int board[10]){
    for (int i = 0 ; i <9 ; i ++)
    cout << " " <<board[i]  ;
    cout << "\n";
}
// to check the draw case
bool is_draw(int board[10]) {
    for (int i = 0; i < 10; i++) {
        if (board[i] != 0) {
            return false;
        }
    }
    return true;
}

bool is_winner(vector <int> player) {
    for (int i = 0; i < player.size() - 2 ;  ++i) {

        for (int j = i + 1 ; j < player.size() - 1; ++j) {
            for (int k = j + 1 ; k < player.size(); ++k) {
                if (player[i] + player[j] + player[k] == 15) {
                    return true;
                }
            }
        }
    }
    return false;
}
// to update the board state cope with the players' inputs
void update_state(int board[10], int index){
    board[index] = 0;
}

bool check_valid(int index,int board[10]){
    if (board[index] == 0){
        return false;
    }
    else
        return true;
}

int main() {
    vector <int> player1 , player2 ; //to put in them the choosen nums of each player and check them

    int board[10] ={1, 2, 3, 4, 5, 6, 7, 8, 9};
   //start the game
    while (true){
     
            //player1
            game_board(board);
            cout << "Please, choose a number (player1): " << endl ;
            int x;
            cin >> x;
            bool y = check_valid(x-1, board);

            if (y == false){
                cout << "invalid input  !!!! ";
                game_board(board);      
                cout << "please try again: .......";
                cin >> x;
                y = check_valid(x-1, board);
            }

            player1.push_back(x);

            // to make the program check at least 3 num
            if (player1.size() >= 3) {
                if (is_winner(player1) == true) {
                    cout << "The winner is player 1";
                    break;
                }   
            }

            update_state(board, x-1);
            if (is_draw(board) == true) {
                cout << "Draw game ";
                break;
            }

             // player2
            game_board(board);
            cout << "Please, choose a number (player2): " << endl ;

            cin >> x;
             y = check_valid(x-1, board);

            if (y == false){
                cout << "invalid input  !!!! ";
                game_board(board);
                cout << "please try again: .......";
                cin >> x;
                y = check_valid(x-1, board);
            }

            player2.push_back(x);

            // to make the program check at least 3 num
            if (player2.size() >= 3) {
                if (is_winner(player2) == true) {
                    cout << "The winner is player 2";
                    break;
                }              
            }
            update_state(board, x-1);

            if (is_draw(board) == true) {
                cout << "Draw game ";
                break;
            }
     }
    return 0;
}
