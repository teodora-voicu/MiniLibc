#ifndef TIME_H
#define TIME_H

struct timespec {
    long int tv_sec;
    long   tv_nsec;
};


int nanosleep(const struct timespec *requested_time, struct timespec *remaining_time);

#endif
