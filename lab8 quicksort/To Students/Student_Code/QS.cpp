#include "QS.h"


QS::QS()
{
}


QS::~QS()
{
	clear();
}

bool QS::recSort(int left, int right, int pivotIndex)
{
	//cout << "Hey " << endl;
	int number = partition(left, right, pivotIndex);
	if (number == -1)
	{
		//cout << "Hey 2" << endl;
		return true;
	}
	int pivot = QS::medianOfThree(left, number - 1);
	int pivot_two = QS::medianOfThree(number + 1, right);
	if (recSort(left, number - 1, pivot) && recSort(number + 1, right, pivot_two))
	{
		//cout << "Hey 3" << endl;
		return true;
	}
}

void QS::sortAll()
{
	bool run_sort;
	if (size > 0)
	{
		int end_position;
		for (int i = 0; i < size; i++)
		{
			if (my_array[i] == -1)
			{
				end_position = i - 1;
				i = size;
				//cout << "one" << endl;
			}
			else
			{
				//cout << "two" << endl;
				end_position = size - 1;
			}
		}
		int middle = QS::medianOfThree(0, end_position);
		/*cout << end_position << endl;
		system("pause");*/
		if (middle != -1)
		{
			run_sort = QS::recSort(0, end_position, middle);
		}
		if (run_sort){}
	}
}

int QS::medianOfThree(int left, int right)
{
	//Check if array is empty
	if (size <= 0)
	{
		//cout << "Hey 1" << endl;
		return -1;
	}
	int end_position;
	for (int i = 0; i < size; i++)
	{
		if (my_array[i] == -1)
		{
			end_position = i - 1;
			i = size;
		}
		else
		{
			end_position = size - 1;
		}
	}
	//Checking first interger is smaller than the first, and Boundaries
	if ((left > right-1) || (left < 0) || (right > end_position))
	{
		//cout << "Hey 2" << endl;
		return -1;
	}
	int middle = (left + right) / 2;
	/*cout << my_array[left] << endl;
	cout << my_array[right] << endl;
	cout << my_array[middle] << endl;
	system("pause");*/
	if (my_array[middle] < my_array[left])
	{
		//cout << "Hey 1" << endl;
		int temp = my_array[middle];
		my_array[middle] = my_array[left];
		my_array[left] = temp;
	}
	if (my_array[right] < my_array[middle])
	{
		//cout << "Hey 2" << endl;
		int temp = my_array[middle];
		my_array[middle] = my_array[right];
		my_array[right ] = temp;
	}
	if (my_array[middle] < my_array[left])
	{
		//cout << "Hey 3" << endl;
		int temp = my_array[middle];
		my_array[middle] = my_array[left];
		my_array[left] = temp;
	}
	return middle;
}

int QS::partition(int left, int right, int pivotIndex)
{
	int end_position = 0;
	for (int i = 0; i < size; i++)
	{
		if (my_array[i] == -1)
		{
			end_position = i - 1;
			i = size;
		}
		else
		{
			end_position = size - 1;
		}
	}
	//Checking first interger is smaller than the first, and Boundaries
	if ((left >= right) || (left < 0) || (right > end_position)) 
	{
		return -1;
	}
	//Checking if pivotIndex is between the two boundardies.
	if((pivotIndex < left) || (pivotIndex > right)) 
	{
		return -1;
	}
	int temp = my_array[pivotIndex];
	my_array[pivotIndex] = my_array[left];
	my_array[left] = temp;

	
	int up = left + 1;
	int down = right;
	do 
	{
		while ((up != right) && !(my_array[left] < my_array[up]))
		{
			up++;
		}
		while (my_array[left]< my_array[down])
		{
			down--;
		}
		if (up < down)
		{
			//swap up and down
			int temp = my_array[down];
			my_array[down] = my_array[up];
			my_array[up] = temp;
		}

	} while (up < down);

	//swap left and down
	int temp_two = my_array[down];
	my_array[down] = my_array[left];
	my_array[left] = temp_two;
	return down;
}

string QS::getArray()
{
	ostringstream output;
	for (int i = 0; i < size; i++)
	{
		if (my_array[i] != -1)
		{
			output << my_array[i];
			if ((i != size - 1) && (my_array[i+1] != -1))
			{
				output << ",";
			}
		}
	}
	return output.str();
	/*for (int i = 0; i < size; i++)
	{
	cout << my_array[i] << endl;
	}
	return "";*/
}

int QS::getSize()
{
	return size;
}

void QS::addToArray(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (my_array[i] == -1)
		{
			my_array[i] = value;
			/*for (int i = 0; i < size; i++)
			{
				cout << my_array[i] << endl;
			}*/
			return;
		}
	}
}

bool QS::createArray(int capacity)
{
	if (capacity < 0)
	{
		return false;
	}
	
	int* temp_array = new int[capacity];
	delete[] my_array;
	my_array = temp_array;
	size = capacity;
	for (int i = 0; i < size; i++)
	{
		my_array[i] = -1;
		//cout << my_array[i] << endl;
	}
	
	return true;

}

void QS::clear()
{
	size = 0;
	delete[] my_array;
	my_array = NULL;
}
