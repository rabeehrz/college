#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 100

int isVowel(char ch) {
	switch(ch) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			return 1;
		default:
			return 0;
	}
}

int stringlen(char *s1) {
    int i = 0;
    while(*s1++)
        i++;
    return i;
}

char * stringcpy(char *s2, char *s1) {
    while((*s2 = *s1)) {
        s1++;
        s2++;
    }
    return s2;
}

int stringcmp(char *s1, char *s2) {
    while(*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1-*s2;
}

char * stringcat(char *s1, char *s2) {
    char *rtrn = s1;
    while(*s1)
        s1++;
    while((*s1++ = *s2++));
    *s1 = '\0';
    return rtrn;
}

int countVowels(char s[]) {
    int i, count = 0;
    char ch;
    for(i = 0; i < stringlen(s); i++) {
        ch = s[i];
        if(isVowel(ch))
            count++;
    }
    return count;
}

int countConsonants(char s[]) {
    int i, count = 0;
    char ch;
    for(i = 0; i < stringlen(s); i++) {
        ch = s[i];
        if(!isVowel(ch) && ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')))
            count++;
    }
    return count;
}

int countWords(char s[]) {
	int i, count = 0;
	char ch, prevch = s[0];
	for(i = 0; i < stringlen(s); i++) {
		ch = s[i];
		if(ch == ' ' && prevch != ' ') {
			count++;
		}
		prevch = ch;
	}
	return count+1;
}

void stringreplace(char *s, char *oldw, char *neww) {
	char *result;
	int i, count = 0;
	int newwlen = strlen(neww);
	int oldwlen = strlen(oldw);
	for(i = 0; s[i] < '\0'; i++) {
		if(strstr(&s[i], oldw) == &s[i]) {
			count++;
			i += oldwlen - 1;
		}
	}
	result = (char *)malloc(i + count * (newwlen - oldwlen) + 1);

	i = 0;
	while(*s) {
		if(strstr(s, oldw) == s) {
			strcpy(&result[i], neww);
			i += newwlen;
			s += oldwlen;
		} else {
			result[i++] = *s++;
		}
	}
	result[i] = '\0';
	printf("%s\n", result);
}

void main() {
    int option;
    char string1[MAX_SIZE], string2[MAX_SIZE], replace[MAX_SIZE];
    printf("String Functions\n\n");
    printf("1. String length\n2. String concatenation\n3. String copy\n4. String compare\n5. Substring search and replace\n6. Count vowels, consonants and words\nChoose an option: ");
    scanf("%d", &option);
    printf("\n");
    switch(option) {
        case 1:
            printf("Enter the string: ");
            scanf(" %[^\n]", string1);
            printf("String length is %d.\n", stringlen(string1));
            break;
        case 3:
            printf("Enter string 1: ");
            scanf(" %[^\n]", string1);
            stringcpy(string2, string1);
            printf("String has been copied. New string is %s\n", string2);
            break;
        case 4:
            printf("Enter string 1: ");
            scanf(" %[^\n]", string1);
            printf("Enter string 2: ");
            scanf(" %[^\n]", string2);
            printf("String compare: %d\n", stringcmp(string1, string2));
            break;
        case 2:
            printf("Enter string 1: ");
            scanf(" %[^\n]", string1);
            printf("Enter string 2: ");
            scanf(" %[^\n]", string2);
            stringcat(string1, string2);
            printf("String concatenation: %s\n", string1);
            break;
    	case 5:
    	    printf("Enter string: ");
    	    scanf(" %[^\n]", string1);
    	    printf("Enter substring to search: ");
    	    scanf(" %[^\n]", string2);
    	    printf("Enter replace string: ");
    	    scanf(" %[^\n]", replace);
    	    stringreplace(string1, string2, replace);
    	    break;
    	case 6:
            printf("Enter string: ");
            scanf(" %[^\n]", string1);
    	    printf("No. of Vowels: %d\n", countVowels(string1));
    	    printf("No. of Consonants: %d\n", countConsonants(string1));
    	    printf("No. of Words: %d\n", countWords(string1));
            break;
        default:
            printf("Wrong option! Try again.");
    }
}
