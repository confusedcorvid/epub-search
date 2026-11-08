#ifndef FILES_H
	#define FILES_H
		char* filetype(char* path);
		char* uncompress(char* filepath);
		char* make_epub(char* directory);
		char* make_zip(char* directory);
		void rm_temp(char* filepath);
		DIR* dir_stream(char* directory);
		char* next_file(DIR* directory);
	#endif