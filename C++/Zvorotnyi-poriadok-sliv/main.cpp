#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string inputName, outputName;
    cout << "Введіть назву вхідного файлу: ";
    cin >> inputName;
    cout << "Введіть назву нового файлу: ";
    cin >> outputName;

    ifstream in(inputName);
    if (!in.is_open()) {
        cout << "Не вдалося відкрити файл.\n";
        return 1;
    }

    vector<string> words;
    string word;

    while (in >> word) {
        words.push_back(word);
    }
    in.close();

    ofstream out(outputName);
    if (!out.is_open()) {
        cout << "Не вдалося створити файл.\n";
        return 1;
    }

    for (int i = words.size() - 1; i >= 0; i--) {
        out << words[i] << " ";
    }

    out.close();
    cout << "Слова записано у зворотньому порядку.\n";

    return 0;
}
