#include <iostream>
#include <vector>
#include <string>

class Wood {
public:
    Wood(int quantity) : quantity(quantity) {}

    void use(int amount) {
        if (quantity >= amount) {
            quantity -= amount;
            std::cout << "Использовано " << amount << " древесины. Осталось: " << quantity << " древесины." << std::endl;
        } else {
            std::cout << "Недостаточно древесины для строительства!" << std::endl;
        }
    }

    int getQuantity() const {
        return quantity;
    }

private:
    int quantity;
};

class Building {
public:
    Building(std::string type, int woodRequired) : type(type), woodRequired(woodRequired) {}

    void build(Wood& wood) {
        if (wood.getQuantity() >= woodRequired) {
            wood.use(woodRequired);
            std::cout << "Построено здание типа: " << type << std::endl;
        } else {
            std::cout << "Недостаточно древесины для постройки здания типа: " << type << std::endl;
        }
    }

private:
    std::string type;
    int woodRequired;
};

int main() {
    Wood playerWood(100); // У игрока 100 единиц древесины
    Building woodenHouse("Деревянный дом", 50); // Для постройки деревянного дома нужно 50 древесины
    Building woodenWall("Деревянная стена", 20); // Для постройки деревянной стены нужно 20 древесины

    // Строим здания
    woodenHouse.build(playerWood);
    woodenWall.build(playerWood);
    woodenWall.build(playerWood); // Попробуем построить стену еще раз

    return 0;
}
