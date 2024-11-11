#include <stdio.h>
#include <ctype.h>
char input;
void converCase()
{
    if(input>= 'A' && input<= 'Z') putchar(tolower(input));
    if(input>= 'a' && input<= 'z') putchar(toupper(input));
}

int main(){
    scanf("%c", &input);
    converCase();

    return 0;
}