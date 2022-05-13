#include "args.h"

char** parse_command_line_arguments(int argc, char **argv) {
    if (argc < 3 ) {
      print_help_message();
      exit(EXIT_FAILURE);
    }
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) {
          print_help_message();
          exit(0);
        } else if (strcmp(argv[i], "-h") == 0) {
          print_help_message();
          exit(0);
        } else {
          return argv;
        }
    }
    return 0;
}

void print_help_message() {
    printf("Usage: %s [options] [<src directory>] [<dest directory>]\n", APP_NAME);
    printf("\n");
    printf("Simulates virtual memory management using a tlb.\n");
    printf("Creates hard-links for all files in src to destination directory\n");
    printf("\n");
    printf("Options:\n");
    printf("  --help       Show this help.\n");
    printf("  -h           Show this help.\n");
}
