#include "makelink.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[]){
  char **dirs = parse_command_line_arguments(argc,argv);

  struct dirent *dir;
  FILE *filesrc;
  FILE *filedest;

  char *srcdir = dirs[1];
  char *destdir = dirs[2];
  DIR *d = opendir(srcdir);

  // Open directory srcdir
  if (d == NULL){
    printf("ERROR:\tdirectory \"%s\" not found\n", srcdir);
    exit(EXIT_FAILURE);
  } else {
    printf("Opened directory \"%s\"\n", srcdir);
  }

  // Read directory srcdir
  // TODO: Print message when directory is empty
  while ((dir = readdir(d)) != NULL){
    if (dir->d_type == DT_REG){
      char* srcfile = concat(srcdir,dir->d_name);
      char* destfile = concat(destdir,dir->d_name);
      link_file(srcfile,destfile);
    }
  }
}

// Create hard link destfile from srcfile
void link_file(const char *srcfile, const char *destfile) {
  if (check_file(srcfile)){
    printf("... linking file %s\n",srcfile);
    link(srcfile,destfile);
  }
  return;
}

// Check if file exists
int check_file(const char *filename) {
  if (access(filename, F_OK) == 0) {
    return 1;
  } else {
    printf("ERROR:\tfile %s not found\n",filename);
    return 0;
  }
}

// Concatenate two strings
char* concat(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    if (result == NULL){
      printf("MALLOC ERROR");
      exit(EXIT_FAILURE);
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char** parse_command_line_arguments(int argc, char **argv) {
    if (argc < 3 ) {
      print_help_message();
      exit(0);
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
