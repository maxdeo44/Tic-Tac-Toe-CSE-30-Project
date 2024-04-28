#ifndef ARTIFICIAL_INTEL_H
#define ARTIFICIAL_INTEL_H

#include <iostream>
#include <ostream>
#include <fstream>
#include "GameState.h"
#include "Graph.h"
#include "Queue.h"

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
        int bestScore = 10000000;
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

int getReward(Vertex<GameState>* start, int player){
    if (start->neighbors.size() == 0){
        int currPlayer = start->data.currentTurn;
        if (start->data.hasWon(player)){
            return 100;
        }
        else if (start->data.hasWon(!player)){
            return -100;
        }
        else{
            return 50;
        }
    }
    else{
        int reward = getReward(start->neighbors[0]->location, player);
        for (int i = 1; i < start->neighbors.size(); i++){
            int curr = getReward(start->neighbors[i]->location, player);
            if (start->data.currentTurn == player){
                if (curr > reward){
                    reward = curr;
                }
            }
            else{
                if (curr < reward){
                    reward = curr;
                }
            }
        }
        return reward;
    }
}

Vec findBestMove(GameState game) {
    int depth = 0;
    Graph<GameState> stateSpace;
    Vertex<GameState>* start = new Vertex<GameState>(game);

    stateSpace.addVertex(start);

    Queue<Vertex<GameState>*> frontier;
    frontier.enqueue(start);

    int bestValue = -1000000000;
    int x = -1, y = -1;

    while (!frontier.isEmpty()) {
        Vertex<GameState>* curr = frontier.dequeue();
        if (!curr->data.done) {
            for (int i = 0; i < game.size; i++) {
                for (int j = 0; j < game.size; j++) {
                    if (curr->data.grid[i][j] == -1) {
                        GameState next = curr->data;
                        next.play(i, j);
                        Vertex<GameState>* successor = new Vertex<GameState>(next);
                        stateSpace.addVertex(successor);
                        stateSpace.addDirectedEdge(curr, successor);
                        int value = getReward(successor, 0); 
                        if (!successor->data.done) {
                            frontier.enqueue(successor);
                        }
                    }
                }
            }
        }
    }
    bestValue = -1000000000; 
    int player = game.currentTurn;
    for(int i = 0; i < start->neighbors.size(); i++) {
        
        int value = getReward(start->neighbors[i]->location, player);
        if(value > bestValue) {
            bestValue = value;
            x = start->neighbors[i]->location->data.lastMove.x;
            y = start->neighbors[i]->location->data.lastMove.y;
        }            
    }
    return Vec(x, y);
}

#endif