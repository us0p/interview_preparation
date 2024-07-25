#include <stdio.h>

void merge(int haystack[], int start, int middle, int inclusive_end) {
    int haystack_left_size = middle - start + 1;
    int haystack_right_size = inclusive_end - middle;

    int temp_left_haystack[haystack_left_size];
    int temp_right_haystack[haystack_right_size];

    // copy respective elements from original arr to temp left array;
    for (int i = 0; i < haystack_left_size; i++) {
	temp_left_haystack[i] = haystack[start + i];
    }

    // copy respective elements from original arr to temp right array;
    for (int i = 0; i < haystack_right_size; i++) {
	temp_right_haystack[i] = haystack[middle + 1 + i];
    }

    int i = 0, j = 0, k = start;

    // merge left and right temp array in original array at their
    // respective positions;
    while (i < haystack_left_size && j < haystack_right_size) {
	if (temp_left_haystack[i] <= temp_right_haystack[j]) {
	    haystack[k] = temp_left_haystack[i];
	    i++;
	} else {
	    haystack[k] = temp_right_haystack[j];
	    j++;
	}
	k++;
    }

    // if left and right temp array sizes are different, merge remaining
    // left elements in following positions;
    while (i < haystack_left_size) {
	haystack[k] = temp_left_haystack[i];
	i++;
	k++;
    }

    // if left and right temp array sizes are different, merge remaining
    // right elements in following positions;
    while (j < haystack_right_size) {
	haystack[k] = temp_right_haystack[j];
	j++;
	k++;
    }
}

void merge_sort(int haystack[], int start, int inclusive_end) {
    if (start >= inclusive_end) return;

    int middle = start + (inclusive_end - start) / 2;

    merge_sort(haystack, start, middle);
    merge_sort(haystack, middle + 1, inclusive_end);

    merge(haystack, start, middle, inclusive_end);
}

void print_haystack(int haystack[]) {
    for (int i = 0; i < 4; i++) {
	printf("%d\n", haystack[i]);
    }
}

int main(void) {
    int haystack[] = {38,27,48,10};
    print_haystack(haystack);
    printf("----\n");
    merge_sort(haystack, 0, 3);
    print_haystack(haystack);
}
