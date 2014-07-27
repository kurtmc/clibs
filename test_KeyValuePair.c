#include <stdio.h>
#include <assert.h>
#include "KeyValuePair.h"

int main(void) {
	KeyValuePair* kv;
	kv = KeyValuePair_new();
	set(kv, 123, 456);
	assert(get(kv, 123) == 456);
	return 0;
}
