/** @file Player.c
  *  @brief Player API implementation
  *
  *  @author Yaniv Aharoni
  *
  *  @bug No known bugs.
  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Player.h"


struct Player
{
  char FirstName[25];
  char LastName[25];
};

Player* CreatePlayer()
{
  Player* player = NULL;
  player = (Player*)malloc(sizeof(Player));
  if(!player->FirstName || !player->LastName )
  {
    return NULL;
  }
  return player;
}

void DestroyPlayer(Player* _player)
{
  if(!_player->FirstName || !_player->LastName )
  {
    return;
  }
  free(_player);
}

void UpdatePlayer(Player* _player,char _firstName[],char _lastName[])
{
  if(!_player)
  {
    return;
  }
  memcpy(_player->FirstName,_firstName,25);
  memcpy(_player->LastName,_lastName,25);
}

void PlayerDisplay(Player* _player,int i)
{
  printf(CYAN"Player %d First name %s\n",i, _player->FirstName);
  printf(CYAN"Player %d Last name %s\n"NORMAL,i, _player->LastName);
}

char* GetFirstName(Player* _player)
{
  return _player->FirstName;
}

char* GetLastName(Player* _player)
{
  return _player->LastName;
}

void Winner_Announcement(Player* _player, int _playerNumber)
{
  printf(BLUE"---PLAYER %d - %s %s ---\nYOU HAVE ACCOMPLISHED 4 IN A ROW\n SO YOU ARE THE\n" BOLD_ON RED BLINK"-----WINNER-----\n"NORMAL BOLD_OFF,_playerNumber, _player->FirstName,_player->LastName);
}
