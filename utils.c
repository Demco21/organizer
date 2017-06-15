#include "libraries.h"
#include "constants.h"

/* print error message to stderr */
void printError(char * errorMsg)
{
  fprintf(stderr, errorMsg);
  fflush(stderr);
  exit(1);
}


/* print error message using perror */
void printPerror(char * errorMsg)
{
  perror(errorMsg);
  fflush(stderr);
  exit(1);
}


/* reverse the order of characters in a string */
void reverseString(char * string)
{
  int i = 0;
  int j = strlen(string) - 1;
  char temp;
  
  while(i < j)
  {
    temp = string[i];
    string[i] = string[j];
    string[j] = temp;
    i++;
    j--;
  }
}


/* Returns the extension of a file */
char * getExtension(char * filename)
{
  int filenameLen = strlen(filename);
  char * extension = malloc(filenameLen);
  int i = 0;
  int j = 0;
  
  /* Start from the end of the string an read backwards until a period is reached */
  for(i = filenameLen - 1; i >= 0; i--)
  {
    j = (filenameLen - 1) - i;
    extension[j] = filename[i];

    if(filename[i] == '.')
    {
      extension[++j] = '\0';
      break;
    }
  }

  reverseString(extension);
  return extension;
}


/* Returns the number of string tokens with delimiter '-' using the file as the string */
int tokenCount(char * file)
{
  char hyphen = '-';
  int numTokens = 1;
  int i = 0;
  
  for(i = 0; i < strlen(file); i++)
  {
    if(file[i] == hyphen)
      numTokens++;
  }
  
  return numTokens;
}


/* Returns an array of string tokens using '-' as the delimitor */
char ** hyphenTokenizer(char string[])
{

  int numTokens = tokenCount(string);
  char ** strTokens = malloc(numTokens*sizeof(char *));
  char * delim = "-";
  char newString[MAX_LEN];
  int i = 0;
  
  /* Make a copy of the string */
  for(i = 0; i < strlen(string); i++)
    newString[i] = string[i];
    
  newString[i] = '\0';

  char * token = strtok(newString, delim);
  strTokens[0] = token;

  i = 1;
  /* fill strTokens[] with each token */
  while((token = strtok(NULL, delim)) != NULL)
  {
    strTokens[i] = token;
    i++;
  }
  
  return strTokens;
}


/* Concatenate two strings with a '-' between them */
char * hyphenConcat(char * str1, char * str2)
{
  int str1Len = strlen(str1);
  int str2Len = strlen(str2);
  char hyphen[2] = "-";
  char * newStr = malloc(str1Len + str2Len + 1);
  int i;
  
  strcat(newStr, str1);
  strcat(newStr, hyphen);
  strcat(newStr, str2);

  return newStr;
}


/* opens a directory, prints error if it doesn't exist */
DIR* openDirectory(char * targetDirectory)
{
  DIR* dirptr;
  
  if ((dirptr = opendir(targetDirectory)) == NULL)
    printPerror("ERROR: directory could not be opened.\n");
  
  return dirptr;
}


/* This function will append onto oldPath a '/' followed by the contents of newDirectory */
char * modifyPath(char * oldPath, char * newDirectory)
{
  char * newPath;
  char slash[2] = "/";
  
  if(strlen(oldPath) < 1 || strlen(newDirectory) < 1)
  {
    printError("ERROR: Cannot pass an empty string into the parameters of getPath()\n");
  }
  else
  {
    newPath = malloc(1 + strlen(oldPath) + strlen(newDirectory));
    
    strcat(newPath, oldPath);
    
    if(oldPath[strlen(oldPath)] != '/')
      strcat(newPath, slash);
      
    strcat(newPath, newDirectory);
  }
  
  return newPath;
}



/* Get the current working directory */
char * getCWD ()
{
  char cwd[MAX_LEN];
  char * currentDir = malloc(256);
  
  if (getcwd(cwd, sizeof(cwd)) != NULL)
  {
    strcpy(currentDir, cwd);
    return currentDir;
  }
  else
  {
    printPerror("ERROR: failed to return cwd path.");
  }
}




