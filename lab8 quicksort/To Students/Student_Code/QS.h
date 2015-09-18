#pragma once
#include "QSInterface.h"
#include <sstream>

class QS :
	public QSInterface
{
private:
	int size = 0;
	int* my_array = new int[size];
public:
	QS();
	~QS();
	void sortAll();
	int medianOfThree(int left, int right);
	int partition(int left, int right, int pivotIndex);
	string getArray();
	int getSize();
	void addToArray(int value);
	bool createArray(int capacity);
	void clear();
	bool recSort(int left, int right, int pivotIndex);
};

