#ifndef TREESTRUCT_H
#define TREESTRUCT_H

struct leaf{
    int value;
    struct leaf *right, *left;
};

#endif
