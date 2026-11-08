#include <stdio.h>			// i/o
#include <stdlib.h>			// dynamic memory
#include <string.h>			// string methods

#include "helpers.h"
#include "search.h"

#include "io.h"


// global variables to be accessed beyond this file
search_modes = (const int**) calloc(NUM_MODES, sizeof(int*));

int logfile_capacity = 2048;
char* logfile = calloc(logfile_capacity, sizeof(char));


/* 	SET_DEFAULTS
	function: 		modify search_modes array to contain default values
	@args: 			none
	@return: 		none
*/
void set_defaults() {
	search_modes[VERBOSITY] = STANDARD;
	search_modes[ERROR_HANDLING] = SAFE;
	search_modes[EXTRACTED_FILES] = DELETE;
	search_modes[FUZZY_ACCURACY] = HIGH;
	// SEARCH_TYPE will be inferred, if not explicitly specified, from args
}


/* 	PARSE_ARGS
	function: 		main function to facilitate validating and parsing arguments, set search_modes array
	@args: 			char** args: pointer to args array
					int argc: number of arguments
	@return: 		struct query*: queries extracted from the argument array; also sets search_modes array
*/
struct query* parse_args(char** args, int argc) {
	// check if there is a target file provided
	// check if text to search is provided 
	// check if the filetype is valid
	// for now, only support searching one main target (file/directory) instead of allowing combinations
	struct query* queries = NULL;
	char* filepath = NULL;
	
	if (queries == NULL)
		print_error("User Input: no files specified, or files have unsupported extension.");
	return NULL;
}


/* 	NEXT_TOKEN
	function: 		get the next token of valid input from the args as a string
	@args: 			char** args_ptr: pointer to args array
					int* cur_ind: location in mem tracking current args index (will be updated by function)
					int argc: number of args
	@return: 		char*: next token as a string, null if no next token
*/
char* next_token(char** args_ptr, int* cur_ind, int argc) {
	if (*cur_ind == argc)
		return NULL;
	(*cur_ind)++;
	return args_ptr[cur_ind-1];
}



/* 	PRINT_WARNING
	function: 		print to screen if there is a warning
	@args: 			char* msg: the warning to print
	@return: 		none
*/
void print_warning(char* msg) {
	char* warning = calloc(128, sizeof(char));
	sprintf(warning, "_YELLOW_WARNING_RESET -> %s\n", msg);
	if (search_modes[ERROR_HANDLING] == UNSAFE)
		print_to_log(warning);
	else 
		printf(warning);
	free(warning);
	warning = NULL;
	if (search_modes[ERROR_HANDLING] == PARANOID) {
		printf("Exiting.\n");
		exit(1);
	}
}

/* 	PRINT_ERROR
	function: 		print to screen if there is an error
	@args: 			char* msg: the error to print
	@return: 		none
*/
void print_error(char* msg) {
	printf("_RED_ERROR_RESET -> %s\nExiting.\n");
	exit(1);
}

/* 	PRINT_HITS
	function: 		print results/hits to the screen at the end of the program
	@args: 			struct file_hits* hits: an array containing all the hits and relevant information
	@return: 		none
*/
void print_hits(struct file_hits* hits) {
	
}


/* 	PRINT_TO_LOG
	function: 		print warnings into a buffer, which will be written into a logfile at the end of the program
	@args: 			char* msg: the warning to print
	@return: 		none
*/
void print_to_log(char* msg) {
	int next_ind = strlen(logfile);
	int needed_size = strlen(msg) + next_ind;
	if (needed_size > logfile_capacity) {
		logfile_capacity *= 2;
		logfile = (char*) realloc(logfile, logfile_capacity);
	}
	strcpy(logfile+next_ind, msg);
}