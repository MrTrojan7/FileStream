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

	cout << "1. Write\n2. Read\n";
	int n;
	cin >> n;

	if (n == 1)
	{
		ofstream out("file.txt", ios_base::app); // создаём выходной файловый поток и присоединяем к нему файл, который открывается на запись в текстовом режиме
		if (!out.is_open()) // если открытие файла завершилось неудачей - выходим
		{
			cout << "File Open Error (WRITE)\n";
			return 0;
		}
		Student a;
		//const char* temp = a.GetPatronymic();
		//_write(1, temp, strlen(temp));
		//out.write(path, sizeof(a));

		out << 10 << ' ' << 123.5 << ' ' << " test! "; // сохраняем данные в файл
		out << a << "\n";
		out << " This is a text file " << 10;
		out.close(); // закрываем файловый поток
	}
	else
	{
		int i;
		double d;
		string str;

		ifstream in("file.txt", ios_base::app); // создаём входной файловый поток и присоединяем к нему файл, который открывается на чтение в текстовом режиме
		if (!in.is_open()) // если открытие файла завершилось неудачей - выходим
		{
			cout << "File Open Error (READ)\n";
			return 0;
		}
		//in >> i >> d; // считываем из файла данные в переменные
		//cout << i << "\n";
		//cout << d << "\n";
		//cin.getline(in, str);
		while (getline(in, str)) // цикл продолжается до тех пор, пока не наступит конец файла
		{
			//in >> str; // считываем строку из файла по одному слову за одну итерацию цикла
			cout << str << "\n";
		}
		in.close(); // закрываем файловый поток
	}

	cout << "\nTextModeExample DONE!\n";
	return 0;
}