#ifndef BASE_H
#define BASE_H

#include <string>
using namespace std;

// Абстрактный базовый класс
class Base {
public:
    Base();
    Base(int size);
    Base(const Base &B);
    virtual ~Base();

    virtual void Set() = 0;
    virtual void Get() = 0;
    virtual void Delete() = 0;
    virtual void Change() = 0;
    virtual void Load(int count, string line) = 0;
    virtual string Save(int count) = 0;
    virtual int TypeID() = 0;
};

// -------- Класс Car --------
class Car : public Base {
private:
    string marka, model, V, color, kpp;

public:
    Car();
    Car(string marka, string model, string v, string color, string kpp);
    Car(const Car &C);
    ~Car();

    void Set() override;
    void Get() override;
    void Delete() override;
    void Change() override;
    void Load(int count, string line) override;
    string Save(int count) override;
    int TypeID() override;
};

// -------- Класс Bike --------
class Bike : public Base {
private:
    string marka, model, V, P, area;

public:
    Bike();
    Bike(string marka, string model, string v, string P, string area);
    Bike(const Bike &B);
    ~Bike();

    void Set() override;
    void Get() override;
    void Delete() override;
    void Change() override;
    void Load(int count, string line) override;
    string Save(int count) override;
    int TypeID() override;
};

// -------- Класс Bus --------
class Bus : public Base {
private:
    string marka, model, count, all_count, destination;

public:
    Bus();
    Bus(string marka, string model, string count, string all_count, string destination);
    Bus(const Bus &B);
    ~Bus();

    void Set() override;
    void Get() override;
    void Delete() override;
    void Change() override;
    void Load(int count, string line) override;
    string Save(int count) override;
    int TypeID() override;
};

#endif
