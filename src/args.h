#ifndef ARGS_H_
#define ARGS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define APP_NAME "makelink"

void print_help_message();
char** parse_command_line_arguments(int argc, char **argv);

#endif // ARGS_H_
