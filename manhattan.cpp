/*
  Los estados estaran representados por letras del a-o siendo el espacio vació
  la letra x, esto para ocupar menos espacio en memoria
*/
#include <iostream>
using namespace std;
int map_[16];

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
    case 'a': map_[i]=1; break;
    case 'b': map_[i]=2; break;
    case 'c': map_[i]=3; break;
    case 'd': map_[i]=4; break;
    case 'e': map_[i]=5; break;
    case 'f': map_[i]=6; break;
    case 'g': map_[i]=7; break;
    case 'h': map_[i]=8; break;
    case 'i': map_[i]=9; break;
    case 'j': map_[i]=10; break;
    case 'k': map_[i]=11; break;
    case 'l': map_[i]=12; break;
    case 'm': map_[i]=13; break;
    case 'n': map_[i]=14; break;
    case 'o': map_[i]=15; break;
    case 'x': map_[i]=0; break;
    }
  }
  return 0;
}

int heuristics (char* tablero){
  int h=0;
  mapper(tablero);
  for (int i=0;i<16;i++){
    h+=distM[map_[i]][i]; // map_i: lo que hay e i:lo que deberia haber
  }
  return h;
}


int heuristics2 (char* tablero){
  int h=0;
  mapper(tablero);
  for (int i=0;i<4;i++)
    for (int j=0;j<4;j++){
      int posi=i+2*j;
      h+=distM[map_[posi]][posi];
      for (int k=i;k<4;k++){ // verifica en la misma fila
        int posi_k=k+2*j;        
        // ve si ambos deberian ir en la misma fila
        if ((i == map_[posi] / 4) && (i == map_[posi_k] / 4)){
          // ve si el orden esta invertido
          if(map_[posi] > map_[posi_k]){
            h+=2;
          }          
        }
      }
      for (int k=j;k<4;k++){ // verifica en la misma columna
        int posi_k=i+2*k;        
        // ve si ambos deberian ir en la misma fila
        if ((i == map_[posi] % 4) && (i == map_[posi_k] % 4)){
          // ve si el orden esta invertido
          if(map_[posi] > map_[posi_k]){
            h+=2;
          }          
        }
      }
    }
  return h;
}
/*int main(){
  int h;
  char test[16]={'a','b','x','c','d','e','f','g','h','i','j','k','l','m','n','o'};

  h=heuristics(test);
  cout<<h;
cout<<'/';
  for (int i=0;i<16;i++){
 cout<<test[i];
  }
  return 0;
  }*/
