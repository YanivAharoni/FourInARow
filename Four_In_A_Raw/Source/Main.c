/** @file Main.c
  *  @brief Main program to launch the game
  *
  *  @author Yaniv Aharoni
  *
  *  @bug No known bugs.
  */
#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include "Board.h"
#include "Player.h"

int main()
{
  int indicator;
  Game* game = CreateGame();
  if(game == NULL)
  {
    printf("Game NOT allocated");
  }
  indicator = RunGame(game);
  if(indicator == 1)
  {
    printf("Game NOT allocated");
  }
  return 0;
}
