#include <stdio.h>

int main(){
    int n, m, p;
    scanf("%d %d %d",&n, &m, &p);
    int vez=1, pinguins=1, rodada=1;

    while(rodada<=n){
        for(int j=0; j<pinguins && rodada<=n; j++){
            if(vez==p){
                if(pinguins==1){
                    printf("%d pinguim\n", pinguins);
                }else{
                    printf("%d pinguins\n", pinguins);

                }
            }
            vez++;
            rodada++;
            vez = vez>m ? 1 : vez;

        }
        for(int j=0; j<pinguins && rodada<=n; j++){
             if(vez==p)
                printf("no gelo\n");
            vez++;
            rodada++;
            vez = vez>m ? 1 : vez;
        }
        for(int j=0; j<pinguins && rodada<=n; j++){
             if(vez==p)
                printf("uhuu!\n");
            vez++;
            rodada++;
            vez = vez>m ? 1 : vez;
        }
        pinguins++;
    }
}