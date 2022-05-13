#include "files.h"

// Check if file exists
int check_file(const char *filename) {
  if (access(filename, F_OK) == 0) {
    return 1;
  } else {
    printf("ERROR:\tfile %s not found\n",filename);
    return 0;
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

DIR* check_dir(const char *dirname) {
  DIR *d = opendir(dirname);
  // Open directory srcdir
  if (d == NULL){
    printf("ERROR:\tdirectory \"%s\" not found\n", dirname);
    exit(EXIT_FAILURE);
  } else {
    printf("Opened directory \"%s\"\n", dirname);
    return d;
  }
}
