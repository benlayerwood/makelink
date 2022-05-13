#define APP_NAME "makelink"

void print_help_message();
char* concat(const char *s1, const char *s2);
int check_file(const char *filename);
void link_file(const char *srcfile, const char *destfile);
char** parse_command_line_arguments(int argc, char **argv);
