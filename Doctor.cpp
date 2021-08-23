#include "Doctor.h"
/*
*Author: Turan Mert Duran
*Date: 22.04.2020
* Id : 21601418
*/
Doctor::Doctor()
{
	id = 0;
	available = true;
	avTime = 0;
}

Doctor::Doctor(int id)
{
	this->id = id;
	available = true;
	avTime = 0;
}

bool Doctor::getAvailable()
{
	return available;
}

int Doctor::getId()
{
	return id;
}

int Doctor::getAvTime()
{
	return avTime;
}

void Doctor::setAv(bool ava)
{
	available = ava;
}
