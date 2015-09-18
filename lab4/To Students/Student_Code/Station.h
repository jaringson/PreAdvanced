#pragma once
#include "StationInterfaceExtra.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Deque.h"
#include "Queue.h"
#include "IRDeque.h"
#include "ORDeque.h"

class Station :
	public StationInterfaceExtra
{
private:
	
	int car_id;
	Deque* deque = new Deque();
	Queue* queue = new Queue();
	Stack* stack = new Stack();
	IRDeque* irdeque = new IRDeque();
	ORDeque* ordeque = new ORDeque();

	LinkedList<int> station_car;

	int CURRENT_CAR = 1;
	int CAPACITY = 5;

public:
	Station();
	~Station();

	bool addToStation(int car);
	int showCurrentCar();
	bool removeFromStation();
	virtual bool addToStack();
	virtual bool removeFromStack();
	virtual int showTopOfStack();
	virtual int showSizeOfStack();
	virtual bool addToQueue();
	virtual bool removeFromQueue();
	virtual int showTopOfQueue();
	virtual int showSizeOfQueue();
	virtual bool addToDequeLeft();
	virtual bool addToDequeRight();
	virtual bool removeFromDequeLeft();
	virtual bool removeFromDequeRight();
	virtual int showTopOfDequeLeft();
	virtual int showTopOfDequeRight();
	virtual int showSizeOfDeque();

	//Extra Credit
	virtual bool addToIRDequeLeft();
	virtual bool removeFromIRDequeLeft();
	virtual bool removeFromIRDequeRight();
	virtual int showTopOfIRDequeLeft();
	virtual int showTopOfIRDequeRight();
	virtual int showSizeOfIRDeque();
	virtual bool addToORDequeLeft();
	virtual bool addToORDequeRight();
	virtual bool removeFromORDequeLeft();
	virtual int showTopOfORDequeLeft();
	virtual int showSizeOfORDeque();
};

