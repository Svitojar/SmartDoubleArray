#pragma once
namespace lesson_9
{
	class SmartDoubleArray
	{
	public:
		SmartDoubleArray();
		SmartDoubleArray(int);
		~SmartDoubleArray();
		int getSize() const;//capacity
		int SizeOf() const;//size
		void Add(const int  value);
		void Insert(const  int index, const int  value);
		void remove(const int index);
		int GetAt(int index);
		int Count(int value);
		int FindNext(int value, int index);
		int operator [] (int i);
	private:
		int *mas;
		int arrSize;
	};
}

