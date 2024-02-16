#include <stdbool.h>

bool linearSearch(int *haystack, int n, int needle) {
	for (int i = 0; i < n; i++) {
		if (haystack[i] == needle)
			return true;
	}

	return false;
}

bool binarySearch(int *haystack, int n, int needle) {
	int start = 0;
	int end = n;

	while(start < end) {
		int middle = start + ( end - start) / 2;
		int value = *(haystack + middle);

		if (value == needle)
			return true;
		else if (value > needle)
			end = middle;
		else
			start = middle + 1;
	}

	return false;
}

void bubbleSort(int *array, int n) {
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}
