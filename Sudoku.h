#include<iostream>
class Sudoku{
public:
 Sudoku();
// Sudoku(const int intput_map[]);
 static const int sudokusize=144;
 void ReadIn();
 void Solve();
private:
 int map[sudokusize];
};
