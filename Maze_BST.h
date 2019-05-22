// BST class for the maze elements
#include <iostream>
#include <string>
#include <vector>

class node{
  private:
  int number;
  vector<std::string> challenge_set;
  node *left;
  node *right;
  node *parent;

  public:
  node(){
    number = 0;
    left = NULL;
    right = NULL;
    parent = NULL; 
  }
  
  node(int value){
    number = value;
    parent = NULL;
    right = NULL;
    left = NULL;
  }
  
  node::right(){return *right;}
  node::left(){return *left;}
  node::parent(){return *parent;}
  node::challenge(){return challenge_set;}
  
  node::set_right(node *ptr){ this->right = ptr;}
  node::set_left(node *ptr){ this->left = ptr;}
  node::set_parent(node *ptr){ this->parent = ptr;}
  node::set_challenge(vector<std::string> input){this->challenge_set = input;}
  
  
}

namespace BST{
  class Maze{
    private:
    node *root;
    int level;
      
    public:
    Maze();
    ~Maze();
    Maze build_maze(int difficulty, vector<vector<std:string>> every_challenge);
    bool node_play(node *ptr);
    bool node_battle(node *ptr);
    bool play_game();
    Maze operator=(const Maze& b);
    
  }
}
