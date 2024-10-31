#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define advantages and disadvantages of each method, for example, which
// size each method generates the least collisions.

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

int hash_function_mid_square_method(int key, int arrSize) {
  // the number of digits to take from the middle is less than or equal to
  // the maximum number of digits the last index of the table has.
  // a table with size 10, has index 0..9, it needs only 1 digit from the
  // middle. a table with size 1000, has indexes 0..999, it needs 1 to 3 digits
  // from the middle.

  // Note: your middle number must be consistent:
  // if you need to take 1 middle digit from the number 123, two is the only
  // choice. but if you need to take 1 middle digit from the number 1234, you
  // can pick 2 or 3, but your choice must be consistent.
  int last_index = arrSize - 1;
  int sqr = key * key;

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
