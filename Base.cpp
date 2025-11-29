#include <iostream>
#include "Base.h"
using namespace std;

// BASE
Base::Base(){ cout << "Base()\n"; }
Base::Base(int size){ cout << "Base(int)\n"; }
Base::Base(const Base &B){ cout << "Base copy\n"; }
Base::~Base(){ cout << "~Base()\n"; }

// -------- CAR --------
Car::Car(){ marka = model = V = color = kpp = "NONE"; }
Car::Car(string marka,string model,string v,string color,string kpp){
    this->marka=marka; this->model=model; this->V=v; this->color=color; this->kpp=kpp;
}
Car::Car(const Car &C){ marka=C.marka; model=C.model; V=C.V;color=C.color;kpp=C.kpp;}
Car::~Car(){}

void Car::Set(){ string buf;getline(cin,buf);
    cout<<"Марка:";getline(cin,marka);
    cout<<"Модель:";getline(cin,model);
    cout<<"Объем ДВС:";getline(cin,V);
    cout<<"Цвет:";getline(cin,color);
    cout<<"КПП:";getline(cin,kpp); }

void Car::Get(){ cout<<"[CAR]\nМарка:"<<marka<<"\nМодель:"<<model<<"\nОбъем:"<<V<<"\nЦвет:"<<color<<"\nКПП:"<<kpp<<"\n"; }
void Car::Delete(){ marka=model=V=color=kpp="NONE"; }

void Car::Change(){
    cout<<"1- Марка\n2- Модель\n3- V\n4- Цвет\n5- КПП\n"; string c;cin>>c; string b;getline(cin,b);
    if(c=="1"){getline(cin,marka);} else if(c=="2"){getline(cin,model);}
    else if(c=="3"){getline(cin,V);} else if(c=="4"){getline(cin,color);}
    else getline(cin,kpp);
}

string Car::Save(int c){ return c==0?marka:c==1?model:c==2?V:c==3?color:kpp;}
void Car::Load(int c,string line){
    if(c==0)marka=line; else if(c==1)model=line;
    else if(c==2)V=line; else if(c==3)color=line; else kpp=line;
}
int Car::TypeID(){ return 1; }

// -------- BIKE --------
Bike::Bike(){ marka=model=V=P=area="NONE";}
Bike::Bike(string marka,string model,string v,string P,string area){
    this->marka=marka; this->model=model; this->V=v; this->P=P; this->area=area; }
Bike::Bike(const Bike&B){ marka=B.marka;model=B.model;V=B.V;P=B.P;area=B.area;}
Bike::~Bike(){}

void Bike::Set(){ string buf;getline(cin,buf);
    cout<<"Марка:";getline(cin,marka);
    cout<<"Модель:";getline(cin,model);
    cout<<"V:";getline(cin,V);
    cout<<"P:";getline(cin,P);
    cout<<"Область:";getline(cin,area);}

void Bike::Get(){ cout<<"[BIKE]\nМарка:"<<marka<<"\nМодель:"<<model<<"\nV:"<<V<<"\nP:"<<P<<"\nОбласть:"<<area<<"\n"; }
void Bike::Delete(){ marka=model=V=P=area="NONE"; }

void Bike::Change(){
    cout<<"1- Марка\n2- Модель\n3- V\n4- P\n5- Область\n"; string c;cin>>c; string b;getline(cin,b);
    if(c=="1")getline(cin,marka); else if(c=="2")getline(cin,model);
    else if(c=="3")getline(cin,V); else if(c=="4")getline(cin,P);
    else getline(cin,area);
}

string Bike::Save(int c){
    return c==0?marka:c==1?model:c==2?V:c==3?P:area; }
void Bike::Load(int c,string l){
    if(c==0)marka=l; else if(c==1)model=l; else if(c==2)V=l; else if(c==3)P=l; else area=l; }

int Bike::TypeID(){ return 2; }

// -------- BUS --------
Bus::Bus(){ marka=model=count=all_count=destination="NONE";}
Bus::Bus(string marka,string model,string count,string all_count,string destination){
    this->marka=marka; this->model=model; this->count=count; this->all_count=all_count; this->destination=destination; }
Bus::Bus(const Bus &B){ marka=B.marka;model=B.model;count=B.count;all_count=B.all_count;destination=B.destination;}
Bus::~Bus(){}

void Bus::Set(){ string buf;getline(cin,buf);
    cout<<"Марка:";getline(cin,marka);
    cout<<"Модель:";getline(cin,model);
    cout<<"Сидячие:";getline(cin,count);
    cout<<"Всего мест:";getline(cin,all_count);
    cout<<"Пункт назначения:";getline(cin,destination);}

void Bus::Get(){ cout<<"[BUS]\nМарка:"<<marka<<"\nМодель:"<<model<<"\nСидячих:"<<count<<"\nВсего:"<<all_count<<"\nКуда:"<<destination<<"\n"; }
void Bus::Delete(){ marka=model=count=all_count=destination="NONE"; }

void Bus::Change(){
    cout<<"1-Марка\n2-Модель\n3-Сид. места\n4-Всего мест\n5-Пункт\n"; string c;cin>>c; string b;getline(cin,b);
    if(c=="1")getline(cin,marka); else if(c=="2")getline(cin,model);
    else if(c=="3")getline(cin,count); else if(c=="4")getline(cin,all_count);
    else getline(cin,destination);
}

string Bus::Save(int c){
    return c==0?marka:c==1?model:c==2?count:c==3?all_count:destination;}
void Bus::Load(int c,string l){
    if(c==0)marka=l; else if(c==1)model=l; else if(c==2)count=l; else if(c==3)all_count=l; else destination=l; }

int Bus::TypeID(){ return 3; }
