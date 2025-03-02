#include "game.h"
#include <math.h>

char *CalculateSize(unsigned char s)
{
    if (s >= 4 && s < 8)
    {
        return PSMALL;
    }
    else if (s >= 8 && s < 12)
    {
        return SMALL;
    }
    else if (s >= 12 && s < 16)
    {
        return MEDIUM;
    }
    else if (s >= 16 && s < 20)
    {
        return PBIG;
    }
    else if (s >= 20)
    {
        return GIANT;
    }
    else
    {
        return ESMALL;
    }
}

int CalculateChildCount(unsigned char c, enum size s) // Chance is from 0-100
{
    float chance = c - 100;

    if (s == small)
    {
        /*
         * Chances are:
         * - 1 ~ 95.0%
         * - 2 ~ 03.5%
         * - 3 ~ 01.5%
         */

        double result = exp(4.1 * chance / 20.0 + 1.0);
        return (result == 0) ? 1 : ceil(result);
    }
    else if (s == medium)
    {
        /*
         * Chances are:
         * - 1 ~ 80.0%
         * - 2 ~ 14.0%
         * - 3 ~ 06.0%
         */

        double result = exp(1.0 * chance / 20.0 + 1.0);
        return (result == 0) ? 1 : ceil(result);
    }
    else if (s == big) // BEST VARIANT
    {
        /*
         * Chances are:
         * - 1 ~ 71.0%
         * - 2 ~ 20.0%
         * - 3 ~ 09.0%
         */

        double result = exp(0.7 * chance / 20.0 + 1.0);
        return (result == 0) ? 1 : ceil(result);
    }
    else // Also is good
    {
        /*
         * Chances are:
         * - 1 ~ 50.0%
         * - 2 ~ 35.0%
         * - 3 ~ 15.0%
         */

        double result = exp(0.4 * chance / 20.0 + 1.0);
        return (result == 0) ? 1 : ceil(result);
    }
}
