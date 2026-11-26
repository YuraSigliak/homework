#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Porushennia {
    string data;
    string opys;
    int shtraf;
};

struct Vuzol {
    string nomer;
    vector<Porushennia> spysok;
    Vuzol* left;
    Vuzol* right;

    Vuzol(string n, Porushennia p) {
        nomer = n;
        spysok.push_back(p);
        left = NULL;
        right = NULL;
    }
};

class BazaDAI {
private:
    Vuzol* root;

    void druk(Vuzol* v) {
        if (v == NULL) return;

        druk(v->left);

        cout << "\nНомер машини: " << v->nomer << endl;
        for (int i = 0; i < v->spysok.size(); i++) {
            cout << "  Дата: " << v->spysok[i].data
                 << ", порушення: " << v->spysok[i].opys
                 << ", штраф: " << v->spysok[i].shtraf << " грн" << endl;
        }

        druk(v->right);
    }

    void drukZaNomerom(Vuzol* v, string nomer) {
        if (v == NULL) return;

        if (nomer < v->nomer)
            drukZaNomerom(v->left, nomer);
        else if (nomer > v->nomer)
            drukZaNomerom(v->right, nomer);
        else {
            cout << "\nНомер машини: " << v->nomer << endl;
            for (int i = 0; i < v->spysok.size(); i++) {
                cout << "Дата: " << v->spysok[i].data
                     << ", порушення: " << v->spysok[i].opys
                     << ", штраф: " << v->spysok[i].shtraf << " грн" << endl;
            }
        }
    }

    void drukDiapazon(Vuzol* v, string pochatok, string kinec) {
        if (v == NULL) return;

        if (v->nomer > pochatok)
            drukDiapazon(v->left, pochatok, kinec);

        if (v->nomer >= pochatok && v->nomer <= kinec) {
            cout << "\nНомер машини: " << v->nomer << endl;
            for (int i = 0; i < v->spysok.size(); i++) {
                cout << "Дата: " << v->spysok[i].data
                     << ", порушення: " << v->spysok[i].opys
                     << ", штраф: " << v->spysok[i].shtraf << " грн" << endl;
            }
        }

        if (v->nomer < kinec)
            drukDiapazon(v->right, pochatok, kinec);
    }

public:
    BazaDAI() {
        root = NULL;
    }

    void dodaty(string nomer, Porushennia p) {
        if (root == NULL) {
            root = new Vuzol(nomer, p);
            return;
        }

        Vuzol* v = root;
        while (true) {
            if (nomer == v->nomer) {
                v->spysok.push_back(p);
                return;
            }
            else if (nomer < v->nomer) {
                if (v->left == NULL) {
                    v->left = new Vuzol(nomer, p);
                    return;
                }
                v = v->left;
            }
            else {
                if (v->right == NULL) {
                    v->right = new Vuzol(nomer, p);
                    return;
                }
                v = v->right;
            }
        }
    }

    void drukVsiuBazу() {
        if (root == NULL)
            cout << "База порожня." << endl;
        else
            druk(root);
    }

    void drukZaNomerom(string nomer) {
        drukZaNomerom(root, nomer);
    }

    void drukDiapazon(string pochatok, string kinec) {
        if (pochatok > kinec) {
            cout << "Неправильно заданий діапазон." << endl;
            return;
        }
        drukDiapazon(root, pochatok, kinec);
    }
};

int main() {
    BazaDAI baza;
    int vibor;

    do {
        cout << "\n1. Додати квитанцію";
        cout << "\n2. Надрукувати всю базу";
        cout << "\n3. Знайти за номером машини";
        cout << "\n4. Знайти за діапазоном номерів";
        cout << "\n0. Вихід";
        cout << "\nВаш вибір: ";
        cin >> vibor;

        if (vibor == 1) {
            string nomer;
            Porushennia p;

            cout << "Введіть номер машини: ";
            cin >> nomer;
            cin.ignore();

            cout << "Введіть дату: ";
            getline(cin, p.data);

            cout << "Введіть опис порушення: ";
            getline(cin, p.opys);

            cout << "Введіть суму штрафу: ";
            cin >> p.shtraf;

            baza.dodaty(nomer, p);
            cout << "Квитанцію додано." << endl;
        }
        else if (vibor == 2) {
            baza.drukVsiuBazу();
        }
        else if (vibor == 3) {
            string nomer;
            cout << "Введіть номер машини: ";
            cin >> nomer;
            baza.drukZaNomerom(nomer);
        }
        else if (vibor == 4) {
            string pochatok, kinec;
            cout << "Введіть початковий номер: ";
            cin >> pochatok;
            cout << "Введіть кінцевий номер: ";
            cin >> kinec;
            baza.drukDiapazon(pochatok, kinec);
        }

    } while (vibor != 0);

    return 0;
}