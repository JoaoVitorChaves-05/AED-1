#include <string.h>
#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int lastIndex[256];
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int maxLen = 0;
    int start = 0;

    for (int end = 0; end < n; end++) {
        char currentChar = s[end];

        if (lastIndex[currentChar] >= start) {
            start = lastIndex[currentChar] + 1;
        }

        lastIndex[currentChar] = end;

        int currentLen = end - start + 1;
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    return maxLen;
}

int main() {
    char s[50000];
    gets(s);
    printf("%i\n", lengthOfLongestSubstring(s));
}