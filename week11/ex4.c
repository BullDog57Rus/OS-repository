#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <memory.h>

int main(int argc, char **argv) {
    int fd1 = open("ex1.txt", O_RDONLY);
    int fd2 = open("ex1.memcpy.txt", O_RDWR | O_CREAT);
    struct stat *stat = malloc(sizeof(struct stat));
    fstat(fd1, stat);
    size_t size = (size_t) stat->st_size;
    ftruncate(fd2, (off_t) size);
    char *mem1 = mmap(0, size, PROT_READ, MAP_SHARED, fd1, 0);
    char *mem2 = mmap(0, size, PROT_WRITE, MAP_SHARED, fd2, 0);
    memcpy(mem2, mem1, size);
    msync(mem2, size, MS_SYNC);
    munmap(mem1, size);
    munmap(mem2, size);

    return 0;
}
