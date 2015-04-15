#include<iostream>
#include"Sudoku.h"
#include<cstdlib>
using namespace std;
Sudoku::Sudoku(){
 for(int i=0;i<sudokusize;i++) map[i]=0;
                                
}

Sudoku::Sudoku(const int intput_map[]){
int i;
for(i=0;i<sudokusize;i++) map[i]=intput_map[i];
                           
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
int solution=0;
int b,i,j,count,brow,bcol;
int neg_one_block=0;
int neg_one_block_perbrow[4]={0};
int neg_one_block_perbcol[4]={0};
//check [-1]block
for(b=0;b<16;b++){
 brow=b/4;
 bcol=b%4;
 count=0;
 for(i=0;i<3;i++)
  for(j=0;j<3;j++)
   if(map[36*brow+3*bcol+12*i+j]==-1) count++;
 if(count!=9&&count!=0){cout<<"block"<< b<<" not complete"<<endl;
                       return ;}
 else if(count==9) {neg_one_block++;
                    neg_one_block_perbrow[brow]++;
                    neg_one_block_perbcol[bcol]++;} 
 }
for(i=0;i<4;i++){if(neg_one_block_perbrow[i]!=1) return;
                 if(neg_one_block_perbcol[i]!=1) return;}
cout<<"start solution"<<endl;
get_solution(question,answer,solution);
cout<<solution<<" solution"<<endl;
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

int Sudoku::get_solution(Sudoku question,Sudoku & answer,int &solution){
int n,p;
question.simplify();
p=question.get_next_zero();
if(p==-1){
 answer=question;
 solution++;
 cout<<"answer:"<<solution<<endl;
 question.print_map();
// if(solution>12) exit(0);
 }          
else
 for(n=1;n<10;n++) if(question.check_one_number(n,p)){question.set_map(n,p);
                                                      get_solution(question,answer,solution);} 
}
void Sudoku::simplify(){
int i,j,k,b,row,col,block,brow,bcol,count,locate;
int suport_table[9*sudokusize]={0};
int change=0;
for(i=0;i<sudokusize;i++){
 row=i/12;
 col=i%12;
 block=3*(col/3)+36*(row/3);
 if(map[i]>0){//self
              for(j=0;j<9;j++) suport_table[i+j*sudokusize]=1;
              //row
              for(j=0;j<12;j++) suport_table[(map[i]-1)*sudokusize+row*12+j]=1;
              //col
              for(j=0;j<12;j++) suport_table[(map[i]-1)*sudokusize+col+j*12]=1;
              //block
              for(j=0;j<3;j++)
               for(k=0;k<3;k++)
                 suport_table[(map[i]-1)*sudokusize+block+12*j+k]=1;
              }
 if(map[i]==-1) for(j=0;j<9;j++) suport_table[i+j*sudokusize]=1;
 }
for(k=0;k<9;k++){
//block
 for(b=0;b<16;b++){
  brow=b/4;
  bcol=b%4;
  count=0;
  locate=-1;
  for(i=0;i<3;i++)
   for(j=0;j<3;j++)
    if(suport_table[k*sudokusize+36*brow+3*bcol+12*i+j]==0) {count++;
                                                             locate=36*brow+3*bcol+12*i+j;}
  if(count==1&&map[locate]==0){map[locate]=k+1;
                               change=1;
                               for(i=0;i<12;i++) suport_table[k*sudokusize+(locate/12)*12+i]=1;
                               for(i=0;i<12;i++) suport_table[k*sudokusize+locate%12+i*12]=1;
                               } 
 }
//row
 for(i=0;i<12;i++){
  count=0;
  locate=-1;
  for(j=0;j<12;j++) 
   if(suport_table[k*sudokusize+12*i+j]==0) {count++;
                                            locate=12*i+j;}
  if(count==1&&map[locate]==0){map[locate]=k+1;
                               change=1;
                               for(j=0;j<12;j++) suport_table[k*sudokusize+locate%12+j*12]=1;
                               row=locate/12;
                               col=locate%12;
                               block=3*(col/3)+36*(row/3);
                               for(b=0;b<3;b++)
                                for(j=0;j<3;j++)
                                 suport_table[k*sudokusize+block+12*b+j]=1;
                               } 
 }
//col
 for(i=0;i<12;i++){
  count=0;
  locate=-1;
  for(j=0;j<12;j++) 
   if(suport_table[k*sudokusize+i+12*j]==0) {count++;
                                            locate=i+12*j;}
  if(count==1&&map[locate]==0){map[locate]=k+1;
                               change=1;
                               for(j=0;j<12;j++) suport_table[k*sudokusize+12*(locate/12)+j]=1;
                               row=locate/12;
                               col=locate%12;
                               block=3*(col/3)+36*(row/3);
                               for(b=0;b<3;b++)
                                for(j=0;j<3;j++)
                                 suport_table[k*sudokusize+block+12*b+j]=1;
                               } 
 }
}
if(change) simplify(); 
//for(i=0;i<9;i++){
// cout<<i+1<<endl;
// for(j=0;j<12;j++){
//  for(k=0;k<12;k++) cout<<suport_table[i*sudokusize+12*j+k]<<" ";
//  cout<<endl;}
//}
}

