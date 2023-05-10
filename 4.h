#include <iostream>
#include <vector>
using namespace std;
struct Session { //структура сеансов с их параметрами
	char cinema[50];
	char film[50];
	unsigned int minutes, hours, num, month;
	char cost[6];
	
};

void PrintTable(Session* data, int lines) { //функция вывода таблицы с введенными в нее данными. Параметры: указатель на lданные структуры, количество строк
	cout << "====================================================================================" << endl;
	cout << "|    Кинотеатр     |" << "     Фильм       |" << "   Начало  |" << "       Дата       |" << "  Стоимость   |" << endl;
	cout << "====================================================================================" << endl;

	//проход по таблице
	for (int i = 0; i < lines; i++) { //мы построчно вводим параметры, указывая необходимые промежутки так, чтобы таблица была ровной
		cout.width(0);
		cout << "| " << data[i].cinema;  //data[i].cinema - берем введенное значение, обращаясь к структуре, получаем нужный параметр
		cout.width(19 - strlen(data[i].cinema));

		cout << "| " << data[i].film;
		cout.width(18 - strlen(data[i].film));

		cout << "| " << data[i].hours << ":" << data[i].minutes;
		cout.width(7);

		cout << "| " << data[i].num << "." << data[i].month;
		cout.width(14);

		cout << "| " << data[i].cost;
		cout.width(14 -strlen(data[i].cost));
		cout << "|" << endl;
	}
	cout << "====================================================================================" << endl;
}



void FillWindow(Session& note) { //ввод значений в поля структуры, & 
	cout << endl;
	cout << "Заполнение записи для одного показа: " << endl;
	cout << "Введите название кинотеатра: ";
	gets_s(note.cinema);
	cout << "Введите название фильма: ";
	gets_s(note.film);
	cout << "Введите время начала показа: " << endl;
	cout << "Часы: ";
	cin >> note.hours;
	cout << endl << "Минуты: ";
	cin >> note.minutes;
	cout << "Введите дату начала показа: " << endl;
	cout << "Число месяца: ";
	cin >> note.num;
	cout << endl << "Месяц: ";
	cin >> note.month;
	cin.ignore();
	cout << "Введите стоимость показа: ";
	gets_s(note.cost);
}

	void Adds(Session note, Session* data, int lines) { //функция, принимающая запись показа для вставки, саму таблицу и количество ее строк
		data[lines - 1] = note; //присвоение последней таблице ячейки значения заполненной записи
	}

	void AddByCinema(Session note, Session* data, int lines) {
		bool flag = false;
		for (int i = 0; i < lines; i++) { //проходимся по строкам 
			if (!strcmp(note.cinema, data[i].cinema)) { //если кинотеатр в записи совпадает с кинотеатром строки в таблице
				flag = true;
				for (int j = lines - 1; j > i; j--) { //проходимся с конца до совпадения 
					data[j] = data[j - 1]; //сдвигая элементы вперед, освобождаем ячейку совпадения
				}
				data[i] = note; //записываем в освободившуюся ячейку нашу строку
				break;
			}
		}
		if (!flag) { //если совпадения не были найдены
			data[lines - 1] = note; //записываем в последнюю строку
		}
	}

	void DelDate(Session* data, int& lines, unsigned int NUM, unsigned int MONTH) { //Таблица, строки таблицы, заданная дата
		for (int i = 0; i < lines; i++) { //проходимся по строкам
			if ((data[i].num == NUM) && (data[i].month == MONTH)) { //если обнаружена запись с такой датой, под индексом i
				for (int j = i; j < lines; j++) { //то мы начинаем перебор от i до конца таблицы
					data[j] = data[j + 1]; //и сдвигаем все оставшиеся киносеансы влево, тем самым удаляя i-й элемент
				}
				lines--;
				i--;
			}
		}
	}

	void Lists(Session* data, int& lines, Session* finds, char* Film) {
		int iterator = 0;
		for (int i = 0; i < lines; i++) {
			if (!strcmp(data[i].film, Film)) {
				finds[iterator] = data[i];
				iterator++;
			}
		}
		lines = iterator;
	}

