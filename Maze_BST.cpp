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
	vector<string> trivia_single_challenge;

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
		trivia_single_challenge.push_back("Trivia");
		trivia_single_challenge.push_back(trivia_q.at(i));
		trivia_single_challenge.push_back(trivia_a.at(i));
		full_set.push_back(trivia_single_challenge);
		trivia_single_challenge.erase(trivia_single_challenge.begin(),trivia_single_challenge.end());        
	}


	/*Puzzles Set (10 problems)*/

	vector<string> puzzle_q;
	vector<string> puzzle_a;
	vector<string> puzzle_single_challenge;

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


	for(int j = 0; j < 10; j++){
		puzzle_single_challenge.push_back("Puzzle");
		puzzle_single_challenge.push_back(puzzle_q.at(i));
		puzzle_single_challenge.push_back(puzzle_a.at(i));
		full_set.push_back(puzzle_single_challenge);
		puzzle_single_challenge.erase(puzzle_single_challenge.begin(),puzzle_single_challenge.end());
	}
	/*
	Battle Set (10 problems)
	The Battle rooms are different, 5 questions they have to answer in a set interval of time.
	*/

	vector<string> battle_q;
	vector<string> battle_a;
	vector<string> battle_single_challenge;

	`   //22.0
	battle_q.push_back("Is the domestic dog a carnivore, omnivore or herbivore?");
	battle_a.push_back("Omnivore");
	//22.1
	battle_q.push_back("What is a dog’s most powerful sense?");
	battle_a.push_back("Smell");
	//22.2
	battle_q.push_back("Because of dogs unique relationship with humans they are often referred to as man’s best________?");
	battle_a.push_back("Friend");
	//22.3
	battle_q.push_back("The tallest dog in the world stands over 150cm in height.(T/F)");
	battle_a.push_back("F");
	//22.4
	battle_q.push_back("What is the name of the phobia for someone who has a fear of dogs?");
	battle_a.push_back("Cynophobia");    
	//23.0
	battle_q.push_back("The two holes in your nose are called?");
	battle_a.push_back("Nostrils");
	//23.1
	battle_q.push_back("The bones around your chest that protect organs such as the heart are called what?");
	battle_a.push_back("Ribs");
	//23.2
	battle_q.push_back("The flow of blood through your heart and around your body is called?");
	battle_a.push_back("Circulation");
	//23.3
	battle_q.push_back("What is the name of the long pipe that shifts food from the back of your throat down to your stomach? ");
	battle_a.push_back("Esophagus");
	//23.4
	battle_q.push_back("The bones that make up your spine are called what?");
	battle_a.push_back("Vertebrae");
	//24.0
	battle_q.push_back("What is the first element on the periodic table?");
	battle_a.push_back("Hydrogen");
	//24.1
	battle_q.push_back("What is the centre of an atom called?");
	battle_a.push_back("Nucleus");
	//24.2
	battle_q.push_back(" Acids have a pH level below 7.(T/F)");
	battle_a.push_back("T");
	//24.3
	battle_q.push_back("Atoms of the same chemical element that have different atomic mass are known as?");
	battle_a.push_back("Isotopes");
	//24.4
	battle_q.push_back("At room temperature, what is the only metal that is in liquid form?");
	battle_a.push_back("Mercury");
	//25.0
	battle_q.push_back("How many horns did Triceratops have?(Enter a number)");
	battle_a.push_back("3");
	//25.1
	battle_q.push_back("The name dinosaur means ‘terrible lizard’.(T/F)");
	battle_a.push_back("T");
	//25.2
	battle_q.push_back("Birds evolved from dinosaurs.(T/F)");
	battle_a.push_back("T");
	//25.3
	battle_q.push_back("Dinosaur fossils have been found on every continent of Earth.(T/F)");
	battle_a.push_back("T");
	//25.4
	battle_q.push_back("What type of dinosaur features on the logo of the Toronto based NBA basketball team?");
	battle_a.push_back("Velociraptor");    
	//26.0
	battle_q.push_back("In what country is the Taj Mahal found?");
	battle_a.push_back("India");
	//26.1
	battle_q.push_back("Which country gave the Statue of Liberty to the USA as a gift?");
	battle_a.push_back("France");
	//26.2
	battle_q.push_back("The Great Sphinx of Giza has the head of a human and the body of a what?");
	battle_a.push_back("Lion");
	//26.3
	battle_q.push_back("Did the Eiffel Tower open in 1789 or 1889?");
	battle_a.push_back("1889");
	//26.4
	battle_q.push_back("What is the largest planet in the Solar System?");
	battle_a.push_back("Jupiter");	
	`   //27.0
	battle_q.push_back("A thermometer is a device used to measure what?");
	battle_a.push_back("Temperature");
	//27.1
	battle_q.push_back("Stratus, cirrus, cumulus and nimbus are types of what?");
	battle_a.push_back("Clouds");
	//27.2
	battle_q.push_back("What country experiences the most tornadoes?");
	battle_a.push_back("USA");
	//27.3
	battle_q.push_back("An avalanche features the rapid descent of _______?");
	battle_a.push_back("Snow");
	//27.4
	battle_q.push_back("Trying to predict the weather is known as weather _______?");
	battle_a.push_back("Forecasting");    
	//28.0
	battle_q.push_back("What’s 2+2*2^2?");
	battle_a.push_back("10");
	//28.1
	battle_q.push_back("What’s 4+6/2?");
	battle_a.push_back("7");
	//28.2
	battle_q.push_back("What’s (10^4)/(10^3)?");
	battle_a.push_back("10");
	//28.3
	battle_q.push_back("What’s e^(2^2-4)? ");
	battle_a.push_back("1");
	//28.4
	battle_q.push_back("What’s 8^(1/3)? ");
	battle_a.push_back("2");
	//29.0
	battle_q.push_back("A vector has both magnitude and ______? ");
	battle_a.push_back("Direction");
	//29.1
	battle_q.push_back("The orbits of the planets around the sun are circular?(T/F)");
	battle_a.push_back("F");
	//29.2
	battle_q.push_back("Electric resistance is typically measured in what units? ");
	battle_a.push_back("Ohms");
	//29.3
	battle_q.push_back("The wire inside an electric bulb is known as the what? ");
	battle_a.push_back("Filament");
	//29.4
	battle_q.push_back("What is the first name of the famous scientist who gave us Newton’s three laws of motion? ");
	battle_a.push_back("Isaac");
	//30.0
	battle_q.push_back(" Botany is the study of? ");
	battle_a.push_back("Plants");
	//30.1
	battle_q.push_back("The common cold is caused by a virus.(T/F)");
	battle_a.push_back("T");
	//30.2
	battle_q.push_back("A salamander is a warm blooded animal?(T/F)");
	battle_a.push_back("F");
	//30.3
	battle_q.push_back("A change of the DNA in an organism that results in a new trait is known as a?");
	battle_a.push_back("Mutation");
	//30.4
	battle_q.push_back("The death of every member of a particular species is known as what?");
	battle_a.push_back("Extinction");    
	//31.0
	battle_q.push_back(" Capital of Greece? ");
	battle_a.push_back("Athens");
	//31.1
	battle_q.push_back("Capital of Portugal?");
	battle_a.push_back("Lisbon");
	//31.2
	battle_q.push_back("Capital of Ireland?");
	battle_a.push_back("Dublin");
	//31.3
	battle_q.push_back("Capital of Japan?");
	battle_a.push_back("Tokyo");
	//31.4
	battle_q.push_back("Capital of Russia?");
	battle_a.push_back("Moscow"); 

	for(int k = 0; k < 10; k++){
		battle_single_challenge.push_back("Puzzle");
		for(int h = 0; h < 5; h++){
			battle_single_challenge.push_back(puzzle_q.at(i));
			battle_single_challenge.push_back(puzzle_a.at(i));
		}
		full_set.push_back(battle_single_challenge);
		battle_single_challenge.erase(battle_single_challenge.begin(),battle_single_challenge.end());
	}

	srand(time(0));
	random_shuffle(full_set.begin(),full_set.end());	

    
    return full_set;
}
