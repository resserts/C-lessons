#include<stdio.h>

unsigned setbits(unsigned x, unsigned y, int p, int n);
unsigned invertbits(unsigned x, int p, int n);
int bitcount(unsigned x);

unsigned value = 0b10101010;
unsigned change = 0b110;


int main(void){

    printf("%u\n", change);
    printf("%i\n", bitcount(value));

}


unsigned setbits(unsigned x, unsigned y, int p, int n){

    unsigned changeable = (y & ~(~0 << n)) << (p - n);

    return ((x & ~((~(~0 << n)) << (p - n))) | changeable);
    //return changeable;

};

int bitcount(unsigned x){
    int b;

    for(b = 0; x != 0; x &= (x - 1)){
        b++;
    }

    return b;
}