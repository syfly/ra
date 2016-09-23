#include <stdio.h>
//t0 = 2607 kb t1=13458kb t2=2256kb t3= 4797 kb t4= 2218 kb t5=5717kb t6= 4395kb t7=1753kb t8=4012kb t9=3591kb t10=1985

#define STAT_COUNT 14
#define ERROR_BOUND 1000000 //e
#define THRESHOLD 0.0 //e
#define INIT_WIGHT 0.5

int alculate_throughout(int *throughout, int *estimateThroughout, int *estimateTDiff,
    int *caculateTDiff, float *predicateWeight, int n)
{
    float dfi = 0;
    float weight = 0;
    int D = 0;
    int diff = 0;
    if (n == 0)
    {
        dfi = 1.0f;
        if (dfi <= ERROR_BOUND)
        {
            weight = INIT_WIGHT * (1 - THRESHOLD);
        }
        else
        {
            weight = INIT_WIGHT * (1 + THRESHOLD);
        }

        diff = throughout[n] - 0;
        D = weight * diff;
        predicateWeight[n] = weight;
        estimateTDiff[n] = D;
        estimateThroughout[n] = 0;

        estimateThroughout[n+1] = throughout[n] + D;

        fprintf(stdout, "n=%d abs dfi=%f weight=%f Diff diff=%d D=%d\n", n, dfi, weight, diff, D);
    }
    else
    {
        dfi = 1.0f * abs(throughout[n] - estimateThroughout[n]) / throughout[n];

        if (dfi <= ERROR_BOUND)
        {
            weight = predicateWeight[n-1] * (1 - THRESHOLD);
        }
        else
        {
            weight = predicateWeight[n-1] * (1 + THRESHOLD);
        }

        diff = throughout[n] - throughout[n-1];
        D = (1 - weight) * estimateTDiff[n-1] + weight * diff;
        estimateTDiff[n] = D;
        predicateWeight[n] = weight;

        estimateThroughout[n+1] = throughout[n] + D;
        fprintf(stdout, "n=%d abs  dfi=%f weight=%f Diff=%d diff=%d D=%d\n", n, dfi, weight, estimateTDiff[n-1], diff, D);
    }

    
}

void ra_algorithm()
{
    int throughout[STAT_COUNT] = {
        19269, 1228, 35856, 25335, 48285,
     24672, 52979, 10255, 19094, 18394,
      19071, 78935, 15193, 37815};
    //{2607, 13458, 2256, 4797, 2218, 5717, 4395, 1753, 4012, 3591};//T
    int estimateThroughout[STAT_COUNT] = {0};//^T

    int estimateTDiff[STAT_COUNT] = {0};//D
    int caculateTDiff[STAT_COUNT] = {2607};//d

    float predicateWeight[STAT_COUNT] = {0.5};//a

    int index = 0;
    while (index < STAT_COUNT)
    {
        alculate_throughout(throughout, estimateThroughout, estimateTDiff, caculateTDiff, predicateWeight, index++);
    }

    int i = 0;
    for (i = 0; i < STAT_COUNT; ++i)
    {
        fprintf(stdout, "[%d] throughout=%d estimateThroughout=%d\n", i, throughout[i], estimateThroughout[i]);
    }
}

int main(int argc, char const *argv[])
{
    char *ip = NULL;
    fprintf(stdout, "main %s\n", ip);
    ra_algorithm();
    return 0;
}