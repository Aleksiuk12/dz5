#include <iostream>

using namespace std;

struct Book {
    char title[100];
    char author[100];
    char publisher[100];
    char genre[100];
};
void editBook(Book& book) {
    cout << "Введіть нову назву: ";
    cin.getline(book.title, 100);
    cout << "Введіть нового автора: ";
    cin.getline(book.author, 100);
    cout << "Введіть нового видавця: ";
    cin.getline(book.publisher, 100);
    cout << "Введіть новий жанр: ";
    cin.getline(book.genre, 100);
}
void printBooks(const Book books[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Назва: " << books[i].title << endl;
        cout << "Автор: " << books[i].author << endl;
        cout << "Видавець: " << books[i].publisher << endl;
        cout << "Жанр: " << books[i].genre << endl;
        cout << endl;
    }
}
int searchByAuthor(const Book books[], int size, const char* author) {
    int found = 0;
    for (int i = 0; i < size; ++i) {
        if (strcmp(books[i].author, author) == 0) {
            cout << "Знайдено книгу:" << endl;
            cout << "Назва: " << books[i].title << endl;
            cout << "Автор: " << books[i].author << endl;
            cout << "Видавець: " << books[i].publisher << endl;
            cout << "Жанр: " << books[i].genre << endl;
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
            cout << "Знайдено книгу:" << endl;
            cout << "Назва: " << books[i].title << endl;
            cout << "Автор: " << books[i].author << endl;
            cout << "Видавець: " << books[i].publisher << endl;
            cout << "Жанр: " << books[i].genre << endl;
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
        {"Книга1", "Автор1", "Видавець1", "Жанр1"},
        {"Книга2", "Автор2", "Видавець2", "Жанр2"},
        {"Книга3", "Автор3", "Видавець3", "Жанр3"},
        {"Книга4", "Автор4", "Видавець4", "Жанр4"},
        {"Книга5", "Автор5", "Видавець5", "Жанр5"},
        {"Книга6", "Автор6", "Видавець6", "Жанр6"},
        {"Книга7", "Автор7", "Видавець7", "Жанр7"},
        {"Книга8", "Автор8", "Видавець8", "Жанр8"},
        {"Книга9", "Автор9", "Видавець9", "Жанр9"},
        {"Книга10", "Автор10", "Видавець10", "Жанр10"}
    };
    editBook(library[0]);
    cout << "Усі книги в бібліотеці:" << endl;
    printBooks(library, SIZE);
    int found = searchByAuthor(library, SIZE, "Автор1");
    if (!found) {
        cout << "Книг не знайдено за автором Автор1" << endl;
    }
    found = searchByTitle(library, SIZE, "Книга5");
    if (!found) {
        cout << "Книга з назвою Книга5 не знайдена" << endl;
    }
    cout << "Сортування бібліотеки за назвою:" << endl;
    sortByTitle(library, SIZE);
    printBooks(library, SIZE);
    cout << "Сортування бібліотеки за автором:" << endl;
    sortByAuthor(library, SIZE);
    printBooks(library, SIZE);
    cout << "Сортування бібліотеки за видавництвом:" << endl;
    sortByPublisher(library, SIZE);
    printBooks(library, SIZE);
    return 0;
}
