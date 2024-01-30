#include<stdio.h>
#include<time.h>
#include<math.h>

#define MAX_SIZE 1000

int twobinsearch(int x, int v[], int n);
int onebinsearch(int x, int v[], int n);
int getText(char s[],int lim);
void escape(char s[], char copied[]);
void expand(char s1[], char s2[]);
int itob(int n, char s[], int b);

char input[MAX_SIZE];
char output[MAX_SIZE];


int main(void){

    if(itob(238579, output, 8)){
        printf("%s\n", output);
    }

}


int twobinsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;


    while (low < high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }

    return -1; /* no match */
}

int onebinsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;


    while (low < high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (x == v[mid]){
        return mid;
    }
    
    return -1; /* no match */
}

void escape(char s[], char copied[]){
    int copIndex = 0;
    for(int i = 0 ; s[i] != '\0'; i++){
        switch(s[i]){
            case '\t':
                copied[copIndex++] = '\\';
                copied[copIndex++] = 't';
            case '\n':
                copied[copIndex++] = '\\';
                copied[copIndex++] = 'n';
                copied[copIndex++] = '\n';
        }

        copied[copIndex++] = s[i];

        printf("%i\n", i);
    }

    copied[copIndex] = '\0';
}

int getText(char s[],int lim)
{
    int c, i;
    for (i=0; (i < lim-1) && ((c=getchar())!=EOF) && (c!='!'); ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
};

void expand(char s1[], char s2[]){

    int copyIndex = 0;

    for(int i = 0; s1[i] != '\0'; i++){
        if(s1[i] == '-'){
            
            if( s1[i - 1] >= 'a' && s1[i - 1] <= 'z' && s1[i + 1] >= 'a' && s1[i + 1] <= 'z' ||
                s1[i - 1] >= 'A' && s1[i - 1] <= 'Z' && s1[i + 1] >= 'A' && s1[i + 1] <= 'Z' ||
                s1[i - 1] >= '0' && s1[i - 1] <= '9' && s1[i + 1] >= '0' && s1[i + 1] <= '9'){
                if(s1[i + 1] > s1[i - 1]){
                    for(char j = s1[i - 1] + 1; j < s1[i + 1]; j++){
                        s2[copyIndex] = j;
                        copyIndex++;
                    }
                }  

                if(s1[i + 1] < s1[i - 1]){
                    for(char j = s1[i - 1] - 1; j > s1[i + 1]; j--){
                        s2[copyIndex] = j;
                        copyIndex++;
                    }
                }
            }

        }else{
            s2[copyIndex] = s1[i];
            copyIndex++;
        }

    }

    s2[copyIndex] = '\0';
}

int itob(int n, char s[], int b){
    
    if(b > 36){
        return -1;
    }



    int charQuant = 0;
    long max = 2147483648;
    while((max /= b) > 1){
        charQuant++;
    }

    int index = 0;
    int number = n;

    s[index++] = '0';
    s[index++] = 'x';

    for(int i = charQuant; i >= 0; i--){
        int currentBase = (int)pow(b, i);

        int quantity;
        for(quantity = 0; number >= currentBase; quantity++){
            number -= currentBase;
        }

        if(quantity >= 0 && quantity <= 9){
            s[index++] = '0' + quantity;
        }else{
            s[index++] = 'a' + quantity - 10;
        } 
    }

    s[index] = '\0';
    return 1;
}