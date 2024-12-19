```c
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
};

typedef struct {
   int capacity;
   int len;
   struct Node** set; 
} MyHashSet;

MyHashSet* myHashSetCreate() {
   MyHashSet* hashSet = malloc(sizeof(MyHashSet) + sizeof(struct Node*) * 100000);
   hashSet->capacity = 100000;
   hashSet->len = 0;
   return hashSet;
}

struct Node* nodeCreate(int val) {
    struct Node* n = calloc(sizeof(struct Node), 1);
    n->val = val;
    return n;
}

int hashFunction(MyHashSet* obj, int key) {
    return key % obj->capacity;
}

void copyHash(MyHashSet* oldObj, MyHashSet* newObj) {
    int copied = 0;
    for (int i = 0; i < oldObj->capacity; i++) {
        struct Node* head = oldObj->set[i];
        while(head != NULL) {
            head = head->next;
            int hash = hashFunction(newObj, head->val);
            struct Node* newHead = newObj->set[hash];
            if (newHead != NULL) {
                head->next = newHead;
            }
            newObj->set[hash] = head;
            copied++;
        }
        if (copied == oldObj->len) break;
    }
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int hash = hashFunction(obj, key);
    struct Node* head = obj->set[hash];
    while (head != NULL) {
        if (head->val == key) return true;
        head = head->next;
    }
    return false;
}

void freeNodes(struct Node* n) {
    if (n == NULL) return;
    freeNodes(n->next);
    free(n);
}

void myHashSetFree(MyHashSet* obj) {
   for (int i = 0; i < obj->capacity; i++) {
    freeNodes(obj->set[i]);
   } 
   free(obj);
}


void myHashSetAdd(MyHashSet* obj, int key) {
   if (myHashSetContains(obj, key)) return; 
   float loadFactor = (float)obj->len / (float)obj->capacity;
   if (loadFactor >= 0.7) {
    MyHashSet* newHashSet = malloc(sizeof(MyHashSet) + sizeof(struct Node*) * obj->capacity * 2);
    newHashSet->capacity = obj->capacity * 2;
    newHashSet->len = obj->len;
    copyHash(obj, newHashSet);
    myHashSetFree(obj);
    *obj = *newHashSet;
   }
   int hash = hashFunction(obj, key);
   struct Node* n = nodeCreate(key);
   if (obj->set[hash] != NULL) {
    n->next = obj->set[hash];
   }
   obj->set[hash] = n;
   obj->len += 1;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int hash = hashFunction(obj, key);
    struct Node* prev = NULL;
    struct Node* head = obj->set[hash];
    while (head != NULL) {
        if (head->val == key) {
            if (prev == NULL) {
                obj->set[hash] = head->next;
            } else {
                prev->next = head->next;
            } 
            free(head);
        };
        head = head->next;
        prev = head;
    }
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/

```
