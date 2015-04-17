all:Sudoku.o give_question.o solve.o
	g++ -o give_question Sudoku.o give_question.o
	g++ -o solve Sudoku.o solve.o
Sudoku.o:Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp
give_question.o:give_question.cpp Sudoku.h
	g++ -c give_question.cpp
solve.o:solve.cpp Sudoku.h
	g++ -c solve.cpp
clean:
	rm *.o
