#include <iostream> 

using namespace std;

class arg {
public:
	int data;
	arg* prev;
};

class stack {
	int count;
public:
	arg* tail;
	stack();

	void add(const int& num);
	void del();
	int value();
	bool isempty();
	void show();
	friend void sort(stack& list);
	friend int GET(stack& list, const int& num);
	friend void SET(stack& list, const int& num, const int& new_data);
};

bool stack::isempty() { return tail ? 1 : 0; }

stack::stack(){
	count = 0;
	tail = NULL;
}

void stack::add(const int& num){
	arg* temp = new arg;
	if (!(count)) { temp->data = num; tail = temp; temp->prev = NULL; }
	else {
		temp->data = num;
		temp->prev = tail;
		tail = temp;
	}
	count++;
}

void stack::del(){
	arg* temp = tail;
	tail = temp->prev;
	count--;
	delete temp;
}

int stack::value() {
	arg* temp = tail;
	return temp->data;
}

void stack::show(){
	arg* temp = tail;
	while (temp) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}

int GET(stack& list, const int& num) {
	arg* tail_temp = list.tail;
	int temp = 0;
	stack list_temp;
	int i = 0;
	while (tail_temp) {
		list_temp.add(list.value());
		list.del();
		tail_temp = tail_temp->prev;
	}
	tail_temp = list_temp.tail;
	while (tail_temp) {
		list.add(list_temp.value());
		if (i == num)
			temp = tail_temp->data;
		list_temp.del();
		i++;
		tail_temp = tail_temp->prev;
	}
	return temp;
}

void SET(stack& list, const int& num, const int& new_data) {
	arg* tail_temp = list.tail;
	int temp = 0;
	stack list_temp;
	int i = 0;
	while (tail_temp) {
		list_temp.add(list.value());
		list.del();
		tail_temp = tail_temp->prev;
	}
	tail_temp = list_temp.tail;
	while (tail_temp) {
		i == num ? list.add(new_data) : list.add(list_temp.value());;
		list_temp.del();
		i++;
		tail_temp = tail_temp->prev;
	}
}

void sort(stack& list)
{
	int temp = 0, key = 0, temp_g;
	arg* tail_temp = list.tail;
	int i = 0;
	while (tail_temp->prev) {
		key = i + 1;
		temp = GET(list, key);
		for (int j = i + 1; j > 0; j--) {
			temp_g = GET(list, j - 1);
			if (temp < temp_g) {
				SET(list, j, temp_g);
				key = j - 1;
			}
		}
		SET(list, key, temp);
		i++;
		tail_temp = tail_temp->prev;
	}
}

int main()
{
	system("chcp 1251->NULL");
	stack l;
	int n, flag = -1;
	while (flag != 7) {
		cout << "1 - Добавить" << endl;
		cout << "2 - Извлечь" << endl;
		cout << "3 - ISEMPTY" << endl;
		cout << "4 - Сортировать" << endl;
		cout << "5 - Вывести" << endl;
		cout << "6 - Удалить" << endl;
		cout << "7 - Выйти" << endl;
		cin >> flag;

		if (flag == 1) {
			cout << "Введите элемент: " << endl;  cin >> n;
			l.add(n);
		}
		if (flag == 2)
			cout << l.value() << endl;

		if (flag == 3)
			cout << l.isempty() << endl;

		if (flag == 4)
			sort(l);

		if (flag == 5)
			l.show();
		if (flag == 6)
			l.del();
	}
}