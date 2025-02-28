#include <stdio.h>
#include "../include/graph.h"

int main(void)
{
    struct artefact a;
    struct artefactNode r = a.rootNode;

    GenerateArtefact(&a, 0);

    printf("%s\n", NodeToString(&r));

    
}
