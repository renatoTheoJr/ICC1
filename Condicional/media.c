#include <stdio.h>

int main(){
    double a, b, c, d, result=0, min=0;

    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    if(a<b && a<c && a<d)
        min = a;
    else if(b<c && b<d)
        min = b;
    else if(c<d){
        min = c;
    }
    else
        min = d;

    result = (a+b+c+d-min)/3;

    printf("%.4lf", result);
    return 0;


}