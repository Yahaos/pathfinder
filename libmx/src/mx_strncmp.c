#include "libmx.h"

int mx_strncmp(const char* s1, const char* s2, int n) {
    if (n == 1)
            return *s1 - *s2;
    for (int i = 0; *s1 == *s2 && (*s1 != '\0' || i != n-1);) {
        s1++;
        s2++;
	i++;
        if (*s1 == '\0' || i == n - 1) {
            return *s1 - *s2;
        }
    }
    return *s1 - *s2;
}
