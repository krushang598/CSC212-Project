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
    bool diff_level, input = false, won = false;
    
    vector<vector<string> create_challenge_set();
    BST::Maze game_maze(); 
    node *root;
    vector<vector<string> challenge_set;
    challenge_set = create_challenge_set();
    
    
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
                    
                    root = build_maze(7,challenge_set,0,root);
                    game_maze.set_root(root);
                    won = play_game(game_maze,game_maze.root())
                    if(won){
                        cout << "Congrats you've passed the last challenge and won the game at the easy level!!!!" << endl;
                        cout << "Maybe you should try the Medium!" << endl;
                        return 0;
                    }else{
                        cout << "Gosh darn it, you made too many mistakes. But that's okay, you can always try it again!" << endl;
                        return 0;
                    }
    
                }
                else if(level_input == 2)
                {
                    input = true;
                    
                    root = build_maze(15,challenge_set,0,root);
                    game_maze.set_root(root);
                    won = play_game(game_maze,game_maze.root())
                    if(won){
                        cout << "Congrats you've passed the last challenge and won the game at the medium level!!!!" << endl;
                        cout << "Maybe you should try the Hard!" << endl;
                        return 0;
                    }else{
                        cout << "Gosh darn it, you made too many mistakes. But that's okay, you can always try it again!" << endl;
                        return 0;
                    }
                }
                else if(level_input == 3)
                {
                    input = true;
                    
                    root = build_maze(31,challenge_set,0,root);
                    game_maze.set_root(root);
                    won = play_game(game_maze,game_maze.root())
                    if(won){
                        cout << "Congrats you've passed the last challenge and won the game!!!!" << endl;
                        return 0;
                    }else{
                        cout << "Gosh darn it, you made too many mistakes. But that's okay, you can always try it again!" << endl;
                        return 0;
                    }
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
            cout << "This is a BST maze, each room has a different challenge. There are three types of rooms: Trivia, Puzzle and Battle" << endl
                 << "Win the challenge and you can advance to the node to your right, lose a challenge and you advance to your left." << endl
                 << "If you move to the left twice in a row, you lost and you are prompted with the choice of either trying again or quitting." << endl
                 << "Player wins when he wins the challenge at the last level."; << endl
                 << "Trivia:" << endl
                 << "Answer a trivia question from any possible subject." << endl
                 << "Puzzle:" << endl
                 << "Solve a brain teaser to pass." << endl
                 << "Battle:" << endl
                 << "5 questions need to be answered on 50 seconds." << endl
                 << "Answer at least 3 questions correctly to pass." << endl;                     
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
