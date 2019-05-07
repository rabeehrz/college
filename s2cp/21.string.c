#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int isPalindrome(char str[])
{
    int l = 0;
    int h = strlen(str) - 1;
    while (h > l) {
        if (str[l++] != str[h--]) {
            return 0;
        }
    }
    return 1;
}
int countVowels(char s[]) {
    int i, count = 0;
    char ch;
    for(i = 0; i < strlen(s); i++) {
        ch = s[i];
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            count++;
    }
    return count;
}
int countDigits(char s[]) {
    int i, count = 0;
    char ch;
    for(i = 0; i < strlen(s); i++) {
        ch = s[i];
        if(ch >= '0' && ch <= '9')
            count++;
    }
    return count;
}
void * replace(char *s, char *oldw, char *neww) {
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
	return result;
}
void main() {
	char s[256], search[256], replac[256];
	char *result;
        int vcount, dcount;
	printf("Enter string: ");
        scanf("%s", s);
        printf("%s", (isPalindrome(s) ? "Palindrome." : "Not Palindrome."));
        vcount = countVowels(s);
        dcount = countDigits(s);
        printf("\nNumber of vowels: %d\nNumber of digits: %d\n", vcount, dcount);
	printf("Enter a substring to search: ");
	scanf("%s", search);
	printf("Enter a substring to replace: ");
	scanf("%s", replac);
	printf("Old String: %s\n", s);
	result = replace(s, search, replac);
	printf("New String: %s\n", result);
}
