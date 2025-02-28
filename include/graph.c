#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include "graph.h"

void AddChild(struct artefactNode* node, struct artefactNode c)
{
    struct artefactNode* temp = realloc(&(node->children), (node->childrenCount + 1) * sizeof(struct artefactNode));

    node->children = temp;
    node->children[node->childrenCount] = c;

    free(temp);
}

void RandomizeThisNode(struct artefactNode* node, unsigned int s, bool highPrecision) // If s == 0, then seed would be random
{
    long int r;

    // Seed {{{
    if(s != 0)
    {
        srandom(s);
    }
    else
    {
        if(highPrecision)
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
    
    for (int i = 0; i < 5; i++)  
    {
        r = labs(random()) % 10;  // Ensuring a non-negative value
        node->id[i] = '0' + r;
    }
    node->id[5] = '\0';
    //}}}
    
    // Random children {{{
    r = random() % 100;
    
    unsigned char probability = 100 - exp(node->depth);
    
    if(r > probability) // Node has childrens!
    {
        node->childrenCount = random % 3 + 1;
        node->children = (struct artefactNode*)malloc(node->childrenCount * sizeof(struct artefactNode));

        // Initialize childrens
        // Not random yet...
        for(int i = 0; i < node->childrenCount; i++)
        {
            node->children[i] = { 0 };
        }
    }
    else // Dead end...
    {
        node->children = NULL;
    }

    //for(int i = 0; i < node->childrenCount; i++)
    //{
        //RandomizeThisNode(&node->children[i], 0, true);
    //}
    // }}}
}

void GenerateArtefact(struct artefact* thisArtefact, unsigned int s)
{
    thisArtefact->rootNode = (struct artefactNode) { 0 };
    RandomizeThisNode(&thisArtefact->rootNode, s, true);

    // Not used yet
    //
    //srandom(s);
    //long int r = random();
}
