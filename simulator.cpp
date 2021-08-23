#include "maxHeap1.h"
//#include "maxHeap2.h"
#include "Doctor.h"
#include "Patient.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
/*
*Author: Turan Mert Duran
*Date: 22.04.2020
* Id : 21601418
*/

int main(int argc, char* argv[]) {
    ifstream input;
    input.open(argv[1]);
    int averageWaitingTime = stoi(argv[2]);
    if (!input)
        cout << "Unable to open file!" << endl;

    int noOfPatients;
    input >> noOfPatients;
    Patient* pDatas = new Patient[noOfPatients];
    int id;
    int priority;
    int arrival;
    int examination;

    for (int i = 0; i < noOfPatients; i++) {
        input >> id >> priority >> arrival >> examination;
        //Patient* newPatient = new Patient(id, priority, arrival, examination);
        Patient newlyPatient(id, priority, arrival, examination);
        pDatas[i] = newlyPatient;
    }
    float avTime = 100;
    int totalAvTime = 0;
    int dctrNo = 1;
    float reg = avTime;
    do {

        if (avTime < averageWaitingTime) {
            dctrNo--;
            cout << "Minimum number of doctors required: " << dctrNo << endl;
            cout << endl;
            cout << "Simulation with " << dctrNo << " doctors:" << endl;
            cout << endl;
        }

        maxHeap nwHeap;
        int patientCtr = 0;
        int time = 0;
        totalAvTime = 0;

        int* avTimes = new int[dctrNo];
        Doctor* doctors = new Doctor[dctrNo];
        for (int i = 0; i < dctrNo; i++) {
            //Try Doctor* nwDoctor = new Doctor(i);
            Doctor nwDoctor(i);
            avTimes[i] = 0;
            doctors[i] = nwDoctor;
        }


        while (patientCtr < noOfPatients || nwHeap.sizeGet() != 0) {

              // IF OPERATION COMPLETED THEN SET AV. OF DOCTORS TRUE AND AVAILABLE TIMES OF THEM 0
            for (int i = 0; i < dctrNo; i++) {
                if (avTimes[i] == time) {
                    avTimes[i] = 0;
                    doctors[i].setAv(true);
                }
            }
            // IF MORE THAN ONE PATIENT COMES IN AT SAME TIME
            while (pDatas[patientCtr].getArriveTime() == time && patientCtr < noOfPatients) {
                nwHeap.insert(pDatas[patientCtr]);
                patientCtr++;

            }

            // IF THERE IS AT LEAST ONE PATIENT WAITS
            for (int i = 0; i < dctrNo; i++) {

                // CHECK IF AVAILABLE DOCTOR IS THERE
                if (doctors[i].getAvailable() == true && nwHeap.sizeGet() != 0) {

                    doctors[i].setAv(false);
                    Patient temp = nwHeap.extractTop();
                    avTimes[i] = time + temp.getExaTime();
                    totalAvTime = (totalAvTime + (time - temp.getArriveTime()));

                    if(avTime < averageWaitingTime)
                        cout << "Doctor " << i << " takes patient " << temp.getId() << " at minute " << time << " (wait: " << time - temp.getArriveTime() << " mins )" << endl;

                }
            }

            // INCREASE OF TIME
            time++;
            
        }
        if (avTime < averageWaitingTime)
            cout << " Average waiting time: " << (float)avTime << " minutes." << endl;
         reg = avTime;
        avTime = (float)totalAvTime / (float) noOfPatients;
        dctrNo++;
        cout.precision(4);
        delete[] doctors;
        delete[] avTimes;
    } while (reg > averageWaitingTime);

    // NEWLY DELETE
    delete[] pDatas;
    input.close();

}

