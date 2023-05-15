// Сиаод 5.cpp 
#include <iostream>
#include <string>
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
    }

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

    void del_first() { //функция удаления первого элемента
        if (head == NULL) return;
        if (head == tail) {
            delete tail;
            head = tail = NULL;
            return;
        }
        Node* node = head;
        head = node->next;
    }

    void del_last() { //функция удаления последнего элемента
        if (tail == NULL) return;
        if (head == tail) {
            delete tail;
            head = tail = NULL;
            return;
        }
        Node* node = head;
       /* while (node->next != tail) {
            node->next;
        }
        node->next = NULL;
        delete tail;
        tail = node;*/
        for (; node->next != tail; node = node->next) {
        }
        node->next = NULL;
        delete tail;
        tail = node;
    }
};

string compare_lists(list first, list second) {

    if (first.get_len() != second.get_len()) return "Списки не совпадают по размеру.";
    for (int i = 0; i < first.get_len(); i++) {
        Node* f = first.get_at(i);
        Node* s = second.get_at(i);
        if (f->data != s->data) return "Списки не совпадают по значениям.";
    }
    return "Списки совпадают.";
}

void push_from_the_end(list first, list second) { //функция, вставляющая конечный элемент из списка second в список first 
    Node* note = second.tail; //мы создаем переменную note и присваиваем ей указатель на конечный элемент второго списка
    first.push_back(note->data); //затем используя вспомогательную функию push_back добавляем ее в первый список 
}

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
}



    int main() {

        setlocale(LC_ALL, "Rus");

        list A;
        list B;

        A.push_back('1');
        A.push_back('2');
        A.push_back('1');
        A.push_back('c');
        A.push_back('3');
        A.push_back('4');
/*
        B.push_back('a');
        B.push_back('b');
        B.push_back('c')*/

        A.print_list();


        B.print_list();

        cout << endl;

        /*string a = compare_lists(A, B);
        cout << a;*/

        //push_from_the_end(A, B);

        /*if (isdigit(A.head->data)) {
            A.del_first();
        }*/
 

        del_nums(A);
        A.print_list();
       
    }
