#include <stdbool.h>

bool linearSearch(int *haystack, int n, int needle) {
	for (int i = 0; i < n; i++) {
		if (haystack[i] == needle)
			return true;
	}

	return false;
}
