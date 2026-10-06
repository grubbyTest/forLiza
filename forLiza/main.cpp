#include <iostream>
#include "Struct.h"

int main(int argc, char* argv[]){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    /*charact::initStruct();
    charact *ptr;*/
    /*about a;
    a.name = "Elizaveta";
    a.secName = "Ageeva";
    a.otchName = "Vladimirovna";
    a.idVK = "@lili";
    a.countBalls = 2300;
    a.phoneNum = {'+', '7' , '9', '8', '8', '7', '4', '1', '8', '2', '9', '2'};

    charact man(a);
    ptr = &man;
    ptr->upper();

    ptr->writeData();*/
    /*ptr = charact::searchObj(PersonProperty::All, "2");
    if(ptr == nullptr) std::cout << "\n\t\tСовпадений не найдено\n";
    else{
        ptr->printInfo();

    }*/
    charact::start();
    /*string str = "Строка";
    char c = 'ю';
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    c = std::toupper(c);
    std::cout << str;*/

    return 0;
}
