// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    return destination;
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t i;

    for (i = 0; i < len && source[i] != '\0'; i++) {
        destination[i] = source[i];
    }

    for (; i < len; i++) {
        destination[i] = '\0';
    }
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int d_len = 0;
    int i = 0;

    while (destination[d_len] != '\0') {
        d_len++;
    }

    while (source[i] != '\0') {
        destination[d_len + i] = source[i];
        i++;
    }

    destination[d_len + i] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int d_len = 0;
    size_t i = 0;

    while (destination[d_len] != '\0') {
        d_len++;
    }

    while (i < len && source[i] != '\0') {
        destination[d_len + i] = source[i];
        i++;
    }

    destination[d_len + i] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        }
        str1++;
        str2++;
    }

    if (*str1 == '\0' && *str2 == '\0') {
        return 0;
    } else if (*str1 == '\0') {
        return -1;
    } else {
        return 1;
    }
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	size_t i = 0;

    while (i < len && str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        }
        i++;
    }

    if (i == len || (str1[i] == '\0' && str2[i] == '\0')) {
        return 0;
    } else if (str1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	 while (*str != '\0') {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	const char *last_ap = NULL;

    while (*str != '\0') {
        if (*str == c) {
            last_ap = str;
        }
        str++;
    }
    return (char *)last_ap;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	if (*needle == '\0') {
        return (char *)haystack;
    }

    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }

        if (*n == '\0') {
            return (char *)haystack;
        }

        haystack++;
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	int h_len = strlen(haystack);
    int n_len = strlen(needle);

    if (n_len == 0) {
        return (char *)(haystack + h_len);
    }

    if (n_len > h_len) {
        return NULL;
    }

    for (int i = h_len - n_len; i >= 0; i--) {
        if (strncmp(haystack + i, needle, n_len) == 0) {
            return (char *)(haystack + i);
        }
    }

    return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination;
    const char *src = (const char *)source;

    for (size_t i = 0; i < num; i++) {
        dest[i] = src[i];
    }

    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
    const char *src = (const char *)source;

    // check if dest and src overlap
    if (dest > src && dest < src + num) {
        // copy from end to beginning to avoid overwriting the source data
        dest = dest + num;
        src = src + num;

        while (num--) {
            *(--dest) = *(--src);
        }
    } else {
        while (num--) {
            *dest++ = *src++;
        }
    }

    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *byte_ptr1 = (const unsigned char *)ptr1;
    const unsigned char *byte_ptr2 = (const unsigned char *)ptr2;

    for (size_t i = 0; i < num; i++)
    {
        if (byte_ptr1[i] < byte_ptr2[i])
        {
            return -1;
        } else if (byte_ptr1[i] > byte_ptr2[i]) {
            return 1;
        }
    }

    return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *byte_source = (unsigned char *)source;

    for (size_t i = 0; i < num; i++)
    {
        byte_source[i] = (unsigned char)value;
    }

    return source;;
}
