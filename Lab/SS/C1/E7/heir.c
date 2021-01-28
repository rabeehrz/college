#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct directory {
  char name[24];
  struct directory* subdirs[50];
  struct directory* parent;
  char files[50][24];
  int subdir_count;
  int file_count;
} dir;

int main() {
  int option, i, k;
  dir* head;
  dir* current;
  head = (dir*) malloc(sizeof(dir));
  strcpy(head->name, "Root");
  head->parent=NULL;
  head->subdir_count=0;
  head->file_count=0;
  current=head;
  do {
    printf("\nCurrent Dir: %s\n", current->name);
    printf("\nChoose an option: \n0.Exit\n1.Create a Subdir\n2.Create a File\n3.Change dir\n4.List contents\n5.Go back\n\nEnter your choice:");
    scanf("%d", &option);
    switch (option) {
      case 0:
        exit(0);
        break;
      case 1:
        printf("\nEnter the name of Subdir: ");
        dir* new = malloc(sizeof(dir));
        scanf("%s", new->name);
        new->parent=current;
        new->subdir_count=0;
        new->file_count=0;
        current->subdir_count++;
        current->subdirs[current->subdir_count] = new;
        printf("New Dir created.\n");
        break;
      case 2:
        printf("\nEnter the name of File: ");
        scanf("%s", current->files[++(current->file_count)]);
        printf("New file created.\n");
        break;
      case 3:
        for(i = 1; i <= current->subdir_count; i++) {
          printf("\n%d. %s", i, current->subdirs[i]->name);
        }
        printf("\nChoose an option:\n");
        scanf("%d", &k);
        current=current->subdirs[k];
        break;
      case 4:
        printf("\nSubDirs:\n");
        for(i = 1; i <= current->subdir_count; i++) {
          printf("%s\n", current->subdirs[i]->name);
        }
        printf("\nFiles:\n");
        
        for(i = 0; i <= current->file_count; i++) {
          printf("%s\n", current->files[i]);
        }
        break;
      case 5:
        if(current->parent == NULL) {
          printf("\nAlready at Root!\n");
        } else {
          current = current->parent;
        }
        break;
      default:
        break;
    }
  } while(option);
}