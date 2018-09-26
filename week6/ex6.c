#include <signal.h>
#include <printf.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int ch[2];
    pipe(ch);
    pid_t pid1 = fork();
    if (pid1 == 0) {
        //First child
        pid_t secondChild;
        close(ch[1]);
        read(ch[0], &secondChild, sizeof(pid_t));
        close(ch[0]);
        sleep(1);
        printf("I am child 1 (%d)\tI receive child 2 (%d)\n", getpid(), secondChild);
        sleep(6);
        printf("I am child 1 (%d)\tI am stopping child 2 (%d)\n", getpid(), secondChild);
        kill(secondChild, SIGSTOP);
        sleep(1);
        printf("Child 2 is stopped\n");
        sleep(1);
        printf("I am child 1 (%d)\tI am killing child 2 (%d)\n", getpid(), secondChild);
        kill(secondChild, SIGKILL);
        sleep(1);
        printf("Child 2 is killed\n");
    } else {
        printf("First child is up\n");
        pid_t pid2 = fork();
        if (pid2 == 0) {
            //Second child
            sleep(4);
            while (1) {
                printf("I am child 2 (%d)\tI am alive\n", getpid());
                sleep(1);
            }
        } else {
            sleep(1);
            printf("Second child is up\n");
            //Parent
            close(ch[0]);
            write(ch[1], &pid2, sizeof(pid_t));
            close(ch[1]);
            sleep(1);
            printf("I am parent\tI sent child 2 (%d) to child 1 (%d)\n", pid2, pid1);
            sleep(1);
            printf("Waiting for change state of 2\n");
            int child2code;
            pid_t child2 = waitpid(pid2, &child2code, 0);
            sleep(2);
            printf("Child 2 finished with code %d\n", child2code);
            return 0;
        }
    }
}
