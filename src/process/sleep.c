#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>


unsigned int sleep(unsigned int seconds) {
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;

    while (nanosleep(&req, &rem) == -1) {
        if (errno == EINTR) {
            req = rem;
        } else {
            return seconds - req.tv_sec;
        }
    }

    return 0;
}
