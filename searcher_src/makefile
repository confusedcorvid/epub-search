.PHONY: clean compile

compile: main.o h_files o_files
	@gcc *.o -o ../searcher
	@rm *.o

h_files: errors.h files.h helpers.h io.h search.h
o_files: errors.o files.o helpers.o io.o search.o

main.o: main.c 
	@gcc -c -Wall main.c
errors.o: errors.c errors.h 
	@gcc -c -Wall errors.c 
files.o: files.c files.h 
	@gcc -c -Wall files.c 
helpers.o: helpers.c helpers.h 
	@gcc -c -Wall helpers.c 
io.o: io.c io.h 
	@gcc -c -Wall io.c 
search.o: search.c search.h 
	@gcc -c -Wall search.c 

clean:
	@rm *.o
	@rm ../searcher