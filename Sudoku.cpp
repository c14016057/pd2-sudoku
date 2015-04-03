#include<iostream>
#include"Sudoku.h"
using namespace std;
Sudoku::Sudoku(){
 for(int i=0;i<sudokusize;i++) map[i]=0;
}
void Sudoku::ReadIn(){
 for(int i=0;i<sudokusize;i++) cin>>map[i];
}
void Sudoku::Solve(){
 for(int i=0;i<12;i++){
  for(int j=0;j<12;j++)  cout<<map[i*12+j];
  cout<<endl;
}
}
