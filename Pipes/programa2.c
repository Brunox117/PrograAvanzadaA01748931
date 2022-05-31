// Usa mkfifo para enviar mensajes cada 10 segundos, con un timestamp 
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
int main()
{
    int fd;
    char * myfifo = "/tmp/myfifo";

    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);
    int time = 10;
    int i = 0;
    while(i<time) {
          /* write "Hi" to the FIFO */
          fd = open(myfifo, O_WRONLY);
          write(fd, "Hi", sizeof("Hi"));
          close(fd);
          sleep(10);
          i++;
        }
    /* remove the FIFO */
    unlink(myfifo);

    return 0;
}
