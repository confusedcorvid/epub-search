#ifndef SEARCH_H
	#define SEARCH_H
	
		// struct returned for each text query
		struct query {
			char* filepath;
			char* extension;
			char* text;
			int* search_fields;
		}
		// indices for search_fields array
		#define NUM_FIELDS 4
		#define TITLE 0
		#define AUTHOR 1
		#define CONTENT 2
		#define TAGS 3
		
		struct hit {
			char* field;
			char* context;
			int file_location;
			int file_line;
			int certainty;
		};
		
		struct file_hits {
			char* filepath;
			int num_hits;
			struct hit* hits;
		};
		
		struct file_hits* find_hits(struct* query);						// main method to deal with query
		struct file_hits* search_directory(char* dir, struct* query);	// search a directory (including one inflated from compressed file)
		
		struct file_hits* match_title(char* filepath, char* text);
		struct file_hits* match_author(char* filepath, char* text);
		struct file_hits* match_content(char* filepath, char* text);
		
		int match_location(char* haystack, char* needle);
		char* get_context(int fd, int location);
		
	#endif