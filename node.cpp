#include "node.hpp"

node::state::state(){
}

node::state::~state(){
}

node::state node::state::init(){
}

bool node::state::is_goal(){
}

list<tuple<node::state,char> > node::state::succ(){
}

node::node(){
}

node::~node(){
}

node make_root(){
}
  
node make_node(node n, char a, node::state s){
}
  
list<char> extract_solution(){
}

int main(int argc,char* argv[]) {
}