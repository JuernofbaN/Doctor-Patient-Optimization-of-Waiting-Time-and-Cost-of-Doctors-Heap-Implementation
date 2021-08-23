
simulator_Q1: simulator.o Doctor.o Patient.o maxHeap1.o
	g++ simulator.o Doctor.o Patient.o maxHeap1.o -o simulator_Q1 -std=c++11
	
simulator.o: simulator.cpp
	g++ -c simulator.cpp -std=c++11

Doctor.o: Doctor.cpp
	g++ -c Doctor.cpp

Patient.o: Patient.cpp
	g++ -c Patient.cpp

maxHeap1.o:	maxHeap1.cpp
	g++ -c maxHeap1.cpp
	
clean:
	rm *.o simulator_Q1