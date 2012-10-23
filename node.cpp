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
	
	list<pair<node::state,char> > succ(){
	  list<pair<node::state,char> > succ_;
	  if((blank - 4) >= 0) {
	    state s = state(board);
		swap(s.board[blank],s.board[blank-4]);
		s.blank = blank - 4;
	    succ_.push_back(make_pair(s,'U'));
	  }
	  if((blank + 4) <= 15) {
	  	state s = state(board);
		swap(s.board[blank],s.board[blank+4]);		
		s.blank = blank + 4;
	    succ_.push_back(make_pair(s,'D'));
	  }
	  if((blank + 1) % 4 != 0) {
	  	state s = state(board);
		swap(s.board[blank],s.board[blank+1]);	  
		s.blank = blank + 1;
	    succ_.push_back(make_pair(s,'R'));
	  }
	  if(!(blank % 4 == 0)) {
	  	state s = state(board);
		swap(s.board[blank],s.board[blank-1]);
		s.blank = blank - 1;
	    succ_.push_back(make_pair(s,'L'));
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
  
  node make_root(node::state s){
    node n = node(s,0,0,0);
    return n;
  }
  
  node make_node(node *n, char a, node::state s,int c){
    node n_ = node(s,n,a,c);
    return n_;
  }
  
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