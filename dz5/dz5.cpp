#include <iostream>

using namespace std;

struct Book {
    char title[100];
    char author[100];
    char publisher[100];
    char genre[100];
};
void editBook(Book& book) {
    cout << "������ ���� �����: ";
    cin.getline(book.title, 100);
    cout << "������ ������ ������: ";
    cin.getline(book.author, 100);
    cout << "������ ������ �������: ";
    cin.getline(book.publisher, 100);
    cout << "������ ����� ����: ";
    cin.getline(book.genre, 100);
}
void printBooks(const Book books[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "�����: " << books[i].title << endl;
        cout << "�����: " << books[i].author << endl;
        cout << "��������: " << books[i].publisher << endl;
        cout << "����: " << books[i].genre << endl;
        cout << endl;
    }
}
int searchByAuthor(const Book books[], int size, const char* author) {
    int found = 0;
    for (int i = 0; i < size; ++i) {
        if (strcmp(books[i].author, author) == 0) {
            cout << "�������� �����:" << endl;
            cout << "�����: " << books[i].title << endl;
            cout << "�����: " << books[i].author << endl;
            cout << "��������: " << books[i].publisher << endl;
            cout << "����: " << books[i].genre << endl;
            cout << endl;
            found = 1;
        }
    }
    return found;
}
int searchByTitle(const Book books[], int size, const char* title) {
    int found = 0;
    for (int i = 0; i < size; ++i) {
        if (strcmp(books[i].title, title) == 0) {
            cout << "�������� �����:" << endl;
            cout << "�����: " << books[i].title << endl;
            cout << "�����: " << books[i].author << endl;
            cout << "��������: " << books[i].publisher << endl;
            cout << "����: " << books[i].genre << endl;
            cout << endl;
            found = 1;
            break;
        }
    }
    return found;
}
void sortByTitle(Book books[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(books[j].title, books[j + 1].title) > 0) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}
void sortByAuthor(Book books[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(books[j].author, books[j + 1].author) > 0) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}
void sortByPublisher(Book books[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(books[j].publisher, books[j + 1].publisher) > 0) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}
int main() {
    setlocale(LC_ALL,"rus");
    const int SIZE = 10;
    Book library[SIZE] = {
        {"�����1", "�����1", "��������1", "����1"},
        {"�����2", "�����2", "��������2", "����2"},
        {"�����3", "�����3", "��������3", "����3"},
        {"�����4", "�����4", "��������4", "����4"},
        {"�����5", "�����5", "��������5", "����5"},
        {"�����6", "�����6", "��������6", "����6"},
        {"�����7", "�����7", "��������7", "����7"},
        {"�����8", "�����8", "��������8", "����8"},
        {"�����9", "�����9", "��������9", "����9"},
        {"�����10", "�����10", "��������10", "����10"}
    };
    editBook(library[0]);
    cout << "�� ����� � ��������:" << endl;
    printBooks(library, SIZE);
    int found = searchByAuthor(library, SIZE, "�����1");
    if (!found) {
        cout << "���� �� �������� �� ������� �����1" << endl;
    }
    found = searchByTitle(library, SIZE, "�����5");
    if (!found) {
        cout << "����� � ������ �����5 �� ��������" << endl;
    }
    cout << "���������� �������� �� ������:" << endl;
    sortByTitle(library, SIZE);
    printBooks(library, SIZE);
    cout << "���������� �������� �� �������:" << endl;
    sortByAuthor(library, SIZE);
    printBooks(library, SIZE);
    cout << "���������� �������� �� ������������:" << endl;
    sortByPublisher(library, SIZE);
    printBooks(library, SIZE);
    return 0;
}
