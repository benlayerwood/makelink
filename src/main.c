#include "main.h"

int main(int argc, char *argv[]){
  char **dirs = parse_command_line_arguments(argc,argv);

  char *srcdir = concat(dirs[1],"/");
  char *destdir = concat(dirs[2],"/");
  readDir(srcdir, destdir);
}

// Read directory srcdir
void readDir(char *srcdir, char* destdir) {
  DIR *src = check_dir(srcdir);
  check_dir(destdir);

  struct dirent *dir;
  while ((dir = readdir(src)) != NULL) {
    char* srcfile = concat(srcdir,dir->d_name);
    char* destfile = concat(destdir,dir->d_name);
    if (dir->d_type == DT_REG) {
      link_file(srcfile,destfile);
    } else if (dir->d_type == DT_DIR && dir->d_name[0] != '.') {
      srcfile = concat(srcfile, "/");
      destfile = concat(destfile, "/");
      mkdir(destfile, 0755);
      readDir(srcfile, destfile);
    }
  }
}
