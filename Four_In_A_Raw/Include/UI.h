/** @file UI.h
  *  @brief UI API for recieving inputs from the players
  *
  *  @author Yaniv Aharoni
  *
  *  @bug No known bugs.
  */

#ifndef __UI_H___
#define __UI_H___

#include "Player.h"
#include "Board.h"
#include "shapesandcolors.h"

/**
  * @brief asking the player for a new disc location
  * @param[in] player pointer
  * @return colomn location
  */

int New_Disc_Location_Colomn(Player* _player);

#endif /* __UI_H__ */
