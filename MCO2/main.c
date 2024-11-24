// XU, Donald G.
// TAN, Richmond T.

#define _CRT_SECURE_NO_WARNINGS //for scanf
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


extern void asm_imgCvtGrayIntToDouble(int** int_array, double** double_array, int height, int width);


void c_imgCvtGrayIntToDouble(int** int_array, double** c_double_array, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            c_double_array[i][j] = (double)int_array[i][j] / 255.0;
        }
    }
}

void rand_array(int** int_array, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int_array[i][j] = rand() % 256; //random pixel value in range [0, 255]
        }
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));// for rand
    //dimensions
    int height, width;
    double temp;

    //get input , w h
    printf("Input: \n");
    scanf("%d %d", &height, &width);

    //double float array, pixel values
    int** int_array = (int**)malloc(height * sizeof(int*));

    double** c_double_array = (double**)malloc(height * sizeof(double*));
    double** asm_double_array = (double**)malloc(height * sizeof(double*));
    for (int i = 0; i < height; i++) {
        int_array[i] = (int**)malloc(width * sizeof(int*));
        c_double_array[i] = (double*)malloc(width * sizeof(double));
        asm_double_array[i] = (double*)malloc(width * sizeof(double));
    }
  
    //read pixel values and initialize
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%lf", &temp);
            //initialize
            int_array[i][j] = temp;
            c_double_array[i][j] = temp;
            asm_double_array[i][j] = temp;
        }
    }
    //run main functions without time testing
    c_imgCvtGrayIntToDouble(int_array, c_double_array, height, width);
    asm_imgCvtGrayIntToDouble(int_array, asm_double_array, height, width);

    //print c output
    printf("-----------------\n");
    printf("Results in C\n");
    printf("Output:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", c_double_array[i][j]);
        }
        printf("\n");
    }

    //print asm output
    printf("-----------------\n");
    printf("Results in ASM\n");
    printf("Output:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%.2f ", asm_double_array[i][j]);
        }
        printf("\n");
    }


    //Time test with random values generated
    //run for 30 times
    //height: 1000, width: 1000 
    //Timing for C ; run 30 times
    //number of tests
    int tests = 30;
    //time elapsed
    double c_elapsed_time = 0, asm_elapsed_time = 0;
    int tempheight = 1000;
    int tempwidth = 1000;

    //allocate array
    int** tempint_array = (int**)malloc(tempheight * sizeof(int*));

    double** tempc_double_array = (double**)malloc(tempheight * sizeof(double*));
    double** tempasm_double_array = (double**)malloc(tempheight * sizeof(double*));
    for (int i = 0; i < tempheight; i++) {
        tempint_array[i] = (int**)malloc(tempwidth * sizeof(int*));
        tempc_double_array[i] = (double*)malloc(tempwidth * sizeof(double));
        tempasm_double_array[i] = (double*)malloc(tempwidth * sizeof(double));
    }

    //random input
    rand_array(tempint_array, tempheight, tempwidth);

    clock_t c_total_time = 0;
    for (int t = 0; t < tests; t++) {
        // Restore the original values
        for (int i = 0; i < tempheight; i++) {
            for (int j = 0; j < tempwidth; j++) {
                tempc_double_array[i][j] = (double)tempint_array[i][j] / 255.0;
            }
        }
        clock_t c_start = clock();
        c_imgCvtGrayIntToDouble(tempint_array, tempc_double_array, tempheight, tempwidth);
        clock_t c_end = clock();
        c_total_time += (c_end - c_start);
    }
    c_elapsed_time = ((double)(c_total_time) / CLOCKS_PER_SEC / tests) *1000;
    // Timing for Assembly ; run 30 times
    clock_t asm_total_time = 0;
    for (int t = 0; t < tests; t++) {
        // Restore the original values
        for (int i = 0; i < tempheight; i++) {
            for (int j = 0; j < tempwidth; j++) {
                tempasm_double_array[i][j] = (double)tempint_array[i][j] / 255.0;
            }
        }
        clock_t asm_start = clock();
        asm_imgCvtGrayIntToDouble(tempint_array, tempasm_double_array, tempheight, tempwidth);
        clock_t asm_end = clock();
        asm_total_time += (asm_end - asm_start);
    }
    asm_elapsed_time = ((double)(asm_total_time) / CLOCKS_PER_SEC / tests) *1000;


    printf("-----------------\n");
    printf("Time Elapsed\nAverage time of %d tests\n", tests);
    printf("Tested with Image Dimensions of\nHeight:%d Width:%d\n", tempheight, tempwidth);
    printf("C: %f ms\n", c_elapsed_time);
    printf("ASM: %f ms\n", asm_elapsed_time);


    //free malloc , end of program
    for (int i = 0; i < height; i++) {
        free(int_array[i]);
        free(c_double_array[i]);
        free(asm_double_array[i]);
        free(tempint_array[i]);
        free(tempc_double_array[i]);
        free(tempasm_double_array[i]);
    }
    free(c_double_array);
    free(asm_double_array);
    free(int_array);
    free(tempc_double_array);
    free(tempasm_double_array);
    free(tempint_array);
    return 0;
 
}
