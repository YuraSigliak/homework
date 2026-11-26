#include <iostream>
#include <string>
using namespace std;

void deleteByNumber(string& s, int number) {
    if (number >= 0 && number < s.length()) {
        s.erase(number, 1);
    }
}

void deleteSymbol(string& s, char symbol) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == symbol) {
            s.erase(i, 1);
            i--;
        }
    }
}

void insertSymbol(string& s, int position, char symbol) {
    if (position >= 0 && position <= s.length()) {
        s.insert(position, 1, symbol);
    }
}

int main() {
    int choice;

    do {
        cout << "\n1. Видалити символ за номером";
        cout << "\n2. Видалити всі входження символу";
        cout << "\n3. Вставити символ у рядок";
        cout << "\n4. Замінити крапки на знаки оклику";
        cout << "\n5. Порахувати входження символу";
        cout << "\n6. Порахувати літери, цифри та інші символи";
        cout << "\n0. Вихід";
        cout << "\nВаш вибір: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string s;
            int number;

            cout << "Введіть рядок: ";
            getline(cin, s);
            cout << "Введіть номер символу (з 0): ";
            cin >> number;

            deleteByNumber(s, number);
            cout << "Результат: " << s << endl;
        }
        else if (choice == 2) {
            string s;
            char symbol;

            cout << "Введіть рядок: ";
            getline(cin, s);
            cout << "Введіть символ: ";
            cin >> symbol;

            deleteSymbol(s, symbol);
            cout << "Результат: " << s << endl;
        }
        else if (choice == 3) {
            string s;
            char symbol;
            int position;

            cout << "Введіть рядок: ";
            getline(cin, s);
            cout << "Введіть позицію (з 0): ";
            cin >> position;
            cout << "Введіть символ: ";
            cin >> symbol;

            insertSymbol(s, position, symbol);
            cout << "Результат: " << s << endl;
        }
        else if (choice == 4) {
            string s;

            cout << "Введіть рядок: ";
            getline(cin, s);

            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '.') {
                    s[i] = '!';
                }
            }

            cout << "Результат: " << s << endl;
        }
        else if (choice == 5) {
            string s;
            char symbol;
            int count = 0;

            cout << "Введіть рядок: ";
            getline(cin, s);
            cout << "Введіть шуканий символ: ";
            cin >> symbol;

            for (int i = 0; i < s.length(); i++) {
                if (s[i] == symbol) {
                    count++;
                }
            }

            cout << "Кількість входжень: " << count << endl;
        }
        else if (choice == 6) {
            string s;
            int letters = 0, digits = 0, other = 0;

            cout << "Введіть рядок: ";
            getline(cin, s);

            for (int i = 0; i < s.length(); i++) {
                unsigned char c = s[i];

                if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                    letters++;
                }
                else if (c >= 48 && c <= 57) {
                    digits++;
                }
                else if (c == 0xD0 || c == 0xD1) {
                    letters++;
                    i++;
                }
                else if (c < 128) {
                    other++;
                }
            }

            cout << "Кількість літер: " << letters << endl;
            cout << "Кількість цифр: " << digits << endl;
            cout << "Кількість інших символів: " << other << endl;
        }

    } while (choice != 0);

    return 0;
}