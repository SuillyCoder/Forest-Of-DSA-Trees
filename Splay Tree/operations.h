#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "treeStruct.h"
#include "insertNode.c"
#include "deleteNode.c"

struct leaf *createLeaf(int value);
struct leaf *insertLeaf(struct leaf *root, int number);
struct leaf *deleteLeaf(struct leaf *root, int deletor, int foundIt);
struct leaf *minValue(struct leaf *root);

#endif