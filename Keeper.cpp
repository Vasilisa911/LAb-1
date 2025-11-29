#include <iostream>
#include <fstream>
#include "Keeper.h"

using namespace std;

Keeper::Keeper(){
    array=new Base*[1]; size=1; countElement=0;
}
Keeper::Keeper(int size){
    array=new Base*[size]; this->size=size; countElement=0;
}
Keeper::Keeper(const Keeper &K){
    array=new Base*[K.size]; size=K.size; countElement=K.countElement;
    for(int i=0;i<countElement;i++)array[i]=K.array[i];
}
Keeper::~Keeper(){ delete [] array; }

void Keeper::Set(){
    cout<<"1-Car  2-Bike  3-Bus\n"; string c; cin>>c;
    if(countElement==size){
        Base**tmp=new Base*[size*2];
        for(int i=0;i<size;i++)tmp[i]=array[i];
        delete[]array; array=tmp; size*=2;
    }
    if(c=="1") array[countElement]=new Car();
    else if(c=="2") array[countElement]=new Bike();
    else array[countElement]=new Bus();
    array[countElement++]->Set();
}

void Keeper::Get(){
    for(int i=0;i<countElement;i++) array[i]->Get();
}

void Keeper::GetChoice(){
    string id;cin>>id;
    array[stoi(id)]->Get();
}

void Keeper::Delete(){
    string id;cin>>id;
    *this -= stoi(id);
}

Keeper& Keeper::operator-=(int e){
    for(int i=e;i<countElement-1;i++) array[i]=array[i+1];
    countElement--; return *this;
}

void Keeper::Change(){
    string id;cin>>id;
    array[stoi(id)]->Change();
}

void Keeper::Save(){
    ofstream C("car.txt"),B("bike.txt"),S("bus.txt");
    int A=0;
    for(int i=0;i<countElement;i++){
        for(int j=0;j<5;j++)
            (array[i]->TypeID()==1?C:(array[i]->TypeID()==2?B:S))<<array[i]->Save(j)<<endl;
    }
    cout<<"SAVE COMPLETE\n";
}

void Keeper::Load(){
    string l;ifstream C("car.txt"),S("bike.txt"),B("bus.txt");
    while(getline(C,l)){
        Base*o=new Car(); o->Load(0,l);
        for(int i=1;i<5;i++){getline(C,l);o->Load(i,l);}
        array[countElement++]=o;
    }
    while(getline(S,l)){
        Base*o=new Bike(); o->Load(0,l);
        for(int i=1;i<5;i++){getline(S,l);o->Load(i,l);}
        array[countElement++]=o;
    }
    while(getline(B,l)){
        Base*o=new Bus(); o->Load(0,l);
        for(int i=1;i<5;i++){getline(B,l);o->Load(i,l);}
        array[countElement++]=o;
    }
    cout<<"LOAD COMPLETE\n";
}
