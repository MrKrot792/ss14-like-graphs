#include "../include/graph.h"
#include <stdio.h>

int count = 0;

void PrintTree(artNode Art)
{
    printf("%s\n", NodeToString(Art, true));
    printf("%c", '\n');
    for (int i = 0; i < Art.childrenCount; i++)
    {
        PrintTree(Art.children[i]);
        count++;
    }
}

int main(void)
{
    art a; // New artefact

    GenerateArtefact(&a, 0); // Generating new one

    PrintTree(a.rootNode);
    printf("%d\n", count + 1);
}
