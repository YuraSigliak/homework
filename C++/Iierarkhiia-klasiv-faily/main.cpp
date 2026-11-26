#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;

class File {
public:
    virtual void Display(const char* path) {
        ifstream file(path);

        if (!file.is_open()) {
            cout << "Не вдалося відкрити файл." << endl;
            return;
        }

        char ch;
        while (file.get(ch)) {
            cout << ch;
        }

        file.close();
    }

    virtual ~File() {}
};

class AsciiFile : public File {
public:
    void Display(const char* path) override {
        ifstream file(path, ios::binary);

        if (!file.is_open()) {
            cout << "Не вдалося відкрити файл." << endl;
            return;
        }

        unsigned char ch;
        while (file.read(reinterpret_cast<char*>(&ch), 1)) {
            cout << (int)ch << " ";
        }

        file.close();
    }
};

class BinaryFile : public File {
public:
    void Display(const char* path) override {
        ifstream file(path, ios::binary);

        if (!file.is_open()) {
            cout << "Не вдалося відкрити файл." << endl;
            return;
        }

        unsigned char ch;
        while (file.read(reinterpret_cast<char*>(&ch), 1)) {
            cout << bitset<8>(ch) << " ";
        }

        file.close();
    }
};

int main() {
    string path;
    int choice;

    cout << "Введіть шлях до файлу: ";
    getline(cin, path);

    cout << "\n1. Вивести файл у текстовому вигляді";
    cout << "\n2. Вивести ASCII-коди символів";
    cout << "\n3. Вивести файл у двійковому вигляді";
    cout << "\nВаш вибір: ";
    cin >> choice;

    File* file = NULL;

    if (choice == 1)
        file = new File();
    else if (choice == 2)
        file = new AsciiFile();
    else if (choice == 3)
        file = new BinaryFile();
    else {
        cout << "Неправильний вибір." << endl;
        return 0;
    }

    cout << "\nВміст файлу:\n";
    file->Display(path.c_str());

    delete file;

    return 0;
}