#include <stdio.h>
#include <stdlib.h>
#include "../include/graph.h"

int main(void)
{
    struct artefact a; // New artefact

    GenerateArtefact(&a, 0); // Generating new one

    printf("%s\n", NodeToString(a.rootNode)); // Printing it's info
}
