Hello! My name is Jamie Jones, NetID tkr36.

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
        void printBoard(): Uses nested for loops to print the 9x9 board
        void boardToString(): Converts a 9x9 board into a formatted string representation for use in displaying the board
        bool writeSudokuToFile(): Writes the string representation to a file to save the puzzle
        void replaceCharacter(): Replaces a character with a new character
        void extractNumber(): Extracts numerical values from a string
        void fillBoard(): Fills the board with increasing integers
        int** readSudokuFromFile(): Reads the puzzle from a text file and stores it
        bool checkIfSolutionIsValid(): Checks to see if a solved board is valid with no errors
        vector<string> getAllSudokuInFolder(): Places all puzzles into the corresponding folder
        void createAndSaveNPuzzles(): Uses functions above to generate n puzzles and saves them to a file
        void displayProgressBar(): Displays percentage based progress bar relating to tests
        void solveAndSaveNPuzzles(): Solves and saves n puzzles to a file
        int** deepCopyBoard(): Copies the current state of the board into a new int** variable
        void compareSudokuSolvers(): Compares the two algorithms based on time taken to solve

utils.h/utils.cpp:
    This file contains various utility functions such as:
        void deallocateBoard(): Deallocates memory used by a board and sets the value to nullptr
        void createFolder(): Creates a folder and prints the path
        void initDataFolder(): Creates a folder to hold the saved puzzles in
        void getFileName(): Retrieves the name of a file

