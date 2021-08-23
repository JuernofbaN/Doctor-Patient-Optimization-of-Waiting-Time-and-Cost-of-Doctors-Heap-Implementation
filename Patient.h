#pragma once

/*
*Author: Turan Mert Duran
*Date: 22.04.2020
* Id : 21601418
*/
class Patient
{
public:
	Patient();
	Patient(int id, int priority, int arriveTime, int examinationTime);
	int getId();
	int getArriveTime();
	int getExaTime();
	int getPriority();
	void operator = (const Patient& patio);

private:
	int priority;
	int arriveTime;
	int examinationTime;
	int id;
};

