/**
 * _strncpy - Copy a string with a specified length.
 * @dest: The destination buffer.
 * @src: The source string.
 * @n: The maximum number of characters to copy.
 * Return: A pointer to the destination buffer.
 */
char *_strncpy(char *dest, const char *src, size_t n) {
    char *d = dest;
    const char *s = src;

    while (n > 0 && *s != '\0') {
        *d++ = *s++;
        n--;
    }

    while (n > 0) {
        *d++ = '\0';
        n--;
    }

    return dest;
}

/**
 * _strncat - Concatenate two strings with a specified length.
 * @dest: The destination string.
 * @src: The source string to append.
 * @n: The maximum number of characters to append.
 * Return: A pointer to the destination string.
 */
char *_strncat(char *dest, const char *src, size_t n) {
    char *d = dest;
    const char *s = src;

    while (*d != '\0') {
        d++;
    }

    while (n > 0 && *s != '\0') {
        *d++ = *s++;
        n--;
    }

    *d = '\0';

    return dest;
}

/**
 * _strchr - Locate the first occurrence of a character in a string.
 * @s: The string to search.
 * @c: The character to locate.
 * Return: A pointer to the first occurrence of 'c' in 's', or NULL if not found.
 */
char *_strchr(const char *s, int c) {
    while (*s != '\0') {
        if (*s == c) {
            return (char *)s;
        }
        s++;
    }

    if (c == '\0') {
        return (char *)s;
    }

    return NULL;
}