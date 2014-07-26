typedef struct DynamicIntArray {
	int * array;
	int size;
	int allocated;
} DynamicIntArray;

int getSize(DynamicIntArray* d)
{
	return d->size;
}

DynamicIntArray* initDynamicIntArray(int allocation)
{
	DynamicIntArray d;
	d.array = malloc(allocation*sizeof(int));
	d.size = 0;
	d.allocated = allocation;
	return &d;
}

void appendToDynamicIntArray(DynamicIntArray* d, int value)
{
	if (d->size < d->allocated) {
		d->array[d->size] = value;
		d->size++;
	} else {
		// Create new array with double allocation
		DynamicIntArray* newArray;
		newArray = initDynamicIntArray(2*d->size);
		int i;
		for (i = 0; i < d->size; i++) {
			newArray->array[i] = d->array[i];
		}
		newArray->size = d->size;
		free(d->array);
		free(d->size);
		free(d->allocated);
		d = newArray;
	}
}
