#pragma once

/*
*Author: Turan Mert Duran
*Date: 22.04.2020
* Id : 21601418
*/
class Doctor
{
public:
	Doctor();
	Doctor(int id);
	bool getAvailable();
	int getId();
	int getAvTime();
	void setAv(bool ava);

private:
	int id;
	int avTime;
	bool available;
};


