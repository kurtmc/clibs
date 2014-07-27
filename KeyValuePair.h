typedef struct KeyValuePair KeyValuePair;

KeyValuePair* KeyValuePair_new();

long get(KeyValuePair* kv, long key);

void set(KeyValuePair* kv, long key, long value);

long in(KeyValuePair* kv, long key);