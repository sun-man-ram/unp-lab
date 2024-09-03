#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
int main() {
    char s1[100] = "";

    mkfifo("/tmp/fifo.1", 0600);
    mkfifo("/tmp/fifo.2", 0600);

    int fd = open("/tmp/fifo.1", O_RDONLY);

    // Continuously read from FIFO until EOF
    int bytesRead;
    while ((bytesRead = read(fd, s1, sizeof(s1))) > 0) {
        printf("File Content: %s", s1);
        memset(s1, 0, sizeof(s1)); // Clear buffer for next read
    }

    close(fd);
    return 0;
}
