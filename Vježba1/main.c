#include <stdio.h>
#include <string.h>

 int mystrlen(char s[]) {
    int i;

    for (i = 0; s[i] != '\0'; ++i);

    return i;
};

char *mystrcpy(char s1[], char s2[]) {
    return s1 = s2;
};

int mystrcmp(const char *s1, const char *s2){
    for(;*s1 && *s2 && (*s1 == *s2); s1++, s2++){}
    if (*s1 - *s2 < 0) return -1;
    else if (*s1 - *s2 > 0) return 1;
    else return 0;
}

void mystrcat(char *s1, char *s2, char *catstring) {
     
    int k=0;
     
    while(*s1 != '\0') {
           catstring[k] = *s1;
           k++;
           s1++;         
    }      
     
    while(*s2 != '\0') {
           catstring[k] = *s2;
           k++;
           s2++;
    }

    catstring[k] = '\0';    
}

char* mystrstr(char *s, char *subs) {
  char *a = s;
  char *b = subs;

  for( ; *s != '\0'; *s++) {
    if(*s != *b) {
      continue;
    }

    a = s;
    while(1) {
      if(*b == '\0') {
        return s;
      } else if(*a++ != *b++) {
        break;
      }
    }
    b = subs;
  }

  return (char *) NULL;
}

void revstr(char *str1) {  

    int i, len, temp;  
    len = mystrlen(str1); 
      
    for (i = 0; i < len/2; i++) {  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}  

void main(void) {
    //char string1[] = "a";
    //char string2[] = "AAA";
    char string3[] = "Hello";
    //char catstring[sizeof(string2) + sizeof(string3)];
//
    //printf("My strlen: %d\n", mystrlen(string1));
    //printf("C strlen: %d \n", strlen(string1));
//
    //printf("My strcpy: %s \n", mystrcpy(string1, string2));
    //printf("C strcpy: %s \n", strcpy(string1, string2));
//
    //printf("My strcmp: %d \n", mystrcmp(string2, string3));
    //printf("C strcmp: %d \n", strcmp(string2, string3));
//
    //mystrcat(string2, string3, catstring);
    //printf("%s\n", catstring);
    //strcat(string2, string3);
    //printf("%s\n", catstring);

    char big_string[] = "Hello";
    char sub_string[] = "ell";

    char *str = big_string;
    char *substr = sub_string;

    char *res = mystrstr(str, substr);
    if(res != (char *) NULL) {
      printf("Substring match starting at: %c\n", *mystrstr(str, substr));
    } else {
      printf("There was no match found.\n");
    }

    revstr(string3);  
    printf ("After reversing the string: %s\n", string3);  
};
