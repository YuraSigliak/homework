#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Spivrobitnyk {
    string prizvyshche;
    string imia;
    int vik;
    string posada;
};

void pokazaty(const vector<Spivrobitnyk>& spysok) {
    if (spysok.empty()) {
        cout << "Список порожній.\n";
        return;
    }

    for (int i = 0; i < spysok.size(); i++) {
        cout << i + 1 << ". " << spysok[i].prizvyshche << " "
             << spysok[i].imia << ", вік: " << spysok[i].vik
             << ", посада: " << spysok[i].posada << endl;
    }
}

void zberehty(const vector<Spivrobitnyk>& spysok, string fail) {
    ofstream out(fail);
    for (int i = 0; i < spysok.size(); i++) {
        out << spysok[i].prizvyshche << "|"
            << spysok[i].imia << "|"
            << spysok[i].vik << "|"
            << spysok[i].posada << endl;
    }
    out.close();
    cout << "Дані збережено у файл.\n";
}

void zavantazhyty(vector<Spivrobitnyk>& spysok, string fail) {
    ifstream in(fail);
    if (!in.is_open()) {
        cout << "Файл не знайдено. Буде створено новий список.\n";
        return;
    }

    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        Spivrobitnyk s;
        string vik;

        getline(ss, s.prizvyshche, '|');
        getline(ss, s.imia, '|');
        getline(ss, vik, '|');
        getline(ss, s.posada);

        if (!s.prizvyshche.empty() && !s.imia.empty()) {
            s.vik = stoi(vik);
            spysok.push_back(s);
        }
    }
    in.close();
    cout << "Список завантажено. Кількість співробітників: "
         << spysok.size() << endl;
}

void dodaty(vector<Spivrobitnyk>& spysok) {
    Spivrobitnyk s;
    cout << "Прізвище: ";
    getline(cin, s.prizvyshche);
    cout << "Ім'я: ";
    getline(cin, s.imia);
    cout << "Вік: ";
    cin >> s.vik;
    cin.ignore();
    cout << "Посада: ";
    getline(cin, s.posada);
    spysok.push_back(s);
}

void redahuvaty(vector<Spivrobitnyk>& spysok) {
    pokazaty(spysok);
    if (spysok.empty()) return;

    int n;
    cout << "Номер співробітника для редагування: ";
    cin >> n;
    cin.ignore();

    if (n < 1 || n > spysok.size()) {
        cout << "Неправильний номер.\n";
        return;
    }

    cout << "Нове прізвище: ";
    getline(cin, spysok[n - 1].prizvyshche);
    cout << "Нове ім'я: ";
    getline(cin, spysok[n - 1].imia);
    cout << "Новий вік: ";
    cin >> spysok[n - 1].vik;
    cin.ignore();
    cout << "Нова посада: ";
    getline(cin, spysok[n - 1].posada);
}

void vydalyty(vector<Spivrobitnyk>& spysok) {
    pokazaty(spysok);
    if (spysok.empty()) return;

    int n;
    cout << "Номер співробітника для видалення: ";
    cin >> n;
    cin.ignore();

    if (n < 1 || n > spysok.size()) {
        cout << "Неправильний номер.\n";
        return;
    }

    spysok.erase(spysok.begin() + n - 1);
    cout << "Співробітника видалено.\n";
}

vector<Spivrobitnyk> poshukZaPrizvyshchem(const vector<Spivrobitnyk>& spysok) {
    vector<Spivrobitnyk> znaydeni;
    string prizvyshche;
    cout << "Введіть прізвище: ";
    getline(cin, prizvyshche);

    for (int i = 0; i < spysok.size(); i++) {
        if (spysok[i].prizvyshche == prizvyshche)
            znaydeni.push_back(spysok[i]);
    }
    return znaydeni;
}

vector<Spivrobitnyk> poshukZaVikom(const vector<Spivrobitnyk>& spysok) {
    vector<Spivrobitnyk> znaydeni;
    int vik;
    cout << "Введіть вік: ";
    cin >> vik;
    cin.ignore();

    for (int i = 0; i < spysok.size(); i++) {
        if (spysok[i].vik == vik)
            znaydeni.push_back(spysok[i]);
    }
    return znaydeni;
}

vector<Spivrobitnyk> poshukZaBukvoiu(const vector<Spivrobitnyk>& spysok) {
    vector<Spivrobitnyk> znaydeni;
    string bukva;
    cout << "Введіть першу букву прізвища: ";
    getline(cin, bukva);

    for (int i = 0; i < spysok.size(); i++) {
        if (spysok[i].prizvyshche.find(bukva) == 0)
            znaydeni.push_back(spysok[i]);
    }
    return znaydeni;
}

int main() {
    vector<Spivrobitnyk> spysok;
    string fail;

    cout << "Введіть назву файлу для завантаження: ";
    getline(cin, fail);
    zavantazhyty(spysok, fail);

    int choice;
    do {
        cout << "\n--- ІНФОРМАЦІЙНА СИСТЕМА СПІВРОБІТНИКИ ---\n";
        cout << "1. Додати співробітника\n";
        cout << "2. Редагувати співробітника\n";
        cout << "3. Видалити співробітника\n";
        cout << "4. Пошук за прізвищем\n";
        cout << "5. Пошук за віком\n";
        cout << "6. Пошук за першою буквою прізвища\n";
        cout << "7. Показати всіх співробітників\n";
        cout << "8. Зберегти знайдену інформацію у файл\n";
        cout << "9. Зберегти весь список у файл\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();

        vector<Spivrobitnyk> znaydeni;

        switch (choice) {
        case 1:
            dodaty(spysok);
            break;
        case 2:
            redahuvaty(spysok);
            break;
        case 3:
            vydalyty(spysok);
            break;
        case 4:
            znaydeni = poshukZaPrizvyshchem(spysok);
            pokazaty(znaydeni);
            break;
        case 5:
            znaydeni = poshukZaVikom(spysok);
            pokazaty(znaydeni);
            break;
        case 6:
            znaydeni = poshukZaBukvoiu(spysok);
            pokazaty(znaydeni);
            break;
        case 7:
            pokazaty(spysok);
            break;
        case 8: {
            znaydeni = poshukZaPrizvyshchem(spysok);
            pokazaty(znaydeni);
            string nazva;
            cout << "Назва файлу для результатів: ";
            getline(cin, nazva);
            zberehty(znaydeni, nazva);
            break;
        }
        case 9:
            zberehty(spysok, fail);
            break;
        case 0:
            zberehty(spysok, fail);
            cout << "Вихід з програми.\n";
            break;
        default:
            cout << "Неправильний пункт меню.\n";
        }
    } while (choice != 0);

    return 0;
}
