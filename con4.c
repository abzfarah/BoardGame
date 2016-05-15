/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : Abdi Farah
* Student Number   : 543707
* Course Code      : MEC2004
* Program Code     : MSc
***********************************************************************/
#include "con4.h"
#include "errno.h"

/**
 * @mainpage COSC1076 - Assignment 1 documentation.
 *
 * This is the main html documentation of assignment 1 for COSC1076 -
 * Advanced Programming Techniques for semester 2, 2015. You will find
 * here a description of the functions that you need to implement for
 * your assignment.
 *
 * Please note that this should not be your first stop when starting
 * your assignment. Please read the assignment 1 specifications that
 * are available on blackboard before reading this documentation. The
 * purpose of this documentation is to clarify the actual individual
 * requirements.
 *
 * This site presents you with the documentation for each function
 * that you need to implement broken down by the file that they exist
 * in. Please go to the <b>Files</b> tab and click on the file you wish to
 * get more information about and then click on that file. An
 * explanation of each function implemented in that file will be
 * displayed.
 **/

/**
 * @file con4.c contains the main function which is the entry point into the
 * application and manages the main memory.
 **/

/**
 * the entry point into the game. You should display the main menu and
 * respond to user requests.
 *
 * The main menu should look like this:
 * Welcome to connect 4
 *  \n\--------------------
 * 1. Play Game
 * 2. Display High Scores
 * 3. Quit
 * Please enter your choice:
 *
 * This menu should also be redisplayed when the program returns from
 * running an option.
 **/
int main(void)
{




    /* the scoreboard for keeping track of winners */
    scoreboard scores;
    /* the two players and a pointer to who won the last game */
    struct player human_player, computer_player, *winner;

    /* initialise the scoreboard */
    init_scoreboard(scores);
    srand(time(NULL));

    /*display menu and get menu choice until the user chooses to quit */
	int menu_id = 0;
	char buf[10];
    while(menu_id != 3){
		puts("Welcome to connect 4");
		puts("--------------------");
		puts("1. Play Game");
		puts("2. Display High Scores");
		puts("3. Quit");
		puts("Please enter your choice:");

		if(fgets(buf, sizeof(buf), stdin) == NULL)	//get user input
			continue;
		if(strlen(buf) == 0)	continue;	//enter on a newline
		menu_id = strtol(buf, NULL, 10);
		if((menu_id == EINVAL) || (menu_id == ERANGE)){
			perror("strtol");
			continue;
		}
		//read_rest_of_line();

		switch(menu_id){
			case 1:
				/* play a game option */
				winner = play_game(&human_player, &computer_player);

				/* if there was not a draw, add player to the scoreboard in
				* order by number of tokens in play
				*/
				if(winner){
					/* let the user know who won */
					if(winner->type == HUMAN){
						printf("Congratullations %s, you won the game.\n", winner->name);
					}else{
						printf("Better luck next time, computer won.\n");
					}
					add_to_scoreboard(scores, winner);
				}else{
					/* if there was a draw, alert the user to this fact */
					printf("Game is a draw.\n");
				}
				break;

			case 2:	/* display the scoreboard option */
				display_scores(scores);
				break;

			case 3:	/* quit the program option */
				break;
		}
	}
    return EXIT_SUCCESS;
}
