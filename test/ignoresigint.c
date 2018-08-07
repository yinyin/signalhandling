#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#include "signalhandling/signalhandling.h"

int main(int argc, char *const argv[]) {
    int i;
    for (i = 3; i > 0; i--) {
        printf("SIGINT with default handler... %d\n", i);
        sleep(1);
    }
    ignore_signal(SIGINT);
    for (i = 3; i > 0; i--) {
        unsigned int unslept_sec;
        printf("SIGINT ignored... %d\n", i);
        unslept_sec = sleep(10);
        printf("unslept second = %d\n", (int)(unslept_sec));
    }
    printf("Exiting...\n");
    return 0;
}
