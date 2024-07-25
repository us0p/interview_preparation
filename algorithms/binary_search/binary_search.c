#include <stdio.h>

int recursive_binary_search(int haystack[], int start, int end, int needle) {
    int middle_index = (end + start) / 2;
    int curr = haystack[middle_index];
    if (start > end) {
	return -1;
    }
    if (curr == needle) {
	return middle_index;
    }
    if (curr < needle) {
	return recursive_binary_search(haystack, middle_index + 1, end, needle);
    }
    
    return recursive_binary_search(haystack, start, middle_index - 1, needle);
}

int iterative_binary_search(int haysatck[], int end, int needle) {
    for (int i = 0, j = end; i <= j;) {
	int middle = (j + i) / 2;
	int curr = haysatck[middle];
	if (curr == needle) {
	    return middle;
	}
	if (curr < needle) {
	    i = middle + 1;
	    continue;
	}
        j = middle - 1;
    }
    return -1;
}

int main(void) {
    int haystack[] = {1,2,3,4,5,6,7,8,9,10};
    int haystack_last_index = (sizeof(haystack) / sizeof(haystack[0])) - 1;
    int needle = 7;
    int needle_index = iterative_binary_search(haystack, haystack_last_index, needle);
    printf("The index of the needle %d is %d.\n", needle, needle_index);

    int missing_needle = 11;
    int missing_needle_index = recursive_binary_search(haystack, 0, haystack_last_index, missing_needle);
    printf("The index of the needle %d is %d.\n", missing_needle, missing_needle_index);
}
