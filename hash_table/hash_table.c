hash_table* create_table(const int size) {
  hash_table* fresh = malloc(sizeof(hash_table));
  assert(fresh != 0);

  fresh->data = malloc(sizeof(key_value) * size);
  assert(fresh->data != 0);

  for(int i = 0; i < size; ++i) {
    fresh->data[i] = NULL;
  }

  fresh->size = size;

  return fresh;
}

void destroy_table(hash_table* table) {

  for(int i = 0; i < table->size; ++i) {
    key_value* kv = table->data[i];
    while (kv) {
      key_value* next = kv->next;
      free(kv->key);
      free(kv->value); 
      free(kv);
      kv = next;
    }
  }

  free(table->data);
  free(table);
}

int hash(const char* key, const int m) {
  int hash = 0;

  for (int i = 0; i < key[i] != '\0'; ++i) {
    hash = hash * 31 + key[i];
  }

  return abs(hash % m);
}

void print_debug(hash_table* table) {
  for (int i = 0; i < table->size; ++i) {
    if (table->data[i] == NULL) {
      printf("%d:\n", i);
    } else {
      printf("%s: %s\n", table->data[i]->key, table->data[i]->value);
    }
  }
  printf("===================\n");
}

bool exists(const hash_table* table, const char* key) {
  key_value* kv = get(table, key);
  return kv != NULL;
}

void add(hash_table* table, const char* key, const key_value* object) {
  int index = hash(key, table->size);

  key_value* kv = get(table, key);
  if (kv != NULL) {
      free(kv->value);
      kv->value = strdup(object->value);
      return;
  }

  kv = malloc(sizeof(key_value)); 
  kv->key = strdup(object->key);
  kv->value = strdup(object->value);
  kv->next = table->data[index];
  table->data[index] = kv;
}

key_value* get(const hash_table* table, const char* key) {
  int index = hash(key, table->size);

  key_value* kv = table->data[index];
  while (kv) {
    if (strcmp(kv->key, key) == 0) {
        return kv;
    }

    kv = kv->next;
  }

  return NULL;
}

void delete(hash_table* table, const char* key) {
  int index = hash(key, table->size);
  key_value* prekv = NULL;

  key_value* kv = table->data[index];
  while (kv) {
    if (strcmp(table->data[index]->key, key) == 0) {
      // kv is head of linker.
      if (prekv == NULL) {
        table->data[index] = kv->next;
      } else {
        prekv->next = kv->next;
      }

      free(kv->key);
      free(kv->value);
      free(kv);
    }

    prekv = kv;
    kv = kv->next;
  }
}
