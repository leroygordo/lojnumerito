#ifndef NODE
#define NODE

#include <list>
#include <tuple>

using namespace std;

class node {
  public:
  struct state {
    char *board;
	
	state(char *board); //init();
	~state();
	bool is_goal();
	list<tuple<state,char> > succ();
  };
  
  state s;
  node *parent;
  char action;
  int cost;
  
  node(state &s, node *p, char a, int c);
  ~node();
  node make_root(node::state s);
  node make_node(node n, char a, node::state s,int c);
  list<char> extract_solution(node* n);
};

#endif