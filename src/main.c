#include "main.h"

int main(int argc, char *argv[]){
  char **dirs = parse_command_line_arguments(argc,argv);

  char *srcdir = concat(dirs[1],"/");
  char *destdir = concat(dirs[2],"/");
  readDir(srcdir, destdir);
}

// Read directory srcdir
// TODO: Print message when directory is empty
void readDir(char *srcdir, char* destdir) {
  DIR *src = check_dir(srcdir);
  check_dir(destdir);

  struct dirent *dir;
  while ((dir = readdir(src)) != NULL){
    if (dir->d_type == DT_REG){
      char* srcfile = concat(srcdir,dir->d_name);
      char* destfile = concat(destdir,dir->d_name);
      link_file(srcfile,destfile);
    }
  }
}
