#include "graph.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void AddChild(struct artefactNode *node, struct artefactNode c)
{
    struct artefactNode *temp = realloc(&(node->children), (node->childrenCount + 1) * sizeof(struct artefactNode));

    node->children = temp;
    node->children[node->childrenCount] = c;

    free(temp);
}

void RandomizeThisNode(struct artefactNode *node, unsigned int s,
                       bool highPrecision) // If s == 0, then seed would be random
{
    long int r;

    // Seed {{{
    if (s != 0)
    {
        srandom(s);
    }
    else
    {
        if (highPrecision)
        {
            struct timespec ts;
            clock_gettime(CLOCK_MONOTONIC, &ts);
            srandom(ts.tv_nsec);
        }
        else
        {
            srandom(time(NULL));
        }
    }
    //}}}

    // Random ID {{{
    for (int i = 0; i < 5; i++)
    {
        r = random() % 10;
        node->id[i] = r + '0';
    }

    node->id[5] = '\0';
    //}}}

    // Random children {{{
    r = random() % 100;

    int probability = 100 - exp(node->depth);

    if (r < probability) // Node has childrens!
    {
        node->childrenCount = random() % 3 + 1;
        node->children = (struct artefactNode *)malloc(node->childrenCount * sizeof(struct artefactNode));

        // Initialize childrens
        // Not random yet...
        for (int i = 0; i < node->childrenCount; i++)
        {
            node->children[i] = (struct artefactNode){0};
            node->children[i].depth = node->depth + 1;
        }
    }
    else // Dead end...
    {
        node->children = NULL;
    }

    for (int i = 0; i < node->childrenCount; i++)
    {
        RandomizeThisNode(&node->children[i], 0, true);
        node->children[i].parent = node;
    }
    // }}}
}

void GenerateArtefact(struct artefact *thisArtefact, unsigned int s)
{
    thisArtefact->rootNode = (struct artefactNode){.depth = 0, .parent = NULL};
    RandomizeThisNode(&thisArtefact->rootNode, s, true);

    // Not used yet
    // srandom(s);
    // long int r = random();
}

char *NodeToString(struct artefactNode node, bool depthDepended)
{
    char *depthTab;

    if (depthDepended)
    {
        depthTab = (char *)malloc(node.depth * sizeof(char) + 1);
        for (int i = 0; i < node.depth; i++)
        {
            depthTab[i] = '\t';
        }

        depthTab[-1] = '\0';
    }
    else
    {
        depthTab = (char *)malloc(sizeof(char));
        depthTab[0] = '\0';
    }

    int edges = (node.parent != NULL) ? node.childrenCount + 1 : node.childrenCount;
    int size =
        snprintf(NULL, 0, "%sID: %s \n%sParent's ID: %s \n%sActivated: %d \n%sDepth: %d \n%sEdges: %d \n", depthTab,
                 node.id, depthTab, node.parent->id, depthTab, node.activated, depthTab, node.depth, depthTab, edges);

    char *result = malloc(size) + 1;

    snprintf(result, size, "%sID: %s \n%sParent's ID: %s \n%sActivated: %d \n%sDepth: %d \n%sEdges: %d \n", depthTab,
             node.id, depthTab, node.parent->id, depthTab, node.activated, depthTab, node.depth, depthTab, edges);

    result[-1] = '\0';

    return result;
}
