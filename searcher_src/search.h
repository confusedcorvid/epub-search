#ifndef SEARCH_H
	#define SEARCH_H
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
		struct file_hits* find_hits(char* filepath, char* field, char* text, int certainty);
		struct file_hits* directory_hits(char* dir);
		int get_fd(char* filename);
		int match_location(char* haystack, char* needle);
		char* get_context(int fd, int location);
	#endif