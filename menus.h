#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <stdexcept>
#include <stdlib.h>


void MainMenu(){
    system("cls");

    std::cout << std::endl
    << "=================\n"
    << "   TIC TAC TOE\n"
    << "=================\n";
    std::cout << std::endl;

    std::cout 
    << "1. Play Tic Tac Toe\n"
    << "2. Exit" 
    << std::endl;
}

void Players(){
    system("cls");

    std::cout << std::endl
    << "=================\n"
    << "     PLAYERS\n"
    << "=================\n";
    std::cout << std::endl;

    std::cout
    << "1. Human vs Human\n"
    << "2. Human vs Computer\n"
    << std::endl;
}

void Difficulty(){
    system("cls");

    std::cout << std::endl
    << "=================\n"
    << "    DIFFICULTY\n"
    << "=================\n";
    std::cout << std::endl;

    std::cout
    << "1. Easy\n"
    << "2. Impossible\n"
    << std::endl;
}

void error(){
    std::cout << "Not an Option" << std::endl;
}


#endif