#include<stdio.h>

void createNew() {
	FILE *fp;
	char name[100], i;
	int regno, marks[6];
	printf("Enter Reg No: ");
	scanf("%d", &regno);
	printf("Enter Name: ");
	scanf("%s", name);
	for(i = 0; i < 6; i++) {
		printf("Enter Mark %d: ", i+1);
		scanf("%d", &marks[i]);
	}
	fp = fopen("STUDENT.DAT", "a");
	fprintf(fp,"%6d%-25s%4d%4d%4d%4d%4d%4d\n", regno, name, marks[0], marks[1], marks[2], marks[3], marks[4], marks[5]);
	fclose(fp);
	printf("\nStudent record saved.\n");
}

void displayOne() {
	FILE *fp;
        char name[100], i;
        int regno, marks[6], flag = 0, reg;
	printf("Enter registration number: ");
	scanf("%d", &reg);
	fp = fopen("STUDENT.DAT", "r");
	while((fscanf(fp,"%6d%25c%4d%4d%4d%4d%4d%4d\n", &regno, name, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4], &marks[5])) != EOF) {
		if(regno==reg) {
			flag = 1;
			printf("\n%d %s %d %d %d %d %d %d\n", regno, name, marks[0], marks[1], marks[2], marks[3], marks[4], marks[5]);
		}
	}
        fclose(fp);
	if(flag == 0)
		printf("\nNo record found.\n");
}

void main() {
	int option;
	while(1) {
		printf("\nStudent details\n1.Read\n2.Create\nChoose an option: ");
		scanf("%d", &option);
		switch(option) {
				case 1:
					displayOne();
					break;
				case 2:
					createNew();
					break;
		}
	}
}
