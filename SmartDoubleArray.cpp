#pragma one;
#include <iostream>
#include <cstring>
#include <math.h>
#include <cmath>
#include <random>
#include "SmartDoubleArray.h"
namespace lesson_9
{
	using namespace std;

	SmartDoubleArray::~SmartDoubleArray()
	{
		delete[] mas;
		mas = 0;
	}
	SmartDoubleArray::SmartDoubleArray() : arrSize(10)
	{
		mas = new int[arrSize];
		if (mas == 0)
		{
			std::cerr << "Can't allocate memory!!";
			exit(-1);
		}
		random_device MyRandom;
		for (int i = 0; i < arrSize; i++)
		{
			mt19937 gen(MyRandom());
			mas[i] = 1 + gen() % 100;
		}
		//memset(mas, 0, arrSize * sizeof(int));
	}

	SmartDoubleArray::SmartDoubleArray(int arr_size) : arrSize(arr_size)
	{
		mas = new int[arrSize];
		if (mas == 0)
		{
			std::cerr << "Can't allocate memory!!";
			exit(-1);
		}
		random_device MyRandom;
		for (int i = 0; i < arrSize; i++)
		{
			mt19937 gen(MyRandom());
			mas[i] = 1 + gen() % 100;
		}
		//memset(mas, 0, arrSize * sizeof(int));
	}

	int SmartDoubleArray::getSize() const// it is capacity
	{
		return (arrSize);
	}

	void SmartDoubleArray::Add(const int  value)
	{
		if (mas == 0)
		{
			std::cerr << "Can't allocate memory!!";
			exit(-1);
		}
		int *temp = new int[arrSize + 1];
		for (int i = 0; i < arrSize; i++)
		{
			temp[i] = mas[i];
		}
		arrSize++;
		temp[arrSize - 1] = value;
		delete[] mas;

		mas = temp;
		//delete[] temp;
	}

	void SmartDoubleArray::Insert(const  int index, const int  value)
	{
		if (mas == 0)
		{
			std::cerr << "Can't allocate memory!!";
			exit(-1);
		}
		if ((index <= 0)||(index>arrSize))
		{
			std::cerr << "Incorrect index!!";
			exit(-1);
		}
		int *temp = new int[arrSize + 1];
		for (int i = 0; i <= index+1; i++)
		{
			temp[i] = mas[i];
		}
		temp[index] = value;
		for (int i = index+1; i <= arrSize; i++)
		{
			temp[i+1] = mas[i];
		}
		delete[] mas;
		arrSize++;
		mas = new int[arrSize];
		mas = temp;
		//delete[] temp;
	}

	void SmartDoubleArray::remove(const int index)
	{
		if (mas == 0)
		{
			std::cerr << "Can't allocate memory!!";
			exit(-1);
		}
		if ((index <= 0) || (index>arrSize))
		{
			std::cerr << "Incorrect index!!";
			exit(-1);
		}
		int *temp = new int[arrSize - 1];
		for (int i = 0; i <= index; i++)
		{
			temp[i] = mas[i];
		}
		
		for (int i = index; i <= arrSize; i++)
		{
			temp[i-1] = mas[i];
		}
		delete[] mas;
		arrSize--;
		mas = new int[arrSize];
		mas = temp;
	}
	int SmartDoubleArray::GetAt(int index)
	{
		if (mas == 0)
		{
			std::cerr << "Can't allocate memory!!";
			exit(-1);
		}
		if ((index <= 0) || (index>arrSize))
		{
			std::cerr << "Incorrect index!!";
			exit(-1);
		}
		return mas[index];
	}

	int SmartDoubleArray::Count(int value)
	{
		if (mas == 0)
		{
			std::cerr << "Can't allocate memory!!";
			exit(-1);
		}
		int count = 0;
		for (int i = 0; i <= arrSize; i++)
		{
			if (mas[i] == value) { count++; }
		}
		return count;
	}

	int SmartDoubleArray::FindNext(int value, int index)
	{
		if (mas == 0)
		{
			std::cerr << "Can't allocate memory!!";
			exit(-1);
		}
		if ((index <= 0) || (index>arrSize))
		{
			std::cerr << "Incorrect index!!";
			exit(-1);
		}
		int i = index;
		while (mas[i] != value)
		{
			i++;
		}
		return i;
	}

	int SmartDoubleArray::operator [](int i)
	{
		if ((i > 0) || (i<arrSize))
		{
			return mas[i];
		}
		else return 0;
	}

	int SmartDoubleArray::SizeOf() const
	{
		return arrSize*sizeof(int);
	}
}