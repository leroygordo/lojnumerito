#include <list>
#include <utility>
#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include "manhattan.cpp"

using namespace std;

class node {
public:
  char board[16];
  int blank;
  node *parent;
  char action;
  int cost;

  node()
    :blank(0),parent(NULL),action(0),cost(0)
  {
  }

  node(char b[], int w, node *p, char a, int c)
    :parent(p),action(a),cost(c)
  {
    for (int i = 0 ; i < 16 ; i++) {
      board[i] = b[i];
      if (board[i] == 'x')
	blank = i;  
    }
  }

~node(){}

	
bool is_goal(){
  for(int i = 0; i <= 15 ; i++) {
    switch(board[i]){
    case 'x':
      if(i != 0) 
	return false;
      break; 
    case 'a': 
      if(i != 1) 
	return false;
      break;
    case 'b': 
      if(i != 2) 
	return false;
      break;
    case 'c': 
      if(i != 3) 
	return false;
      break;
    case 'd': 
      if(i != 4) 
	return false;
      break;
    case 'e': 
      if(i != 5) 
	return false;
      break;
    case 'f': 
      if(i != 6) 
	return false;
      break;
    case 'g': 
      if(i != 7) 
	return false;
      break;
    case 'h': 
      if(i != 8) 
	return false;
      break;
    case 'i': 
      if(i != 9) 
	return false;
      break;
    case 'j': 
      if(i != 10) 
	return false;
      break;
    case 'k': 
      if(i != 11) 
	return false;
      break;
    case 'l': 
      if(i != 12) 
	return false;
      break;
    case 'm': 
      if(i != 13) 
	return false;
      break;
    case 'n': 
      if(i != 14) 
	return false;
      break;
    case 'o': 
      if(i != 15) 
	return false;
      break;
    default:
      return false;
    }
  }
  return true;
}
  
char* succ() {
  char* succ_ = (char *) malloc(4 * sizeof(char));
  if((blank - 4) >= 0) {
    succ_[1] = 'U';
  }
  else {
    succ_[1] = 'W';
  }
    
  if((blank + 4) <= 15) {
    succ_[3] = 'D';
  }
  else {
    succ_[3] = 'W';	  
  }
    
  if((blank + 1) % 4 != 0) {
    succ_[2] = 'R';
  }
  else { 
    succ_[2] = 'W';
  }
    
  if(!(blank % 4 == 0)) {
    succ_[0] = 'L';
  }
  else {
    succ_[0] = 'W';	
  }
    
  return succ_;
}

  
list<char> extract_solution(){
  list<char> path;
  node *n_ = this;
  while (n_ != NULL) {
    path.push_front(n_->action);
    cout << n_ << endl;
    n_ = n_->parent;
  }
  return path;
}  
};


class CompareNode {
public:
  bool operator()(const node &n1, const node &n2) {
    return (n1.cost < n2.cost);
  }
};

node make_root(char s[]){
  node n = node(s,0,0,0,0);
  return n;
 }
  
node make_node(node *n, char a, char s[],int c){
  //cout << s << endl;
  node n_ = node(s,0,n,a,(n->cost+1)+c);
  return n_;
}

char* action(char s[], int blank, char a){
  char *new_state =  (char *) malloc(16 * sizeof(char));

  for(int i = 0 ; i  < 16 ; i++)
    new_state[i] = s[i];

  switch(a){
  case 'U':
    swap(new_state[blank],new_state[blank-4]);
    break;
  case 'D':
    swap(new_state[blank],new_state[blank+4]);
    break;	
  case 'L':
    swap(new_state[blank],new_state[blank+1]);
    break;	
  case 'R':
    swap(new_state[blank],new_state[blank-1]);
    break;	
  }

  return new_state;
}
