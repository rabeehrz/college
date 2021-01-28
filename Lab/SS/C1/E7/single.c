#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct directory {
    char dirName[10];
    char fileName[10][10];
    int fileCount;
} dir;

int main()
{
    int i, ch;
    char tmp[10];
    dir.fileCount = 0;
    printf("Enter a directory name: ");
    scanf("%s", dir.dirName);

    while (1)
    {
        printf("\nOperations\n\n1.Create File\n2.Delete File\n3.Search in Directory\n4.View Files\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch) {

            case 1:
                printf("Enter the name of the file: ");
                scanf("%s", dir.fileName[dir.fileCount++]);
                break;

            case 2:
                printf("Enter the name of the file: ");
                scanf("%s", tmp);
                for (i = 0; i < dir.fileCount; ++i) {
                    if (strcmp(tmp, dir.fileName[i]) == 0) {                       
                        printf("The File %s is deleted!\n", tmp);                     
                        strcpy(dir.fileName[i], dir.fileName[dir.fileCount - 1]); 
                        dir.fileCount--;
                        break;
                    }
                }
                if (i == dir.fileCount) {
                    printf("404 | File Not Found\n");
                }
                break;

            case 3:
                printf("Enter the name of the file to be searched for: ");
                scanf("%s", tmp);
                for (i = 0; i < dir.fileCount; ++i) {
                    if (strcmp(tmp, dir.fileName[i]) == 0) {
                        printf("File Found!!");
                        break;
                    }
                }
                if (i == dir.fileCount) {
                    printf("404 | File Not Found\n");
                }
                break;

            case 4:
                if (dir.fileCount == 0) {
                    printf("Empty Directory!!\n");
                }
                else {
                    printf("Files:\n");
                    for (i = 0; i < dir.fileCount; ++i)
                    {
                        printf("%s\n", dir.fileName[i]);
                    }
                    printf("Total %d files in directory\n", dir.fileCount);
                }
                break;

            default:
                exit(0);
        }
    }

    return 0;
}