#include <stdio.h>

int main(){
    int n=0;

    if(!scanf("%i", &n))
        return 0;
    if(n%11 == 0 && n%13==0 && n%19==0){
        printf("BaDumTssTss");
        return 0;
    }
    if(n%11 == 0 && n%13==0){
        printf("BaDumDum");
        return 0;
    }
    if(n%11 == 0 && n%19==0){
        printf("BaDumTss");
        return 0;
    }
    if(n%13 == 0 && n%19==0){
        printf("DumDumTss");
        return 0;
    }
    if(n%11==0){
        printf("BaBa");
        return 0;
    }
    if(n%13==0){
        printf("BaDum");
        return 0;
    }
    if(n%19==0){
        printf("BaTss");
        return 0;
    }
    printf("%d", n);
    return 0;
    
}