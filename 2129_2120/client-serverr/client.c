#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

void add_student(const char *filename) {
    int fd2;
    int fd = open("/tmp/fifo.1", O_WRONLY);

    fd2 = open(filename, O_RDONLY);
    char fcontent[1000] = "";
    int bytesRead;

    while ((bytesRead = read(fd2, fcontent, sizeof(fcontent))) > 0) {
        write(fd, fcontent, bytesRead);
        memset(fcontent, 0, sizeof(fcontent));
    }

    close(fd2);
    close(fd);
}

void add_course(const char *filename){
  int fd2;
    int fd = open("/tmp/fifo.1", O_WRONLY);

    fd2 = open(filename, O_RDONLY);
    char fcontent[100] = "";
    int bytesRead;

    while ((bytesRead = read(fd2, fcontent, sizeof(fcontent))) > 0) {
        write(fd, fcontent, bytesRead);
        memset(fcontent, 0, sizeof(fcontent));
    }

    close(fd2);
    close(fd);
}

void initialDatabase(const char *filename){
 const char *fifo_path = "/tmp/fifo.1";
  int fd2;
    if (access(fifo_path, F_OK) == -1) {
        printf("FIFO does not exist!\n");
        return;
    }
    int fd = open("/tmp/fifo.1", O_WRONLY);

    fd2 = open(filename, O_RDONLY);
    char fcontent[100] = "";
    int bytesRead;

    while ((bytesRead = read(fd2, fcontent, sizeof(fcontent))) > 0) {
        write(fd, fcontent, bytesRead);
        memset(fcontent, 0, sizeof(fcontent));
    }

    close(fd2);
    close(fd);
}
void deleteCourse(const char *filename){
  int fd2;
    int fd = open("/tmp/fifo.1", O_WRONLY);

    fd2 = open(filename, O_RDONLY);
    char fcontent[100] = "";
    int bytesRead;
    while ((bytesRead = read(fd2, fcontent, sizeof(fcontent))) > 0) {
        write(fd, fcontent, bytesRead);
        memset(fcontent, 0, sizeof(fcontent)); 
    }

    close(fd2);
    close(fd);
}
void modifyCourse(const char *filename){
  int fd2;
    int fd = open("/tmp/fifo.1", O_WRONLY);

    fd2 = open(filename, O_RDONLY);
    char fcontent[100] = "";
    int bytesRead;
    while ((bytesRead = read(fd2, fcontent, sizeof(fcontent))) > 0) {
        write(fd, fcontent, bytesRead);
        memset(fcontent, 0, sizeof(fcontent));
    }

    close(fd2);
    close(fd);
}
void modifyStudent(const char *filename){
  int fd2;
    int fd = open("/tmp/fifo.1", O_WRONLY);

    fd2 = open(filename, O_RDONLY);
    char fcontent[100] = "";
    int bytesRead;

    while ((bytesRead = read(fd2, fcontent, sizeof(fcontent))) > 0) {
        write(fd, fcontent, bytesRead);
        memset(fcontent, 0, sizeof(fcontent));
    }

    close(fd2);
    close(fd);
 
}
void deleteStudent(const char *filename){
  int fd2;
    int fd = open("/tmp/fifo.1", O_WRONLY);

    fd2 = open(filename, O_RDONLY);
    char fcontent[100] = "";
    int bytesRead;

    while ((bytesRead = read(fd2, fcontent, sizeof(fcontent))) > 0) {
        write(fd, fcontent, bytesRead);
        memset(fcontent, 0, sizeof(fcontent));
    }

    close(fd2);
    close(fd);
}
