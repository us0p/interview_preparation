#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_key_value(char *key) {
  int key_value = 0;
  for (char *c = key; *c != '\0'; c++) {
    key_value += *c;
  }
  return key_value;
}

int hash_function_division_method(int key, int arrSize) {
  return key % arrSize;
}

int hash_function_mid_square(int key, int arrSize) {
  int sqr = key * key;
  // how to determine te number of digits to take from the middle element?

  // if it's based on the fact that the number can be even of odd, this means
  // that the key might only have 1 to 2 digits, thus the range of possible
  // values or, table size, must be within the range 0..99

  // calculates the mid number of sqr by removing from the start and end of the
  // number at the same time; 12: sqr -> 144 mid -> remove 1 frot start and 4
  // from the end result -> 4

  // 123:
  // sqr -> 15129
  // mid ->
  // remove 1 from start and 9 from the end
  // remove 5 from the start and 2 from the end
  // result -> 1

  // 50:
  // sqr -> 2500
  // mid ->
  // remove 2 from the start and 0 from the end
  // result -> 50
  return (key * key) % arrSize;
}

int hash_function_folding_method(int key, int arrSize) {
  // split the key into equal sized chunks
  // sum the chunks
  // apply mod
  // 1234 -> 12 + 34 = 46 -> 46 % arrSize
  return 0;
}

// multiplication method
int hash_function(int key, int arrSize) {
  float A = 0.6180339887;
  int prime = 1 << 16 | 5;
  double t = key * A;
  double f;
  modf(t, &f);
  return (int)(f * prime) % arrSize;
}

typedef struct Person {
  char *name;
  int age;
  char *job;
} Person;

int main(void) {
  srand(time(NULL));

  int arrSize = 100;
  Person **arr = (Person **)malloc(sizeof(Person) * arrSize);

  Person *p1 = (Person *)malloc(sizeof(Person));
  p1->job = "Developer";
  p1->age = rand() % 75;
  p1->name = "jose";
  arr[hash_function(get_key_value(p1->name), arrSize)] = p1;

  Person *p2 = (Person *)malloc(sizeof(Person));
  p2->job = "Developer";
  p2->age = rand() % 75;
  p2->name = "maria";
  arr[hash_function(get_key_value(p2->name), arrSize)] = p2;

  Person *p3 = (Person *)malloc(sizeof(Person));
  p3->job = "Developer";
  p3->age = rand() % 75;
  p3->name = "pedro";
  arr[hash_function(get_key_value(p3->name), arrSize)] = p3;

  for (int i = 0; i < arrSize; i++) {
    Person *p = arr[i];
    printf("%d: ", i);
    if (p) {
      printf("name: %s, ", p->name);
      printf("job: %s, ", p->job);
      printf("age: %d\n", p->age);
      continue;
    }
    puts("NULL");
  }
}
