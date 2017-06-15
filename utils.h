
void printError(char * errorMsg);

void printPerror(char * errorMsg);

void reverseString(char * string);

char * getExtension(char * filename);

int tokenCount(char * file);

char ** hyphenTokenizer(char string[]);

char * hyphenConcat(char * str1, char * str2);

DIR* openDirectory(char * targetDirectory);

char * modifyPath(char * oldPath, char * newDirectory);

char * getCWD();