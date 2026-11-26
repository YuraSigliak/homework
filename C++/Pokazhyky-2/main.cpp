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

            int* temp = new int[M + N];
            int k = 0;

            for (int i = 0; i < M; i++) {
                bool inB = false;
                bool inTemp = false;

                for (int j = 0; j < N; j++) {
                    if (*(A + i) == *(B + j)) {
                        inB = true;
                        break;
                    }
                }

                for (int j = 0; j < k; j++) {
                    if (*(A + i) == *(temp + j)) {
                        inTemp = true;
                        break;
                    }
                }

                if (!inB && !inTemp) {
                    *(temp + k) = *(A + i);
                    k++;
                }
            }

            if (choice == 2) {
                for (int i = 0; i < N; i++) {
                    bool inA = false;
                    bool inTemp = false;

                    for (int j = 0; j < M; j++) {
                        if (*(B + i) == *(A + j)) {
                            inA = true;
                            break;
                        }
                    }

                    for (int j = 0; j < k; j++) {
                        if (*(B + i) == *(temp + j)) {
                            inTemp = true;
                            break;
                        }
                    }

                    if (!inA && !inTemp) {
                        *(temp + k) = *(B + i);
                        k++;
                    }
                }
            }

            int* C = new int[k];

            for (int i = 0; i < k; i++) {
                *(C + i) = *(temp + i);
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
            delete[] temp;
            delete[] C;
        }

    } while (choice != 0);

    return 0;
}