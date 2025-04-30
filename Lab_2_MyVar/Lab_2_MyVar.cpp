#include <iostream>
#include "Tabl.h"
using namespace std;
Car b, b2;
Car* buf = &b, *buf2 = &b2;
Tabl t(3);
int main()
{
	char c, endline;

	do
	{
		cout << "for get case input number and press enter" << endl;
		cout << "0-exit" << endl;
		cout << "1-input elements" << endl;
		cout << "2-output elements" << endl;
		cout << "3-find" << endl;
		cout << "4-erase" << endl;
		cout << "5-remove" << endl;
		cout << "6-replace" << endl;
		cout << "7-sort" << endl;

		cin.get(c);
		cin.get(endline);
		switch (c)
		{
		case '1':
		{
			cout << "input elements" << endl;
			t.Input(buf);
			cin.clear();
			break;
		}
		case '2':
		{
			cout << "elements:" << endl;
			t.Output();
			break;
		}
		case '3':
		{
			cout << "input elements for find" << endl;
			buf->input();
			int i = t.find(t.begin(), t.end(), buf);
			if (i >= 0)
				cout << "position=" << i << endl;
			else
				cout << "no found" << endl;
			break;
		}
		case '4':
		{
			cout << "input position for erse" << endl;
			int pos;
			cin >> pos;
			cin.get(endline);
			t.erase(t.begin() + pos, t.end());
			break;
		}
		case '5':
		{
			cout << "input element for remove" << endl;
			buf->input();
			int i = t.remove(t.begin(), t.end(), buf);
			if (i == 0)
				cout << "no found" << endl;
			break;
		}
		case '6':
		{
			cout << "input OLD element for replace" << endl;
			buf->input();
			cout << "input NEW element for replace" << endl;
			buf2->input();
			int i = t.replace(t.begin(), t.end(), buf, buf2);
			if (i == 0)
				cout << "no found" << endl;
			break;
		}
		case '7':
		{
			t.sort(t.begin(), t.end());
			break;
		}
		}
	} while (c != '0');

	system("pause");
}