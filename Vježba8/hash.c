#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable* NewTable(int size) {

	HashTable* hash = (HashTable*)malloc(sizeof(HashTable));
	hash->table = (Bin*)malloc(size * sizeof(Bin));
	hash->size = size;
	hash->load = 0;

	for (int i = 0; i < hash->size; i++) {
		hash->table[i] = NULL;
	}

	return hash;
}

unsigned int hash(char* word) {

	unsigned int key = 0;

	while (*word != '\0') {
		key = key * HCONST + *word;
		word++;
	}

	return key;
}

void Insert(HashTable* ht, char* word) {

	Bin* novi = (Bin*)malloc(sizeof(Bin));

	int i = hash(word) % ht->size;

	novi->word = word;
	novi->next = ht->table[i];

	ht->table[i] = novi;
	ht->load++;
}

int Get(HashTable* ht, char* word) {

	int i = hash(word) % ht->size;

	Bin* h = ht->table[i];

	while (h != NULL) {
		if (!strcmp(h->word, word)) {
			return 1;
		} else {
			h = h->next;
		}
	}

	return 0;
}

void DeleteTable(HashTable* ht) {

	for (int i = 0; i < ht->size; i++) {

		Bin* h = ht->table[i];

		while (h != NULL) {
			Bin* del = h;
			h = h->next;
			free(del->word);
			free(del);
		}
	}

	free(ht->table);
	free(ht);
}
