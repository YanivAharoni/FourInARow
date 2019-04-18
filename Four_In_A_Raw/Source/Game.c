/** @file Game.c
  *  @brief Game API implementation
  *
  *  @author Yaniv Aharoni
  *
  *  @bug No known bugs.
  */

#include <stdio.h>
#include <stdlib.h>
#include "Game.h"

#define NUM_OF_PLAYERS 2

struct Game
{
  Board* m_board;
  Player* m_players[NUM_OF_PLAYERS];

};

Game* CreateGame()
{
	Game* game;
  Board* board;
  char P1_FName[25];
  char P1_LName[25];
  char P2_FName[25];
  char P2_LName[25];
  Player* Player1;
  Player* Player2;
  Player1 = CreatePlayer();
  Player2 = CreatePlayer();
	game = (Game*)malloc(sizeof(Game));
  if(!game)
  {
    return NULL;
  }
  game->m_players[0] = Player1;
  game->m_players[1] = Player2;

  printf("Player 1 please enter your First name\n");
  scanf("%s", P1_FName);
  printf("Player 1 please enter your Last name\n");
  scanf("%s", P1_LName);

  printf("-------------------------------------\n");
  printf("Player 2 please enter your first name\n");
  scanf("%s", P2_FName);
  printf("Player 2 please enter your Last name\n");
  scanf("%s", P2_LName);
  printf(CLEAR_SCREEN"\n");
  UpdatePlayer(game->m_players[0],P1_FName,P1_LName);
  UpdatePlayer(game->m_players[1],P2_FName,P2_LName);

  PlayerDisplay(Player1,1);
  PlayerDisplay(Player2,2);
  board = CreateBoard();
  game->m_board = board;
  BoardDisplay(game->m_board);
  printf("\n");
	return game;
}

void DestroyGame(Game* _game)
{
	int i;
	if(!_game)
	{
		return ;
	}
	for (i=0;i<NUM_OF_PLAYERS;++i)
	{
		free(_game->m_players[i]);
	}
	free(_game);
}

int RunGame(Game* _game)
{
  int i = 0;
  int counter = 0;
  int winner = 0;
  int colomn,row;
	if(!_game)
	{
		return 1;
	}

	while(winner == 0)
	{
    do
    {
      colomn = New_Disc_Location_Colomn(_game->m_players[i]);
    }
    while(CheckIf_Legal(_game->m_board,colomn));
    row =  Define_Row(_game->m_board, colomn);
    UpdateBoard(_game->m_board,row,colomn,i+1);
    printf(CLEAR_SCREEN"\n");
    BoardDisplay(_game->m_board);
    ++counter;
    if(counter >= 7)
    {
      if(counter == 42)
      {
        printf(CYAN"---THE BOARD IS FULL---\n--NO WINNER THIS TIME--\n-------TRY AGAIN-------\n"NORMAL);
        break;
      }
      winner = Check_If_We_Have_A_Winner(_game->m_board);
    }
    if(winner != 0)
    {
      Winner_Announcement(_game->m_players[i],i+1);
      break;
    }
    ++i;
    if(i == 2)
    {
      i = 0;
    }

	}
  DestroyBoard(_game->m_board);
  DestroyGame(_game);
	return 0;
}
