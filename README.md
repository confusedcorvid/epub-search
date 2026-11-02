# epub-search

## General Idea
This is intended to be a quick and easy tool to be run in command line to batch search and sort text files. No muss, no fuss, no app-based tagging that goes away when the app does.

## Intended features
- Main feature
  - add-on feature
 
- Batch search: Lists all files in given directory with matches in specified text (title, author, body text). Runs search on the whole file but does not retain searched material, only if that file returned a hit or not.
  - Sort by # of hits
  - Output list of files to text file and exit ('find and list').
  - Add 'paranoid', 'safe', and 'unsafe' modes.
    - Paranoid should stop process the second an error occurs, output an error log and exit.
    - Safe should skip files that produce an error, output error to terminal and continue. Once finished output error log.
    - Unsafe should ignore all errors and finish process. Once finished output error log.
- Single search: Searches a given filename and returns all hits with a section of surrounding text + location + % of the way through file.
  - Add 'display x number of hits', sorta akin to --head.
  - Output all hits to a text file.
- Filetype detection: detect filetype from suffix. Types of files planned: .md, .txt, .rtf, .docx, .pdf, .epub, .mobi. Further may be added.
  - Match/confirm suffix with its header
  - Handle each accordingly by type during batch search
- Batch move/delete/rename: Once searched perform X action on all hits.
