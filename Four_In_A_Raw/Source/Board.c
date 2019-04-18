/** @file Board.c
  *  @brief Board API implementation
  *
  *  @author Yaniv Aharoni
  *
  *  @bug No known bugs.
  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Board.h"

struct Board
{
  char (*Board_storage[7][8]);
};

Board* CreateBoard()
{
  Board* board = NULL;
  board = (Board*)malloc(sizeof(Board));
  memset(board->Board_storage,0,56);
  if(!board->Board_storage)
  {
    return NULL;
  }
  return board;
}

void DestroyBoard(Board* _board)
{
  if(!_board->Board_storage)
	{
		return;
	}
	free(_board);
}

void UpdateBoard(Board* _board,int _row,int _colomn,int _playerNumber)
{
  if(!_board)
  {
    return;
  }
  if(_playerNumber == 1)
  {
    _board->Board_storage[(_row)][_colomn] = "1";
  }
  else if(_playerNumber == 2)
  {
    _board->Board_storage[(_row)][_colomn] = "2";
  }
}

void BoardDisplay(Board* _board)
{
 int i,j;
 if(!_board)
 {
   return;
 }
 for(i = 0 ;i < 6 ; ++i)
 {
  for(j = 0 ; j < 7 ; ++j)
  {
    if(_board->Board_storage[i][j] != 0)
    {
      printf("|%s|",_board->Board_storage[i][j]);
    }
    else
    {
      printf("|0|");
    }
  }
  printf("\n");
 }
}

int CheckIf_Legal(Board* _board,int _colomn)
{
  int row = Define_Row(_board,_colomn);
  if (_board->Board_storage[row][_colomn] != 0 || row < 0)
  {
    printf(RED BLINK"THIS LOCATION IS ILLEGAL PLEASE TRY ANOTHER COLOMN\n"NORMAL);
    return 1;
  }
  return 0;
}

int Define_Row(Board* _board, int _colomn)
{
  int i = 5;
  while(_board->Board_storage[i][_colomn] != 0 && i >= 0)
  {
    --i;
  }
  return (i);
}

int Check_If_We_Have_A_Winner(Board* _board)
{
  int row,colomn;
  /*vertical check*/
  for(row = 5; row >= 3; --row)
  {
    for(colomn = 0 ; colomn < 7 ; ++colomn)
    {
      if((_board->Board_storage[row][colomn] != 0) &&
          (_board->Board_storage[row][colomn] == _board->Board_storage[row - 1][colomn]) &&
          (_board->Board_storage[row][colomn] == _board->Board_storage[row - 2][colomn]) &&
          (_board->Board_storage[row][colomn] == _board->Board_storage[row - 3][colomn]))
      {
        return *_board->Board_storage[row][colomn];
      }
    }
  }

  /*horizontal check*/
  for(row = 5; row >= 0; --row)
  {
    for(colomn = 0 ; colomn < 4 ; ++colomn)
    {
      if((_board->Board_storage[row][colomn] != 0) &&
          (_board->Board_storage[row][colomn] == _board->Board_storage[row][colomn + 1]) &&
          (_board->Board_storage[row][colomn] == _board->Board_storage[row][colomn + 2]) &&
          (_board->Board_storage[row][colomn] == _board->Board_storage[row][colomn + 3]))
      {
        return *_board->Board_storage[row][colomn];
      }
    }
  }

    /*right and up and right and down*/
  for(colomn = 0 ; colomn <= 3 ; ++colomn)
  {
    for(row = 5 ; row >= 3 ; --row)
    {
      if(_board->Board_storage[row][colomn] != 0 &&
          _board->Board_storage[row][colomn] == _board->Board_storage[row - 1][colomn + 1] &&
          _board->Board_storage[row][colomn] == _board->Board_storage[row - 2][colomn + 2] &&
          _board->Board_storage[row][colomn] == _board->Board_storage[row - 3][colomn + 3])
      {
        return *_board->Board_storage[row][colomn];
      }
    }
    for(row = 2 ; row >= 0 ; --row)
    {
      if(_board->Board_storage[row][colomn] != 0 &&
          _board->Board_storage[row][colomn] == _board->Board_storage[row + 1][colomn + 1] &&
          _board->Board_storage[row][colomn] == _board->Board_storage[row + 2][colomn + 2] &&
          _board->Board_storage[row][colomn] == _board->Board_storage[row + 3][colomn + 3])
      {
        return *_board->Board_storage[row][colomn];
      }
    }
  }
return 0;
}
