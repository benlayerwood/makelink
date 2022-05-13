#include "main.h"

int main(int argc, char *argv[]){
  char **dirs = parse_command_line_arguments(argc,argv);

  struct dirent *dir;
  FILE *filesrc;
  FILE *filedest;

  char *srcdir = concat(dirs[1],"/");
  char *destdir = concat(dirs[2],"/");

  DIR *d = check_dir(srcdir);
  check_dir(destdir);

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
