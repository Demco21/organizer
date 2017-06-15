#include "libraries.h"
#include "utils.h"
#include "videos.h"
#include "music.h"
#include "documents.h"


/* This program will accept a command line argument as follows: organizer (targetDirectory)
   where the target directory is a directory containing numerous files.
   This program will organize these files into subdirectories: music, movies, shows, documents, pictures, other 
   If (targetDirectory) is not entered, this program will run on the current working directory   */
   
/* movie and show files must have extension .mkv and must be formatted as follows:  movies: <year-title.mkv>
                                                                                    shows: <show-season-episode-title.mkv>  */
                                                                                    
/* music files must have extension .mp3 and must be formatted as follows:  <artist-album-song.mp3> */

/* documents must have extension .txt or .docx and need not be formatted
   pictures must have extension .png or .jpg and need not be formatted    */


void main(char argc, char **argv)
{
  if(argc > 2)
  {
    printError("ERROR: Invalid number of command line arguments.\n");
  }

  DIR * dirptr;
  struct dirent * dp;
  char * targetDirectory;

  if(argv[1] != NULL)
    targetDirectory = argv[1];
  else
    targetDirectory = getCWD();  /* Use current working directory if target directory is not provided */

  dirptr = openDirectory(targetDirectory);

  /* Read each file in the directory */
  while ((dp = readdir(dirptr)) != NULL) 
  {
    /* Get the file name and the extension */
    char * file = dp->d_name;
    char * extension = getExtension(file);

    /* Sort the file based on its extension and format */
    if(isMusic(file))
    {
      sortMusic(file, targetDirectory);
    }
    else if(isMovie(file))
    {
      sortMovies(file, targetDirectory);
    }
    else if(isShow(file))
    {
      sortShows(file, targetDirectory);
    }
    else if(isDocument(file))
    {
      sortDocuments(file, targetDirectory);
    }
    else if(isPicture(file))
    {
      sortPictures(file, targetDirectory);
    }
    else if(isOther(file, targetDirectory))
    {
        sortOthers(file, targetDirectory);
    }
  }
  puts("Your files have successfully been organized.");
  closedir(dirptr);                              
}



