//Main
#include <string>
#include <vector>
#include <iostream>
#include "Maze_BST.h"

vector<vector<string>> create_challenge_set();

using namespace std;

int main()
{
    int menu = 0;
    int wrong_ans = 0;
    int select = 0;
    bool diff_level, input = false;
    
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
                cout<<"Choose Difficulty: "<<endl;
                cout<<"1. Easy"<<emdl;
                cout<<"2. Medium"<<endl;
                cout<<"3. Hard"<<endl;
                cin>>select;
                
                if(select == 1)
                {
                    index = true;
                }
                else if(select = 2)
                {
                    index = true;
                }
                else if(select = 3)
                {
                    index = true;
                }
                else
                {
                    Please enter correct option:
                }
                
            }
            diff_level = true; 
        }
        else if(menu == 2)
        {
            diff_level = true;
        }
        else if(menu == 3)
        {
            diff_level = true;
        }
        else
        {
            cout<<"Please enter a valid input.";
        }
    }
    
    
    
    
    
    
}

