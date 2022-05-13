#ifndef FILES_H_
#define FILES_H_

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int check_file(const char *filename);
void link_file(const char *srcfile, const char *destfile);
DIR* check_dir(const char *dirname);

#endif // FILES_H_
