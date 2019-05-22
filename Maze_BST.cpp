//Implementation of the maze class
#include <iostream>
#include <vector>
#include <stdl>
#include <chrono>
#include <string>
#include <algorithm>
#include "Maze_BST.h"

using namespace std;

BST::Maze build_maze(int difficulty, vector<vector<std:string>> challenge_set, int i, node *root){
   /* This functions will not only build the BST which will be used as the maze
      (Easy = Depth of 3, 7 nodes; Medium = Depth of 4, 15 nodes; Hard = Depth of 5, 31 nodes)
      , but also populate each node (randomly) with one of the unique challenge.
      Then trasverse through it and play the game. Win makes you go right, lose makes you go left.
      Go left twice and you loose the game.
      We based our function on a function to insert nodes in level order found at:
      https://www.geeksforgeeks.org/construct-complete-binary-tree-given-array/
   */
	if (i < difficulty) 
	{ 
	node *temp(i);
	temp.set_challenge(challenge_set.at(i));	
	root = temp; 

	// insert left child 
	root->left = build_maze(difficulty,challenge_set, 2 * i + 1,root->left()); 

	// insert right child 
	root->right = build_maze(difficulty, challenge_set(), 2 * i + 2, root->right()); 
	} 
	return root; 		 
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
    
    int score = 0, time_elapsed;
    string player_answer, correct_answer;   
    vector<string> challenge;
    challenge = ptr.challenge():
    
    
    cout << "This is a " << challenge.at(0) << " challenge." <<endl;
    cout << "Answer 3 out of 5 questions correctly in 50 seconds or less to win." <<endl<<endl;
    
    auto start = high_resolution_clock::now();
    
    cout << challenge.at(1) <<endl;
    cout << "Answer: ";
    cin >> player_answer;
    correct_answer = challenge.at(2);
    
    transform(correct_answer.begin(), correct_answer.end(), correct_answer.begin(), ::tolower);
    transform(player_answer.begin(), player_answer.end(), player_answer.begin(), ::tolower);
    
    if(correct_answer == player_answer)(
        score++;
    )
    auto end1 = high_resolution_clock::now();
	auto duration1 = duration_cast<milliseconds>(end1-start);
    time_elapsed = int(duration1.count());
    if(time_elapsed => 50000){
        cout << "Ran out of time."<<endl;
        return False;
    }
    
    
    cout << challenge.at(3) <<endl;
    cout << "Answer: ";
    cin >> player_answer;
    correct_answer = challenge.at(4);
    
    transform(correct_answer.begin(), correct_answer.end(), correct_answer.begin(), ::tolower);
    transform(player_answer.begin(), player_answer.end(), player_answer.begin(), ::tolower);
    
    if(correct_answer == player_answer)(
        score++;
    )
    auto end2 = high_resolution_clock::now();
	auto duration2 = duration_cast<milliseconds>(end2-start);
    time_elapsed = int(duration2.count());
    if(time_elapsed => 50000){
        cout << "Ran out of time."<<endl;
        return False;
    }
    

    cout << challenge.at(5) <<endl;
    cout << "Answer: ";
    cin >> player_answer;
    correct_answer = challenge.at(6);
    
    transform(correct_answer.begin(), correct_answer.end(), correct_answer.begin(), ::tolower);
    transform(player_answer.begin(), player_answer.end(), player_answer.begin(), ::tolower);
    
    if(correct_answer == player_answer)(
        score++;
    )
    auto end3 = high_resolution_clock::now();
	auto duration3 = duration_cast<milliseconds>(end3-start);
    time_elapsed = int(duration3.count());
    if(time_elapsed => 50000){
        cout << "Ran out of time."<<endl;
        return False;
    }    
    
    cout << challenge.at(7) <<endl;
    cout << "Answer: ";
    cin >> player_answer;
    correct_answer = challenge.at(8);
    
    transform(correct_answer.begin(), correct_answer.end(), correct_answer.begin(), ::tolower);
    transform(player_answer.begin(), player_answer.end(), player_answer.begin(), ::tolower);
    
    if(correct_answer == player_answer)(
        score++;
    )
    auto end4 = high_resolution_clock::now();
	auto duration4 = duration_cast<milliseconds>(end4-start);
    time_elapsed = int(duration4.count());
    if(time_elapsed => 50000){
        cout << "Ran out of time."<<endl;
        return False;
    }
    

    cout << challenge.at(9) <<endl;
    cout << "Answer: ";
    cin >> player_answer;
    correct_answer = challenge.at(10);
    
    transform(correct_answer.begin(), correct_answer.end(), correct_answer.begin(), ::tolower);
    transform(player_answer.begin(), player_answer.end(), player_answer.begin(), ::tolower);
    
    if(correct_answer == player_answer)(
        score++;
    )
    auto end5 = high_resolution_clock::now();
	auto duration5 = duration_cast<milliseconds>(end5-start);
    time_elapsed = int(duration5.count());
    if(time_elapsed => 50000){
        cout << "Ran out of time."<<endl;
        return False;
    }    
    
    if(score => 3){
        cout << "Congrats! You answered " << score << " questions correctly inside the time interval!" << endl;
        return True;
    }else{
        cout << "Gosh darn it, you only answered "<< score << " out of 5 questions correctly. Better luck next time!" << endl;
        return False;
    }
}

bool play_game(Maze game_board, node *current){
	
	vector<string> challenge;
	challenge = current.challenge();
	bool passed = false;
	
	if(challenge.at(0) == "Battle"){
		passed = node_battle(current);
		if(passed){
			if(current->right() != NULL){
				game_board.set_left_counter(0);
				play_game(game_board,current->right());
			}else{
				return True;
			}
		}else{
			game_board.set_left_counter(game_board.left_counter() + 1);
			if(game_board.left_counter() == 2){
				return False;
			}else{
				play_game(game_board,current->left());
			}
		}
	}else{
		passed = node_play(current);
		if(passed){
			if(current->right() != NULL){
				game_board.set_left_counter(0);
				play_game(game_board,current->right());
			}else{
				return True;
			}
		}else{
			game_board.set_left_counter(game_board.left_counter() + 1);
			if(game_board.left_counter() == 2){
				return False;
			}else{
				play_game(game_board,current->left());
			}
		}
	}

}


void operator=(const Maze& b){
 	this->set_root(b.root());
	this->set_level(b.level());
}
