#include <utility>
#include "node.cpp"
//#include "manhattan.cpp"

//sucesores estaticos
using namespace std;
int i_out;

node mem[1000];
int point=0;

list<char> c_out;

pair<list<char>,int> DFS_acotado(int t, node n){
  pair <list<char>,int> answ;

  int h=heuristics(n.board);

  int new_t;

  if (n.cost + h > t) {
    answ.first=c_out;
    answ.second=n.cost+h;
    return answ;
  }

  if (n.is_goal()){
    c_out=*(n.extract_solution());
    answ.first=c_out;
    answ.second=n.cost;
    return answ;
   
  }

  new_t = 1000000;
  char* succ = n.succ();
  for (int i=0;i<=3;i++) {
    if (succ[i]!='W'){
      //int out_n;

      char* s_ = action(n.board,n.blank,succ[i]);

     
      point++;
      mem[point].parent=&n;//&n;
      mem[point].action=succ[i]; //succ[i];
      memcpy(mem[point].board,s_,16);
      mem[point].cost=n.cost+1; //n.cost+1;
      
      answ = DFS_acotado(t,mem[point]);
      if (!answ.first.empty()) {
	
        return answ;
      }
      new_t= min(new_t,answ.second);
    }
  }
  pair <list<char>,int> empty;
  return empty; 
  

}



pair<list<char>,int> ida_star(char* s, int w){
  pair <list<char>,int> answ;
  mem[point].parent=NULL;
  mem[point].action='W';
  memcpy(mem[point].board,s,16);
  mem[point].cost=0;
  

  int t=w*heuristics(s);
 
  while (c_out.empty() && t < 1000000) {
 
    
    answ = DFS_acotado(t,mem[point]);
    t=answ.second;
    
    }
  return answ;
}


int main(){
  int h;
  char test[16]={'a','b','x','c','d','e','f','g','h','i','j','k','l','m','n','o'};
  pair <list<char>,int> result;
  result= ida_star(test,1);
  // for (list<char>::iterator itr=(result->l).begin(),lim=(result->l).end();itr!=lim;itr++){
   //cout<<*itr<<'-';
  //}
  
  return 0;
}
