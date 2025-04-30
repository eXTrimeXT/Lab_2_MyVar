#include <iostream>
#include "Car.h"
class Tabl {
	T* array_cars;
	T* cursor;
	int size;
public:
	Tabl(int sz);
	~Tabl();
	T* begin();
	T* end();
	int length();
	int getSize();

	T* insert(T* first_item, T* last_item, const T& item);
	T* erase(T* first, T* last);
	void clear(T* first, T* last);
	int remove(T* first, T* last, const T& item);
	int find(T* first, T* last, const T& item);
	int replace(T* first, T* last, const T& Old, const T& New);
	void sort(T* first, T* last);
	int Input(T buf);
	void Output();
};