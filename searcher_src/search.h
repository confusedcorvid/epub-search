#ifndef SEARCH_H
	#define SEARCH_H
		struct hit {
			char* filename;
			char* field;
			char* context;
			int location;
			int line;
			int certainty;
		};
		int find_hits(struct hit** hits_location_ptr, char* filename, char* field, char* text, int certainty);
		int get_fd(char* filename);
		int match_location(char* haystack, char* needle);
		char* get_context(int fd, int location);
	#endif