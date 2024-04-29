#include <iostream>
#include <stdlib.h>
#include "GameState.h"
#include "artificalIntel.h"
#include "menus.h"

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

int thegame(){
    int choice1;
    int choice2;
    int choice3;
    int size;
    char player1,player2,intelligence2;

    MainMenu();

    while (std::cin >> choice1){
        // erorr control
        if (choice1 < 1  ,choice1 > 2){
            error();
            cin >> choice1;
        }


        if (choice1 == 1){
            Players();
            // second menu 
            std::cin >> choice2;

            // error control
            if (choice2 < 1  ,choice2 > 3){
                error();
                cin >> choice2;
            }

            if (choice2 == 1){
                player1 = 'h';
                player2 = 'h';
            }
            else if (choice2 == 2 || choice2 == 3){
                Difficulty();
                // third menu
                std::cin >> choice3;

                // error control
                if (choice3 < 1 || choice3 > 3){
                    error();
                    cin >> choice3;
                }

            // Difficulty Functions
                if (choice3 == 1){
                    player1 = 'h';
                    player2 = 'm';
                    intelligence2 = 's';
                }
                else if (choice3 == 2){
                    player1 = 'h';
                    player2 = 'm';
                    intelligence2 = 'i';
                }
            }

        }
        else if (choice1 == 2){
            // end menus
            exit(0);
            return 0;
        }
        std::cout << "How big do you want the game to be? ";
        if (intelligence2 == 'i'){
            size = 3;
        } else{
            std::cin >> size;
        }
        break;
    }
    
    GameState game(size);
    system("cls");

    while (!game.done) {
        int row, col;

        if(player1 == 'h' && player2 == 'h'){
            cout << game << endl;
            cout << (!game.currentTurn ? "Player 1's Turn: " : "Player 2's Turn: ");
            std::cin >> row >> col;

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
                    std::cin >> row >> col;
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

        if(player1 == 'h' && player2 == 'm'){
            if(intelligence2 == 'i'){
                cout << game << endl;
                if(game.currentTurn){
                    Vec move = findBestMove(game);
                    row = move.x;
                    col = move.y;
                }
                else{
                    cout << endl;
                    cout << (!game.currentTurn ? "Player 1's Turn" : "Player 2's Turn") << ": ";
                    std::cin >> row >> col;
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
    }

    printResult(game);
    string text;
    std::cout << "Do you want to play again? ";
    std::cin >> text;
    if (toupper(text[0]) == 'Y'){
        thegame();
    }
    return 0;
    }

int main() {
    thegame();
    return 0;
}