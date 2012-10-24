/*
  Los estados estaran representados por letras del a-o siendo el espacio vació
  la letra x, esto para ocupar menos espacio en memoria
*/
#include <iostream>
using namespace std;
int map[16];

int distM[16][16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                   1,0,1,2,2,1,2,3,3,2,3,4,4,3,4,5,
                   2,1,0,1,3,2,1,2,4,3,2,3,5,4,3,4,
                   3,2,1,0,4,3,2,1,5,4,3,2,6,5,4,3,
                   1,2,3,4,0,1,2,3,1,2,3,4,2,3,4,5,
                   2,1,2,3,1,0,1,2,2,1,2,3,3,2,3,4,
                   3,2,1,2,2,1,0,1,3,2,1,2,4,3,2,3,
                   4,3,2,1,3,2,1,0,4,3,2,1,5,4,3,2,
                   2,3,4,5,1,2,3,4,0,1,2,3,1,2,3,4,
                   3,2,3,4,2,1,2,3,1,0,1,2,2,1,2,3,
                   4,3,2,3,3,2,1,2,2,1,0,1,3,2,1,2,
                   5,4,3,2,4,3,2,1,3,2,1,0,4,3,2,1,
                   3,4,5,6,2,3,4,5,1,2,3,4,0,1,2,3,
                   4,3,4,5,3,2,3,4,2,1,2,3,1,0,1,2,
                   5,4,3,4,4,3,2,3,3,2,1,2,2,1,0,1,
                   6,5,4,3,5,4,3,2,4,3,2,1,3,2,1,0};

int mapper (char* tablero){
  for (int i=0;i<16;i++){
    switch(tablero[i]){
    case 'a': map[i]=1; break;
    case 'b': map[i]=2; break;
    case 'c': map[i]=3; break;
    case 'd': map[i]=4; break;
    case 'e': map[i]=5; break;
    case 'f': map[i]=6; break;
    case 'g': map[i]=7; break;
    case 'h': map[i]=8; break;
    case 'i': map[i]=9; break;
    case 'j': map[i]=10; break;
    case 'k': map[i]=11; break;
    case 'l': map[i]=12; break;
    case 'm': map[i]=13; break;
    case 'n': map[i]=14; break;
    case 'o': map[i]=15; break;
    case 'x': map[i]=0; break;
    }
  }
  return 0;
}

int heuristics (char* tablero){
  int h=0;
  //int j[16]={7,15,8,2,13,6,3,12,11,0,4,10,9,5,1,14};
  mapper(tablero);
  for (int i=0;i<16;i++){
    h+=distM[map[i]][i];
 cout<<h;
  }
  return h;
}

int main(){
  int h;
  char test[16]={'a','b','x','c','d','e','f','g','h','i','j','k','l','m','n','o'};

  h=heuristics(test);
  cout<<h;
cout<<'/';
  for (int i=0;i<16;i++){
 cout<<test[i];
  }
  return 0;
}
