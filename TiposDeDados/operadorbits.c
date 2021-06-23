#include <stdio.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%i\n", a&b);
    printf("%i\n", a|b);
    printf("%i\n", a^b);
    printf("%i\n", ~a);
    printf("%i\n", ~b);
    printf("%i\n", a >> 2); //a right shif  2
    printf("%i\n", b << 2); //b left shift 2


}