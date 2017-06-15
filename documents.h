
void sortDocuments(char * document, char * directory);

void sortPictures(char * picture, char * directory);

void sortOthers(char * file, char * directory);

int isPicture(char * file);

int isDocument(char * file);

int isOther(char * file, char * currentDirPath);