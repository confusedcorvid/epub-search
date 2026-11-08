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

### Generic EPUB Searching
| Change | Feature            | Functionality                                                                                                                                                                                                                                                                                                                                                       	|
|--------|--------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| NEW    | Argument Parsing   | - parse all flags <br> - flag order does not matter <br> - exit with error if flags unrecognized																																																																		|
| NEW    | Flags              | - -q, --quick <br> - -v, --verbose <br> - -u, --unsafe <br> - -p, --paranoid <br> - -s, --save <br> - -k, --keep <br> - -f, --file {file} <br> - -d, --dir {directory} <br> - -r, --dirr {directory} <br> - -t, --title {text} <br> - -a, --author {text} <br> - -c, --content {text} <br> - --move {location} <br> - --rename {reg_exp} <br> - --delete				|
| NEW    | Filetype Detection | - checks file extension                                                                                                                                                                                                                                                                                                                                             	|
| NEW    | Supported Files    | - .epub																																																																																									|
| NEW    | Batch Search       | - unzip (copy of) target into temporary directory <br> - search all files in target <br> - return names of files with a hit <br> - delete temporary directory																																																			|
| NEW    | Single Search      | - unzip (copy of) target into temporary directory <br> - search file for all hits <br> - return all hits plus some surrounding text, location in file <br> - delete temporary directory																																													|
| NEW    | File Extraction    | - default: delete temporarily extracted files after search <br> - if enabled: keep all files with a hit <br> - if enabled: keep all extracted files																																																						|
| NEW    | File Modification  | - move all files with hits to a new location (overwrite epub) <br> - rename all files with a hit (overwrite epub) <br> - delete all files with a hit (overwrite epub)																																																	|
| NEW    | Handled Errors     | - flag not recognized <br> - file not found <br> - file format not supported (based on extention) <br> - could not unzip <br> - could not create file <br> - could not overwrite file <br> - could not delete file <br>																																					|

---
*Future:*

## PHASE 1

### Improved Search Features


## PHASE 2

### Ao3-Specific Features


## PHASE 3

### Web Integration & Other Stretch Goals