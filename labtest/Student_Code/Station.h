#pragma once
//#include "StationInterface.h"
#include "StationInterfaceExtra.h"
#include "LinkedList.h"
class Station :
	public StationInterfaceExtra
{
private:
	/*struct Car
	{
		Car(int id_var)
		{
			id = id_var;
		}
		int id;
		
	};*/
	int car_id;
	LinkedList<int> station_car;
	LinkedList<int> queue_cars;
	LinkedList<int> deque_cars;
	LinkedList<int> stack_cars;
	LinkedList<int> IRdeque_cars;
	LinkedList<int> ORdeque_cars;
	int CURRENT_CAR = 1;
	int CAPACITY = 5;

public:
	Station();
	~Station();

	bool addToStation(int car);
	int showCurrentCar();
	bool removeFromStation();
	bool addToStack();
	bool removeFromStack();
	int showTopOfStack();
	int showSizeOfStack();
	bool addToQueue(); 
	bool removeFromQueue();
	int showTopOfQueue();
	int showSizeOfQueue();
	bool addToDequeLeft();
	bool addToDequeRight();
	bool removeFromDequeLeft();
	bool removeFromDequeRight();
	int showTopOfDequeLeft();
	int showTopOfDequeRight();
	int showSizeOfDeque();

	//Extra Credit
	bool addToIRDequeLeft();
	bool removeFromIRDequeLeft();
	bool removeFromIRDequeRight();
	int showTopOfIRDequeLeft();
	int showTopOfIRDequeRight();
	int showSizeOfIRDeque();
	bool addToORDequeLeft();
	bool addToORDequeRight();
	bool removeFromORDequeLeft();
	int showTopOfORDequeLeft();
	int showSizeOfORDeque();
};

