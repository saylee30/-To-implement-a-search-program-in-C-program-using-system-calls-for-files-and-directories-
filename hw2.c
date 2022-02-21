
/* 
Name: Saylee Raut
BlazerId: saylee30
Project #: To implement a search program in C program using system calls for files and 
directories. 
To compile: gcc hw2.c -o hw2 
To run: ./hw2 .
*/
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <dirent.h> 

void file(char* baseP, const int root);
int main (int argc, char **argv) 

{ 
  struct dirent *dirent; 
  DIR *parentDir; 

  if (argc < 2) { 
    printf ("Usage: %s <dirname>\n", argv[0]); 
    exit(-1);
  } 
  parentDir = opendir (argv[1]); 
  if (parentDir == NULL) { 
    printf ("Error opening directory '%s'\n", argv[1]); 
    exit (-1);
  } 
  else
  {
    file(argv[1],0);
  }
}


void file(char *baseP, const int root)
{
    char path[1000];
    struct dirent *dp;
    int i;
    DIR *parentDir = opendir(baseP);

   
    if (!parentDir)
        return;

  while ((dp = readdir(parentDir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            for (i=0; i<root; i++) 
            {
                if (i%2 == 0 || i == 0)
                    printf("%c", 179);
                else
                    printf(" ");

            }

            printf("%c%c%s\n", 195, 196, dp->d_name);

            strcpy(path, baseP);
            strcat(path, "/");
            strcat(path, dp->d_name);
            file(path, root + 2);
        }
    }
    closedir (parentDir);
}
