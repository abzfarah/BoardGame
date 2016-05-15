/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : Abdi Farah
* Student Number   : 543707
* Course Code      : MEC2004
* Program Code     : MSc
***********************************************************************/
#include "helpers.h"

/**
 * @file helpers.c contains various functions that help in the
 * implementation of the program. You should put functions you create
 * here unless they logically belong to another module (such as
 * player, board or game
 **/

void read_rest_of_line(void)
{
    int ch;
    while(ch = getc(stdin), ch!=EOF && ch != '\n')
        ; /* gobble each character */
    /* reset the error status of the stream */
    clearerr(stdin);
}


