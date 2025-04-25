Hello! My name is Jamie Jones. 

This is the repository that holds my Sudoku Solving Algorithm project for CS2308 Spring 2025 with Prof. Bhandari.

This project generates, modifies, and solves sudoku puzzles using two different solving algorithms and compares their 
performance in solving puzzles. The first algorithm is a standard brute force solving method that tries every possible 
correct value until the puzzle is solved. The second algorithm uses an extra function to find the cell with the fewest
possible correct values and starts with that to solve the puzzle.

Important files and their contents:

generator.h/generator.cpp:
    This file includes functions that generate solvable sudoku puzzles. These functions are:
        int** getEmptyBoard(): Generates an empty 9x9 board full of zeros
        vector<int> getShuffledVector(): Randomly shuffles a base {1, 2, 3, 4, 5, 6, 7, 8, 9} vector
        void fillBoardWithIndependentBoxes(): Fills the top left, center, and bottom right boxes with shuffled vectors
        void deleteRandomItems(): Deletes n random items (sets spaces to 0)
        int** generateBoard(): Combines the above functions to generate an empty board, solve it, and delete n items

sudoku.h/sudoku.cpp:
    This file contains functions that modify generated boards to solve them. These functions include:
        bool isValid(): Checks to see if a given value is valid in a (row, col) location
        bool solveBoard(): Uses a brute force esque recursion algorithm to solve the board
        tuple <int, int, int> findNextCell(): Uses isValid() to find the cell with the fewest valid options
        bool solveBoardEfficient(): Uses findNextCell() and recursion to solve the board more efficiently
        bool solve(): Contains both above solving functions and calls the one the user chooses based on a boolean flag

sudoku_io.h/sudoku_io.cpp:
    This file contains functions that track and display progress of testing and solving puzzles. These functions include:
        

utils.h/utils.cpp:

