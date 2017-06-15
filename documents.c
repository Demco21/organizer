#include "libraries.h"
#include "constants.h"
#include "utils.h"


void sortDocuments(char * document, char * currentDirPath)
{
  char * newDirectoryPath;
  char * oldDirectoryPath;

  /* Append DOCS_DIR onto currentDirPath and store the result into
  newDirectoryPath then call mkdir to create the documents directory. */
  newDirectoryPath = modifyPath(currentDirPath, DOCS_DIR);
  mkdir(newDirectoryPath, DEFAULT_MODE);

  /* Get the original path to file */
  oldDirectoryPath = modifyPath(currentDirPath, document);
  
  /* This path will be the final path for the document file */
  newDirectoryPath = modifyPath(newDirectoryPath, document);

  rename(oldDirectoryPath, newDirectoryPath);
}



void sortPictures(char * picture, char * currentDirPath)
{
  char * newDirectoryPath;
  char * oldDirectoryPath;

  /* Append PICS_DIR onto currentDirPath and store the result into
  newDirectoryPath then call mkdir to create the pictures directory. */
  newDirectoryPath = modifyPath(currentDirPath, PICS_DIR);
  mkdir(newDirectoryPath, DEFAULT_MODE);

  /* Get the original path to file */
  oldDirectoryPath = modifyPath(currentDirPath, picture);
  
  /* This path will be the final path for the document file */
  newDirectoryPath = modifyPath(newDirectoryPath, picture);

  rename(oldDirectoryPath, newDirectoryPath);
}



void sortOthers(char * file, char * currentDirPath)
{
  char * newDirectoryPath;
  char * oldDirectoryPath;

  /* Append OTHERS_DIR onto currentDirPath and store the result into
  newDirectoryPath then call mkdir to create the others directory. */
  newDirectoryPath = modifyPath(currentDirPath, OTHER_DIR);
  mkdir(newDirectoryPath, DEFAULT_MODE);

  /* Get the original path to file */
  oldDirectoryPath = modifyPath(currentDirPath, file);
  
  /* This path will be the final path for the document file */
  newDirectoryPath = modifyPath(newDirectoryPath, file);

  rename(oldDirectoryPath, newDirectoryPath);
}


/* Return 1 if the file matches the required format for a picture file */
int isPicture(char * file)
{
  char * extension = getExtension(file);
  
  if(strcmp(extension, ".png") == 0 || strcmp(extension, ".jpg") == 0)
    return 1;
  else
    return 0;
}


/* Return 1 if the file matches the required format for a document file */
int isDocument(char * file)
{
  char * extension = getExtension(file);
  
  if(strcmp(extension, ".txt") == 0 || strcmp(extension, ".docx") == 0)
    return 1;
  else
    return 0;
}


/* Return 1 if the file is an other file */
int isOther(char * file, char * currentDirPath)
{
  char * extension = getExtension(file);
  char * filepath = modifyPath(currentDirPath, file);
  int boolVal;
  
  /* boolVal will be set to 0 if the file is a directory file and not a regular file */
  struct stat path_stat;
  stat(filepath, &path_stat);
  boolVal = S_ISREG(path_stat.st_mode);
  
  if(strcmp(extension, ".mp3") == 0 || strcmp(extension, ".mkv") == 0 || strcmp(extension, ".png") == 0 || strcmp(extension, ".jpg") == 0
   || strcmp(extension, ".txt") == 0 || strcmp(extension, ".docx") == 0)
    return 0;
    
  if(strcmp(extension, ".c") == 0 || strcmp(extension, ".o") == 0 || strcmp(extension, ".h") == 0 || strcmp(file, "makefile") == 0
   || strcmp(file, "organizer") == 0 || strcmp(file, "core") == 0 || strcmp(file, ".") == 0 || strcmp(file, "..") == 0 || boolVal == 0)
    return 0;
    
  else
    return 1;
}




