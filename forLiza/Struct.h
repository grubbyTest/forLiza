#include <string>
#include "header.h"
#include <iostream>
#include <filesystem>

using namespace std;

const int STRSIZE = 30;
static int local_id = 0;

struct about{
    string name;
    string secName;
    string otchName;
    string idVK;
    int countBalls;
    string phoneNum;

    void printInfo();

};

enum class PersonProperty{ID, SecName, Name, VK, Balls, phone, All};

class charact : public about{
    int id;
public:
    charact(){
        id = local_id + 1;
        name = " ";
        secName = " ";
        otchName = " ";
        idVK = " ";
        countBalls = 0;
        phoneNum = " ";
    }
    charact(about&);
    static int start();
private:

    static bool initFs();
    static bool initTime();
    static void initStruct();
    bool writeData();
    int printInfo();
    bool upper();
    static charact *searchObj(PersonProperty, string);
    static int Interface(int);
    static void getSearch(PersonProperty, string);

};


