#include<iostream>
class Sudoku{
public:
 Sudoku();
 Sudoku(const int intput_map[]);
 static const int sudokusize=144;
 void ReadIn();
 void Solve();
 int check_one_number(int n,int index);
 int iscorrect();
 void set_map(int n,int index);
 void print_map(); 
private:
 int map[sudokusize];
 int answer[sudokusize];
 int get_next_zero();
 int get_solution(Sudoku question,Sudoku & answer);
};
