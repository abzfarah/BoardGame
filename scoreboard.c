/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : Abdi Farah
* Student Number   : 543707
* Course Code      : MEC2004
* Program Code     : MSc
***********************************************************************/
#include "scoreboard.h"

/**
 * @param board the scoreboard to initialise
 **/
void init_scoreboard(scoreboard board)
{
	int i;
	for(i=0; i < SCOREBOARDSIZE; i++){
		memset(board[i].name, 0, NAMELEN + 1);
		board[i].thiscolor = C_EMPTY;
		board[i].counters = 0;
		board[i].type = COMPUTER;
	}

}

/** For this requirement, you will need to display the scores in the
 * order they are scored in the scoreboard array.
 *
 * The display should look as follows:
 * Player               |Score
 * ---------------------------------------------
 * Barney               |17
 * Magi                 |15
 * Red                  |10
 * Computer             |8
 * Computer             |7
 * Computer             |6
 * Paul                 |4
 * Fred                 |4
 * Muaddib              |4
 * Zafiqa               |4
 *
 * @param board the scoreboard to display
 **/
void display_scores(const scoreboard board)
{
	printf("%-20s|Score\n", "Player");
	puts("---------------------------------------------");
	int i;
	for(i=0; i < SCOREBOARDSIZE; i++){
		if(board[i].thiscolor != C_EMPTY)
			printf("%-20s|%i\n", board[i].name, board[i].counters);
	}
}

/** When the game ends, you need to return the appropriate game state
 * back to main. You will then need to insert the winner's score
 * sorted in order by the number of counters that they played in the
 * game. You should only store the top ten scores and so when a new score
 * is entered on a full scoreboard, the lowest score simply drops off the
 * bottom of the board.
 *
 * Both scoreboard and score are typedefs (aliases) of other types.
 *
 * Scoreboard is defined as: typedef struct player
 *
 * scoreboard[SCOREBOARDSIZE]; and score is defined as:
 *
 * typedef struct player score;
 *
 * In other words, a scoreboard is an array of struct player of
 * SCOREBOARDSIZE (10) and a score is another name of a player struct.
 * This has been done so we can reuse the type and it simplifies the
 * maintenance of the code.
 *
 * @param board the scoreboard to add the score to @param sc the score
 * to add to the scoreboard
 **/
 BOOLEAN add_to_scoreboard(scoreboard board, const score * sc)
 {
    int i;
    for(i=0; i < SCOREBOARDSIZE; i++){
		if(	(board[i].thiscolor == C_EMPTY) ||
			(board[i].counters < sc->counters))
			break;

	}

	if(i < SCOREBOARDSIZE){	//if score is to be inserted
		memmove(&board[i], &board[i+1], sizeof(score)*(SCOREBOARDSIZE-i-1));	//shift old resulst
		memcpy(&board[i], sc, sizeof(score));	//save new result
		return TRUE;
	}
    return FALSE;
}
