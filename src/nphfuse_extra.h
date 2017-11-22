/*
  Copyright (C) 2016 Hung-Wei Tseng, Ph.D. <hungwei_tseng@ncsu.edu>

  This program can be distributed under the terms of the GNU GPLv3.
  See the file COPYING.

  You may extend this file if necessary  
*/

#include <time.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <dirent.h>

struct nphfuse_state {
    FILE *logfile;
    char *device_name;
    int devfd;
    char *rootdir;
};

struct file_struct {
    int offset;
    char file_name[NAME_MAX];
    char file_path[PATH_MAX];
    struct stat *dir_struct;
    bool is_directory;
    struct file_struct *parent;
    struct file_struct **next;
    struct dirent *dirents;
    int dir_size;
}*root;
