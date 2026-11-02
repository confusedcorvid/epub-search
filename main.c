//mandatories and basics
#include <stdio.h>
#include <string.h>
//opening and extracting .epub contents
#include <zip.h>
//parsing .xml in epub
//#include <libxml/parser.h>
//#include <libxml/tree.h>

//include <libjson-c-dev.h> //To handle and structure the extracted book metadata


void flaghandler(int returnArray[], int argc, char * argv[], char * flags[], int NUM_FLAGS){ //this handles flag checking without if/else
  int flagArray[NUM_FLAGS];
  for (int e = 1; e < argc; e++){ //check all argvs after program name
    for (size_t i = 0; i < NUM_FLAGS; i++) { //runs through all flags
      if (strcmp(argv[e], flags[i]) == 0){ //if argv[argCounter] matches a flag
        returnArray[i] = 1; //flag up
      }
    }
  }
}

int main (int argc, char * argv[]){
  //////////////////////////////////////////////////////
  //header
  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("\t\tSEARCHER\n  A TOOL FOR THE FRUSTRATED AND CONFUSED");
  printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Copyright 0, 2026, by Lucia Mercone.\n");
  printf("\n~~~\n");
  printf("This tool is created to help those over frustrated by the \nineptitude of grep when it comes to file formats such as \n.epub.\n");
  printf("Run 'zip_searcher help' for further functionality.\n\n");
  printf("Running program...\n\n\n");
  //////////////////////////////////////////////////////
  //Setup
  #define NUM_FLAGS 5
  #define NUM_FT 5

  char * flags[NUM_FLAGS] = {
    "--debug", //debug
    "--dir", //directory scan exclusive
    "-dirr", //directory scan recursive
    "--file", //single file
    "--quick" //skip all confirm messages/checks
  };

  char * filetypes[NUM_FT] = {
    ".txt",
    ".md",
    ".epub",
    ".mobi",
    ".pdf"
  };

  //////////////////////////////////////////////////////
  /// Insufficient Arg Handling
  if (argc == 1){
    printf("ERROR! No file provided.\n");
    printf("\nExiting.\n");
    return 0;
  }

  if (argc == 2 && (strcmp(argv[1], "help") == 0)){
    printf("Usage:");
    printf("\t searcher [FILE] [FLAGS]");
    printf("\n\nExiting.\n");
    return 0;
  }

  if (argc == 2){
    printf("ERROR! Insufficient arguments (target file, mode) provided.\n");
    printf("Exiting.\n");
    return 0;
  }

  //check if file works and what type
  int FileTypeFound = -1;

  for (int i = 0; i < NUM_FT; i++) {
    if (strstr(argv[1], filetypes[i]) != 0){
      FileTypeFound = i;
      break;
    }
  }

  if (FileTypeFound == -1){
    printf("ERROR! Filetype unsupported.\n");
    printf("Exiting.\n");
    return -1;
  }


  //Flag handling
  int flagArray[NUM_FLAGS] = {0};
  flaghandler(flagArray, argc, argv, flags, NUM_FLAGS);

  //DEBUG PRINTOUT
  if (flagArray[0] == 1){ 
    printf("DEBUG Flagarray: ");
    for (size_t i = 0; i < NUM_FLAGS; i++) {
      printf("%d ", flagArray[i]);
    }
    printf("\n");
  }

//check for incompatible flags and exit here if necessary

//add . checker
//

  //debug and quick cancel out
  if (flagArray[4] == 1 && flagArray[0] == 1){
    printf("ERROR! --debug and --quick are incompatible with each other. Please specify one or the other.");
    printf("\nExiting.");
    return -1;
  }

  //ask file/etc
  if (flagArray[4] != 1){
    printf("Program detects a %s format file from filename. Would you like to open it as a %s? (Y/n/exit)\n", filetypes[FileTypeFound], filetypes[FileTypeFound]);
    int typeAccepted = 1;
    while (typeAccepted){
      char buff[8] = {'\0'};
      fgets(buff, 8, stdin);
      char * replace = strchr(buff, '\n');
      if (replace != NULL) {
        *replace = '\0';
      }
      if (strcmp(buff, "exit") == 0){
        printf("Defaulting to %s format.\n", filetypes[FileTypeFound]);
        break;
      }
      if (strcmp(buff, "Y") == 0){
        typeAccepted = 0;
        break;
      }
      if (strcasecmp(buff, "n") == 0){
        printf("Please type the filetype you wish to open as instead:\n");
        int altFileTypeAccepted = 1;
        while (altFileTypeAccepted){
          char altFileType[8] = {'\0'};
          fgets(altFileType, 8, stdin);
          if (flagArray[0] == 1){
            printf("DEBUG altFileType addr = %p\n", (void *)altFileType);
            printf("DEBUG contents pre newline strip = '%s'\n", altFileType);
          }
          char * replace = strchr(altFileType, '\n');
          if (replace != NULL) {
            *replace = '\0';
          }
          int altFileTypeFound = -1;
          for (size_t i = 0; i < NUM_FT; i++) {
            if (strstr(altFileType, filetypes[i]) != 0){
              altFileTypeFound = i;
              altFileTypeAccepted = 0;
              typeAccepted = 0;
              FileTypeFound = altFileTypeFound;
              break;
            }
          }
          if (altFileTypeFound == -1){
            printf("Specified filetype not supported. Please try again, or type 'exit' to resume operation with assumed default %s :\n", filetypes[FileTypeFound]);
          }
        }
      }
      else {
        printf("Please try again.");
      }
    }
    printf("\nProceeding with opening and reading as %s\n", filetypes[FileTypeFound]);

  }

  //FILE * plaintext = openFile ("frequencies/ENGLISH.txt");

  return 0;
}
