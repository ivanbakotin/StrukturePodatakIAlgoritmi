#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Dictionary create() {

	Dictionary head = (Dictionary)malloc(sizeof(Word));

	head->next = NULL;

	return head;
}

void add(Dictionary dict, char *str) {
  
    Dictionary new = dict;

	while (new->next != NULL) {
		if (!strcmp(new->next->word, str)) {
			new->next->count++;
			return;
		} else if (strcmp(str, new->next->word) < 0) {
			Dictionary novi = (Dictionary)malloc(sizeof(Word));
			novi->word = strdup(str);
			novi->count = 1;
			novi->next = new->next;
			new->next = novi;	
			return;
		} 
		
		new = new->next;
	}

	new->next = (Dictionary) malloc(sizeof(Word));
	new->next->word = strdup(str);
	new->next->count = 1;
	new->next->next = NULL;
}

void print(Dictionary dict) {
	dict = dict->next;

    while (dict != NULL) {
        printf("%d, %s \n", dict->count, dict->word);
        dict = dict->next;
    }
}

void destroy(Dictionary dict) {

	Dictionary tmp = dict;

	while (tmp->next != NULL) {
		Dictionary del = tmp->next;
		tmp->next = tmp->next->next;
		free(del);
	}
}

int filter(Dictionary w) {
	if (w->count >= 5 && w->count <= 10 && strlen(w->word) > 3) return 1;
	else return 0;
}

Dictionary filterDictionary(Dictionary indict, int(*filter)(Dictionary w)) {
	Dictionary tmp = indict;

	if (tmp->next == NULL) return NULL;

	while (tmp->next != NULL) {
		if (filter(tmp->next) == 1) {
			tmp = tmp->next;

		} else {
			Dictionary del = tmp->next;
			tmp->next = tmp->next->next;
			free(del);
		}
	}

	return indict;
}
