#include<stdio.h>
#include<math.h>
#include"fast_inv_sqrt.c"

// Check for 64-bit environment
#if _WIN64 || __x86_64__ || __ppc64__
#define ENV64
#endif

double percent_diff_64(double x, unsigned int newton_iters)
{
    double math_lib_inv_sqrt = (1/sqrt(x));
    return ( ( fast_inv_sqrt_64(x,newton_iters) - math_lib_inv_sqrt ) / math_lib_inv_sqrt )*100;
}

float percent_diff_32(float x, unsigned int newton_iters)
{
    float math_lib_inv_sqrt = (1/sqrt(x));
    return ( ( fast_inv_sqrt_32(x,newton_iters) - math_lib_inv_sqrt ) / math_lib_inv_sqrt )*100;
}

int main() {

    printf("Welcome! Lets evaluate the fast inverse square root algorithm");
    printf("Enter a float to perform an inverse square operation on: ");
#ifdef ENV64
    double x;
    scanf("%lf", &x);
    printf("\nquake3: %lf", fast_inv_sqrt_64(x,1));
    printf("\nusing std sqrt: %lf", (1/sqrt(x)));
    printf("\npercent diff w/ 1 Newton-Raphson iteration: %lf %%", percent_diff_64(x,1));
    printf("\npercent diff w/ 2 Newton-Raphson iteration: %lf %%\n", percent_diff_64(x,2));
#else // 32-bit
    float x;
    scanf("%f", &x);
    printf("\nquake3: %f", fast_inv_sqrt_32(x,1));
    printf("\nusing std sqrt: %f", (1/sqrt(x)));
    printf("\npercent diff w/ 1 Newton-Raphson iteration: %f", percent_diff_32(x,1));
    printf("\npercent diff w/ 2 Newton-Raphson iteration: %f\n", percent_diff_32(x,2));
#endif

    return 0;
}