#include <list>
#include <utility>
#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <memory>

using namespace std;

class node {
  public:
  struct state {
    char board[16];
	int blank;
	
	state(char b[]){
	  for (int i = 0 ; i < 16 ; i++) {
	    board[i] = b[i];
		if ((int) board[i] == 0)
		  blank = i;
	  }
	}
	
    ~state(){}
	
	bool is_goal(){
	  for(int i = 0; i <= 15 ; i++) {
	    if((int) board[i] != i) {
		  return false;
		}
	  }
	  return true;
	}
	
	char* succ() {
	  char* succ_ = (char *) malloc(4 * sizeof(char));
	  if((blank - 4) >= 0) {
	    succ_[0] = 'U';
	  }
	  else {
	    succ_[0] = 'W';
	  }
	  
	  if((blank + 4) <= 15) {
	    succ_[1] = 'D';
	  }
	  else {
	    succ_[1] = 'W';	  
	  }
	  
	  if((blank + 1) % 4 != 0) {
	    succ_[2] = 'R';
	  }
	  else { 
	    succ_[2] = 'W';
	  }
	  
	  if(!(blank % 4 == 0)) {
	    succ_[3] = 'L';
	  }
	  else {
	    succ_[3] = 'W';	
	  }

	  return succ_;
	}
  };
  
  public:
  state s;
  node *parent;
  char action;
  int cost;

  node()
    :s(0),parent(0),action(0),cost(0)
  {}
  
  node(node::state &s, node *p, char a, int c)
    :s(s),parent(p),action(a),cost(c)
  {}
  
  ~node(){}
  
  list<char> extract_solution(){
    list<char> path;
    node *n_ = parent;
    while (!n_->parent) {
      path.push_front(n_->action);
	  n_ = n_->parent;
    }
    return path;
  }  
};

bool operator<(const node &n1, const node &n2) {
 return (n1.cost < n2.cost);
}

node make_root(node::state s){
  node n = node(s,0,0,0);
  return n;
 }
  
node make_node(node *n, char a, node::state s,int c){
  node n_ = node(s,n,a,c);
  return n_;
}

node::state action(node::state s, char a){
  node::state new_state = node::state(s.board);
  switch(a){
    case 'U':
		swap(new_state.board[s.blank],new_state.board[s.blank-4]);
		new_state.blank = s.blank - 4;
		break;
	case 'D':
		swap(new_state.board[s.blank],new_state.board[s.blank+4]);
		new_state.blank = s.blank + 4;
		break;	
	case 'L':
		swap(new_state.board[s.blank],new_state.board[s.blank+1]);
		new_state.blank = s.blank + 1;
		break;	
	case 'R':
		swap(new_state.board[s.blank],new_state.board[s.blank-1]);
		new_state.blank = s.blank - 1;
		break;	
  }
  return new_state;
}
