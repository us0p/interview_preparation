#include <stdio.h>

int partition(int haystack[], int start, int end) {
    int pivot_index = end - 1;
    int pivot = haystack[pivot_index];
    int last_swap_index = start;
    for (int i = start; i < pivot_index; i++) {
	if (haystack[i] <= pivot) {
	    int tmp = haystack[last_swap_index];
	    haystack[last_swap_index] = haystack[i];
	    haystack[i] = tmp;
	    last_swap_index++;
	}
    }
    haystack[pivot_index] = haystack[last_swap_index];
    haystack[last_swap_index] = pivot;
    return last_swap_index;
}

void recursive_quick_sort(int haystack[], int start, int end) {
    if (start >= end) {
	return;
    }
    int last_swap_index = partition(haystack, start, end);
    recursive_quick_sort(haystack, start, last_swap_index);
    recursive_quick_sort(haystack, last_swap_index + 1, end);
}

void iterative_quick_sort(int haytsack[], int haystack_size) {
    int stack[haystack_size]; 
  
    int top = -1; 
  
    // Initializing stack
    stack[++top] = 0; 
    stack[++top] = haystack_size; 
  
    // Keep popping from stack while is not empty 
    while (top >= 0) { 
        int end = stack[top--]; 
        int start = stack[top--]; 
  
        // Set pivot element at its correct position 
        // in sorted array 
        int last_swap_index = partition(haytsack, start, end); 
  
        // If there are elements on left side of pivot, 
        // then push left side to stack 
        if (last_swap_index > start) { 
            stack[++top] = start; 
            stack[++top] = last_swap_index; 
        } 
  
        // If there are elements on right side of pivot, 
        // then push right side to stack 
        if (last_swap_index + 1 < end) { 
            stack[++top] = last_swap_index + 1; 
            stack[++top] = end; 
        } 
    }
}

int main(void) {
    int haystack[] = {3, 5, 2, 6, 1, 8, 7, 9, 0, 4};

    int haystack_size = sizeof(haystack) / sizeof(int);

    iterative_quick_sort(haystack, haystack_size);

    for (int i = 0; i < haystack_size; i++) {
	printf("%d\n", haystack[i]);
    }
}
