#include <stdio.h>

int main(void){

    int c;
    int leftP = 0, rightP = 0;
    int leftB = 0, rightB = 0;
    
    int valid = 1;
    while((c = getchar()) != EOF){
        if(valid && c == '"')
            valid = 0;
        else if (c == '"')
            valid = 1;
        
        if(valid){
            if(c == '(')
                leftP++;
            else if (c == ')')
                rightP++;
            else if (c == '{')
                leftB++;
            else if (c == '}')
                rightB++;
        }
    }

    if(leftP == rightP)
        printf("\nparenthesis are all right");
    else
        printf("\nthere are parenthesis without a pair");

    if(leftB == rightB)
        printf("\nall brackets have a pair");
    else 
        printf("\nthere are brackets without pair");

}