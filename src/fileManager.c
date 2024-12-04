#include "../include/fileManager.h"

int readTextFile(const char *fileName, void (*func)(void *, void *)
                 , void *param)
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

int writeTextFile(const char *fileName, void (*func)(FILE *, void *)
                  , void *param)
{
    FILE *fp = fopen(fileName, "w");

    if(!fp)
        return -1;

    func(fp, param);
    fclose(fp);

    return 0;
}

int appendTextFile(const char *fileName, void *data, unsigned size)
{
    FILE *fp = fopen(fileName, "a");

    if(!fp)
        return -1;

    fwrite(data, size, 1, fp);
    fclose(fp);

    return 0;
}
