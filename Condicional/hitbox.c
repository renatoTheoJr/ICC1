
#include <stdio.h>

int main(){
    long long int x1, y1, largura1, altura1;
    long long int x2, y2, largura2, altura2;

    scanf("%lld %lld %lld %lld", &x1, &y1, &largura1, &altura1);
    scanf("%lld %lld %lld %lld", &x2, &y2, &largura2, &altura2);
    long long int xfinal=0, yfinal=0, larguraFinal =0, alturaFinal=0;
    if ( (x1+largura1 >= x2 && x2 >= x1 && ((y1+altura1 >= y2 && y2 >= y1) || (y2<=y1 && y1<=y2+altura2))) ||
         ( x2 <= x1 && x1<=x2+largura2 && ((y1+altura1 >= y2 && y2 >= y1) || (y2<=y1 && y1<=y2+altura2)))
    ){
        if(x1+largura1 >= x2 && x2 >= x1 ){
            xfinal=x2;
            if(x2+largura2 > x1+largura1){
                larguraFinal = x1+largura1-x2;
                larguraFinal =  larguraFinal >=0 ? larguraFinal :  -1*larguraFinal;
            }else{
                larguraFinal = largura2;
            }
        }else{
            xfinal=x1;
            if(x1+largura1 > x2+largura2){
                larguraFinal = x2+largura2-x1;
                larguraFinal =  larguraFinal >=0 ? larguraFinal :  -1*larguraFinal;
            }else{
                larguraFinal = largura1;
            }
        }
        if(y1+altura1 >= y2 && y2 >= y1){
            yfinal=y2;
            if(y2+altura2>y1+altura1){
                alturaFinal = y1+altura1-y2;
                alturaFinal = alturaFinal >= 0 ? alturaFinal : -1 *alturaFinal;
            }else{
                alturaFinal = altura2;
            }
        }else{
            yfinal =y1;
             if(y1+altura1>y2+altura2){
                alturaFinal = y2+altura2-y1;
                alturaFinal = alturaFinal >= 0 ? alturaFinal : -1 *alturaFinal;
            }else{
                alturaFinal = altura1;
            }
        }
        printf("HIT: %lld %lld %lld %lld", xfinal, yfinal, larguraFinal, alturaFinal);
     }
    else{
        printf("MISS");
    }

    return 0;
     
     
}