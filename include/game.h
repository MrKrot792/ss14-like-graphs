#pragma once

#define ESMALL "Extremely small!" // 0-4
#define PSMALL "Pretty small"     // 4-8
#define SMALL "Small"             // 8-12
#define MEDIUM "Medium"           // 12-16
#define PBIG "Pretty big"         // 16-20
#define GIANT "Giant!"            // 20-255, i guess?

enum size
{
    small,  // 0
    medium, // 1
    big,    // 2
    giant   // 3
};

char *CalculateSize(unsigned char s);

int CalculateChildCount(unsigned char c, enum size s);
