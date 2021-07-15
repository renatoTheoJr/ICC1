/* @author Renato Tadeu Theodoro Junior
   @USP  11796750
   @Title [5 - Alocação Dinâmica] Padding de Imagens
*/
#include <stdio.h>
#include<stdlib.h>

int main(){
    int width = 0, height = 0;

    scanf("%d", &width);
    scanf("%d", &height);

    int **image = malloc(height * sizeof(int *));
    for(int i = 0; i < height; i++){
        image[i] = malloc(width * sizeof(int));
        for(int j = 0; j < width; j++){
            scanf("%d", &image[i][j]);
        }
    }

    int padding = 0; 
    scanf("%d", &padding);

    int newWidth = width + 2 * padding, newHeight = height + 2 * padding;

    int **newImage = malloc(newHeight * sizeof(int *));
    for(int i = 0; i < newHeight; i++){
        newImage[i] = malloc(newWidth * sizeof(int));
        for(int j = 0; j < newWidth; j++){
            if((i > padding - 1 && i < height + padding) && (j > padding - 1 && j < width + padding)){
                newImage[i][j] = image[i - padding][j - padding];
            }else{
                newImage[i][j] = 0;
            }
            printf("%d ", newImage[i][j]);
        }
        printf("\n");
        free(newImage[i]);
    }
    printf("\n");
    free(newImage);

    for(int i = 0; i < height; i++){
        for(int  j = 0; j < width; j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
        free(image[i]);
    }
    free(image);

    return 0;
}