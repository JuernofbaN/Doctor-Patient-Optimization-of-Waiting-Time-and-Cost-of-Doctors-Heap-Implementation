#include "Patient.h"
/*
*Author: Turan Mert Duran
*Date: 22.04.2020
* Id : 21601418
*/
Patient::Patient() {

}
Patient::Patient(int id, int priority, int arriveTime, int examinationTime)
{
	this->id = id;
	this->priority = priority;
	this->arriveTime = arriveTime;
	this->examinationTime = examinationTime;
}

int Patient::getId()
{
	return id;
}

int Patient::getArriveTime()
{
	return arriveTime;
}

int Patient::getExaTime()
{
	return examinationTime;
}

int Patient::getPriority()
{
	return priority;
}

void Patient::operator=(const Patient& patio)
{
	priority = patio.priority;
	arriveTime = patio.arriveTime;
	examinationTime = patio.examinationTime;
	id = patio.id;
}
