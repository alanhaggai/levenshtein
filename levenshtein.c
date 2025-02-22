#include <string.h>
#include <stdio.h>

char head(char *str) {
    return str[0];
}

char *tail(char *str) {
    return str + 1;
}

int levenshtein(char *str1, char *str2) {
    int d1 = 0,
        d2 = 0,
        d3 = 0;

    if (strlen(str2) == 0) {
        return strlen(str1);
    }
    if (strlen(str1) == 0) {
        return strlen(str2);
    }
    if (head(str1) == head(str2)) {
        return levenshtein(tail(str1), tail(str2));
    }

    d1 = levenshtein(tail(str1), str2);
    d2 = levenshtein(str1, tail(str2));
    d3 = levenshtein(tail(str1), tail(str2));

    if (d1 < d2 && d1 < d3) {
        return d1 + 1;
    }
    else if (d2 < d1 && d2 < d3 ) {
        return d2 + 1;
    }
    else {
        return d3 + 1;
    }
}
