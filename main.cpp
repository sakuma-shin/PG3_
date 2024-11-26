#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <memory>  // std::shared_ptr

// 基底クラス：Animal
class Animal {
public:
    virtual void makeSound() const = 0; // 純粋仮想関数
    virtual ~Animal() = default;
};

// 派生クラス：Dog
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

// 派生クラス：Cat
class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // ポリモーフィズムを使って Animal ポインタで異なるクラスを扱う
    std::shared_ptr<Animal> myDog = std::make_shared<Dog>();
    std::shared_ptr<Animal> myCat = std::make_shared<Cat>();

    myDog->makeSound();  // 出力: Woof!
    myCat->makeSound();  // 出力: Meow!

    return 0;
}

