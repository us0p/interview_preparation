#include <stdio.h>

void insertion_sort(int haystack[]) {
    for (int i = 1; i < 5; i++) {
	int unordered_element = haystack[i];
	for (int j = i - 1; j >= 0; j--) {
	    int ordered_element = haystack[j];
	    if (ordered_element < unordered_element) break;
	    haystack[j + 1] = ordered_element;
	    haystack[j] = unordered_element;
	}
    }
}

void print_haystack(int haystack[]) {
    for (int i = 0; i < 5; i++) {
	printf("%d\n", haystack[i]);
    }
}

int main(void) {
    int haystack[] = {23, 1, 10, 5, 2};
    print_haystack(haystack);
    printf("-----\n");
    insertion_sort(haystack);
    print_haystack(haystack);
}
