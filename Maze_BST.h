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
  node::number(){return number;}
  
  node::set_right(node *ptr){ this->right = ptr;}
  node::set_left(node *ptr){ this->left = ptr;}
  node::set_parent(node *ptr){ this->parent = ptr;}
  node::set_number(int value){ this->number = value;}
  node::set_challenge(vector<std::string> input){this->challenge_set = input;}
  
  void operator=(const node& n){
    this->set_right(n.right());
    this->set_left(n.left());
    this->set_parent(n.parent());
    this->set_number(n.number());
    this->set_challenge(n.challenge());
  }
  
  
}

namespace BST{
  class Maze{
    private:
    node *root;
    int level;
    int left_counter
      
    public:
    Maze();
    ~Maze();
    Maze build_maze(int difficulty, vector<vector<std:string>> every_challenge);
    bool node_play(node *ptr);
    bool node_battle(node *ptr);
    bool play_game(Maze game_board);
    void set_root(node *ptr){this->root = ptr;}
    void set_level(int lvl){this->level = lvl;}
    void set_left_counter(int v){this->left_counter = v;}
    Maze operator=(const Maze& b);
    
  }
}
