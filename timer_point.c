#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>




int timer_create(clockid_t clockid, struct sigevent *sevp, timer_t *timerid);

timer_create(): _POSIX_C_SOURCE >= 