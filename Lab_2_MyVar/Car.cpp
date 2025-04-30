#include "Car.h"
#include <string.h>
#include < iostream>
using namespace std;

Car::Car()
{
	marka = new char[1];
	*marka = '\0';
	company[0] = '\0';
	id = 0;
	price = 0;
}
Car::Car(char* t, char* a, int n, double p)
{
	marka = new char[strlen(t) + 1];
	strcpy_s(marka, strlen(t), t);
	strcpy_s(company, sizeof company, a);
	id = n;
	price = p;
}
Car::Car(const Car& t)
{
	strcpy_s(company, sizeof company, t.company);
	marka = new char[strlen(t.marka) + 1];
	strcpy_s(marka, strlen(t.marka) + 1, t.marka);
	id = t.id;
	price = t.price;
}
void Car::dispose()
{
	delete[] marka;
}
Car::~Car()
{
	dispose();
}
Car* Car::copy()
{
	return new Car(*this);
}
int Car::validate() { return 1; }
int Car::equal(const Car& t)
{
	{ return
		((marka && t.marka[0] != 0) ? !strcmp(marka, t.marka) : 1) &&
		((company[0] != 0) ? !strcmp(company, t.company) : 1) &&
		((id != 0) ? id == t.id : 1) &&
		((price != 0) ? price == t.price : 1);
	}
}
int Car::cmp(const Car& t)
{
	int cond;
	if (marka[0] != 0 && (cond = strcmp(marka, t.marka))) return cond;
	else if (company[0] != 0 && (cond = strcmp(company, t.company))) return cond;
	else return id - t.id;
}
int Car::input(FILE* fp) { return !cin.eof(); }
int Car::input()
{
	static int count;
	char c, endline, end;
	char buf[256];
	cout.width(10); cout << "marka ";
	cin.getline(buf, 254, '\n');
	if (cin.eof())return 0;
	marka = new char[strlen(buf) + 1];
	strcpy_s(marka, strlen(buf) + 1, buf);
	cout.width(10);
	cout << "company ";
	cin.getline(buf, sizeof company, '\n');
	strcpy_s(company, sizeof company, buf);
	cout.width(10);
	cout << "id ";
	cin >> id; cin.get(endline);
	cout.width(10);
	cout << "price ";
	cin >> price; cin.get(endline);
	if (!cin.eof())
	{
		cout << "------------------------- " << count++ << "\n";
		return 1;
	}
	return 0;
}
void Car::output(FILE* f) {}
void Car::output()
{
	static int count;
	if (!count++) {
		cout.width(35); cout << "marka";
		cout.width(15); cout << "company";
		cout.width(8); cout << "id";
		cout.width(8); cout << "price" << "\n";;
	}
	cout.width(35); cout << marka;
	cout.width(15); cout << company;
	cout.width(8); cout << id;
	cout.width(8); cout << price << "\n";
	cout << "\n";
}