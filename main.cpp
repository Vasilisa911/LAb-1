#include <iostream>
#include "Keeper.h"
using namespace std;

int main(){
    Keeper k;
    while(true){
        cout<<"1-Add\n2-Show All\n3-Show One\n4-Delete\n5-Edit\n6-Load\n7-Save\n";
        string c; cin>>c;
        if(c=="1")k.Set();
        else if(c=="2")k.Get();
        else if(c=="3")k.GetChoice();
        else if(c=="4")k.Delete();
        else if(c=="5")k.Change();
        else if(c=="6")k.Load();
        else if(c=="7")k.Save();
        else break;
    }
}
