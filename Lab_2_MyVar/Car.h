#pragma once
#include <stdio.h>
class Car
{
	char* marka; // Марка машины
	char company[15]; // Компания = владелец
	int id; // Инвентарный номер = ID
	double price; // Цена
public:
	Car();
	Car(char* a, char* t, int n, double p);
	Car(const Car&);
	~Car();
	Car* copy();
	void dispose();
	int validate();
	int equal(const Car&);
	int cmp(const Car&);
	int input(FILE* fp);
	int input();
	void output(FILE* f);
	void output();
};
typedef Car* T;