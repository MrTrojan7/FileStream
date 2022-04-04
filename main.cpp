#include "AllLibraries.h"
#include "Student.h"

int main()
{
	setlocale(LC_ALL, "UKR");
	cout << "Напишите программу, которая показывает на экране консоли меню,\n";
	cout << "состоящее из двух пунктов. При выборе пункта 1 в двоичный файл\n";
	cout << "записывается (либо дописывается в конец) один объект классового\n";
	cout << "типа Person. При выборе пункта 2 - на экране отображается\n";
	cout << "содержимое полей всех объектов из этого файла.\n";

	int num;
	Student test;
	while (true)
	{
		cout << "1. Write\n2. Read\n";
		cin >> num;
		if (num == 1)
		{
			ofstream out("file", ios_base::app);
			if (!out.is_open())
			{
				cout << "File Open Error (WRITE)\n";
				return 0;
			}
			out << test << "\n";
			out.close();
		}
		else
		{
			string str;
			ifstream in("file", ios_base::app);
			if (!in.is_open())
			{
				cout << "File Open Error (READ)\n";
				return 0;
			}
			while (getline(in, str))
			{
				cout << str << "\n";
			}
			in.close();
		}
	}

	cout << "\nTextModeExample DONE!\n";
	return 0;
}