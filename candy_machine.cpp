#include <iostream>

class cashRegister {
private:
    int cashOnHand;
public:
    cashRegister() : cashOnHand(500) {} // Конструктор по умолчанию
    cashRegister(int cash) : cashOnHand(cash) {} // Конструктор с начальным количеством денег

    int getCurrentBalance() const {
        return cashOnHand;
    }

    void acceptAmount(int amount) {
        cashOnHand += amount;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int cost;
public:
    dispenserType() : numberOfItems(50), cost(50) {} // Конструктор по умолчанию
    dispenserType(int items, int cost) : numberOfItems(items), cost(cost) {} // Конструктор с начальными значениями

    int getNoOfItems() const {
        return numberOfItems;
    }

    int getCost() const {
        return cost;
    }

    void makeSale() {
        if (numberOfItems > 0)
            numberOfItems--;
    }
};

void showSelection(const dispenserType& candy, const dispenserType& chips, const dispenserType& gum, const dispenserType& cookies) {
    std::cout << "1. Конфеты (" << candy.getCost() << " руб.)\n";
    std::cout << "2. Чипсы (" << chips.getCost() << " руб.)\n";
    std::cout << "3. Жвачка (" << gum.getCost() << " руб.)\n";
    std::cout << "4. Печенье (" << cookies.getCost() << " руб.)\n";
}

void sellProduct(dispenserType& product, cashRegister& registerCash) {
    if (product.getNoOfItems() > 0) {
        std::cout << "Пожалуйста, внесите " << product.getCost() << " руб. для покупки.\n";
        int amount;
        std::cin >> amount;
        if (amount >= product.getCost()) {
            product.makeSale();
            registerCash.acceptAmount(product.getCost());
            std::cout << "Спасибо за покупку!\n";
        } else {
            std::cout << "Недостаточно денег. Транзакция отменена.\n";
        }
    } else {
        std::cout << "Извините, этот товар закончился.\n";
    }
}

int main() {
    dispenserType candy;
    dispenserType chips;
    dispenserType gum;
    dispenserType cookies;

    cashRegister registerCash;

    int choice;
    showSelection(candy, chips, gum, cookies);
    std::cout << "Введите ваш выбор (1-4): ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            sellProduct(candy, registerCash);
            break;
        case 2:
            sellProduct(chips, registerCash);
            break;
        case 3:
            sellProduct(gum, registerCash);
            break;
        case 4:
            sellProduct(cookies, registerCash);
            break;
        default:
            std::cout << "Неверный выбор.\n";
            break;
    }

    return 0;
}
