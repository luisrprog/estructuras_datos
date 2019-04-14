#ifndef _queue
#define _queue
#define True 1
#define False 0
#define MAX 100

typedef struct {
    char name[MAX];
    int id;
    int time;
} Customer;

typedef struct {
    Customer customer[MAX];
    int first;
    int last;
    int size;
} Master_Queue;
typedef Master_Queue * MQ;

MQ createQueue();
int emptyQueue(MQ);
int next(int);
Customer pop(MQ);
void push(MQ, Customer);
Customer firstQueue(MQ);

#endif