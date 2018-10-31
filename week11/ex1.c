#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <memory.h>

int main(int argc, char **argv) {
    char *text = "This is a nice day";
    int fd = open("ex1.txt", O_RDWR);
    struct stat *stat = malloc(sizeof(struct stat));
    fstat(fd, stat);
    char *mem;
    size_t size = strlen(text);
    ftruncate(fd, (off_t) size);
    mem = mmap(0, size, PROT_WRITE, MAP_SHARED, fd, 0);
    memcpy(mem, text, strlen(text));
    msync(mem, size, MS_SYNC);
    munmap(mem, size);

    return 0;
}
