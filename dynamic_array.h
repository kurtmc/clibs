typedef struct DynamicIntArray DynamicIntArray;

int getSize(DynamicIntArray* d);

DynamicIntArray* initDynamicIntArray(int allocation);

void appendToDynamicIntArray(DynamicIntArray* d, int value);
