#pragma once
#include "Patient.h"
/*
*Author: Turan Mert Duran
*Date: 22.04.2020
* Id : 21601418
*/
const int MAX_HEAP = 2000;

class maxHeap
{
public:
    maxHeap();
    void insert(Patient newPatient);
    Patient extractTop();
    int sizeGet();
    int get(int index);
    void rebuildAfterInsert(int root);
    void rebuildAfterTop(int root);
   

private:
    Patient items[MAX_HEAP];
    int size;
};

