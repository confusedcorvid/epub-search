#include <errno.h>              // for errno
#include <stdio.h>              // printf
#include <stdlib.h>				// exit
#include <string.h>             // for string methods, strerror

#include "helpers.h"

/* 	STREQ
	function: 		check if two strings are equal; wrapper for strcmp
	@args: 			char* s0: string to compare
					char* s1: string to compare
	@return: 		int: 0 if not equal, non-zero if equal (boolean)
*/
int streq(char* s0, char* s1) {
	return strcmp(s0, s1) == 0;
}

/* 	CHECK_ERR
	function: 		check to see if an action has resulted in an error, and exit if so
	@args: 			int i: result of operation (-1 if error)
					char* message: description of error
					char* file: filename of bad code
					int line: fileline of bad code
	@return: 		none; exits if error
*/
void check_err(int i, char* message, char* file, int line) {
  if (i < 0) {
          printf("Error: %s in file %s, line %d - %s\n", message, file, line, strerror(errno));
    exit(errno);
  }
}