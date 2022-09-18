#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arguments.h"

/**
 * @brief Program entrypoint
 *
 * @param argc Number of command-line arguments
 * @param argv Array of command-line arguments as strings
 * @return Return code for program
 */
int main(int argc, char* argv[])
{
    printf("Hello World!\n");

    // Parse arguments
    Arguments* args = malloc(sizeof(Arguments));
    if (args == NULL) {
        fprintf(stderr, "Failed to allocate memory for argument parsing\n");
        return 1;
    }

    parse_args(args, argc, argv);
    printf("%s\n", args->echo);

    return 0;
}
