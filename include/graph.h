#pragma once
#include <stdbool.h>

typedef struct artefactNode
{
    char id[6];
    unsigned char depth;
    bool activated;

    char *activation;
    char *stimulator;
    unsigned short points;

    struct artefactNode *parent;   // Pointer
    struct artefactNode *children; // Array
    unsigned char childrenCount;

} artNode;

void AddChild(struct artefactNode *node, struct artefactNode c);

void RandomizeThisNode(struct artefactNode *node, unsigned int s, bool highPrecision); // Children nodes won'tbe random

char *NodeToString(struct artefactNode node, bool depthDepended);

void GeneratePoins(struct artefactNode *node);

void FreeNode(struct artefactNode *node);

void PrintTree(artNode Art, unsigned int *count);

typedef struct artefact
{
    struct artefactNode rootNode;

} art;

void GenerateArtefact(struct artefact *thisArtefact, unsigned int s);

void FreeArtefact(struct artefact *thisArtefact);
