#include <string.h>

#include "arguments.h"
#include "info.h"

const char* argp_program_version = PROJECT_NAME_AND_VERS;
const char* argp_program_bug_address = "bug_email@example.com";
static char doc[] = "A program to print out the words \"Hello World!\"";
static char args_doc[] = "PROGRAM";

static struct argp_option options[] = {
    {
        "echo",
        'e',
        "ECHO_STATEMENT",
        0,
        "Will print ECHO_STATEMENT on a separate line after the \"Hello World!\" message",
    },
    {0},
};

error_t parse_opt(int key, char* arg, struct argp_state* state)
{
    Arguments* arguments = state->input;

    switch (key) {
    case 'e':
        arguments->echo = arg;
        break;
    case ARGP_KEY_ARG:
        // Check for too many arguments
        if (state->arg_num >= 0) {
            argp_usage(state);
        }
        break;
    case ARGP_KEY_END:
        // Check for not enough arguments
        if (state->arg_num < 0) {
            argp_usage(state);
        }
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

static struct argp argp = {options, parse_opt, args_doc, doc, 0, 0, 0};

/**
 * @brief Parse arguments into an Arguments structure
 *
 * @param args Arguments struct to parse into
 * @param argc Number of arguments
 * @param argv List of arguments as strings
 */
void parse_args(Arguments* args, int argc, char* argv[])
{
    // Set defaults here
    args->echo = "";

    argp_parse(&argp, argc, argv, 0, 0, args);
}
