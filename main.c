/*
 * This assignment is the translation of X assembly instructions to X86-64 instructions.
 * Some of the main concepts used are using the File api to read the binary file,
 * Bitwise operations and the translation itself.
 */

#include <stdio.h>
#include <errno.h>
#include "xtra.h"


int main(int argc, char **argv) {
    if (argc < 2) {
        printf("No file specified\b");
        return 1;
    }
    // Pass the argument of which file to translate.
    FILE *f = fopen(argv[1], "rb");
    if (f == NULL) {
        // if file not found print appropriate error.
        printf("Open failed, errno:%d \n",errno);
        return 1;
    }


    translatorFile(f); // invoke function which translates the assembly to X86-64.


    return 0;

}
