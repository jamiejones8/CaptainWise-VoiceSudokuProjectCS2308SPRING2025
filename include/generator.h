/**
* @file generator.h
 * @brief Function prototypes for generating random solvable Sudoku boards.
 *
 * This header defines functions to:
 * - Create empty Sudoku boards.
 * - Fill independent diagonal boxes.
 * - Solve and generate a complete Sudoku board.
 * - Randomly delete cells to create a solvable puzzle.
 * - Generate a complete Sudoku puzzle with a specific number of empty cells.
 *
 * Detailed function descriptions and parameters are provided below.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>

 /**
  * @brief
  * This function simply initializes a 9x9 board (2d array) full of zeros.
  */
int** getEmptyBoard();

/**
  * @brief
  * This function takes a base vector of
  * {1, 2, 3, 4, 5, 6, 7, 8, 9} and shuffles it randomly, returning the result.
  */
std::vector<int> getShuffledVector();

/**
  * @brief
  * This function utilizes randomized vectors provided by getShuffledVector()
  * to fill the top left, center, and bottom left boxes of our board created by getEmptyBoard().
  */
void fillBoardWithIndependentBox(int** BOARD);

/**
  * @brief
  * This function uses hardware based randomization to delete n number of items from the board (set them to 0)
  * It validates n (0 < n < 82) and terminates if n is not within that range.
  * It then deletes n items using the following process:
  * 1. Navigate to a random location in the 2d array
  * 2. Check if that location is already 0
  * 3. If so, find a new location. If not, set the value to zero and increment the counter.
  * 4. Terminate the while loop when count == n
  *
  * @param int** BOARD contains our solved board
  * @param n is the number of items to be deleted
  */
void deleteRandomItems(int** BOARD, const int& n);

/**
  * TODO: Provide appropriate Documentation, see other examples provided within the projects
  */
int** generateBoard(const int& empty_boxes);

#endif // GENERATOR_H
