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
        }
        closedir(dir);
    }
    // If a command was specified, list open files for processes with that command
    else if(command != NULL){
        dir = opendir("/proc");
        if(dir != NULL){

        }
        closedir(dir);
    }
    else{

    }

    return EXIT_SUCCESS;
}