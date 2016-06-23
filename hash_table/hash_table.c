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
    if (table->data[i]) {
      free(table->data[i]->key);
      free(table->data[i]->value);
      free(table->data[i]);
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
  int index = hash(key, kTableSize);
  int original_index = index;
  bool found = false;

  while (table->data[index] != NULL) {
    if (strcmp(table->data[index]->key, key) == 0) {
      found = true;
      break;
    }
    index = (index + 1) % table->size;
    if (index == original_index) {
      break;
    }
  }

  return found;
}

void add(hash_table* table, const char* key, const key_value* object) {
  int index = hash(key, kTableSize);
  int original_index = index;
  bool found = false;
  int dummyIndex = -1;

  while (table->data[index] != NULL) {
    if (strcmp(table->data[index]->key, key) == 0) {
      found = true;
      break;
    } else if (strcmp(table->data[index]->key, kDummy) == 0) {
      dummyIndex = index;
    }
    index = (index + 1) % table->size;
    if (index == original_index) {
      return;
    }
  }

  if (! found && dummyIndex != -1) {
    // use dummy index to insert
    index = dummyIndex;
  }

  if (table->data[index] == NULL) {
    table->data[index] = malloc(sizeof(key_value));
  } else {
    free(table->data[index]->key);
    free(table->data[index]->value);
  }

  table->data[index]->key = strdup(object->key);
  table->data[index]->value = strdup(object->value);
}

char* get(const hash_table* table, const char* key) {
  int index = hash(key, table->size);
  int original_index = index;

  while (table->data[index] != NULL) {
    if (strcmp(table->data[index]->key, key) == 0) {
      return table->data[index]->value;
    }
    index = (index + 1) % table->size;
    if (index == original_index) {
      break;
    }
  }

  return NULL;
}

void delete(hash_table* table, const char* key) {
  int index = hash(key, table->size);
  int original_index = index;

  while (table->data[index] != NULL) {
    if (strcmp(table->data[index]->key, key) == 0) {
      free(table->data[index]->key);
      free(table->data[index]->value);
      table->data[index]->key = strdup(kDummy);
      table->data[index]->value = strdup("");
      break;
    }
    index = (index + 1) % table->size;
    if (index == original_index) {
      return;
    }
  }
}
