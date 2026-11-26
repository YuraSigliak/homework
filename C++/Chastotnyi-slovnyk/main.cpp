#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
using namespace std;

string obrobytySlovo(string slovo) {
    string rez = "";

    for (int i = 0; i < slovo.length(); i++) {
        if (slovo[i] != '.' && slovo[i] != ',' && slovo[i] != '!' &&
            slovo[i] != '?' && slovo[i] != ':' && slovo[i] != ';' &&
            slovo[i] != '(' && slovo[i] != ')' && slovo[i] != '"' &&
            slovo[i] != '\'') {
            rez += tolower((unsigned char)slovo[i]);
        }
    }

    return rez;
}

int main() {
    ifstream input("input.txt");

    if (!input.is_open()) {
        cout << "Не вдалося відкрити файл input.txt" << endl;
        return 0;
    }

    map<string, int> slovnyk;
    string slovo;

    while (input >> slovo) {
        slovo = obrobytySlovo(slovo);

        if (slovo != "") {
            slovnyk[slovo]++;
        }
    }

    input.close();

    cout << "Частотний словник:" << endl;

    string maxSlovo = "";
    int maxKil = 0;

    for (auto element : slovnyk) {
        cout << element.first << " - " << element.second << endl;

        if (element.second > maxKil) {
            maxKil = element.second;
            maxSlovo = element.first;
        }
    }

    if (maxKil > 0) {
        cout << "\nНайчастіше слово: " << maxSlovo
             << " (" << maxKil << " разів)" << endl;
    }
    else {
        cout << "У файлі немає слів." << endl;
    }

    ofstream output("frequency.txt");

    if (!output.is_open()) {
        cout << "Не вдалося створити файл frequency.txt" << endl;
        return 0;
    }

    output << "Частотний словник:" << endl;

    for (auto element : slovnyk) {
        output << element.first << " - " << element.second << endl;
    }

    if (maxKil > 0) {
        output << "\nНайчастіше слово: " << maxSlovo
               << " (" << maxKil << " разів)" << endl;
    }

    output.close();

    cout << "\nРезультат записано у файл frequency.txt" << endl;

    return 0;
}