#include "maxHeap2.h"
#include <iostream>
/*
*Author: Turan Mert Duran
*Date: 22.04.2020
* Id : 21601418
*/
maxHeap::maxHeap()
{
	size = 0;
	// BY DEFAULT CASE OUR MAX SIZE STARTS WITH 10 AND WE INCREASE OR DECREASE ITS SIZE IN INSERT AND EXTRACT METHODS
	items = new Patient[10];
	arSize = 10;
}

maxHeap::~maxHeap()
{
	//std::cout << "DESTRUCTOR CALLED" << std::endl ;
	delete[] items;
}

void maxHeap::insert(Patient newPatient)
{
	// IF SIZE REACHED THE MAXIMUM ( MAX NUM OF DYNAMIC ARRAY) WE RECREATE ARRAY WITH DOUBLE OF ITS SIZE
	if (size == arSize) {
		arSize = arSize * 2;	
		Patient* temp = new Patient[size];
		for (int i = 0; i < size; i++) {
			temp[i] = items[i];
		}
		delete[] items;
		// DELETE ITEMS BEFORE ....*************************
		items = new Patient[arSize];
		for (int i = 0; i < size; i++) {
			items[i] = temp[i];
		}
		delete[] temp;
		// DELETE TEMP....*************************
	}
	
	items[size] = newPatient;
	size++;
	rebuildAfterInsert(size - 1);
	
}

Patient maxHeap::extractTop()
{
	// REMOVING FIRST ITEM IN THE TREE AND GIVING LAST INDEXED PATIENT TO FIRST INDEX
	// AND DECREASE SIZE BY ONE AND REAGAIN BUILDING TREE 
	Patient max = items[0];
	items[0] = items[size - 1];
	size--;
	// IF OUR SIZE IS LESS THAN HALF OF  DYNAMIC ARRAY'S SIZE'S WE RECREATE OUR DYNAMIC ARRAY AND DECREASE SIZE BY HALF
	if (size < (arSize / 2)) {
		arSize = arSize / 2;
		// DELETE TEMP BEFORE ....*************************
		Patient* temp = new Patient[size];
		for (int i = 0; i < size; i++) {
			temp[i] = items[i];
		}
		delete[] items;
		// DELETE TEMP BEFORE ....*************************
		items = new Patient[arSize];
		for (int i = 0; i < size; i++) {
			items[i] = temp[i];
		}
		delete[] temp;
	}
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
	// DECLARING INDEXES OF CHILDS
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
