#include<iostream>
#include"heap.h"

PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;
	if (MaxElements < MinPQSize)
		Error("Priority queue size is too small");

	H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
	if (H == NULL)
		FatalError("Out of space!!!");

	H->Elements = (int*)(malloc((MaxElements + 1) * sizeof(int)));
	if (H->Elements == NULL)
		FatalError("Out of space!!!");

	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MinData;
	
	return H;
}

void Insert(int X, PriorityQueue H)
{
	int i;

	if (IsFull(H))
	{
		Error("Priority queue is full");
		return;
	}
	for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = X;
}

int DeleteMin(PriorityQueue H)
{
	int i, Child;
	int MinElements, LastElements;
	if (IsEmpty(H))
	{
		Error("Priority queue is empty");
		return H->Elements[0];
	}
	MinElements = H->Elements[1];
	LastElements = H->Elements[H->Size--];

	for (i = 1; i * 2 <= H->Size; i = Child)
	{
		Child = i * 2;
		if (Child != H->Size & Child + 1] < H->Elements[Child])
			Child++;
		if (LastElements > H->Elements[Child])
			H->Elements[i] = H->Elements[Child];
		else
			break;
	}
	H->Elements[i] = LastElements;
	return MinElements;
}