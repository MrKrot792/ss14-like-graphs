#include "game.h"

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
