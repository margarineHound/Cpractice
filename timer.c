#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

int main(int argc, char const *argv[])
{

//clock_t begin;
clock_t end;
double seconds;

printf("Please enter required time in seconds\n");
scanf("\n%lf", &seconds);

//double time_spent;
//begin = clock();
end = seconds*CLOCKS_PER_SEC + clock();


while(((double)clock() != end) && (round((double)(clock()/CLOCKS_PER_SEC))== ((double)(clock()/CLOCKS_PER_SEC))))
	printf("The time is %lf\n", (double)(clock()/CLOCKS_PER_SEC));

return 0;
}