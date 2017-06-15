#include "libraries.h"
#include "constants.h"
#include "utils.h"


void sortMovies(char * file, char * currentDirPath)
{
  char year[MAX_LEN];
  char name[MAX_LEN];
  char ** tokens = hyphenTokenizer(file);
  char * newDirectoryPath;
  char * oldDirectoryPath;
  
  strcpy(year, tokens[0]);
  strcpy(name, tokens[1]);
  
  /* Append MOVIES_DIR onto currentDirPath and store the result into 
  newDirectoryPath then call mkdir to create the movies directory.
  Continue this appending process onto newDirectoryPath for year
  and name to make all the required subdirectories. */
  newDirectoryPath = modifyPath(currentDirPath, MOVIES_DIR);
  mkdir(newDirectoryPath, DEFAULT_MODE);
  
  newDirectoryPath = modifyPath(newDirectoryPath, year);
  mkdir(newDirectoryPath, DEFAULT_MODE);
  
  /* Get the original path to file */
  oldDirectoryPath = modifyPath(currentDirPath, file);
  
  /* This path will be the final path for the movie file */
  newDirectoryPath = modifyPath(newDirectoryPath, name);
  
  rename(oldDirectoryPath, newDirectoryPath);
}



void sortShows(char * file, char * currentDirPath)
{
  char show[MAX_LEN];
  char season[MAX_LEN];
  char episode[MAX_LEN];
  char title[MAX_LEN];
  char ** tokens = hyphenTokenizer(file);
  char * newDirectoryPath;
  char * oldDirectoryPath;
  
  strcpy(show, tokens[0]);
  strcpy(season, tokens[1]);
  strcpy(episode, tokens[2]);
  strcpy(title, tokens[3]);
  
  /* Append SHOWS_DIR onto currentDirPath and store the result into 
  newDirectoryPath then call mkdir to create the shows directory.
  Continue this appending process onto newDirectoryPath for season,
  episode, and title to make all the required subdirectories. */
  newDirectoryPath = modifyPath(currentDirPath, SHOWS_DIR);
  mkdir(newDirectoryPath, DEFAULT_MODE);
  
  newDirectoryPath = modifyPath(newDirectoryPath, show);
  mkdir(newDirectoryPath, DEFAULT_MODE);
  
  newDirectoryPath = modifyPath(newDirectoryPath, season);
  mkdir(newDirectoryPath, DEFAULT_MODE);
  
  /* Get the original path to file */
  oldDirectoryPath = modifyPath(currentDirPath, file);
  
  /* This path will be the final path for the movie file */
  newDirectoryPath = modifyPath(newDirectoryPath, hyphenConcat(episode, title));
  
  rename(oldDirectoryPath, newDirectoryPath);
}


/* Return 1 if the file matches the required format for a movie file */
int isMovie(char * file)
{
  char movieExt[5] = ".mkv";
  char * extension = getExtension(file);
  int numTokens = tokenCount(file);
  
  if(numTokens == NUM_MOVIE_TOKENS && strcmp(extension, movieExt) == 0)
    return 1;
  else
    return 0;
}



/* Return 1 if the file matches the required format for a show file */
int isShow(char * file)
{
  char * extension = getExtension(file);
  int numTokens = tokenCount(file);
  
  if(numTokens == NUM_SHOW_TOKENS && strcmp(extension, ".mkv") == 0)
    return 1;
  else
    return 0;
}

