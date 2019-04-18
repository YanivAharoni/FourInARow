/** @file Player.h
  *  @brief Player API
  *
  *  @author Yaniv Aharoni
  *
  *  @bug No known bugs.
  */

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "shapesandcolors.h"


typedef struct Player Player;

/** @brief Creating a Player for the game
  * @param[in] --------
  * @return the Player
  */

Player* CreatePlayer();

/** @brief destroing a Player
  * @param[in] pointer to an existing Player
  * @return ----------
  */

void DestroyPlayer(Player* _player);

/** @brief update the player information
  * @param[in] Player* 1 or 2
  * @param[in] char* first name
  * @param[in] char* last name
  * @return ----------
  */

void UpdatePlayer(Player* _player,char _firstName[],char _lastName[]);

/** @brief display the Player information
  * @param[in] Player*
  * @param[in] Player Number
  * @return ----------
  */

void PlayerDisplay(Player* _player,int i);

/** @brief getting First Name of the Player
  * @param[in] Player*
  * @return First Name of the Player
  */

char* GetFirstName(Player* _player);

/** @brief getting Last Name of the Player
  * @param[in] Player*
  * @return Last Name of the Player
  */

char* GetLastName(Player* _player);

/** @brief announcing the Winner
  * @param[in] Player*
  * @param[in] Player number
  * @return ---------
  */

void Winner_Announcement(Player* _player, int _playerNumber);

#endif /* __PLAYER_H_ */
