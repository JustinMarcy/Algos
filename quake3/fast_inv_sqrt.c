//single precision
float fast_inv_sqrt_32(float number, unsigned int newton_iters)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = * (long *) &y;
    i = 0x5f3759df - (i >> 1);
    y = * (float * ) &i;
    for (unsigned int j=0; j<newton_iters; j++)
    {
        y = y * (threehalfs - (x2 * y * y) );
    }

    return y;
}

// double precision
double fast_inv_sqrt_64(double number, unsigned int newton_iters)
{
    long i; // TODO: long is still 32 bits in WIN64
    double x2, y;
    const double threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = * (long *) &y;
    i = 0x5FE6EB3BF5709A00 - (i >> 1);
    y = * (double * ) &i;

    for (unsigned int j=0; j<newton_iters; j++)
    {
        y = y * (threehalfs - (x2 * y * y) );
    }

    return y;
}