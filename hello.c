#include<stdio.h>

#define MAX 100

unsigned long long power(int base, int elevate);
int getlinha(char s[],int lim);
long htoi(char hex[]);
void squeeze(char excluded[], char compare[]);

char input[MAX];
char exclude[MAX];
int main(void){
    
    getlinha(input, MAX);
    getlinha(exclude, MAX);

    squeeze(input, exclude);

    printf("%s\n", input);
    
};

unsigned long long power(int base, int elevate){
    
    unsigned long long result = base;
    for (int i = 1; i< elevate; i++){
        result *= base;
    }
    return result;
};

int getlinha(char s[],int lim)
{
    int c, i;
    for (i=0; (i < lim-1) && ((c=getchar())!=EOF) && (c!='\n'); ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
};

long htoi(char hex[]){
    long result = 0;

    for(int i = 0; hex[i] != '\n'; i++){
        if(hex[i] >= '0' && hex[i] <= '9'){
            result = result * 16 + hex[i] - 48;
        }else if(hex[i] >= 'a' && hex[i] <= 'f'){
            result = result * 16 + hex[i] - 87;
        }else if(hex[i] >= 'A' && hex[i] <= 'F'){
            result = result * 16 + hex[i] - 55;
        }
    }

    return result;
};

void squeeze(char excluded[], char compare[]){
    printf("started\n\n");
    for(int i = 0; excluded[i] != '\0'; i++){
        printf("%i\n", i);

        for(int j = 0; compare[j] != '\0'; j++){
            printf("  %i\n", j);
            
            if(excluded[i] == compare[j]){
                for(int k = i; excluded[k] != '\0'; k++){
                    excluded[k] = excluded[k + 1];
                }
                i--;

                break;
            }
        }
    }

};