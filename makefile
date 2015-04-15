test:Sudoku.o test.o
	g++ -o test Sudoku.o test.o
Sudoku.o:Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp
test.o:test.cpp Sudoku.h
	g++ -c test.cpp
clean:
	rm *.o
	rm test
