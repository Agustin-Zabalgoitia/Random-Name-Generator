#include <stdio.h>
#include <stdlib.h>

#include "../include/fileManager.h"
#include "../include/str.h"
#include "../include/binaryTree.h"
#include "../include/list.h"
#include "../include/utils.h"
#include "../include/nameGenerator.h"

#define DEFAULT_NUMBER_OF_NAMES     25
#define DEFAULT_OUTPUT_FILE_NAME    "rng-names.txt"

void showHelp()
{
    printf("Options:\n");
    printf("\t-n --number\t\tnumber of names to generate\n");
    printf("\t-f --files\t\tpath of the input files\n");
    printf("\t-o --output\t\tpath of the output file\n");
    printf("\t-p --print\t\tprint names to screen\n");
    printf("\t-r --random-lists\tset this option if you want the program to ");
    printf("use a random number of files to generate names\n");
    printf("\t-h --help\t\tshow this message\n");
}

int main(int argc, char *argv[])
{
    unsigned numberOfNames = DEFAULT_NUMBER_OF_NAMES;
    char randomListsFlag = 0;
    char printFlag = 0;
    char *outputFileName = NULL;
    int numberOfFiles = 0;
    LinkedList *listFromFile;

    const char * options[] = {"number","files","output","print"
                              ,"random-lists","help",NULL
                             };
    while(*argv)
    {
        char option = getOptions(++argv, options);

        switch(option)
        {
        case 'n':
            numberOfNames = stringToInteger(*(++argv));
            break;
        case 'f':

            char **counterPointer = ++argv;
            while(*counterPointer && **counterPointer != '-')
            {
                counterPointer++;
                numberOfFiles++;
            }
            listFromFile = (LinkedList *)malloc(
                               sizeof(LinkedList)*(numberOfFiles));
            LinkedList *aux = listFromFile;
            while(*argv && **argv != '-')
            {
                createList(listFromFile);
                loadTextFileToList(*argv++, listFromFile);
                listFromFile++;
            }
            listFromFile = aux;
            argv--;
            break;
        case 'o':
            outputFileName = createString(stringLength(*(++argv)));
            concatenateStrings(*argv, outputFileName);
            break;
        case 'p':
            printFlag = 1;
            break;
        case 'r':
            randomListsFlag = 1;
            break;
        case 'h':
            showHelp();
            return 0;
            break;
        case '?':
            printf("Unknown \"%s\" command, use --help\n", *argv);
        }
    }

    if(numberOfFiles <= 0)
    {
        printf("At least one input file must be provided!\n");
        return -1;
    }

    //Store the lists previously created in a list of lists
    LinkedList srcLists;
    createList(&srcLists);
    while(numberOfFiles-->0)
        addItem(&srcLists, listFromFile++, sizeof(LinkedList*));

    //Generate names and store them in dest
    LinkedList dest;
    createList(&dest);
    generateName(&srcLists, &dest, numberOfNames, randomListsFlag, printFlag);

    //Store the generated names on a text file
    writeListToTextFile(outputFileName ? outputFileName
                        : DEFAULT_OUTPUT_FILE_NAME, &dest);

    return 0;
}
