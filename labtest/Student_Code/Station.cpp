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
	if (queue_cars.find(car))
	{
		proceed = false;
	}
	else if (deque_cars.find(car))
	{
		proceed = false;
	}
	else if (stack_cars.find(car))
	{
		proceed = false;
	}
	else if (IRdeque_cars.find(car))
	{
		proceed = false;
	}
	else if (ORdeque_cars.find(car))
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
		//delete tempcar;
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

bool Station::addToStack()
{
	if (station_car.size() <= 0)
	{
		return false;
	}
	if (stack_cars.size() >= CAPACITY)
	{
		return false;
	}
	else 
	{
		stack_cars.insertHead(station_car.at(0));
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
		station_car.insertHead(stack_cars.at(0));
		stack_cars.remove(stack_cars.at(0));
		return true;
	}
}

int Station::showTopOfStack()
{
	if (stack_cars.size() == 0)
	{
		return -1;
	}
	else
	{
		return stack_cars.at(0);
	}

}

int Station::showSizeOfStack()
{
	return stack_cars.size();
}

bool Station::addToQueue()
{
	if (station_car.size() <= 0)
	{
		return false;
	}
	if (queue_cars.size() >= CAPACITY)
	{
		return false;
	}
	else
	{
		queue_cars.insertTail(station_car.at(0));
		station_car.clear();
		return true;
	}
}

bool Station::removeFromQueue()
{
	if (station_car.size() >= 1 || queue_cars.size() <= 0)
	{
		return false;
	}
	else
	{
		station_car.insertHead(queue_cars.at(0));
		queue_cars.remove(queue_cars.at(0));
		return true;

	}
}

int Station::showTopOfQueue()
{
	if (queue_cars.size() <= 0)
	{
		return -1;
	}
	else
	{
		return queue_cars.at(0);
	}
}

int Station::showSizeOfQueue()
{
	return queue_cars.size();
}

bool Station::addToDequeLeft()
{
	if (station_car.size() <= 0 || deque_cars.size() >= CAPACITY)
	{
		return false;
	}
	else
	{
		deque_cars.insertHead(station_car.at(0));
		station_car.clear();
		return true;
	}
}

bool Station::addToDequeRight()
{
	if (station_car.size() <= 0 || deque_cars.size() >= CAPACITY)
	{
		return false;
	}
	else
	{
		deque_cars.insertTail(station_car.at(0));
		station_car.clear();
		return true;
	}
}

bool Station::removeFromDequeLeft()
{
	if (station_car.size() >= 1 || deque_cars.size() <= 0)
	{
		return false;
	}
	else
	{
		station_car.insertHead(deque_cars.at(0));
		deque_cars.remove(deque_cars.at(0));
		return true;
	}
}

bool Station::removeFromDequeRight()
{
	if (station_car.size() >= 1 || deque_cars.size() <= 0)
	{
		return false;
	}
	else
	{
		station_car.insertHead(deque_cars.at(deque_cars.find_end()));
		deque_cars.remove(deque_cars.at(deque_cars.find_end()));
		return true;
	}
}

int Station::showTopOfDequeLeft()
{
	if (deque_cars.size() <= 0)
	{
		return -1;
	}
	else
	{
		return deque_cars.at(0);
	}
}

int Station::showTopOfDequeRight()
{
	if (deque_cars.size() <= 0)
	{
		return -1;
	}
	else
	{
		return deque_cars.at(deque_cars.find_end());
	}
}

int Station::showSizeOfDeque()
{
	return deque_cars.size();
}
//-------------------------------------
bool Station::addToIRDequeLeft()
{
	if (station_car.size() <= 0 || IRdeque_cars.size() >= CAPACITY)
	{
		return false;
	}
	else
	{
		IRdeque_cars.insertHead(station_car.at(0));
		station_car.clear();
		return true;
	}
}

bool Station::removeFromIRDequeLeft()
{
	if (station_car.size() >= 1 || IRdeque_cars.size() <= 0)
	{
		return false;
	}
	else
	{
		station_car.insertHead(IRdeque_cars.at(0));
		IRdeque_cars.remove(IRdeque_cars.at(0));
		return true;
	}
}
bool Station::removeFromIRDequeRight()
{
	if (station_car.size() >= 1 || IRdeque_cars.size() <= 0)
	{
		return false;
	}
	else
	{
		station_car.insertHead(IRdeque_cars.at(IRdeque_cars.find_end()));
		IRdeque_cars.remove(IRdeque_cars.at(IRdeque_cars.find_end()));
		return true;
	}
}
int Station::showTopOfIRDequeLeft()
{
	if (IRdeque_cars.size() <= 0)
	{
		return -1;
	}
	else
	{
		return IRdeque_cars.at(0);
	}
}
int Station::showTopOfIRDequeRight()
{
	if (IRdeque_cars.size() <= 0)
	{
		return -1;
	}
	else
	{
		return IRdeque_cars.at(IRdeque_cars.find_end());
	}
}
int Station::showSizeOfIRDeque()
{
	return IRdeque_cars.size();
}

//-----------------------------
bool Station::addToORDequeLeft()
{
	if (station_car.size() <= 0 || ORdeque_cars.size() >= CAPACITY)
	{
		return false;
	}
	else
	{
		ORdeque_cars.insertHead(station_car.at(0));
		station_car.clear();
		return true;
	}
}
bool Station::addToORDequeRight()
{
	if (station_car.size() <= 0 || ORdeque_cars.size() >= CAPACITY)
	{
		return false;
	}
	else
	{
		ORdeque_cars.insertTail(station_car.at(0));
		station_car.clear();
		return true;
	}
}
bool Station::removeFromORDequeLeft()
{
	if (station_car.size() >= 1 || ORdeque_cars.size() <= 0)
	{
		return false;
	}
	else
	{
		station_car.insertHead(ORdeque_cars.at(0));
		ORdeque_cars.remove(ORdeque_cars.at(0));
		return true;
	}
}
int Station::showTopOfORDequeLeft()
{
	if (ORdeque_cars.size() <= 0)
	{
		return -1;
	}
	else
	{
		return ORdeque_cars.at(0);
	}
}
int Station::showSizeOfORDeque()
{
	return ORdeque_cars.size();
}
