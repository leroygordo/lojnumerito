#include "node.hpp"

node::state::state(char *board)
  :board(board)
{
}

node::state::~state(){
}

bool node::state::is_goal(){
}

list<tuple<node::state,char> > node::state::succ(){
}

node::node(node::state &s, node *p, char a, int c)
  :s(s),parent(p),action(a),cost(c){
}

node::~node(){
}

node make_root(node::state s){
  node n = node(s,0,0,0);
  return n;
}
  
node make_node(node *n, char a, node::state s,int c){
  node n_ = node(s,n,a,c);
  return n_;
}
  
list<char> extract_solution(node * n){
  list<char> path;
  node * n_ = n;
  while (!n_->parent) {
    path.push_front(n_->action);
	n_ = n_->parent;
  }
  return path;
}

int main(int argc,char* argv[]) {
}