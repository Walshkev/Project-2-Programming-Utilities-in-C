#include <stdio.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    FILE *fin = fopen(argv[1], "r");

    if (fin == NULL) {
        perror("not able to open file");
        return 1;
    }

    char buffer[2048];
    ssize_t bytesRead = read(fileno(fin), buffer, sizeof(buffer));

    if (bytesRead == -1) {
        perror("read error");
        return 1;
    }

    ssize_t bytesWritten = write(1, buffer, bytesRead);

    if (bytesWritten == -1) {
        perror("write error");
        return 1;
    }

    fclose(fin);
    return 0;
   
}




