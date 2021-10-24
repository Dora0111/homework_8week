#ifndef _BinHeap_H 

struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;

PriorityQueue Initailize(int MaxElements);
void Dsstrory(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(int X, PriorityQueue H);
int DeleteMin(PriorityQueue H);
int FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

#endif

struct HeapStruct
{
	int Capacity;
	int Size;
	int* Elements;
};
