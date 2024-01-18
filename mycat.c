#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    int input_fd;
    ssize_t bytes_read;
    char buffer[BUFFER_SIZE];

    if (argc == 1) {
        // No files specified, read from stdin
        input_fd = 0;
    } else {
        // Loop through the files specified on the command line
        for (int i = 1; i < argc; i++) {
            input_fd = open(argv[i], O_RDONLY);
            if (input_fd == -1) {
                perror("Error opening file");
                exit(EXIT_FAILURE);
            }

            // Read from the file and write to stdout
            while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
                if (write(1, buffer, bytes_read) != bytes_read) {
                    perror("Error writing to stdout");
                    exit(EXIT_FAILURE);
                }
            }

            if (bytes_read == -1) {
                perror("Error reading file");
                exit(EXIT_FAILURE);
            }

            // Close the file
            if (close(input_fd) == -1) {
                perror("Error closing file");
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}
