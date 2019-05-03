// THIS PROGRAM IS NOT COMPLETE. REVERSING OF THE STRING IS NOT ADDED
#include<stdio.h>
#include<string.h>
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
void main() {
    char s[256] = "9radar9"; 
    int vcount, dcount;
    // scanf("%s", s);
    printf("%s", (isPalindrome(s) ? "Palindrome." : "Not Palindrome."));
    vcount = countVowels(s);
    dcount = countDigits(s);
    printf("\nNumber of vowels: %d\nNumber of digits: %d\n", vcount, dcount);
}
