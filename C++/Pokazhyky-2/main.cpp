#include <iostream>
using namespace std;

int main() {
    int choice;

    do {
        cout << "\n1. Елементи масиву A, яких немає в B";
        cout << "\n2. Елементи масивів A і B, які не є спільними";
        cout << "\n0. Вихід";
        cout << "\nВаш вибір: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            int M, N;

            cout << "Введіть розмір масиву A: ";
            cin >> M;
            cout << "Введіть розмір масиву B: ";
            cin >> N;

            int* A = new int[M];
            int* B = new int[N];

            cout << "Введіть елементи масиву A:" << endl;
            for (int i = 0; i < M; i++) {
                cin >> *(A + i);
            }

            cout << "Введіть елементи масиву B:" << endl;
            for (int i = 0; i < N; i++) {
                cin >> *(B + i);
            }

            int* C = new int[M + N];
            int k = 0;

            for (int i = 0; i < M; i++) {
                bool єВB = false;
                bool єВC = false;

                for (int j = 0; j < N; j++) {
                    if (*(A + i) == *(B + j)) {
                        єВB = true;
                        break;
                    }
                }

                for (int j = 0; j < k; j++) {
                    if (*(A + i) == *(C + j)) {
                        єВC = true;
                        break;
                    }
                }

                if (choice == 1) {
                    if (!єВB && !єВC) {
                        *(C + k) = *(A + i);
                        k++;
                    }
                }
                else {
                    if (!єВB && !єВC) {
                        *(C + k) = *(A + i);
                        k++;
                    }
                }
            }

            if (choice == 2) {
                for (int i = 0; i < N; i++) {
                    bool єВA = false;
                    bool єВC = false;

                    for (int j = 0; j < M; j++) {
                        if (*(B + i) == *(A + j)) {
                            єВA = true;
                            break;
                        }
                    }

                    for (int j = 0; j < k; j++) {
                        if (*(B + i) == *(C + j)) {
                            єВC = true;
                            break;
                        }
                    }

                    if (!єВA && !єВC) {
                        *(C + k) = *(B + i);
                        k++;
                    }
                }
            }

            cout << "Третій масив: ";
            for (int i = 0; i < k; i++) {
                cout << *(C + i) << " ";
            }
            if (k == 0) {
                cout << "порожній";
            }
            cout << endl;

            delete[] A;
            delete[] B;
            delete[] C;
        }

    } while (choice != 0);

    return 0;
}