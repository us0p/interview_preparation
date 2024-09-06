#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_key_value(char *key) {
    int key_value = 0;
    for(char *c = key; *c != '\0'; c++){
	key_value += *c;
    }
    return key_value;
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
    
    for(int i = 0; i < arrSize; i++) {
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
