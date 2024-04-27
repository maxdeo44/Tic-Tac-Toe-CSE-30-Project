#ifndef ARTIFICIAL_INTEL_H
#define ARTIFICIAL_INTEL_H

#include <iostream>
#include <vector>
#include "gamestate.h"

Vec validMove(GameState game){
    for(int i = 0; i < game.size; i++){
        for(int j = 0; j < game.size; j++){
            if(game.grid[i][j] == -1){
                return Vec(i,j);
            }
        }
    }
    return Vec(0,0);
}

int minimax(GameState& state, int depth, bool currentTurn){
    int won = 1;
    int loss = -1;
    int tie = 0;
    int scores[3] = {loss, tie, won};
    int result = state.hasWon();

    if(result != -1){
        int score = scores[result];
        return score;
    }
    if(!currentTurn){
        int bestScore = -1000;
        for(int i = 0; i < state.size; i++){
            for(int j = 0; j < state.size; j++){
                if(state.grid[i][j] == -1){
                    state.play(i, j);
                    int score = minimax(state, depth + 1, false);
                    state.grid[i][j] = -1;
                    if(score > bestScore){
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
    else{
        int bestScore = 1000;
        for(int i = 0; i < state.size; i++){
            for(int j = 0; j < state.size; j++){
                if(state.grid[i][j] == -1){
                    state.play(i, j);
                    int score = minimax(state, depth + 1, true);
                    state.grid[i][j] = -1;
                    if(score < bestScore){
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}

Vec findBestMove(GameState state, bool currentTurn){
    int bestScore = -1000;
    int temp_row = -1, temp_col = -1;
    for(int i = 0; i < state.size; i++){
        for(int j = 0; j < state.size; j++){
            if(state.grid[i][j] == -1){
                state.play(i, j);
                int score = minimax(state, 0, currentTurn);
                state.grid[i][j] = -1;
                if(score > bestScore){
                    bestScore = score;
                    temp_row = i;
                    temp_col = j;
                }
            }
        }
    }
    if (temp_row != -1 && temp_col != -1)
        return Vec(temp_row, temp_col);
    
    return Vec(0, 0);
}

#endif