#include <iostream>
#include "GameState.h"
#include "artificalIntel.h"

using namespace std;

void printResult(GameState& state) {
    std::cout << state;
    if (state.hasWon(0)) {
        std::cout << "Player 1 wins!\n";
    } 
    else if (state.hasWon(1)) {
        std::cout << "Player 2 wins!\n";
    } 
    else {
        std::cout << "It's a draw!\n";
    }
}

int main() {
    system("clear");

    cout << "[h] for Human, [m] for AI" << endl;
    cout << "Select player 1: ";
    char player1;
    char intelligence1;
    cin >> player1;

    if(player1 == 'm'){
        cout << "[s] for Simple AI, [i] for Intelligent AI: ";
        cin >> intelligence1;
    }

    cout << "[h] for Human, [m] for AI" << endl;
    cout << "Select player 2: ";
    char player2;
    char intelligence2;
    cin >> player2;

    if(player2 == 'm'){
        cout << "[s] for Simple AI, [i] for Intelligent AI: ";
        cin >> intelligence2;
    }

    cout << "Select Board Size: ";
    int size;
    cin >> size;
    
    GameState game(size);

    while (!game.done) {
        int row, col;

        if(player1 == 'h' && player2 == 'h'){
            cout << game << endl;
            cout << (!game.currentTurn ? "Player 1's Turn: " : "Player 2's Turn: ");
            cin >> row >> col;

            if (row < 0 || row >= game.size || col < 0 || col >= game.size) {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            if (!game.play(row, col)) {
                cout << "That cell is already occupied. Try again.\n";
                continue;
            }
            
        }

        if(player1 == 'h' && player2 == 'm'){
            if(intelligence2 == 's'){
                cout << game << endl;
                if(game.currentTurn){
                    Vec move = validMove(game);
                    row = move.x;
                    col = move.y;
                }
                else{
                    cout << endl;
                    cout << (!game.currentTurn ? "Player 1's Turn" : "Player 2's Turn") << ": ";
                    cin >> row >> col;
                    if (row < 0 || row >= game.size || col < 0 || col >= game.size) {
                        cout << "Invalid move. Try again.\n";
                        continue;
                    }

                    if (!game.play(row, col)) {
                        cout << "That cell is already occupied. Try again.\n";
                        continue;
                    }
                }
                game.play(row, col);
            }
        }

        if(player1 == 'm' && player2 == 'h'){
            if(intelligence1 == 's'){
                cout << game << endl;
                if(game.currentTurn){
                    cout << endl;
                    cout << (!game.currentTurn ? "Player 1's Turn" : "Player 2's Turn") << ": ";
                    cin >> row >> col;
                    if (row < 0 || row >= game.size || col < 0 || col >= game.size) {
                        cout << "Invalid move. Try again.\n";
                        continue;
                    }

                    if (!game.play(row, col)) {
                        cout << "That cell is already occupied. Try again.\n";
                        continue;
                    }
                }
                else{
                    Vec move = validMove(game);
                    row = move.x;
                    col = move.y;
                }
                game.play(row, col);
            }
        }

        if(player1 == 'h' && player2 == 'm'){
            if(intelligence2 == 'i'){
                cout << game << endl;
                if(game.currentTurn){
                    Vec move = findBestMove(game, game.currentTurn);
                    row = move.x;
                    col = move.y;
                }
                else{
                    cout << endl;
                    cout << (!game.currentTurn ? "Player 1's Turn" : "Player 2's Turn") << ": ";
                    cin >> row >> col;
                    if (row < 0 || row >= game.size || col < 0 || col >= game.size) {
                        cout << "Invalid move. Try again.\n";
                        continue;
                    }

                    if (!game.play(row, col)) {
                        cout << "That cell is already occupied. Try again.\n";
                        continue;
                    }
                }
                game.play(row, col);
            }
        }
        
        if(player1 == 'm' && player2 == 'h'){
            if(intelligence1 == 'i'){
                cout << game << endl;
                if(game.currentTurn){
                    cout << endl;
                    cout << (!game.currentTurn ? "Player 1's Turn" : "Player 2's Turn") << ": ";
                    cin >> row >> col;
                    if (row < 0 || row >= game.size || col < 0 || col >= game.size) {
                        cout << "Invalid move. Try again.\n";
                        continue;
                    }

                    if (!game.play(row, col)) {
                        cout << "That cell is already occupied. Try again.\n";
                        continue;
                    }
                }
                else{
                    Vec move = findBestMove(game, game.currentTurn);
                    row = move.x;
                    col = move.y;
                }
                game.play(row, col);
            }
        }
    }

    printResult(game);

    return 0;
}