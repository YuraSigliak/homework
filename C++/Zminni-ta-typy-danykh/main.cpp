#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int choice;

    do {
        cout << "\n1. Переведення секунд у години, хвилини і секунди";
        cout << "\n2. Перетворення числа у грошовий формат";
        cout << "\n3. Обчислення швидкості бігу";
        cout << "\n4. Перетворення днів у тижні і дні";
        cout << "\n0. Вихід";
        cout << "\nВаш вибір: ";
        cin >> choice;

        if (choice == 1) {
            int seconds;
            cout << "Введіть кількість секунд: ";
            cin >> seconds;

            int hours = seconds / 3600;
            int minutes = (seconds % 3600) / 60;
            int rest = seconds % 60;

            cout << hours << " год. " << minutes << " хв. " << rest << " сек." << endl;
        }
        else if (choice == 2) {
            double sum;
            cout << "Введіть суму: ";
            cin >> sum;

            int hryvni = (int)sum;
            int kopiyky = (int)((sum - hryvni) * 100 + 0.5);

            if (kopiyky == 100) {
                hryvni++;
                kopiyky = 0;
            }

            cout << hryvni << " грн. " << kopiyky << " коп." << endl;
        }
        else if (choice == 3) {
            double distance, time;
            cout << "Обчислення швидкості бігу." << endl;

            cout << "Введіть довжину дистанції (метрів) = ";
            cin >> distance;

            cout << "Введіть час (хв.сек) = ";
            cin >> time;

            int minutes = (int)time;
            int seconds = (int)((time - minutes) * 100 + 0.5);
            int totalSeconds = minutes * 60 + seconds;

            double speed = distance / 1000.0 / (totalSeconds / 3600.0);

            cout << "Дистанція: " << distance << " м." << endl;
            cout << "Час: " << minutes << " хв " << seconds
                 << " сек = " << totalSeconds << " сек." << endl;
            cout << fixed << setprecision(2);
            cout << "Ви бігли зі швидкістю " << speed << " км/год." << endl;
        }
        else if (choice == 4) {
            int days;
            cout << "Введіть кількість днів: ";
            cin >> days;

            int weeks = days / 7;
            int rest = days % 7;

            cout << weeks << " тижні і " << rest << " дні." << endl;
        }

    } while (choice != 0);

    return 0;
}