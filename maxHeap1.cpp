#include "maxHeap1.h"
/*
*Author: Turan Mert Duran
*Date: 22.04.2020
* Id : 21601418
*/
void swap(Patient* a, Patient* b) {
	Patient* temp;
	temp = a;
	a = b;
	b = temp;
}
maxHeap::maxHeap()
{
	size = 0;
}

void maxHeap::insert(Patient newPatient)
{
	// IF SIZE REACHED THE MAXIMUM WE CANNOT TAKE PATIENT
	if (size <= MAX_HEAP) {
		items[size] = newPatient;
		size++;
		// Rearranging  heap after inserting
		rebuildAfterInsert(size - 1);
	}
}

Patient maxHeap::extractTop()
{
	// REMOVING FIRST ITEM IN THE TREE AND GIVING LAST INDEXED PATIENT TO FIRST INDEX
	// AND DECREASE SIZE BY ONE AND REAGAIN BUILDING TREE 
	Patient max = items[0];
	items[0] = items[size - 1];
	size--;
	rebuildAfterTop(0);
	return max;

}


int maxHeap::sizeGet()
{
	return size;
}

void maxHeap::rebuildAfterInsert(int root)
{
	//DECLARING INDEX OF PARENT
	int parentIndex = (root - 1) / 2;

	// CONTROLLING IF PARENT'S PRIORTIY IS BIGGER THAN OR NOT
	if (root > 0 && items[parentIndex].getPriority() < items[root].getPriority()) 
	{
		// IF PARENTS PRIORITY LESS THAN ITS CHILD MAKING SWAP
		Patient temp = items[root];
		items[root] = items[parentIndex];
		items[parentIndex] = temp;
		rebuildAfterInsert(parentIndex);
	}
}
void maxHeap::rebuildAfterTop(int root)
{
	// DECLARING INDEXES OF CHILDREN
	int leftChild = (root * 2) + 1;
	int rightChild = (root * 2) + 2;
	int biggest = root;

	if (leftChild < size) {
		// CHECKING WHETHER PRIORTIY OF CURRENT IS LESS THAN LEFT OR NOT
		if (items[leftChild].getPriority() > items[root].getPriority())
			biggest = leftChild;
		else if (items[leftChild].getPriority() == items[root].getPriority() && items[leftChild].getArriveTime() < items[root].getArriveTime())
			biggest = leftChild;
	}
	
	if (rightChild < size) {
		// CHECKING WHETHER PRIORTIY OF CURRENT IS LESS THAN RIGHT OR NOT
		if (items[rightChild].getPriority() > items[biggest].getPriority())
			biggest = rightChild;
		else if (items[rightChild].getPriority() == items[biggest].getPriority() && items[rightChild].getArriveTime() < items[root].getArriveTime())
			biggest = rightChild;
	}
	// IF AT THE END BIGGEST CHANGED SOMEWHERE, WE CHANGE THE ITEMS BETWEEN THESE 
	if (biggest != root) {
		Patient temp = items[root];
		items[root] = items[biggest];
		items[biggest] = temp;
		rebuildAfterTop(biggest);
	}
}
