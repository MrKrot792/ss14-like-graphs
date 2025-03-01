#include "../include/graph.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

#define ESMALL "Extremely small!" // 0-4
#define PSMALL "Pretty small"     // 4-8
#define SMALL "Small"             // 8-12
#define MEDIUM "Medium"           // 12-16
#define PBIG "Pretty big"         // 16-20
#define GIANT "Giant!"            // 20-255, i guess?

unsigned char count = 0;

void PrintTree(artNode Art)
{
    char *output;
    output = NodeToString(Art, true);
    printf("%s\n", output);
    printf("%c", '\n');

    for (int i = 0; i < Art.childrenCount; i++)
    {
        PrintTree(Art.children[i]);
        count++;
    }

    free(output);
}

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

int main(void)
{
    art a;
    char *artefactsSize;

    GenerateArtefact(&a, 0);
    artefactsSize = CalculateSize(count + 1);

    PrintTree(a.rootNode);
    printf("%d\n", count + 1);
    printf("%s\n", artefactsSize);

    // free(artefactsSize); // Yeah... an error
    FreeArtefact(&a);
}
