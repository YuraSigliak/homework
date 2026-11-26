#include <iostream>
using namespace std;

int main() {
    int choice;

    do {
        cout << "\n1. Скопіювати один масив в інший";
        cout << "\n2. Змінити порядок елементів масиву на протилежний";
        cout << "\n3. Скопіювати масив у зворотному порядку";
        cout << "\n0. Вихід";
        cout << "\nВаш вибір: ";
        cin >> choice;

        if (choice == 1) {
            int a[100], b[100], n;

            cout << "Введіть кількість елементів: ";
            cin >> n;

            cout << "Введіть елементи масиву:" << endl;
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }

            int* p1 = a;
            int* p2 = b;

            for (int i = 0; i < n; i++) {
                *p2 = *p1;
                p1++;
                p2++;
            }

            cout << "Другий масив: ";
            for (int i = 0; i < n; i++) {
                cout << b[i] << " ";
            }
            cout << endl;
        }
        else if (choice == 2) {
            int a[100], n;

            cout << "Введіть кількість елементів: ";
            cin >> n;

            cout << "Введіть елементи масиву:" << endl;
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }

            int* p = a;

            for (int i = 0; i < n / 2; i++) {
                int temp = *(p + i);
                *(p + i) = *(p + n - 1 - i);
                *(p + n - 1 - i) = temp;
            }

            cout << "Масив у зворотному порядку: ";
            for (int i = 0; i < n; i++) {
                cout << *(p + i) << " ";
            }
            cout << endl;
        }
        else if (choice == 3) {
            int a[100], b[100], n;

            cout << "Введіть кількість елементів: ";
            cin >> n;

            cout << "Введіть елементи першого масиву:" << endl;
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }

            int* p1 = a;
            int* p2 = b + n - 1;

            for (int i = 0; i < n; i++) {
                *p2 = *p1;
                p1++;
                p2--;
            }

            cout << "Другий масив у зворотному порядку: ";
            for (int i = 0; i < n; i++) {
                cout << b[i] << " ";
            }
            cout << endl;
        }

    } while (choice != 0);

    return 0;
}