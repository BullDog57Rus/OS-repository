#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int background = 0;

char *read_line(void) {
    char *line = NULL;
    ssize_t bufsize = 0;
    getline(&line, (size_t *) &bufsize, stdin);
    return line;
}

char **split_line(char *line) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens) {
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\r\n\a");
    while (token != NULL) {
        if (strcmp(token, "&") == 0) {
            background = 1;
        }
        tokens[position] = token;
        position++;
        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;
    return tokens;
}

int execute(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        execvp(args[0], args);
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        if (background) {
            return 1;
        }
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int start(char **args) {
    if (args[0] == NULL) {
        // An empty command was entered.
        return 1;
    }

    return execute(args);
}

int main() {
    char *line;
    char **args;

    while (1) {
        printf("> ");
        line = read_line();
        args = split_line(line);
        start(args);

        free(line);
        free(args);
    }
}
