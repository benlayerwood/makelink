#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* concat(const char *s1, const char *s2);

int main(int argc, char *argv[]){
  FILE *filesrc;
  FILE *filedest;

  char *srcdir = "/tmp/test/";
  char *destdir = "/tmp/test/";

  if ((filesrc = fopen(concat(srcdir,"test.txt"), "r")) == NULL) {
    printf("ERROR:\tfile not found\n");
  } else {
    printf("SUCC:\tfile exists!\n");
  }

  link(concat(srcdir, "test.txt"),concat(destdir,"testhl.txt"));
}

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
