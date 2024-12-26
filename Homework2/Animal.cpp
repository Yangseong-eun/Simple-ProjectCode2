#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Animal 클래스 (기본 클래스)
class Animal {
public:
    virtual void makeSound() const = 0; // 순수 가상 함수
    virtual ~Animal() {} // 가상 소멸자
};

// Dog 클래스
class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Woof!" << endl;
    }
};

// Cat 클래스
class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "Meow!" << endl;
    }
};

// Cow 클래스
class Cow : public Animal {
public:
    void makeSound() const override {
        cout << "Moo!" << endl;
    }
};

// Zoo 클래스
class Zoo {
private:
    Animal* animals[10]; // 동물 객체를 저장할 포인터 배열
    int animalCount;     // 저장된 동물 개수

public:
    Zoo() : animalCount(0) {
        for (int i = 0; i < 10; i++) {
            animals[i] = nullptr;
        }
    }

    void addAnimal(Animal* animal) {
        if (animalCount < 10) {
            animals[animalCount++] = animal;
        }
        else {
            cout << "Zoo is full!" << endl;
        }
    }

    void performActions() const {
        for (int i = 0; i < animalCount; i++) {
            animals[i]->makeSound();
        }
    }

    ~Zoo() {
        for (int i = 0; i < animalCount; i++) {
            delete animals[i];
        }
    }
};

// 랜덤 동물을 생성하는 함수
Animal* createRandomAnimal() {
    int random = rand() % 3; // 0, 1, 2 중 하나를 생성
    if (random == 0) {
        return new Dog();
    }
    else if (random == 1) {
        return new Cat();
    }
    else {
        return new Cow();
    }
}

// 메인 함수
int main() {
    srand(static_cast<unsigned>(time(0))); // 랜덤 시드 초기화

    Zoo zoo;

    // 랜덤으로 동물 추가
    for (int i = 0; i < 5; i++) {
        zoo.addAnimal(createRandomAnimal());
    }

    // 동물의 행동 수행
    cout << "Animals in the Zoo are making sounds:" << endl;
    zoo.performActions();

    return 0;
}
