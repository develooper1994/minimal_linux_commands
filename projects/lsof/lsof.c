/**
 * Copyright 2023 Mustafa Selçuk Çağlar(develooper1994)
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// standart c headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// posix headers
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
    DIR* dir;
    struct dirent* entry;
    char path[64];
    int fd;
    int pid = -1;
    char* command = NULL;

    // Parse command line arguments
    int opt;
    while((opt=getopt(argc, argv, "p:c:")) != -1){
        switch(opt){
            case 'p':
                pid = atoi(optarg);
                break;
            case 'c':
                command = optarg;
                break;
            default:
                fprintf(stderr, "Usage: %s [-p PID] [-c command]\n", argv[0]);
                return EXIT_FAILURE;
        }
    }

    // IF a PID was specified, list open files for that process
    if(pid != -1){
        snprintf(path, sizeof(path), "/proc/%d/fd", pid);
        dir=opendir(path);
        if(dir != NULL){
            while((entry = readdir(dir)) != NULL){
                if (entry->d_name[0] != '.'){
                    fd = atoi(entry->d_name);
                    printf("%5d %s\n", fd, entry->d_name);
                }
            }
            closedir(dir);
        }
    }
    // If a command was specified, list open files for processes with that command
    else if(command != NULL){
        dir = opendir("/proc");
        if(dir != NULL){
            while((entry = readdir(dir)) != NULL){
                if(entry->d_type == DT_DIR && entry->d_name[0] >= '0' && entry->d_name[0] <= '9'){
                    pid = atoi(entry->d_name);
                    snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);
                    fd=open(path, O_RDONLY);
                    if(fd != -1){
                        char cmdline[1024];
                        ssize_t len = read(fd, cmdline, sizeof(cmdline) - 1);
                        if(len > 0){
                            cmdline[len = '\0'];
                            if(strcmp(cmdline, command) == 0){
                                printf("%5d %s\n", pid, cmdline);
                            }
                        }
                        close(fd); // close if fd is opened
                    }
                }
            }
            closedir(dir);  // close if fd is opened
        }
    }
    // Otherwise, list open files for all processes
    else{
        dir = opendir("/proc");
        if(dir != NULL){
            while((entry = readdir(dir)) != NULL){
                if(entry->d_type == DT_DIR && entry->d_name[0] >= '0' && entry->d_name[0]<='9'){
                    pid = atoi(entry->d_name);
                    snprintf(path, sizeof(path), "/proc/%d/fd", pid);
                    DIR* fd_dir = opendir(path);
                    if(fd_dir != NULL){
                        struct dirent* fd_entry;
                        while((fd_entry = readdir(fd_dir)) != NULL){
                            if(fd_entry->d_name[0] != '.'){
                                fd = atoi(fd_entry->d_name);
                                printf("%5d %5d %s\n", pid, fd, fd_entry->d_name);
                            }
                        }
                        closedir(fd_dir);
                    }
                }
            }
            closedir(dir);
        }
    }

    return EXIT_SUCCESS;
}