#ifndef TWINLINKNODE_H_INCLUDED
#define TWINLINKNODE_H_INCLUDED

typedef struct charNodeTag charNode;

struct charNodeTag{
    char letter;
    charNode *prevNode;
    charNode *nextNode;
};

charNode *createCharNode(char aChar);

void freeCharNode(charNode *theNode);

#endif // TWINLINKNODE_H_INCLUDED
