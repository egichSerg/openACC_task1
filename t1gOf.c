#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define PI2 6.28318530718

int main()
{
    float arr_sum = 0.f;
    int N = 10000000;
    float* arr = (float*)malloc(sizeof(float) * (N+1));
    double step = PI2 / N;

    #pragma acc data create(arr[0:N]) copy(arr_sum)
    {
        double global_rad_var = 0.0;

        for (int i = 0; i < N; i++)
        {
            arr[i] = sin(global_rad_var);
            global_rad_var += step;
        }

        #pragma acc parallel loop reduction(+:arr_sum)
        for (int i = 0; i < N; i++)
        {
            arr_sum += arr[i];
        }
    }

    printf("%f\n", arr_sum);
    printf("Done!\n");

    free(arr);

    return 0;
}
