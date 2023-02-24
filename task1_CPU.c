#include <stdio.h>
#include <malloc.h>
#include <math.h>

#define PI2 6.28318530718

void sin_arr(double** arr, int N)
{
    double step = PI2 / N;
    double global_rad_var = 0.0;

    (*arr) =(double*) malloc(sizeof(double) * (N + 1));
    for (int i = 0; i < N; i++)
    {
        (*arr)[i] = sin(global_rad_var);
        global_rad_var += step;
    }

}

int main()
{
    double* arr;
    int N = 10000000;
    sin_arr(&arr, N);

    double arr_sum = 0.0;
    for (int i = 0; i < N; i++)
    {
        arr_sum += arr[i];
    }
    printf("%lf\n", arr_sum);
    printf("Done!\n");
    return 0;
    
    free(arr);
}
