#include "Tabl.h"
Tabl::Tabl(int sz)
{
	cursor = array_cars = new T[size = sz];
}
Tabl::~Tabl()
{
	clear(array_cars, cursor);
	cursor = array_cars;
	delete[] array_cars;
}
T* Tabl::begin() { return array_cars; }
T* Tabl::end() { return cursor; }
int Tabl::length() { return cursor - array_cars; }
int Tabl::getSize() { return size; }

T* Tabl::insert(T* first_item, T* last_item, const T& item)
{
	if ((last_item - first_item) < size)
		*last_item++ = item->copy();
	return last_item;
}
T* Tabl::erase(T* first, T* last)
{
	(*first)->dispose();
	for (T* i = first; i < last; i++)
		*i = *(i + 1);
	cursor--;
	return first;
}
void Tabl::clear(T* first, T* last)
{
	for (T* i = first; i < last; i++)
		(*i)->dispose();
}
int Tabl::remove(T* first, T* last, const T& item)
{
	T* j = first;
	int n = 0;
	for (T* i = first; i < last; i++)
		if (!(*i)->equal(*item))
		{
			*j++ = *i;
		}
		else
		{
			(*i)->dispose();
			n++;
		}
	cursor = j;

	return n;
}
int Tabl::find(T* first, T* last, const T& item)
{
	for (T* i = first; i < last; i++)
		if ((*i)->equal(*item))
			return i - array_cars;
	return -1;
}
int Tabl::replace(T* first, T* last, const T& Old, const T& New)
{
	int count = 0;
	for (T* i = first; i < last; i++)
		if ((*i)->equal(*Old))
		{
			(*i)->dispose();
			(*i) = (New)->copy();
			count++;
		}
	return count;
}
void Tabl::sort(T* first, T* last)
{
	int len = last - first;
	for (int j = 0; j < len - 1; j++)
		for (int i = 0; i < len - 1 - j; i++)
			if (array_cars[i]->cmp(*array_cars[i + 1]) > 0)
			{
				T tmp = array_cars[i];
				array_cars[i] = array_cars[i + 1];
				array_cars[i + 1] = tmp;
			}
}
int Tabl::Input(T buf)
{
	int count;
	cursor = begin();
	T* m = cursor;
	for (count = 0; count < getSize() && buf->input(); count++)
		cursor = insert(m, cursor, buf);
	return count;
}
void Tabl::Output()
{
	for (T* i = begin(); i != end(); i++)
		(*i)->output();
}