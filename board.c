/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : Abdi Farah
* Student Number   : 543707
* Course Code      : MEC2004
* Program Code     : MSc
***********************************************************************/
#include "board.h"
#include "player.h"

/**
 * @file board.c contains implementations of functions related to the game
 * board.
 **/

/**
 * @param board the board to reset the contents of
 **/
void initialise_board(enum cell_contents board[BOARDHEIGHT][BOARDWIDTH])
{
	int i, j;
	for(i=0; i < BOARDHEIGHT; i++)
		for(j=0; j < BOARDWIDTH; j++)
			board[i][j] = C_EMPTY;
}

/**
 * In this requirement you are required to display the game board.
 * The game board should be displayed as shown on the first page of the
 * assignment specification.
 * @param board the board to display
 **/
void display_board(enum cell_contents board[BOARDHEIGHT][BOARDWIDTH])
{
	puts("This is the state of the board:");
	int i;
	for(i=0; i < BOARDWIDTH; i++)
		printf("%3i|", i+1);
	puts("\n----------------------------");	//7 * 4 -
	for(i=0; i < BOARDHEIGHT; i++){
		int j;
		for(j=0; j < BOARDWIDTH; j++){
			switch(board[i][j]){
				case C_RED:
					printf(" %s |", RED_TOKEN);
					break;
				case C_WHITE:
					printf(" %s |", WHITE_TOKEN);
					break;
				case C_EMPTY:
				default:
					printf("   |");
					break;
			}
		}
		printf("\n");
	}
}


