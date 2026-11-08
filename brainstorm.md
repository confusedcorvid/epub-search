# Setup/Use

### Setup
Open your terminal. Navigate to whichever directory you'd like this tool to be in and run the following commands: 
```
git clone git@github.com:confusedcorvid/epub-search.git
cd epub-search
. setup.sh
```
You will be asked if you want to support the browser interface.
- default is `yes`, which will download/install more stuff into a `.env` file
- `no` will not create the `.env` and will delete the browser-interface related code in the directory

<br> 

### To use

#### CLI
The following are all valid executions of this tool. See the Flags section for more details. Run from your `epub-search/searcher` directory.
```
./searcher <flags> <args>               # general format--MUST include target and text to search for!

./searcher <target> <text>              # searches target file trying to match text
./searcher -f <target> -c <text>        # also searches target file trying to match text
./searcher -d <target> -c <text>        # searches target directory trying to match text
./searcher -r <target> -c <text>        # recursively searches target directory trying to match text
```

#### Browser
Run the following from your `epub-search/app` directory.
```
# LINUX/MACOS
. .venv/bin/activate

# WINDOWS/WSL
. .venv/scripts/activate 

python app.py
```
To use the app, open your browser and search for `localhost:5000`. <br>
To quit the app, go back to the terminal running the program and hit `Ctrl-C`. 



# FEATURES
*Note: The following features are listed as though we will complete Phase 2, including the stretch goals. For what is currently implemented, please see the PLANNED PHASES section.*

## Overview

#### Description
A tool that can search various filetypes (notably, `.epub` and `.zip`) in a less inconvenient way than grep. <br>
Simple to use, but capable of more complicated things if you check the flags.

#### Search Modes
The following can be specified by the user to configure the tool's behavior. (See also: the Flags section)
| Specification                       | Default     | Options                                                                       |
|-------------------------------------|-------------|-------------------------------------------------------------------------------|
| search target                       |             | single file, batch (directory of files), recursive batch (directory of files) |
| search field                        | all content | title, author, all content                                                    |
| error handling/caution level        | safe        | unsafe, safe, paranoid                                                        |
| verbosity                           | standard    | quiet, standard, verbose                                                      |
| handle temporary uncompressed files | delete all  | keep all, keep hits, delete all                                               |
| (optional) modify original file     |             | move hits, rename hits, delete hits                                           |

#### Actions: Correct Execution 
Should nothing go wrong with the execution of this tool, the following would happen:
- if the user's file is a supported compressed filetype, it will be copied and uncompressed into a temporary directory
- the script will run whatever search the user specified
- output will be displayed
- if the user selected to extract files, that will be done
- if the user selected to modify the original file, that will be done 
- if the user's file was compressed, the uncompressed copy will be deleted unless you specified otherwise

#### Browser Interface
- flask app that runs on localhost
- the app is solely concerned with the browser interface; on the backend, it re-uses the main script
- users can drag & drop a target file
- there are switches & input forms as necessary for the flags
- outputs and errors are displayed
- users can download the files they extracted/modified if they so wish


## Flags
| Short | Long          | Arguments                                 | Functionality                                                            |
|-------|---------------|-------------------------------------------|--------------------------------------------------------------------------|
| `-q`  | `--quiet`     |                                           | don't print anything except the output unless a fatal error occurs       |
| `-v`  | `--verbose`   |                                           | print everything--good for debugging                                     |
| `-u`  | `--unsafe`    |                                           | ignore basically all errors except fatal ones, then output error log     |
| `-p`  | `--paranoid`  |                                           | cease execution at once upon encountering any minor error                |
| `-s`  | `--save`      |                                           | save extracted files that had a hit                                      |
| `-k`  | `--keep`      |                                           | keep all extracted files                                                 |
| `-f`  | `--file`      | filename                                  | specify target to search (single search)                                 |
| `-d`  | `--dir`       | directory                                 | specify target to search (batch search)                                  |
| `-r`  | `--dirr`      | directory                                 | specify target to search (recursive batch search)                        |
| `-t`  | `--title`     | (snippet of) title                        | try to match title                                                       |
| `-a`  | `--author`    | (snippet of) author's username            | try to match author                                                      |
| `-c`  | `--content`   | (snippet of) content                      | try to match text                                                        |
| `-g`  | `--tags`      | text in the form of Ao3 tags              | in case the file was downloaded from Ao3, search the tags                |
| `-e`  | `--extension` | file extension                            | specify a file extension that targets must have                          |
| `-m`  | `--match`     | number [1-5] for fuzzy matching certainty | decide how "fuzzy" a match can be before it's not included in the output |
|       | `--move`      | new filename                              | extract and move files with a hit, modify original file                  |
|       | `--rename`    | new filename/regular expression           | extract and rename files with a hit, modify original file                |
|       | `--delete`    |                                           | delete files with a hit, modify original file                            |

# DEPENDENCIES
- we will likely need something here for fuzzy string matching (phase one)
- we will likely need something here for the web interface (phase two)



# DIRECTORY STRUCTURE

## Core/Commandline
```
.
|-----------README.md
|-----------searcher
|-----------searcher_src/
|           |-----------code
|           |           |-----------errors.c
|           |           |-----------files.c
|           |           |-----------helpers.c
|           |           |-----------io.c
|           |           |-----------main.c
|           |           |-----------search.c
|           |-----------makefile
|-----------setup.sh
(.h files not shown)
```

## Browser Interface 
```
...
|-----------app/
|           |-----------.venv
|           |-----------app.py
|           |-----------requirements.txt
|           |-----------templates
|                       |-----------searcher.html
...
(rest of directory not shown, see above)
```


# PLANNED PHASES

*Complete:*

---
*Current:*

## PHASE 0

### Summary: Generic EPUB Searching
- add a flag parser that recognizes most of the generic flags we need to search the `.epub` well
- check the target's filetype by looking at the extension. `.epub` support only (for this phase)
- support single search, batch search, and recursive batch search (as outline above)
- let the user control what happens to the extracted files: keep hits, keep all, or delete all by default
- add an error handler to handle generic/predictable errors

### Table of Features:
| Change | Feature            | Functionality                                                                                                                                                                                                                                                                                                                                             | Status      |
|--------|--------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------|
| NEW    | argument parsing   | - parse all flags <br> - flag order does not matter <br>  - exit with error if flags unrecognized                                                                                                                                                                                                                                                         | IN PROGRESS |
| NEW    | flags              | - -q, --quiet <br> - -v, --verbose <br> - -u, --unsafe <br> - -p, --paranoid <br> - -s, --save <br> - -k, --keep <br> - -f, --file {file} <br> - -d, --dir {directory} <br> - -r, --dirr {directory} <br> - -t, --title {text} <br> - -a, --author {text} <br> - -c, --content {text}																	  | IN PROGRESS |
| NEW    | filetype detection | - checks file extension                                                                                                                                                                                                                                                                                                                                   | IN PROGRESS |
| NEW    | supported files    | - `.epub`                                                                                                                                                                                                                                                                                                                                                 | IN PROGRESS |
| NEW    | batch search       | - unzip (copy of) target into temporary directory <br> - search all files in target <br> - return names of files with a hit <br> - delete temporary directory                                                                                                                                                                                             | NOT STARTED |
| NEW    | single search      | - unzip (copy of) target into temporary directory <br> - search file for all hits <br> - return all hits plus some surrounding text, location in file <br> - delete temporary directory                                                                                                                                                                   | NOT STARTED |
| NEW    | file extraction    | - default: delete temporarily extracted files after search <br> - if enabled: keep all files with a hit <br> - if enabled: keep all extracted files                                                                                                                                                                                                       | NOT STARTED |
| NEW    | handled errors     | - flag not recognized <br> - file not found <br> - file format not supported (based on extention) <br> - could not unzip                                                                                                                                    																							  | IN PRORESS  |

---
*Future:*

## PHASE 1

### Summary: Improved Search Features
- support more filetypes (specifics in table)
- verify a file's type by checking both the extension AND the file header
- use fuzzy string matching for search, rate results based on likelyhood
- add flag to determine how "fuzzy" matches can be before they are not displayed in the output
- add flag to limit targets to files with a specific extension
- add flags to specify how files containing hits might be extracted and moved, extracted and renamed, or deleted, updating the original file in the process
- update error checking to check for errors associated with creating, modifying, and deleting files
- allow users to combine text matches for certain fields (title, author, content, filetype, file, directory) with logical operators (&, \| (precedence), ~, ())

### Table of Features:
| Change  | Feature            | Functionality                                                                                                                                                                                                                                                                                                                                                                                                                 										| Status      |
|---------|--------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------|
| UPDATED | argument parsing   | *- parse all flags <br> - flag order does not matter <br>  - exit with error if flags unrecognized* <br> - for certain flags, multiple inputs can be considered with &, \| (precedence), ~, ()                                                                                                                                                                                                                                										| NOT STARTED |
| UPDATED | flags              | *- -q, --quiet <br> - -v, --verbose <br> - -u, --unsafe <br> - -p, --paranoid <br> - -s, --save <br> - -k, --keep <br> - -f, --file {file} <br> - -d, --dir {directory} <br> - -r, --dirr {directory} <br> - -t, --title {text} <br> - -a, --author {text} <br> - -c, --content {text}* <br>  - -g, --tags {text} <br> - -e, --extension {file_extension} <br> - -m, --match {[1-5]} <br> - --move {location} <br> - --rename {reg_exp} <br> - --delete	  		| NOT STARTED |
| UPDATED | filetype detection | *- checks file extension* <br> - checks against header of file                                                                                                                                                                                                                                                                                                                                                                										| NOT STARTED |
| UPDATED | supported files    | - *`.epub`* <br> - `.txt` <br> - `.md` <br> - `.rtf` <br> - `.docx` <br> - `.pdf` <br> - `.mobi`                                                                                                                                                                                                                                                                                                                                          							| NOT STARTED |
| UPDATED | batch search       | *- unzip (copy of) target into temporary directory <br> - search all files in target <br> - return names of files with a hit <br> - delete temporary directory* <br> - use fuzzy string matching                                                                                                                                                                                                                              										| NOT STARTED |
| UPDATED | single search      | *- unzip (copy of) target into temporary directory <br> - search file for all hits <br> - return all hits plus some surrounding text, location in file <br> - delete temporary directory* <br> - use fuzzy string matching                                                                                                                                                                                                    										| NOT STARTED |
|         | *file extraction*  | *- default: delete temporarily extracted files after search <br> - if enabled: keep all files with a hit <br> - if enabled: keep all extracted files*                                                                                                                                                                                                                                                                         										|             |
| NEW     | file modification  | - extract and move all files with hits to a new location (overwrite original file) <br> - extract and rename all files with a hit (overwrite original file) <br> - delete all files with a hit (overwrite original file)                                                                                                                                                                                                     										| NOT STARTED |
| UPDATED | handled errors     | *- flag not recognized <br> - file not found* <br> - file format not supported (based on extention AND header) <br> *- could not unzip* <br> - could not create file <br> - could not overwrite file <br> - could not delete file                                                                                                                                                                                             										| NOT STARTED |


## PHASE 2

### Summary: Web Integration & Other Stretch Goals
- make a whole Flask app to do All Of The Above, But From The Browser This Time
- this will run on localhost
- allow users to drag & drop a target file
- provide switches & input forms as necessary for the flags
- display both outputs and errors on the website
- offer the user the option to download the extracted files and/or just the files with hits
- if the user chose and option that modified the target file, give the option to download the modified file

### Table of Features:
| Change | Feature              | Functionality                                                                                                                                                                                                                                                                                                                                                                                                               										| Status      |
|--------|----------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------|
|        | *argument parsing*   | *- parse all flags <br> - flag order does not matter <br>  - exit with error if flags unrecognized <br> - for certain flags, multiple inputs can be considered with &, \| (precedence), ~, ()*                                                                                                                                                                                                                               										|             |
| UPDATED | supported files    | - *`.epub` <br> - `.txt` <br> - `.md` <br> - `.rtf` <br> - `.docx` <br> - `.pdf` <br> - `.mobi`*                                                                                                                                                                                                                                                                                                                                          							|             |
|        | *filetype detection* | *- checks file extension <br> - checks against header of file*                                                                                                                                                                                                                                                                                                                                                               										|             |
|        | *supported files*    | - *`.epub` <br> - .txt <br> - .md <br> - .rtf <br> - .docx <br> - .pdf <br> - .mobi*                                                                                                                                                                                                                                                                                                                                         										|             |
|        | *batch search*       | *- unzip (copy of) target into temporary directory <br> - search all files in target <br> - return names of files with a hit <br> - delete temporary directory <br> - use fuzzy string matching*                                                                                                                                                                                                                             										|             |
|        | *single search*      | *- unzip (copy of) target into temporary directory <br> - search file for all hits <br> - return all hits plus some surrounding text, location in file <br> - delete temporary directory <br> - use fuzzy string matching*                                                                                                                                                                                                   										|             |
|        | *file extraction*    | *- default: delete temporarily extracted files after search <br> - if enabled: keep all files with a hit <br> - if enabled: keep all extracted files*                                                                                                                                                                                                                                                                        										|             |
|        | *file modification*  | *- extract and move all files with hits to a new location (overwrite original file) <br> - extract and rename all files with a hit (overwrite original file) <br> - delete all files with a hit (overwrite original file)*                                                                                                                                                                                                   										|             |
|        | *handled errors*     | *- flag not recognized <br> - file not found <br> - file format not supported (based on extention AND header) <br> - could not unzip <br> - could not create file <br> - could not overwrite file <br> - could not delete file*                                                                                                                                                                                              										|             |
| NEW    | Web Interface        | - flask app running on localhost <br> - drag & drop target file <br> - output displayed on web <br> - option to download files <br> - option to modify target file and download new version <br> - switches/fields for flags listed above where appropriate                                                                                                                                                                   									| NOT STARTED |