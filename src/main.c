#include "game.h"
#include "graph.h"
#include <stdbool.h>
#include <stdio.h>

unsigned int count = 0;

int main(void)
{
    art a;

    GenerateArtefact(&a, 0, big);

    PrintTree(a.rootNode, &count);
    printf("%d\n", count + 1); // Debug info
    printf("%s\n", CalculateSize(count));

    FreeArtefact(&a);
    return 0;
}
