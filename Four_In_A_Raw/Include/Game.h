/** @file Game.h
  *  @brief game
  *
  *  @author Yaniv Aharoni
  *
  *  @bug No known bugs.
  */

#ifndef __GAME_H___
#define __GAME_H___

#include "Player.h"
#include "UI.h"
#include "Board.h"

typedef struct Game Game;

/**
  * @brief CreateGame with 2 players
  * @param[in] --------
  * @return Game pointer
  */
Game* CreateGame();

/** @brief destroing game and free allocated space
  * @param[in] pointer to an existing game
  * @return ---
  */

void DestroyGame(Game* game);

/** @brief runing the game up to a WIN accomplish 4 in a row
  * @param[in] game pointer
  * @return 1 if _game didint initialSized
  * @return 0 while runing game was succesful
  */

int RunGame(Game* _game);

#endif /* __GAME_H___ */
