#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

#include<unistd.h>

#include<fcntl.h>

#include<sys/types.h>

#include<sys/stat.h>

#include<string.h>
// i am successfully fetching the name of file into the client 
// the files contain the data that is to implemented on the linkedlist 
// but along with the name of file the data need to be sent into the server

void add_student(const char *filename) {
    int fd2;
    int fd = open("/tmp/fifo.1", O_WRONLY);

    fd2 = open(filename, O_RDONLY);
    char fcontent[100] = "";
    int bytesRead;

    // Read file content and write it to FIFO
    while ((bytesRead = read(fd2, fcontent, sizeof(fcontent))) > 0) {
        write(fd, fcontent, bytesRead);
        memset(fcontent, 0, sizeof(fcontent)); // Clear buffer for next read
    }

    close(fd2);
    close(fd);
}

void add_course(const char *filename){
 printf("%s\n ",filename);
}

void initialDatabase(const char *filename){
 printf("%s\n ",filename);
}
void deleteCourse(const char *filename){
 printf("%s\n ",filename);
}
void modifyCourse(const char *filename){
 printf("%s\n ",filename);
}
void modifyStudent(const char *filename){
 printf("%s\n ",filename);
}
void deleteStudent(const char *filename){
 printf("%s\n ",filename);
}
