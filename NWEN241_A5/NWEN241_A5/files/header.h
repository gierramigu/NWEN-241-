#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 12344
#define DEFAULT_STRLEN 2000

struct movie{
	char title[64];
	char director[64];
	int year; 
	int oscar; 
	char country[64];
};

typedef struct movie mov; //user defined type 
mov *movies;

int loadFile (const char *in); //for reading the file