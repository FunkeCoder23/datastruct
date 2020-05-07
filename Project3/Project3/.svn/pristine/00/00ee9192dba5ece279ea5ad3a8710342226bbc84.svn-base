//
//  avlMenu.cpp
//  Project
//
//  Created by Noah Krill on 3/2/20.
//  Copyright © 2020 Noah Krill. All rights reserved.
//

#include <iostream>
#include "avltree.h"
void menu(int &);
void validate(int &);
void insertNode();
int main()
{
    int choice=0;
    
    AvlTree<int>tr;
    while (choice!=9)
    {
    menu(choice);
    if (choice==1)
    {
        int numberChoice;
        std::cout << "What number would you like to enter into the tree ";
        std::cin >> numberChoice;
        tr.insert(numberChoice);
    }
    else if (choice==2)
    {
        int numberChoice;
        std::cout << "What number would you like to remove from the tree ";
        std::cin >> numberChoice;
        tr.remove(numberChoice);
    }
    else if(choice==3)
    {
        tr.printLevelOrder();
    }
    else if (choice==4)
    {
        tr.printTree();
    }
    else if (choice == 5)
    {
        tr.outputRange();
    }
    else if (choice==6)
    {
        tr.numNodes();
    }
    else if (choice ==7)
    {
        tr.numLeaves();
    }
    else if (choice==8)
    {
        tr.numFull();
    }
    }
    return 0;
}


void menu(int &choice)
{
    std::cout << " ---------------------------------------"<<std::endl;
    std::cout << "|           Noah Krill                  |" <<std::endl;
    std::cout << "|           AVL Menu                    |" <<std::endl;
    std::cout << " ---------------------------------------"<<std::endl;
    std::cout << "|      1. Insert Int                    |" << std::endl;
    std::cout << "|      2. Remove Int                    |"<< std::endl;
    std::cout << "|      3. Print Level Order             |"<< std::endl;
    std::cout << "|      4. Print Sorted Order            |" << std::endl;
    std::cout << "|      5. Output Range                  |" << std::endl;
    std::cout << "|      6. Output Number of Nodes        |" << std::endl;
    std::cout << "|      7. Output Number of Leaves       |" << std::endl;
    std::cout << "|      8. Output Number of Full Nodes   | " << std::endl;
    std::cout << "|      9. Exit                          |" << std::endl;
    std::cout << " --------------------------------------- "<<std::endl;
    std::cin >> choice;
    validate(choice);
  
    
}
void validate(int & choice)
{
    bool isGood = false;
    while (!isGood)
    {
        if (std::cin.fail() || choice < 1 || choice >10)
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please enter valid information ";
            std::cin >> choice;
        }
        else
        {
            isGood=true;
        }
    }
}
