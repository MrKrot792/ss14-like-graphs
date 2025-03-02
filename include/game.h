#pragma once

#define ESMALL "Extremely small!" // 0-4
#define PSMALL "Pretty small"     // 4-8
#define SMALL "Small"             // 8-12
#define MEDIUM "Medium"           // 12-16
#define PBIG "Pretty big"         // 16-20
#define GIANT "Giant!"            // 20-255, i guess?

char *CalculateSize(unsigned char s);
