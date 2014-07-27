#include <stdlib.h>
#define SIZE 100003 // 100003 is prime

typedef struct KeyValuePair {
	long key[SIZE];
	long value[SIZE];
} KeyValuePair;

KeyValuePair* KeyValuePair_new() { 
  KeyValuePair* kv = (KeyValuePair*) malloc(sizeof(KeyValuePair));
  int i = 0;
  for (i = 0; i < SIZE; i++) {
	  kv->key[i] = -1;
  }
  return kv;
}

long get(KeyValuePair* kv, long key) {
	int pos = key % SIZE;
	
	while (kv->key[pos] != -1) {
		if (kv->key[pos] == key) {
			return kv->value[pos];
		}
		pos = (pos + 1) % SIZE;
	}
	return -1;
}

void set(KeyValuePair* kv, long key, long value) {
	int pos = key % SIZE;
	
	while (kv->key[pos] != -1) {
		if (kv->key[pos] == key) {
			kv->value[pos] = value;
			return;
		}
		pos = (pos + 1) % SIZE;
	}
	kv->key[pos] = key;
	kv->value[pos] = value;
}

long in(KeyValuePair* kv, long key) {
	int pos = key % SIZE;
	
	while (kv->key[pos] != -1) {
		if (kv->key[pos] == key) {
			return 1;
		}
		pos = (pos + 1) % SIZE;
	}
	return 0;
}
