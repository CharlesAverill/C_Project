#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <argp.h>

/**
 * @struct Arguments
 * @brief Structure containing command line arguments
 */
typedef struct Arguments {
    /**This will be printed after "Hello World"*/
    char* echo;
    // Add your arguments here
} Arguments;

void parse_args(Arguments* args, int argc, char* argv[]);

#endif /* ARGUMENTS_H */
