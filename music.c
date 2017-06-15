#include "libraries.h"
#include "constants.h"
#include "utils.h"


void sortMusic(char * file, char * currentDirPath)
{
  char artist[MAX_LEN];
  char album[MAX_LEN];
  char song[MAX_LEN];
  char ** tokens = hyphenTokenizer(file);
  char * newDirectoryPath;
  char * oldDirectoryPath;
  
  strcpy(artist, tokens[0]);
  strcpy(album, tokens[1]);
  strcpy(song, tokens[2]);
  
  /* Append MUSIC_DIR onto currentDirPath and store the result into 
  newDirectoryPath then call mkdir to create the music directory.
  Continue this appending process onto newDirectoryPath for artist, 
  album, and song to make all the required subdirectories. */
  newDirectoryPath = modifyPath(currentDirPath, MUSIC_DIR);
  mkdir(newDirectoryPath, DEFAULT_MODE);
  
  newDirectoryPath = modifyPath(newDirectoryPath, artist);
  mkdir(newDirectoryPath, DEFAULT_MODE);

  newDirectoryPath = modifyPath(newDirectoryPath, album);
  mkdir(newDirectoryPath, DEFAULT_MODE);

  /* Get the original path to file */
  oldDirectoryPath = modifyPath(currentDirPath, file);
  
  /* This path will be the final path for the song file */
  newDirectoryPath = modifyPath(newDirectoryPath, song);

  rename(oldDirectoryPath, newDirectoryPath);
}


/* Return 1 if the file matches the required format for a music file */
int isMusic(char * file)
{
  char musicExt[5] = ".mp3";
  char * extension = getExtension(file);
  int numTokens = tokenCount(file);
  
  if(numTokens == NUM_MUSIC_TOKENS && strcmp(extension, musicExt) == 0)
    return 1;
  else
    return 0;
}