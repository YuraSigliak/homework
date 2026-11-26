#include <iostream>
#include <string>
using namespace std;

struct Kniga {
    string nazva;
    string avtor;
    string vydavnytstvo;
    string zhanr;
};

void drukKnig(Kniga books[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nКнига " << i + 1 << endl;
        cout << "Назва: " << books[i].nazva << endl;
        cout << "Автор: " << books[i].avtor << endl;
        cout << "Видавництво: " << books[i].vydavnytstvo << endl;
        cout << "Жанр: " << books[i].zhanr << endl;
    }
}

void redaguvaty(Kniga books[], int n) {
    int number;
    cout << "Введіть номер книги для редагування (1-10): ";
    cin >> number;
    cin.ignore();

    if (number < 1 || number > n) {
        cout << "Неправильний номер!" << endl;
        return;
    }

    int i = number - 1;
    cout << "Нова назва: ";
    getline(cin, books[i].nazva);
    cout << "Новий автор: ";
    getline(cin, books[i].avtor);
    cout << "Нове видавництво: ";
    getline(cin, books[i].vydavnytstvo);
    cout << "Новий жанр: ";
    getline(cin, books[i].zhanr);

    cout << "Книгу змінено." << endl;
}

void poshukAvtora(Kniga books[], int n) {
    string author;
    cout << "Введіть автора: ";
    getline(cin, author);

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (books[i].avtor == author) {
            cout << books[i].nazva << " - " << books[i].avtor << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Книгу не знайдено." << endl;
    }
}

void poshukNazvy(Kniga books[], int n) {
    string name;
    cout << "Введіть назву книги: ";
    getline(cin, name);

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (books[i].nazva == name) {
            cout << books[i].nazva << " - " << books[i].avtor << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Книгу не знайдено." << endl;
    }
}

void sortNazva(Kniga books[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (books[j].nazva > books[j + 1].nazva) {
                Kniga temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void sortAvtor(Kniga books[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (books[j].avtor > books[j + 1].avtor) {
                Kniga temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void sortVydavnytstvo(Kniga books[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (books[j].vydavnytstvo > books[j + 1].vydavnytstvo) {
                Kniga temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int N = 10;
    Kniga books[N];

    cout << "Введіть дані для 10 книг:" << endl;

    for (int i = 0; i < N; i++) {
        cout << "\nКнига " << i + 1 << endl;
        cout << "Назва: ";
        getline(cin, books[i].nazva);
        cout << "Автор: ";
        getline(cin, books[i].avtor);
        cout << "Видавництво: ";
        getline(cin, books[i].vydavnytstvo);
        cout << "Жанр: ";
        getline(cin, books[i].zhanr);
    }

    int choice;

    do {
        cout << "\n--- БІБЛІОТЕКА ---" << endl;
        cout << "1. Редагувати книгу" << endl;
        cout << "2. Друк усіх книг" << endl;
        cout << "3. Пошук за автором" << endl;
        cout << "4. Пошук за назвою" << endl;
        cout << "5. Сортувати за назвою" << endl;
        cout << "6. Сортувати за автором" << endl;
        cout << "7. Сортувати за видавництвом" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            redaguvaty(books, N);
        }
        else if (choice == 2) {
            drukKnig(books, N);
        }
        else if (choice == 3) {
            poshukAvtora(books, N);
        }
        else if (choice == 4) {
            poshukNazvy(books, N);
        }
        else if (choice == 5) {
            sortNazva(books, N);
            cout << "Книги відсортовано за назвою." << endl;
        }
        else if (choice == 6) {
            sortAvtor(books, N);
            cout << "Книги відсортовано за автором." << endl;
        }
        else if (choice == 7) {
            sortVydavnytstvo(books, N);
            cout << "Книги відсортовано за видавництвом." << endl;
        }

    } while (choice != 0);

    return 0;
}