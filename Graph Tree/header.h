#ifndef HEADER_H
#define HEADER_H


struct vertex {
    int value; 
    struct vertex *next;
};

struct vertex *createVertex(int);

struct graph{
    unsigned long long vertexCount;
    struct vertex **adjLists;
    int *visited;
};

struct queue {
  int items[500];
  int front;
  int rear;
};

struct vertex *createVertex(int value);
struct graph *createGraph(unsigned long long vertices);
void addEdge(struct graph *graphTree, int origin, int endpoint);
void displayGraph(struct graph *graphTree);

void breadth (struct graph *graphTree, int startVertex);

struct queue* createQueue(void);
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

#endif
