/** @file Board.h
  *  @brief Board
  *
  *  @author Yaniv Aharoni
  *
  *  @bug No known bugs.
  */

#ifndef __BOARD_H__
#define __BOARD_H__

#include "shapesandcolors.h"

typedef struct Board Board;

/** @brief Creating the Board for the game
  * @return the Board for the game
  */

Board* CreateBoard();

/** @brief destroing the Board
  * @param[in] pointer to an existing Board
  * @return ----------
  */

void DestroyBoard(Board* _board);

/** @brief update the board with a new disc on the Board
  * @param[in] Board* containing the "discs"
  * @param[in] _row to be placed a disc
  * @param[in] _colomn to be placed a disc
  * @param[in] int player number - 1 or 2
  * @return ----------
  */

void UpdateBoard(Board* _board,int _row,int _colomn,int _playerNumber);

 /** @brief display the Board
   * @param[in] Board* containing the "discs"
   * @return ----------
   */

void BoardDisplay(Board* _board);

/** @brief checking if the specific cell is empty and in the boarders of the game
  * @param[in] Board* containing the "discs"
  * @param[in] _colomn that the player wants to insert new disc
  * @return 1 - legal cell, 0 illegal cell
  */

int CheckIf_Legal(Board* _board,int _colomn);

/** @brief defining specific row according to a desired colomn
  * @param[in] Board* containing the "discs"
  * @param[in] _colomn to check
  * @return the concurrent row
  */

int Define_Row(Board* _board, int _colomn);

/** @brief checking if we have a winner
  * @param[in] Board* containing the "discs"
  * @return if there is a winner - 1 for Player1, 2 for Player2 and 0 if there is no winner.
  */

int Check_If_We_Have_A_Winner(Board* _board);

#endif /* __BOARD_H__ */
