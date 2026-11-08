#include <errno.h>              // for errno
#include <stdio.h>              // printf
#include <stdlib.h>				// exit
#include <string.h>             // for string methods, strerror

#include <errors.h>


void check_err(int i, char* message, char* file, int line) {
  if (i < 0) {
          printf("Error: %s in file %s, line %d - %s\n", message, file, line, strerror(errno));
    exit(errno);
  }
}