#include <stdio.h>
#include "levenshtein.h"

void usage(const char *prog) {
    fprintf(stderr, "Usage: %s STRING1 STRING2\n", prog);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        usage(argv[0]);
        return 1;
    }

    printf("%d\n", levenshtein(argv[1], argv[2]));
    return 0;
}
