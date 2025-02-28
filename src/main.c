#include <stdio.h>
#include "../include/graph.h"

int main(void)
{
    struct artefact a;
    struct artefactNode r = a.rootNode;

    GenerateArtefact(&a, 0);

    for(int i = 0; i < r.childrenCount; i++)
    {
        printf("Depth: %i, id: %s", r.children[i].depth, r.children[i].id);
    }
}
