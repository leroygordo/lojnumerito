//#include "node.hpp"

#include <list>
#include <utility>
#include <iostream>
#include <string.h>

using namespace std;

class node {
  public:
  struct state {
    int *board;
	
	state(int *board):board(board){}
    ~state(){}
	bool is_goal(){
	  for(int i = 0; i < 15 ; i++)
	    if(board[i] != i) {
		  return false;
		}
	}
	list<pair<node::state,char> > succ(){}
  };
  
  public:
  state s;
  node *parent;
  char action;
  int cost;

  node():s(0),parent(0),action(0),cost(0){}
  node(node::state &s, node *p, char a, int c):s(s),parent(p),action(a),cost(c){}
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
  
int main(int argc,char* argv[]) {
}