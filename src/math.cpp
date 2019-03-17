#include "math.h"

namespace lak
{
    float mod(const float A, const float B)
    {
        const int64_t frac = (int64_t)(A / B);
        const float result = A - ((float)frac * B);
        return result;
    }

    double mod(const double A, const double B)
    {
        const int64_t frac = (int64_t)(A / B);
        const double result = A - ((double)frac * B);
        return result;
    }
}