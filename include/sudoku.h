/**
 * @file sudoku.h
 * @brief Core Sudoku solving and board generation functions.
 *
 * This header file declares functions essential for solving Sudoku puzzles
 * and validating board states. It includes:
 * - A backtracking Sudoku solver.
 * - A cell validation function to ensure valid number placement.
 * - A board generation stub for creating Sudoku puzzles.
 *
 * All functions operate on dynamically allocated 9x9 Sudoku boards
 * represented as `int**`, where empty cells are denoted by 0.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef SUDOKUPROJECT_SUDOKU_H
#define SUDOKUPROJECT_SUDOKU_H

#include <iostream>

/**
  * @brief
  * This function, given a row, column, and k value, checks to see if the given k value can
  * be placed in the (row, col) position. If yes, it returns true, if not, false is returned.
  * It does this by checking each position in the row, column, and box of the given location
  * to ensure there is no duplicate k already present
  *
  * @param BOARD The 9x9 sudoku board
  * @param r The row index for the location to be checked
  * @param c the col index for the location to be checked
  * @param k the value that will be tested in the location r, c
  */
bool isValid(int** BOARD, const int& r, const int& c, const int& k);

/**
  * @brief
  * This function uses a brute force method to solve the sudoku board. It starts at
  * the first empty space, checks every number 1-9 using isValid(), and places the lowest number that works.
  * It then moves on to the next empty space and continues doing the same. If it finds a space
  * where no number works, backtracking is triggered by a false return value and returns to the
  * previous space and continues trying new numbers. Backtracking continues if no number is found again.
  * Eventually,the board will be solved and the function will return true, which closes all recursive
  * function calls in reverse order.
  *
  * @param BOARD Our 9x9 sudoku board
  * @param r The starting row value (const set to 0)
  * @param c The starting col value (const set to 0)
  */
bool solveBoard(int** BOARD, const int& r=0, const int& c=0);

// ========================= Efficient Solutions ==========================


/**
  * @brief
  * This function takes the board as input and iterates over it using nested for loops.
  * It checks every empty space and keeps track of how many possibilities fit within that space.
  * Using a counter-based updating system, it keeps track of the row and column of the space with
  * the fewest options. The first two values in the returned tuple are the row and column index, and
  * the third value is the number of possible options that space has.
  *
  * @param BOARD Our 9x9 sudoku board
  */
std::tuple<int, int, int> findNextCell(int** BOARD);


/**
  * @brief
  * This function works fundamentally the same as the original solveBoard(), with the notable exception
  * of using findNextCell() to fill the cell with the fewest possibilities instead of filling the cells in order.
  * It still makes use of recursion and backtracking to finish the board.
  *
  * @param BOARD Our 9x9 sudoku board
  */
bool solveBoardEfficient(int** BOARD);

/**
  * @brief
  * This simple function allows the user to choose between the two solving algorithms,
  * solveBoard() and solveBoardEfficient(). If the efficient flag is true, the efficient algorithm
  * is used. If not, the original algorithm is used.
  *
  * @param board Our 9x9 sudoku board
  * @param efficient A boolean flag to choose what algorithm to use
  */
bool solve(int** board, const bool& efficient = false);

#endif //SUDOKUPROJECT_SUDOKU_H