#include <search.h>

#ifndef IO_H
	#define IO_H
	
		// terminal colors (all are bright + bold)
		#define _RESET_ \033[0m
		#define _RED_ \033[91;1m
		#define _GREEN_ \033[92;1m
		#define _YELLOW_ \033[93;1m
		#define _CYAN_ \033[96;1m
		
		// argument array (to be accessed globally)
		const int** search_modes;
		// indices for modes array 
		#define NUM_MODES 5
		#define VERBOSITY 0
			#define QUIET 0
			#define STANDARD 1
			#define VERBOSE 2
		#define ERROR_HANDLING 1
			#define UNSAFE 0
			#define SAFE 1
			#define PARANOID 2
		#define EXTRACTED_FILES 2
			#define KEEP 0
			#define SAVE 1
			#define DELETE 2
		#define SEARCH_TYPE 3
			#define SINGLE 0
			#define BATCH 1
			#define RECURSIVE 2
		#define FUZZY_ACCURACY 4
			#define LOWEST 1
			#define LOW 2
			#define MEDIUM 3
			#define HIGH 4
			#define EXACT 5
		
		// argument handling
		void parse_args(char** args, char** targets);
		char** next_token(char** arg_pointer);
		
		// printing output
		void print_note(char* msg);
		void print_error(char* msg);
		void print_hits(struct file_hits* hits);
		
	#endif