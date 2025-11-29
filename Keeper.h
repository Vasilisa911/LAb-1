#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"

class Keeper {
private:
    Base **array;
    int size, countElement;

public:
    Keeper();
    Keeper(int size);
    Keeper(const Keeper &K);
    ~Keeper();

    void Set();
    void Get();
    void GetChoice();
    void Delete();
    Keeper& operator-=(int element);
    void Change();
    void Save();
    void Load();
};

#endif
