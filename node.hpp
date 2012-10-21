#ifndef NODE
#define NODE

#include <list>
#include <tuple>

using namespace std;

class node {
  public:
  struct state {
    char board[15];
	
	state();
	~state();
	state init();
	bool is_goal();
	list<tuple<state,char> > succ();
  };
  
  state s;
  node *parent;
  char action;
  int cost;
  
  
  public:
  explicit node();
  
  ~node();
  
  node make_root();
  
  node make_node(node n, char a, state s);
  
  list<char> extract_solution();
};

#endif