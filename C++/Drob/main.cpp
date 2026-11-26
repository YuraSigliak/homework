#include <iostream>
#include <cstdlib>
using namespace std;

class Drob {
private:
    int chyselnyk;
    int znamennyk;

    void skorotyty() {
        int a = abs(chyselnyk);
        int b = abs(znamennyk);

        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }

        if (a != 0) {
            chyselnyk /= a;
            znamennyk /= a;
        }

        if (znamennyk < 0) {
            chyselnyk = -chyselnyk;
            znamennyk = -znamennyk;
        }
    }

public:
    Drob() {
        chyselnyk = 0;
        znamennyk = 1;
    }

    void vvesty() {
        cout << "Vvedit chyselnyk: ";
        cin >> chyselnyk;

        do {
            cout << "Vvedit znamennyk: ";
            cin >> znamennyk;

            if (znamennyk == 0) {
                cout << "Pomylka! Znamennyk ne mozhe buty 0.\\n";
            }
        } while (znamennyk == 0);

        skorotyty();
    }

    void vyvesty() {
        cout << chyselnyk << "/" << znamennyk << endl;
    }

    Drob dodaty(Drob d) {
        Drob r;
        r.chyselnyk = chyselnyk * d.znamennyk +
                      d.chyselnyk * znamennyk;
        r.znamennyk = znamennyk * d.znamennyk;
        r.skorotyty();
        return r;
    }

    Drob vidniaty(Drob d) {
        Drob r;
        r.chyselnyk = chyselnyk * d.znamennyk -
                      d.chyselnyk * znamennyk;
        r.znamennyk = znamennyk * d.znamennyk;
        r.skorotyty();
        return r;
    }

    Drob pomnozhyty(Drob d) {
        Drob r;
        r.chyselnyk = chyselnyk * d.chyselnyk;
        r.znamennyk = znamennyk * d.znamennyk;
        r.skorotyty();
        return r;
    }

    bool podilyty(Drob d, Drob &r) {
        if (d.chyselnyk == 0) {
            return false;
        }

        r.chyselnyk = chyselnyk * d.znamennyk;
        r.znamennyk = znamennyk * d.chyselnyk;
        r.skorotyty();

        return true;
    }
};

int main() {
    Drob a, b, r;

    cout << "Pershyi drob:\\n";
    a.vvesty();

    cout << "\\nDrugyi drob:\\n";
    b.vvesty();

    cout << "\\nDodaty: ";
    r = a.dodaty(b);
    r.vyvesty();

    cout << "Vidniaty: ";
    r = a.vidniaty(b);
    r.vyvesty();

    cout << "Pomnozhyty: ";
    r = a.pomnozhyty(b);
    r.vyvesty();

    cout << "Podilyty: ";
    if (a.podilyty(b, r)) {
        r.vyvesty();
    } else {
        cout << "Na nul dilyty ne mozhna!\\n";
    }

    return 0;
}
