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
  
  node(int value,vector<std:string> c){
    number = value;
    challenge_set = c;
    parent = NULL;
    right = NULL;
    left = NULL;
  }
  
  node::right(){return *right;}
  node::left(){return *left;}
  node::parent(){return *parent;}
  
  node::set_right(node *ptr){ this->right = ptr;}
  node::set_left(node *ptr){ this->left = ptr;}
  node::set_parent(node *ptr){ this->parent = ptr;}
  
}

namespace BST{
  class Maze{
    private:
    node *root;
    int level;
      
    public:
    Maze();
    ~Maze();
    Maze create_game(int difficulty, vector<vector<std:string>> every_challenge);
    
  }
}
