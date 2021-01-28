#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
  char label[24];
  char type[24];
  struct node * next;
} Node;

#define SIZE 4

Node* table[SIZE];

Node* createNode() {
  Node* newNode;
  newNode = (Node*) malloc(sizeof(Node));
  newNode->next = NULL;
  return newNode;
}

void displayTable() {
  int i;
  Node* temp;
  printf("\n");
  for(i = 0; i < SIZE; i++) {
    temp = table[i];
    int k = 0;
    while(temp != NULL) {
      printf("%d %s %s\n", i*10+k,temp->label, temp->type);
      k++;
      temp=temp->next;
    }
  }
}

int findLabel(char label[24]) {
  int index, j=0;
  Node *temp;
  index = strlen(label) % SIZE;
  temp = table[index];
  while(temp!=NULL) {
    if(strcmp(temp->label, label) == 0) {
      return 10*index+j;
    }
    temp = temp->next;
    j++;
  }
  return -1;
}

void lookupTable() {
  char label[24];
  int address;
  printf("\nEnter the label to look: ");
  scanf("%s", label);
  address = findLabel(label);
  if(address == -1) {
    printf("\nNOT FOUND");
  } else {
    printf("\nFOUND\n%d %s", address, label);
  }
}

void insertNode(char label[24], char type[24]) {
  int index;
  Node *temp, *newNode;
  index = strlen(label) % SIZE;
  temp = table[index];
  if(temp==NULL) {
    table[index] = createNode();
    newNode = table[index];
  } else {
    newNode = createNode();
    while(temp->next!=NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
  strcpy(newNode->label, label);
  strcpy(newNode->type, type);
  printf("\n%s INSERT AT INDEX %d", label, index);
}

int main() {
  int i, o;
  char label[24], type[24];
  for(i = 0; i < SIZE; i++) {
    table[i] = NULL;
  }
  while(1) {
    printf("\n\nSymbol Table: \n1.Insert\n2.Lookup\n3.Display\n\nChoose an Option: ");
    scanf("%d", &o);
    switch (o)
    {
    case 1:
      printf("Enter the label: ");
      scanf("%s", label);
      printf("Enter datatype: ");
      scanf("%s", type);
      if(findLabel(label) == -1) {
        insertNode(label, type);
      } else {
        printf("\nAlready Exists!");
      }
      break;
    case 2:
      lookupTable();
      break;
    case 3:
      displayTable();
      break;
    default:
      printf("INVALID OPTION!\n");
      break;
    }
  }
  return 0;
}