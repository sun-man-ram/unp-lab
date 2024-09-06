#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Give correct arguments as input file\n");
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    parseFile(argv[1]);
    return 0;
}
