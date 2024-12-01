#include "../include/fileManager.h"

int readTextFile(char *fileName, void (*func)(void *, void *), void *param)
{
    char line[100];
    FILE *fp = fopen(fileName, "rt");

    if(!fp)
        return -1;

    while(fgets(line, sizeof(line), fp))
    {
        func(line, param);
    }

    fclose(fp);
    return 0;
}
