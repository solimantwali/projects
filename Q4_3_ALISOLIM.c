#include <stdio.h>


int prob2038(long long int time, long long int n){
    long long int timax = (0b1 << (n-1)) - 1;
    printf("max time is %lld\n");
    if (time >= timax)              {return 1;}
    else                            {return 0;}
}

int main(void){
    return 0;
}

