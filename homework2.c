
/* 
Name: Saylee Raut
BlazerId: saylee30
Project #: To implement a search program in C program using system calls for files and 
directories. 
To compile: gcc homework2.c -o homework2 
To run: Unable to compile the program 
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <getopt.h>

void file(char *baseP, const int root);
int main(int argc, char **argv)

{
    int c;
    int recursive = 0;
    int minimum_size;
    int filter;
    extern char *optarg;
    struct dirent *dirent;
    DIR *parentDir;

    if (argc < 2)
    {
        printf("Usage: %s <dirname>\n", argv[0]);
        exit(-1);
    }
    parentDir = opendir(argv[1]);
    if (parentDir == NULL)
    {
        printf("Error opening directory '%s'\n", argv[1]);
        exit(-1);
    }
    else
    {
        file(argv[1], 0);
    }

    while ((c = getopt(argc, argv, "Ss:f:t")) != -1)
    {
        switch (c)
        {
        case 'S':
            printf("Case: S\n");
            printf("option -%c with argument '%s'\n", c, argv[optind]);
            listSizefunction(argv[2]);
            break;
        case 's':
            printf("Case: s\n");
            printf("option -%c with argument '%s'\n", c, optarg);
            getfilesize(baseptr, root);
            break;
        case 'f':
            printf("Case: f\n");
            Dir *dir = ".";
            printf("option -%c with argument '%s'\n", c, optarg);
            const char *string = argv[2];
            if (locateFile(dir, string) == 0)
                printf("File found");
            else
                printf("File not found");

            break;
            case 't':
            printf("Case: t\n");
            printf("option -%c with argument '%s'\n", c, argv[optind]);
            
            break;
        default:
            printf("...");
        }

        int i;
        for (i = optind; i < argc; i++)
        {

            printf(argv[i], recursive, minimum_size, filter);
        }
        if (optind < argc)
        {
            printf("non-option ARGV-elements: ");
            while (optind < argc)
                printf("%s ", argv[optind++]);
            printf("\n");
        }
        return 0;
    }

    int locateFile(Dir * dir, char *string)
    {
        int i = 0;
        j = 0;
        int nTemp = i;
    }

    void listSizefunction(char *baseP, int root)
    {
        FILE *fp;
        char ch;
        int size = 0;

        fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            printf("\nFile unable to open ");
        }

        fseek(fp, 0, 2);
        size = ftell(fp);
        printf("%s\t %d\n", argv[2], size);
        fclose(fp);
    }

    void getfilesize(char *baseP, const int root)
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
                for (i = 0; i < root; i++)
                {
                    if (i % 2 == 0 || i == 0)
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
        closedir(parentDir);
    }
