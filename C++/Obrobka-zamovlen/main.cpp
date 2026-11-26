#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Food {
public:
    virtual string getName() = 0;
    virtual ~Food() {}
};

class Pizza : public Food {
public:
    string getName() override {
        return "Піца";
    }
};

class Burger : public Food {
public:
    string getName() override {
        return "Бургер";
    }
};

class Sushi : public Food {
public:
    string getName() override {
        return "Суші";
    }
};

class Order {
private:
    shared_ptr<Food> food;
    int state;

public:
    Order(shared_ptr<Food> f) {
        food = f;
        state = 0;
    }

    void show() {
        cout << "Страва: " << food->getName() << endl;

        if (state == 0)
            cout << "Статус: прийнятий" << endl;
        else if (state == 1)
            cout << "Статус: готується" << endl;
        else
            cout << "Статус: доставлений" << endl;
    }

    void nextState() {
        if (state < 2) {
            state++;
            cout << "Статус замовлення змінено." << endl;
        }
        else {
            cout << "Замовлення вже доставлене." << endl;
        }
    }
};

int main() {
    vector<shared_ptr<Order>> orders;
    int choice;

    do {
        cout << "\n1. Створити замовлення";
        cout << "\n2. Показати всі замовлення";
        cout << "\n3. Змінити статус замовлення";
        cout << "\n0. Вихід";
        cout << "\nВаш вибір: ";
        cin >> choice;

        if (choice == 1) {
            int foodChoice;
            shared_ptr<Food> food;

            cout << "\nОберіть страву:";
            cout << "\n1. Піца";
            cout << "\n2. Бургер";
            cout << "\n3. Суші";
            cout << "\nВаш вибір: ";
            cin >> foodChoice;

            if (foodChoice == 1)
                food = make_shared<Pizza>();
            else if (foodChoice == 2)
                food = make_shared<Burger>();
            else if (foodChoice == 3)
                food = make_shared<Sushi>();
            else {
                cout << "Неправильний вибір." << endl;
                continue;
            }

            orders.push_back(make_shared<Order>(food));
            cout << "Замовлення створено. Його статус: прийнятий." << endl;
        }
        else if (choice == 2) {
            if (orders.empty()) {
                cout << "Замовлень поки немає." << endl;
            }
            else {
                for (int i = 0; i < orders.size(); i++) {
                    cout << "\nЗамовлення №" << i + 1 << endl;
                    orders[i]->show();
                }
            }
        }
        else if (choice == 3) {
            int number;
            cout << "Введіть номер замовлення: ";
            cin >> number;

            if (number < 1 || number > orders.size()) {
                cout << "Такого замовлення немає." << endl;
            }
            else {
                orders[number - 1]->nextState();
                orders[number - 1]->show();
            }
        }

    } while (choice != 0);

    return 0;
}