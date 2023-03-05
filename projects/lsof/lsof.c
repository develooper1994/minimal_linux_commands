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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
                command = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s [-p PID] [-c command]\n", argv[0]);
                return EXIT_FAILURE;
        }
    }

    if(pid != -1){

    }
    else if(command != NULL){

    }
    else{

    }

    return EXIT_SUCCESS;
}