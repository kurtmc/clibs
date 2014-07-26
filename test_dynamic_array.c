#include <stdio.h>
#include <assert.h>
#include "dynamic_array.h"

int main(void)
{
	DynamicIntArray* d = initDynamicIntArray(10);

	int i;
	for (i = 0; i < 10; i++) {
		appendToDynamicIntArray(d, i);
		printf("Size: %d", getSize(d));
		//assert(getSize(d) == (i + 1));
	}
	return 0;
}
