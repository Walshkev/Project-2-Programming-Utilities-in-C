#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    int fin;
    ssize_t bytes_read;
    char buffer[BUFFER_SIZE];

    if (argc == 1) {
        
        fin = 0;
    } else {

        for (int i = 1; i < argc; i++) {
            fin = open(argv[i], O_RDONLY);
         
            bytes_read = read(fin, buffer, BUFFER_SIZE);
            write(1, buffer, bytes_read);


            if (bytes_read == -1) {
                perror("Error reading file");
                exit(EXIT_FAILURE);
            }
            close(fin) ;
        }
   
    }

    return 0;
}
