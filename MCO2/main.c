#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



//extern void imgCvtGrayIntToDouble();
void c_imgCvtGrayIntToDouble(double** double_array, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            double_array[i][j] /= 255.0; //divide
        }
    }
}

int main(int argc, char* argv[]) {
    int height, width;

    //get input , w h
    printf("Input: \n");
    scanf("%d %d", &height, &width);

    //double float array, pixel values
    double** double_array = (double**)malloc(height * sizeof(double*));
    for (int i = 0; i < height; i++) {
        double_array[i] = (double*)malloc(width * sizeof(double));
    }

    //read pixel values
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%lf", &double_array[i][j]);
        }
    }

    c_imgCvtGrayIntToDouble(double_array, height, width);


    //print output
    printf("Output:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", double_array[i][j]);
        }
        printf("\n");
    }



    //free malloc , end of program
    for (int i = 0; i < height; i++) {
        free(double_array[i]);
    }
    free(double_array);
    return 0;
}
