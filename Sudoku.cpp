#include<iostream>
#include"Sudoku.h"
using namespace std;
Sudoku::Sudoku(){
 for(int i=0;i<sudokusize;i++) {map[i]=0;
                                answer[i]=0;}
}
Sudoku::Sudoku(const int intput_map[]){
int i;
for(i=0;i<sudokusize;i++) {map[i]=intput_map[i];
                           answer[i]=0;}
}
void Sudoku::ReadIn(){
 for(int i=0;i<sudokusize;i++) cin>>map[i];
}
void Sudoku::set_map(int n,int index){
map[index]=n;
}
void Sudoku::print_map(){
 for(int i=0;i<12;i++){
  for(int j=0;j<12;j++)  cout<<map[i*12+j]<<" ";
  cout<<endl;}

}
void Sudoku::Solve(){
Sudoku question(map);
Sudoku answer;
get_solution(question,answer);
// for(int i=0;i<12;i++){
//  for(int j=0;j<12;j++)  cout<<map[i*12+j]<<" ";
//  cout<<endl;
answer.print_map();


}

int Sudoku::check_one_number(int n,int index){
//row
int row=index/12;
int count=0;
int i,j;
for(i=0;i<12;i++) if(map[row*12+i]==n) count++;
if(count>0) return 0;
//col
int col=index%12;
count=0;
for(i=0;i<12;i++) if(map[col+i*12]==n) count++;
if(count>0) return 0;
//block
int block=3*(col/3)+36*(row/3);
count=0;
for(i=0;i<3;i++)
 for(j=0;j<3;j++)
  if(map[block+12*i+j]==n) count++;
if(count>0) return 0;
return 1;
}
int Sudoku::iscorrect(){
int n,i;
for(i=0;i<sudokusize;i++){
if(map[i]==0) return 0;
else if(map[i]>0){
 n=map[i];
 map[i]=0;
 if(!check_one_number(n,i)){
  map[i]=n;
  return 0;}
 else map[i]=n;}
 }
return 1;
}
int Sudoku::get_next_zero(){
int i;
for(i=0;i<sudokusize;i++) if(map[i]==0) return i;
return -1;
}
int Sudoku::get_solution(Sudoku question,Sudoku & answer){
if(question.get_next_zero()==-1) answer=question;




}

