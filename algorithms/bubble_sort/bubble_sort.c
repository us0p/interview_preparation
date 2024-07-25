#include <stdio.h>

void bubble_sort(int *haystack, int haystack_size) {
    int *last_address = haystack + haystack_size - 1;
    for (int *i = haystack; i < last_address; i++) {
	for(int *j = haystack; j < (last_address - i) + haystack; j++) {
	    int curr = *j;
	    int next = *(j + 1);
	    if (curr > next) {
		int tmp = curr;
		*j = next;
		*(j + 1) = curr;
	    }
	}
    }
}

int main(void) {
    int haystack[] = {3, 5, 2, 6, 1, 8, 7, 9, 0, 4};

    int haystack_size = sizeof(haystack) / sizeof(int);

    bubble_sort(haystack, haystack_size);

    for (int i = 0; i < haystack_size; i++) {
	printf("%d\n", haystack[i]);
    }
}
