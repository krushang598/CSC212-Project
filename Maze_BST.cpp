//Implementation of the maze class
#include <iostream>
#include <vector>
#include <stdl>
#include <string>
#include <algorithm>
#include "Maze_BST.h"

using namespace std;

Maze create_game(int difficulty, vector<vector<std:string>> every_challenge){
    
}
bool node_play(node *ptr){
    string player_answer, correct_answer;
    vector<string> challenge;
    challenge = ptr.challenge();
    correct_answer = challenge.at(2);
    
    cout << "This is a " << challenge.at(0) << " challenge." <<endl<<endl;
    cout << challenge.at(1) <<endl;
    cout << "Answer: ";
    cin >> player_answer;
    
    transform(correct_answer.begin(), correct_answer.end(), correct_answer.begin(), ::tolower);
    transform(player_answer.begin(), player_answer.end(), player_answer.begin(), ::tolower);
    
    if(player_answer == correct_answer){return True;}
    else{return False;}
    
    
}

bool node_battle(node *ptr){
}
bool play_game(Maze game_board){
}




vector<vector<string>> create_challenge_set(){
    /*
    The challenge set is composed of a vector of vectors of strings.
    Each vector of strings is composed, respectively, of:
    1st.Its type (battle,trivia,puzzle)
    2nd.The challenge
    3rd.The answer     
    There will be 31 challenges max, which will be max number 
    of nescessary challenges for a BST of depth 4
    */

    vector<vector<string>> full_set;
    vector<string> single_challenge;
    
    /*Trivia set (11 problems)*/
    vector<string> trivia_q;
    vector<string> trivia_a;
    //1
    trivia_q.push_back("What is the world’s most widely spoken native tongue language?");
    trivia_a.push_back("Mandarim");
    //2
    trivia_q.push_back("The atomic number of an element indicate the number of _______ in it");
    trivia_a.push_back("Protons");
    //3
    trivia_q.push_back("The term ‘Pulmonary’ relates to which organ?");
    trivia_a.push_back("Lungs");
    //4
    trivia_q.push_back("Which country is the world’s biggest producer of coffee?");
    trivia_a.push_back("Brazil");
    //5
    trivia_q.push_back("What is the study of Fossils?");
    trivia_a.push_back("Palaeontology");    
    //6
    trivia_q.push_back("The South American city of Brazillia is built in the shape of what?");
    trivia_a.push_back("Airplane");    
    //7
    trivia_q.push_back("Who was the Greek god of war?");
    trivia_a.push_back("Ares");    
    //8
    trivia_q.push_back("Who was the Roman god of war?");
    trivia_a.push_back("Mars");
    //9
    trivia_q.push_back("A Binary Tree in which every node other than the leaves has two children is called _____");
    trivia_a.push_back("Full");    
    //10
    trivia_q.push_back("A Binary Tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible is called ________");
    trivia_a.push_back("Complete");    
    //11
    trivia_q.push_back("What is the S.I unit of capacitance");
    trivia_a.push_back("Farad");

  
    
    for(int i = 0; i < 11; i++){
    
        single_challenge.push_back("Trivia");
        single_challenge.push_back(trivia_q.at(i));
        single_challenge.push_back(trivia_a.at(i));
        full_set.push_back(single_challenge);
        single_challenge.erase(single_challenge.begin(),single_challenge.end());        
    }
    
    
    /*Puzzles Set (10 problems)*/
    
    vector<string> puzzle_q;
    vector<string> puzzle_a;
    
    //12
    puzzle_q.push_back("It is flat as a leaf, round as a ring, Has two eyes, yet cannot see a thing. What is it ? ");
    puzzle_a.push_back("Button");
    //13
    puzzle_q.push_back("What is 3/7 chicken, 2/3 cat, and a half goat?");
    puzzle_a.push_back("Chicago");
    //14
    puzzle_q.push_back("Which seven-letter word contains dozens of letters? ");
    puzzle_a.push_back("Mailbox");
    //15
    puzzle_q.push_back("I have six faces and twenty-one eyes, yet I can not see. What am I ? ");
    puzzle_a.push_back("Dice");
    //16
    puzzle_q.push_back("What is orange and sounds like a parrot? ");
    puzzle_a.push_back("Carrot");
    //17
    puzzle_q.push_back("You use a knife to slice my head, And weep beside me when I’m dead. What am I ?");
    puzzle_a.push_back("Onion");
    //18
    puzzle_q.push_back("You throw away the outside and cook the inside. Then you eat the outside and throw away the inside. What do you eat? ");
    puzzle_a.push_back("Corn");
    //19
    puzzle_q.push_back("What’s black when you get it, red when you use it, and white when you’re all through with it? ");
    puzzle_a.push_back("Charcoal");
    //20
    puzzle_q.push_back("What occurs once in every minute, twice in every moment, but never in a thousand years? ");
    puzzle_a.push_back("M");
    //21
    puzzle_q.push_back("What gets wetter as it dries ? ");
    puzzle_a.push_back("Towel");
    //22
    puzzle_q.push_back("When you have me, you want to share me. When you share me, you no longer have me.");
    puzzle_a.push_back("Secret");
    
    
    for(int j = 0; j < 10; j++){
        single_challenge.push_back("Puzzle");
        single_challenge.push_back(puzzle_q.at(i));
        single_challenge.push_back(puzzle_a.at(i));
        full_set.push_back(single_challenge);
        single_challenge.erase(single_challenge.begin(),single_challenge.end());
    }
    /*
    Battle Set (10 problems)
    
    vector<string> battle_q;
    vector<string> battle_a;
    
    //23
    battle_q.push_back("What’s black when you get it, red when you use it, and white when you’re all through with it? ");
    battle_a.push_back("Charcoal");
    //24
    battle_q.push_back("What’s black when you get it, red when you use it, and white when you’re all through with it? ");
    battle_a.push_back("Charcoal");
    //25
    battle_q.push_back("What’s black when you get it, red when you use it, and white when you’re all through with it? ");
    battle_a.push_back("Charcoal");
    //26
    battle_q.push_back("What’s black when you get it, red when you use it, and white when you’re all through with it? ");
    battle_a.push_back("Charcoal");
    //27
    battle_q.push_back("What’s black when you get it, red when you use it, and white when you’re all through with it? ");
    battle_a.push_back("Charcoal");
    //28
    battle_q.push_back("What’s black when you get it, red when you use it, and white when you’re all through with it? ");
    battle_a.push_back("Charcoal");
    //29
    battle_q.push_back("What’s black when you get it, red when you use it, and white when you’re all through with it? ");
    battle_a.push_back("Charcoal");
    //30
    battle_q.push_back("What’s black when you get it, red when you use it, and white when you’re all through with it? ");
    battle_a.push_back("Charcoal");
    //31
    battle_q.push_back("What’s black when you get it, red when you use it, and white when you’re all through with it? ");
    battle_a.push_back("Charcoal");
    //32
    battle_q.push_back("What’s black when you get it, red when you use it, and white when you’re all through with it? ");
    battle_a.push_back("Charcoal");
    */
    
    
    return full_set;
}
