#include "node.cpp"
#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <stdlib.h>

using namespace std;

bool isInSet(node::state s, set<node::state> states) {
}

/*list<char> a_star(char board[]) {
  list<char> solution;
  priority_queue<node> queue_;
  node root;
  root.make_root(node::state(board));
  queue_.push(root);
  set<node::state> closed;
  
  while (!queue_.empty()) {
    node n; 
	n = queue_.top();
	queue_.pop();
	if (!isInSet(n.s,closed)) {
	  closed.insert(n.s);
	  if(n.s.is_goal()) {
	    solution = n.extract_solution();
	  }
	  list<pair<node::state,char> > succ_ = n.s.succ();
	  for(list<pair<node::state,char> >::iterator iter=succ_.begin(),limit=succ_.end() ; iter != limit ; iter++) {
	    node n_;
		n_.make_node(n,(*iter).second,(*iter).first,0);
	  }
	}
  }
  return solution;
}*/

int main(int argc,char* argv[]) {
  char b[16] = {1,12,2,3,4,5,6,7,8,9,10,11,0,13,14,15};
  node::state s = node::state(b);
  
  char* suc = s.succ();
  
  node r = make_root(s);
  
  node c = make_node(&r,'U',s,8);
  
  cout << suc[0] << endl;
  cout << suc[1] << endl;
  cout << suc[2] << endl;
  cout << suc[3] << endl;
  
  node::state n = action(s,'U');
  
  cout << n.blank << endl;

}