#include "../include/graph.h"
#include <stdio.h>

int main(void)
{
    struct artefact a; // New artefact
    int ejdj;

    GenerateArtefact(&a, 0); // Generating new one

    printf("%s\n", NodeToString(a.rootNode, true)); // Printing it's info
    for (int i = 0; i < a.rootNode.childrenCount; i++)
    {
        printf("%s\n", NodeToString(a.rootNode.children[i], true));
        printf("%c", '\n');
        for (int j = 0; j < a.rootNode.children[i].childrenCount; j++)
        {
            printf("%s\n", NodeToString(a.rootNode.children[i].children[j], true));
            printf("%c", '\n');
        }
    }
}
