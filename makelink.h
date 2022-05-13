#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define APP_NAME "makelink"

void print_help_message();
char* concat(const char *s1, const char *s2);
int check_file(const char *filename);
DIR *check_dir(const char *dirname);
void link_file(const char *srcfile, const char *destfile);
char** parse_command_line_arguments(int argc, char **argv);
