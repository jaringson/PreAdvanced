#include "Station.h"
//#include "LinkedList.h"


Station::Station()
{
}


Station::~Station()
{
}

bool Station::addToStation(int car)
{
	if (car <= 0)
	{
		return false;
	}
	//Car* tempcar = new Car(car);
	bool proceed = true;
	if (queue->find(car))
	{
		proceed = false;
	}
	else if (deque->find(car))
	{
		proceed = false;
	}
	else if (stack->find(car))
	{
		proceed = false;
	}
	else if (irdeque->find(car))
	{
		proceed = false;
	}
	else if (ordeque->find(car))
	{
		proceed = false;
	}
	else
	{
		proceed = true;
	}
	if (station_car.size() >= 1)
	{
		proceed = false;
	}

	if (proceed)
	{
		station_car.insertHead(car);
		return true;
	}
	else
	{
		return false;
	}
	
}

int Station::showCurrentCar()
{
	if (station_car.size() == 0 || station_car.size() > CURRENT_CAR)
	{
		return -1;
	}
	else
	{
		return station_car.at(0);
	}
}

bool Station::removeFromStation()
{
  if (station_car.size() == 0 || station_car.size() > CURRENT_CAR)
	{
		return false;
	}
	else
	{
		station_car.clear();
		return true;
	}
}

//Stack---------------------------------------------------------------
bool Station::addToStack()
{
	if (station_car.size() <= 0)
	{
		return false;
	}
	if (stack->size() >= CAPACITY)
	{
		return false;
	}
	else
	{
		stack->push(station_car.at(0));
		station_car.clear();
		return true;
	}

	
}
bool Station::removeFromStack()
{
	if (station_car.size() >= 1)
	{
		return false;
	}
	else
	{
		station_car.insertHead(stack->pop());
		return true;
	}
	
}
int Station::showTopOfStack()
{
  if(stack->size() == 0)
    {
      return -1;
    }
  else 
    {
	return stack->top();
    }
}
int Station::showSizeOfStack()
{
	return stack->size();
}

//Queue--------------------------------
bool Station::addToQueue()
{
	if (station_car.size() <= 0)
	{
		return false;
	}
	if (queue->size() >= CAPACITY)
	{
		return false;
	}
	else
	{
		queue->push(station_car.at(0));
		station_car.clear();
		return true;
	}
}
bool Station::removeFromQueue()
{
	if (station_car.size() >= 1 || queue->size() <= 0)
	{
		return false;
	}
	else
	{
		station_car.insertHead(queue->pop());
		return true;
	}
}
int Station::showTopOfQueue()
{
	return queue->front();
}
int Station::showSizeOfQueue() 
{
	return queue->size();
}

//Deque-------------------------------
bool Station::addToDequeLeft()
{
	if (station_car.size() <= 0 || deque->size() >= CAPACITY)
	{
		return false;
	}
	else
	{
		deque->push_left(station_car.at(0));
		station_car.clear();
		return true;
	}
}
bool Station::addToDequeRight()
{
	if (station_car.size() <= 0 || deque->size() >= CAPACITY)
	{
		return false;
	}
	else
	{
		deque->push_right(station_car.at(0));
		station_car.clear();
		return true;
	}
}
bool Station::removeFromDequeLeft()
{
	if (station_car.size() >= 1 || deque->size() <= 0)
	{
		return false;
	}
	else
	{
		station_car.insertHead(deque->pop_left());
		return true;
	}
	
}
bool Station::removeFromDequeRight()
{ 
	if (station_car.size() >= 1 || deque->size() <= 0)
	{
		return false;
	}
	else
	{
		station_car.insertHead(deque->pop_right());
		return true;
	}
}
int Station::showTopOfDequeLeft()
{
	if (deque->size() <= 0)
	{
		return -1;
	}
	else
	{
		return deque->top_left();
	}
}
int Station::showTopOfDequeRight()
{

	if (deque->size() <= 0)
	{
		return -1;
	}
	else
	{
		return deque->top_right();
	}
}
int Station::showSizeOfDeque()
{
	return deque->size();
}

//Extra Credit
//IRDeque--------------------------------
bool Station::addToIRDequeLeft()
{
	if (station_car.size() <= 0 || irdeque->size() >= CAPACITY)
	{
		return false;
	}
	else
	{
		irdeque->push_left(station_car.at(0));
		station_car.clear();
		return true;
	}
}
bool Station::removeFromIRDequeLeft()
{
	if (station_car.size() >= 1 || irdeque->size() <= 0)
	{
		return false;
	}
	else
	{
		station_car.insertHead(irdeque->pop_left());
		return true;
	}
}
bool Station::removeFromIRDequeRight()
{
	if (station_car.size() >= 1 || irdeque->size() <= 0)
	{
		return false;
	}
	else
	{
		station_car.insertHead(irdeque->pop_right());
		return true;
	}
}
int Station::showTopOfIRDequeLeft()
{
	if (irdeque->size() <= 0)
	{
		return -1;
	}
	else
	{
		return irdeque->top_left();
	}
}
int Station::showTopOfIRDequeRight()
{
	if (irdeque->size() <= 0)
	{
		return -1;
	}
	else
	{
		return irdeque->top_right();
	}
}
int Station::showSizeOfIRDeque()
{
	return irdeque->size();
}

//ORDeque------------------------------------------
bool Station::addToORDequeLeft()
{
	if (station_car.size() <= 0 || ordeque->size() >= CAPACITY)
	{
		return false;
	}
	else
	{
		ordeque->push_left(station_car.at(0));
		station_car.clear();
		return true;
	}
}
bool Station::addToORDequeRight()
{
	if (station_car.size() <= 0 || ordeque->size() >= CAPACITY)
	{
		return false;
	}
	else
	{
		ordeque->push_right(station_car.at(0));
		station_car.clear();
		return true;
	}
}
bool Station::removeFromORDequeLeft()
{
	if (station_car.size() >= 1 || ordeque->size() <= 0)
	{
		return false;
	}
	else
	{
		station_car.insertHead(ordeque->pop_left());
		return true;
	}
}
int Station::showTopOfORDequeLeft()
{
	if (ordeque->size() <= 0)
	{
		return -1;
	}
	else
	{
		return ordeque->top_left();
	}
}
int Station::showSizeOfORDeque()
{
	return ordeque->size();
}
