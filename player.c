/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Course Code      : EDIT HERE
* Program Code     : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/
#include "player.h"
#include "errno.h"

static color get_rand_color(){
	static color taken_color = C_EMPTY;

	switch(taken_color){
		case C_WHITE:
			taken_color = C_RED;
			break;

		case C_RED:
			taken_color = C_WHITE;
			break;

		case C_EMPTY:
		default:
			taken_color = (rand() > 100) ? C_RED : C_WHITE;
			break;
	}
	return taken_color;
}

/**
 * @param human the human player to initialise
 **/
enum input_result get_human_player(struct player* human)
{
    /* placeholder return value. You should prompt the user
     * for their name and then initialise all other values in the
     * player struct to sensible values.
     */
	puts("Enter your name:");
    if(fgets(human->name, NAMELEN, stdin) == NULL)	//get user input
		return feof(stdin) ? RTM : FAILURE;

	int len = strlen(human->name);
	if(len == 1)	return RTM;	//enter on a newline
	human->name[len-1] = '\0';

    //read_rest_of_line();
    human->thiscolor = get_rand_color();
	human->counters = 0;
	human->type = HUMAN;

    return SUCCESS;
}

/**
 * @param computer the computer player to initialise
 **/
enum input_result get_computer_player(struct player * computer)
{
    /* initialise all variables that are part of the struct to sensible
     * values */
    strncpy(computer->name, "Computer", NAMELEN);
	computer->thiscolor = get_rand_color();
	computer->counters = 0;
	computer->type = COMPUTER;

    return SUCCESS;
}

void take_turn_computer(struct player * comp, enum cell_contents board[BOARDHEIGHT][BOARDWIDTH]){
	int i,k;
	for(k=0; k < BOARDWIDTH; k++){
		int j = rand() % BOARDWIDTH;	//select column at random
		for(i=BOARDHEIGHT-1; i >=0 ; i--){	//find first free cell at this column
			if(board[i][j] == C_EMPTY){
				board[i][j] = comp->thiscolor;	//set cell with player color
				return;
			}
		}
	}
}

enum input_result take_turn_human(struct player * human, enum cell_contents board[BOARDHEIGHT][BOARDWIDTH]){
	char buf[100];
	while(1){
		printf("Please enter a column in which to drop a token:");
		if(fgets(buf, sizeof(buf), stdin) == NULL){	//get user input
			return feof(stdin) ? RTM : FAILURE;
		}

		if(strlen(buf) == 0)	return RTM;	//enter on a newline

		//valudate
		int j = strtol(buf, NULL, 10);
		if((j == EINVAL) || (j == ERANGE)){
			perror("strtol");
		}

		if((j <= 0) || ( j >= BOARDWIDTH)){
			fprintf(stderr, "Error: Column is out of range [1:%i]\n", BOARDWIDTH);
		}
		int i;
		for(i=BOARDHEIGHT-1; i >=0 ; i--){	//find first free cell at this column
			if(board[i][j-1] == C_EMPTY){
				board[i][j-1] = human->thiscolor;	//set cell with player color
				return SUCCESS;
			}
		}
		fprintf(stderr, "Error: Column %i has no empty cells\n", j);
	}

	return FAILURE;
}

/**
 * In this requirement, you need to handle the taking of a turn - either
 * of a human or a computer player.
 *
 * For the human player, you will need to allow the user to enter the
 * column they wish to place a token in. You will need to validate what
 * the user enters, then place a token correctly in that column so that
 * it occupies the cell closest to the bottom of the board array for that
 * column.
 *
 * For the computer player, you will need to randomly generate a column
 * number to place a token in and if that column is full, generate a
 * different column number until a column number with some free space has
 * been found.
 *
 * @param current the current player
 * @param board the game board that we will attempt to insert a token into
 * @return enum @ref input_result indicating the state of user input (in
 * case this run involved user input
 **/
enum input_result take_turn(struct player * current,
        enum cell_contents board[BOARDHEIGHT][BOARDWIDTH])
{
    /*
     * Default return value - delete this comment and the return
     * value and replace it with appropriate logic to handle either
     * a human or computer turn including handling any input errors.
     */
	if(		current->type == HUMAN)		return take_turn_human(current, board);
	else if(current->type == COMPUTER)		   take_turn_computer(current, board);

    return SUCCESS;
}
