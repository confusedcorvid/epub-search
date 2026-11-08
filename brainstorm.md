# LIST OF FEATURES

## Overview

- VERBOSITY: quick, standard (default), verbose
- ERROR RESPONSE: unsafe, safe (default), paranoid
- DELETE UNZIPPED: delete all (default), save hits, keep all
- SEARCH TARGET: single, batch, recursive (no default: must specify)
- SEARCH FIELD: all (default), title, author, content
- MODIFY: none (default), move, rename, delete

## Flags


# TECH STACK & DESIGN

## Core/Commandline

## Web (Stretch Feature)


# PLANNED PHASES AND FEATURES

*Complete:*

---
*Current:*

## PHASE 0

#### Generic EPUB Searching

### Summary:

### Table of Features:
| Change | Feature            | Functionality                                                                                                                                                                                                                                                                                                                                             | Status      |
|--------|--------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------|
| NEW    | Argument Parsing   | - parse all flags <br> - flag order does not matter <br>  - exit with error if flags unrecognized                                                                                                                                                                                                                                                         | IN PROGRESS |
| NEW    | Flags              | - -q, --quick <br> - -v, --verbose <br> - -u, --unsafe <br> - -p, --paranoid <br> - -s, --save <br> - -k, --keep <br> - -f, --file {file} <br> - -d, --dir {directory} <br> - -r, --dirr {directory} <br> - -t, --title {text} <br> - -a, --author {text} <br> - -c, --content {text}																	  | IN PROGRESS |
| NEW    | Filetype Detection | - checks file extension                                                                                                                                                                                                                                                                                                                                   | IN PROGRESS |
| NEW    | Supported Files    | - .epub                                                                                                                                                                                                                                                                                                                                                   | IN PROGRESS |
| NEW    | Batch Search       | - unzip (copy of) target into temporary directory <br> - search all files in target <br> - return names of files with a hit <br> - delete temporary directory                                                                                                                                                                                             | NOT STARTED |
| NEW    | Single Search      | - unzip (copy of) target into temporary directory <br> - search file for all hits <br> - return all hits plus some surrounding text, location in file <br> - delete temporary directory                                                                                                                                                                   | NOT STARTED |
| NEW    | File Extraction    | - default: delete temporarily extracted files after search <br> - if enabled: keep all files with a hit <br> - if enabled: keep all extracted files                                                                                                                                                                                                       | NOT STARTED |
| NEW    | Handled Errors     | - flag not recognized <br> - file not found <br> - file format not supported (based on extention) <br> - could not unzip                                                                                                                                    																							  | IN PRORESS  |

---
*Future:*

## PHASE 1

#### Improved Search Features

### Summary:

### Table of Features:
| Change  | Feature            | Functionality                                                                                                                                                                                                                                                                                                                                                                                                                 | Status      |
|---------|--------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------|
| UPDATED | Argument Parsing   | *- parse all flags <br> - flag order does not matter <br>  - exit with error if flags unrecognized* <br> - for certain flags, multiple inputs can be considered with &, \| (precedence), ~, ()                                                                                                                                                                                                                                | NOT STARTED |
| UPDATED | Flags              | *- -q, --quick <br> - -v, --verbose <br> - -u, --unsafe <br> - -p, --paranoid <br> - -s, --save <br> - -k, --keep <br> - -f, --file {file} <br> - -d, --dir {directory} <br> - -r, --dirr {directory} <br> - -t, --title {text} <br> - -a, --author {text} <br> - -c, --content {text}* <br>  - -g, --tags {text} <br> - -e, --extension {file_extension} <br> - --move {location} <br> - --rename {reg_exp} <br> - --delete | NOT STARTED |
| UPDATED | Filetype Detection | *- checks file extension* <br> - checks against header of file                                                                                                                                                                                                                                                                                                                                                                | NOT STARTED |
| UPDATED | Supported Files    | - *.epub* <br> - .txt <br> - .md <br> - .rtf <br> - .docx <br> - .pdf <br> - .mobi                                                                                                                                                                                                                                                                                                                                            | NOT STARTED |
| UPDATED | Batch Search       | *- unzip (copy of) target into temporary directory <br> - search all files in target <br> - return names of files with a hit <br> - delete temporary directory* <br> - use fuzzy string matching                                                                                                                                                                                                                              | NOT STARTED |
| UPDATED | Single Search      | *- unzip (copy of) target into temporary directory <br> - search file for all hits <br> - return all hits plus some surrounding text, location in file <br> - delete temporary directory* <br> - use fuzzy string matching                                                                                                                                                                                                    | NOT STARTED |
|         | *File Extraction*  | *- default: delete temporarily extracted files after search <br> - if enabled: keep all files with a hit <br> - if enabled: keep all extracted files*                                                                                                                                                                                                                                                                         |             |
| NEW     | File Modification  | - extract and move all files with hits to a new location (overwrite original file) <br> - extract and rename all files with a hit (overwrite original file) <br> - delete all files with a hit (overwrite original file)                                                                                                                                                                                                      | NOT STARTED |
| UPDATED | Handled Errors     | *- flag not recognized <br> - file not found* <br> - file format not supported (based on extention AND header) <br> *- could not unzip* <br> - could not create file <br> - could not overwrite file <br> - could not delete file                                                                                                                                                                                            | NOT STARTED |


## PHASE 2

#### Web Integration & Other Stretch Goals

### Summary:

### Table of Features: