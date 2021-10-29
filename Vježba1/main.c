#include <stdio.h>
#include <string.h>

int mystrlen(char *s) {
    int i;

    for (i = 0; s[i] != '\0'; i++);

    return i;
};

void mystrcpy(char *s1, char *s2) {
    int a, b;
    
    for (int i = 0; s2[i] != '\0'; i++) {
        s1[i] = s2[i];
    }
};

int mystrcmp(const char *s1, const char *s2){
    int i = 0;
    while(s1[i] == s2[i] && s1[i]) {i++;}

    if (s1[i] < s2[i]) return -1;
    else if (s1[i] > s2[i]) return 1;
    else return 0;
}

void mystrcat(char *s1, char *s2) {
     
    int i, len1, len2;
    len1 = mystrlen(s1);
    len2 = mystrlen(s2) + len1 + 1;

    for (len1, i = 0; len1 < len2; len1++, i++) {
        s1[len1] = s2[i];
    }
}

char* mystrstr(char* s1, char* s2) {

    char *a = s1;
    char *b = s2;

    for( ; *s1 != '\0'; *s1++) {
      if(*s1 != *b) {
        continue;
      }

      a = s1;
      while(1) {
        if(*b == '\0') {
          return s1;
        } else if(*a++ != *b++) {
          break;
        }
      }
      b = s2;
    }

    return (char *) NULL;
}

void reverse(char* s1, char* s2) {

    int i;

    int len = mystrlen(s1);

    for (i = 0; s1[i] != '\0'; i++) {
 
        s2[i] = s1[len - 1 - i];
    }

    s2[i] = '\0';
}

void main(void) {
    char string1[30] = "aa";
    char string2[30] = "Hello";
    char string3[30] = "ello";

    //printf("My strlen: %d\n", mystrlen(string1));
    //printf("C strlen: %d \n", strlen(string1));

    //mystrcpy(string1, string3);
    //printf("Mystrcpy: %s\n", string1);
    //strcpy(string1, string3);
    //printf("Strcpy: %s\n", string1);

    //printf("My strcmp: %d \n", mystrcmp(string2, string3));
    //printf("C strcmp: %d \n", strcmp(string2, string3));

    //mystrcat(string2, string3);
    //printf("Mystrcat: %s\n", string2);
    //strcat(string2, string3);
    //printf("Strcat: %s\n", string2);

    printf("Mystrstr: %s\n", mystrstr(string2, string3));
    printf("Strstr: %s\n", strstr(string2, string3));

    //reverse(string2, string3);  
    //printf("After reversing the string: %s\n", string3);  
};
