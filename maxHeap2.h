#pragma once
#include "Patient.h"
/*
*Author: Turan Mert Duran
*Date: 22.04.2020
* Id : 21601418
*/

class maxHeap
{
public:
    maxHeap();
    ~maxHeap();
    void insert(Patient newPatient);
    Patient extractTop();
    int sizeGet();
    int get(int index);
    void rebuildAfterInsert(int root);
    void rebuildAfterTop(int root);
   

private:
    int arSize;
    int size; 
    Patient* items;
};

