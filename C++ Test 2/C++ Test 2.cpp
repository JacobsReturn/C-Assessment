// C++ Test 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Table.h"
#include "Players.h"

#include "Commands.h"
#include "Add.h"
#include "View.h"
#include "Remove.h"
#include "Save.h"
#include "Load.h"
#include "Search.h"

#include "C++ Test 2.h"

const int size = 5;
Commands* commands[size] = { new View(1), new Add(2), new Remove(3), new Save(4), new Search(5) };
Table* scoreboard = new Table();

// Grabbing commands.
int GetByCommand(int command) 
{
    int index = 0;

    for (int i = 0; i < size; i++)
    {
        if (commands[i]->command == command) {
            index = i;
            
            break;
        }
    }

    return index;
}

int main()
{
    scoreboard->LoadFile();
    std::cout << "Player Database" << std::endl << "Commands (type out the number):" << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << commands[i]->command << ": " << commands[i]->name << std::endl;
    }

    while (true)
    {
        //char input = (char)std::cin.get();
        int n;
        std::cin >> n;

        if (!std::cin || n > size) // or if(cin.fail())
        {
            // user didn't input a number
            std::cin.clear(); // reset failbit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            // next, request user reinput

            continue;
        }
        
        system("cls");

        commands[GetByCommand(n)]->Run(scoreboard);

        std::cout << std::endl << "Player Database" << std::endl << "Commands (type out the number):" << std::endl;

        for (int i = 0; i < size; i++)
        {
            std::cout << commands[i]->command << ": " << commands[i]->name << std::endl;
        }
    }

    delete[] commands;

    scoreboard->Remove();
    delete scoreboard;
}