/** @file UI.c
  *  @brief UI API implementation
  *
  *  @author Yaniv Aharoni
  *
  *  @bug No known bugs.
  */

#include <stdio.h>
#include <stdlib.h>
#include "UI.h"

int New_Disc_Location_Colomn(Player* _player)
{
	int colomn;
	int flag = 0;
	if(!_player)
	{
		return -1;
	}
	while(flag != 1)
	{
		
		printf(BLUE "%s\n----PLEASE ENTER YOUR NEW DISC COLOMN----  \n",GetFirstName(_player));
		printf(BLUE"----ENTER COLOMN NUMBER BETWEEN 1 TO 7----\n");
		scanf("%d",&colomn);
		if(0 < colomn && colomn < 8)
		{
			printf(GREEN"YOUR COLOMN SELECTION IS: %d\n"NORMAL,colomn );
			flag = 1;
		}
		else
		{
			printf(RED"WRONG COLOMN NUMBER PLEASE TRY AGAIN\n"NORMAL);
		}
	}
	return colomn-1;
}
