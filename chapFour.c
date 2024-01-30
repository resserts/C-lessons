#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAXLINE 1000 /* maximum input line length */

int getlinha(char line[], int max);
int strindex(char source[], char searchfor[]);
double atof(char s[]);

char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main(void)
{
    char line[MAXLINE];
    int found = 0;
    while (getlinha(line, MAXLINE) > 0)
        printf("%f\n", atof(line));

    return found;
}

/* getline: get line into s, return length */
int getlinha(char line[], int max)
{
    int c, i;
    i = 0;
    while (--max > 0 && (c=getchar()) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
        ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

double atof(char s[])
{
    double val, power;
    int i, sign, elevate;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;

    sign = (s[i] == '-') ? -1 : 1;
    
    if (s[i] == '+' || s[i] == '-')
        i++;
    
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    
    if (s[i] == '.')
        i++;
    
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e'){
        i++;

        for(elevate = 0; isdigit(s[i]); i++){
            elevate = 10.0 * elevate + (s[i] - '0');
        }
    }

    return pow((sign * val / power), elevate);
}