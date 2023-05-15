#pragma once
// Сиаод 5.cpp 
#include <iostream>
#include <string.h>
using namespace std;

struct Node {
    char data; //значение элемента
    Node* next; //указатель на следующий элемент
    Node(char _data) : data(_data), next(nullptr) {} //конструктор
};

struct list {
    Node* head; //указатель на первый объект 
    Node* tail; //указатель на последний объект 
    list() : head(nullptr), tail(nullptr) {} //конструктор

    bool is_empty() {
        return head == nullptr;
    };


    void push_back(char data) { //добавляет 1 элемент в конец списка
        Node* node = new Node(data); //создаем новый элемент списка (текущий)
        if (head == nullptr) { //если список пустой, текущий элемент становится первым
            head = node;
            tail = node;
            return;
        }
        if (tail != nullptr) tail->next = node; //если последний элемент != null то после него вставляем текущий.
        tail = node; // переопределение последнего элемента tail.
    };


    void print_list() {
        if (is_empty()) {
            return;
        }
        Node* node = head;
        while (node) {
            cout << node->data << " : ";
            node = node->next;
        }
        cout << endl;
    };

    int get_len() {
        Node* node = head;
        int c = 0;
        while (node) {
            node = node->next;
            c++;
        }
        cout << endl;
        return c;
    };

    Node* get_at(int k) {
        Node* node = head;
        int n = 0;
        while (node && n != k && node->next) {
            node = node->next;
            n++;
        }
        return (n == k) ? node : NULL;
    };

};

void create_list(list& first) {
    cout << "Введите количество элементов списка : ";
    int len;
    char d;
    cin >> len;
    if (len <= 0) {
        return;
    }

    cout << "Введите в строку исходное количество элементов списка : ";
    for (int i = 0; i < len; i++) {
        cin >> d;
        first.push_back(d);
    };

}
void push_from_the_end(list first, list second) { //функция, вставляющая конечный элемент из списка second в список first 
    Node* note = second.tail; //мы создаем переменную note и присваиваем ей указатель на конечный элемент второго списка
    first.push_back(note->data); //затем используя вспомогательную функию push_back добавляем ее в первый список 
};

string compare_lists(list first, list second) {
    if (first.get_len() != second.get_len()) {
        return "Списки не совпадают по размеру.";
    }
    for (int i = 0; i < first.get_len(); i++) {
        Node* f = first.get_at(i);
        Node* s = second.get_at(i);
        if (f->data != s->data) return "Списки не совпадают по значениям.";
    }
    return "Списки совпадают.";
};

void del_nums(list& first) {

    Node* curr = first.head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (isdigit(curr->data)) {
            if (prev == nullptr) {
                first.head = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            delete curr;
            curr = (prev == NULL) ? first.head : prev->next;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    list L1;
    list L2;
    cout << "Введем первый список: " << endl;
    create_list(L1);
    cout << endl;
    cout << "Введем второй список: " << endl;
    create_list(L2);
    cout << endl;
    
    cout << "Полученные списки: " << endl;
    cout << "L1: ";
    L1.print_list();
    cout << endl;
    cout << "L2: ";
    L2.print_list();
    cout << endl;

    while (true) {
        cout << "Выберите операцию над списком: " << endl;
        cout << "1. Проверить на равенство списки L1 и L2." << endl;
        cout << "2. Вставить в список L1 последний элемент списка L2." << endl;
        cout << "3. Удалить из списка L2 все элементы, являющиеся цифрами." << endl;
        cout << "Ввод: ";
        int Q;
        cin >> Q;

        if (Q == 1) {
            cout << compare_lists(L1, L2) << endl;
        }
        else if (Q == 2) {
            push_from_the_end(L1, L2);

            cout << endl << "L1: ";
            L1.print_list();
            cout << endl;
            cout << "L2: ";
            L2.print_list();
            cout << endl;

        }
        else if (Q == 3) {
            del_nums(L2);
            cout << endl;
            cout << "Полученный список L2: ";
            L2.print_list();
        }
        else {
            cout << "Неверно введенное значение";
            continue;
        }
    }
}




