//Main
#include <string>
#include <vector>
#include <iostream>
#include "Maze_BST.h"

using namespace std;

int main()
{
    int menu = 0;
    int wrong_ans = 0;
    int level_input = 0;
    bool diff_level, input = false;
    
    
    BST::Maze game_maze(); 
    
    
    
    
    Cout<<"-----------------------Game of Maze-------------------------";
    while(!diff_level)
    {   
        cout<<"Select one option: ";
        cout<<"1. Play "<<endl;
        cout<<"2. Instructions "<<endl;
        cout<<"3. Quit "<<endl;
        cin>>menu;
        if(menu == 1)
        {
            while(!input)
            {
                cout << "Choose Difficulty: "<<endl;
                cout << "1. Easy"<<endl;
                cout << "2. Medium"<<endl;
                cout << "3. Hard"<<endl;
                cin>>level_input;
                
                if(level_input == 1)
                {
                    input = true;
                }
                else if(level_input == 2)
                {
                    input = true;
                }
                else if(level_input == 3)
                {
                    input = true;
                }
                else
                {
                    cout << "Please enter an acceptable input (1,2 or 3)." << endl;
                }
                
            }
            diff_level = true; 
        }
        else if(menu == 2)
        {
            diff_level = true;
            cout << "This is a BST maze, each room has a different challenge. There are three types of rooms: Trivia, Puzzle and Battle\n"
                 << "Win the challenge and you can advance to the node to your right, lose a challenge and you advance to your left.\n"
                 << "If you move to the left twice in a row, you lost and you are prompted with the choice of either trying again or quitting.\n"
                 << "Player wins when he wins the challenge at the last level.\n";
                 << "Trivia:\n"
                 << "Answer a trivia question from any possible subject.\n"
                 << "Puzzle:\n"
                 << "Solve a brain teaser to pass.\n"
                 << "Battle:\n"
                 << "10 questions need to be answered on a set time interval.\nAnswer at least 5 questions correctly to pass.\n";                     
        }
        else if(menu == 3)
        {
            break;
            
        }
        else
        {
            cout << "Please enter an acceptable input (1,2 or 3)." << endl;
        }
    }
    
    
    
    
    
    return 0;
}

