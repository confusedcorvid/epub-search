#include <stdio.h>			// i/o
#include <stdlib.h>			// dynamic memory
#include <string.h>			// string methods

#include "helpers.h"
#include "search.h"

#include "io.h"


// global variables to be accessed beyond this file
search_modes = (const int**) calloc(NUM_MODES, sizeof(int*));


/* 	PARSE_ARGS
	function: 		main function to facilitate validating and parsing arguments, set search_modes array
	@args: 			char** args: pointer to args array
					int argc: number of arguments
	@return: 		struct query*: queries extracted from the argument array; also sets search_modes array
*/
struct query* parse_args(char** args, int argc); {
	return null;
}


/* 	NEXT_TOKEN
	function: 		get the next token of valid input from the args as a string
	@args: 			char** args_ptr: pointer to args array
					int* cur_ind: location in mem tracking current args index (will be updated by function)
					int argc: number of args
	@return: 		char*: next token as a string, null if no next token
*/
char* next_token(char** args_ptr, int* cur_ind, int argc) {
	return null;
}



/* 	PRINT_WARNING
	function: 		print to screen if there is a warning
	@args: 			char* msg: the warning to print
	@return: 		none
*/
void print_warning(char* msg) {
	
}

/* 	PRINT_ERROR
	function: 		print to screen if there is an error
	@args: 			char* msg: the warning to print
	@return: 		none
*/
void print_error(char* msg) {
	
}

/* 	PRINT_HITS
	function: 		print results/hits to the screen at the end of the program
	@args: 			char* msg: the warning to print
	@return: 		none
*/
void print_hits(struct file_hits* hits) {
	
}