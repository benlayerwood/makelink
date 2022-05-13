#include "makelink.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char *argv[]){
  FILE *filesrc;
  FILE *filedest;

  char *srcdir = "./test/";
  char *destdir = "./testlinks/";

  DIR *d = opendir(srcdir);
  struct dirent *dir;

  // Open directory srcdir
  if (d == NULL){
    printf("ERROR:\tdirectory %s not found\n", srcdir);
    exit(EXIT_FAILURE);
  } else {
    printf("Opened directory:%s\n", srcdir);
  }

  // Read directory srcdir
  while ((dir = readdir(d)) != NULL){
    if (dir->d_type == DT_REG){
      char* srcfile = concat(srcdir,dir->d_name);
      char* destfile = concat(destdir,dir->d_name);
      linkFile(srcfile,destfile);
    }
  }
}

// Create hard link destfile from srcfile
void linkFile(const char *srcfile, const char *destfile) {
  if (checkFile(srcfile)){
    printf("... linking file %s\n",srcfile);
    link(srcfile,destfile);
  }
  return;
}

// Check if file exists
int checkFile(const char *filename) {
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
      exit(1);
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
