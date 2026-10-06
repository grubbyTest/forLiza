#include "Struct.h"
#pragma warning(disable : 4996)
//#include <unistd.h>

std::vector<charact> charactVec;



charact::charact(about& obj){

    this->id = local_id + 1;
    this->name = obj.name;
    this->secName = obj.secName;
    this->otchName = obj.otchName;
    this->idVK = obj.idVK;
    this->countBalls = obj.countBalls;
    this->phoneNum = obj.phoneNum;

}

int charact::start(){
    bool mainFlag = true;
    string temp;
    charact* ptr;

    initTime();
    if(initFs()){
        std::cout << INITFSDONE;
        Sleep(1500);
    }else{
        std::cout << INITFSERR;
        return 2;
    }
    while (mainFlag) {
        switch (Interface(0)) {
        case 1:
            system(SCREENCLR);
            ptr = new charact;

            std::cout << "\n\t\t\t***Ввод данных о пользователе***\n\tВведите Фамилию Имя Отчество(при наличии) пользователя и нажмите Enter:\n\t---> ";
            std::cin >> ptr->secName >> ptr->name >> ptr->otchName;
            system(SCREENCLR);

            std::cout << "\n\t\t\t***Ввод данных о пользователе***\n\tВведите идентификатор ВК пользователя и нажмите Enter:\n\t---> ";
            std::cin >> ptr->idVK;
            system(SCREENCLR);

            std::cout << "\n\t\t\t***Ввод данных о пользователе***\n\tВведите номер телефона пользователя и нажмите Enter:\n\t---> ";
            std::cin >> ptr->phoneNum;
            system(SCREENCLR);

            std::cout << "\n\t\t\t***Ввод данных о пользователе***\n\tВведите количество баллов пользователя и нажмите Enter:\n\t---> ";
            std::cin >> ptr->countBalls;
            system(SCREENCLR);

            std::cout << "\n\t\t\t***Ввод данных о пользователе***\n\tПроверьте введёные данные и нажмите Enter (0 - ОТМЕНА):\n\t---> ";
            ptr->printInfo();
            std::cin >> temp;
            if (temp[0] == '0') break;
            else ptr->writeData();
            system(SCREENCLR);

            
            break;
        case 2:
            for (int i = 0; i < charactVec.size() - 1; i++) {
                charactVec.at(i).printInfo();
            }
            PAUSE;
            break;
        case 3:

            switch (Interface(3)) {
                system(SCREENCLR);
                
            case 1:
                
                getSearch(PersonProperty::SecName, SEARCHSECNAME);
                break;
            case 2:
                getSearch(PersonProperty::All, SEARCHALL);
                break;
            case 3:
                getSearch(PersonProperty::VK, SEARCHVK);
                break;
            case 4:
                getSearch(PersonProperty::phone, SEARCHNUM);
                break;
            case 5:
                getSearch(PersonProperty::ID, SEARCHID);
                break;
            case 6:
                getSearch(PersonProperty::Name, SEARCHNAME);
                break;
            }
            break;
        case 4:
            system(SCREENCLR);
            system("color fc");
            std::cout << ABOUTAPP;
            PAUSE;
            break;
        case 5:
            mainFlag = false;
            break;
        default:
            break;
        }
    }
    system(SCREENCLR);
    std::cout << "\n\n\n\n\n\t\tThe "; Sleep(500); std::cout << "truth "; Sleep(500);
    std::cout << "is "; Sleep(500); std::cout << "out "; Sleep(500);
    std::cout << "there..."; Sleep(1500);
    system(SCREENCLR);


    return 1;
}

void charact::getSearch(PersonProperty item, string line) {
    system(SCREENCLR);
    string str;
    std::cout << line;
    std::cin >> str;
    searchObj(item, str)->printInfo();
    PAUSE;
}

int charact::Interface(int n = 0){

    system(SCREENCLR);

    string str;
    if (n == 3) str = STR11;
    else str = STR1;

    int lenghtStr = str.length() + 2;
    int tab = TAB;

    int temp;
    /////////////////////////Menu
    for(int i = 0; i < LENGHTMENU; i++){
        std::cout << MENUBORDERSYM;
    }
    std::cout << std::endl << MENUBORDERSYM;
    for(int i = 0; i < LENGHTMENU - 2; i++){
        std::cout << ' ';
    }
    std::cout << MENUBORDERSYM;

    std::cout << std::endl << MENUBORDERSYM;                   /////////1
    for(int i = 0; i < tab; i++){             //
        std::cout << ' ';                                              //
    }                                                                   //
    std::cout << str;                                                   //
    for(int i = 0; i < (LENGHTMENU - lenghtStr) - tab; i++){              //
        std::cout << ' ';                                               //
    }                                                                  //
    std::cout << MENUBORDERSYM;                                  ////////1
    std::cout << std::endl << MENUBORDERSYM;
    for(int i = 0; i < LENGHTMENU - 2; i++){
        std::cout << ' ';
    }
    std::cout << MENUBORDERSYM;

    if (n == 3) str = STR22;
    else str = STR2;                                         ////////////2
    lenghtStr = strlen(str.c_str()) + 2;                                //
    std::cout << std::endl << MENUBORDERSYM;                            //
    for(int i = 0; i < tab; i++){                                       //
        std::cout << ' ';                                               //
    }                                                                   //
    std::cout << str;                                                   //
    for(int i = 0; i < (LENGHTMENU - lenghtStr) - tab; i++){        ////
        std::cout << ' ';                                               //
    }                                                                   //
    std::cout << MENUBORDERSYM;                                         //
    std::cout << std::endl << MENUBORDERSYM;                            //
    for(int i = 0; i < LENGHTMENU - 2; i++){                            //
        std::cout << ' ';                                               //
    }                                                                   //
    std::cout << MENUBORDERSYM;                             /////////////2

    if (n == 3) str = STR33;
    else str = STR3;                                        ////////////3
    lenghtStr = strlen(str.c_str()) + 2;                               //
    std::cout << std::endl << MENUBORDERSYM;                           //
    for(int i = 0; i < tab; i++){                                      //
        std::cout << ' ';                                               //
    }                                                                   //
    std::cout << str;                                                   //
    for(int i = 0; i < (LENGHTMENU - lenghtStr) - tab; i++){        ////
        std::cout << ' ';                                               //
    }                                                                   //
    std::cout << MENUBORDERSYM;                                         //
    std::cout << std::endl << MENUBORDERSYM;                            //
    for(int i = 0; i < LENGHTMENU - 2; i++){                            //
        std::cout << ' ';                                               //
    }                                                                   //
    std::cout << MENUBORDERSYM;                             /////////////3

    if (n == 3) str = STR44;
    else str = STR4;                                        ////////////4
    lenghtStr = strlen(str.c_str()) + 2;                               //
    std::cout << std::endl << MENUBORDERSYM;                           //
    for(int i = 0; i < tab; i++){                                      //
        std::cout << ' ';                                               //
    }                                                                   //
    std::cout << str;                                                   //
    for(int i = 0; i < (LENGHTMENU - lenghtStr) - tab; i++){         ////
        std::cout << ' ';                                               //
    }                                                                   //
    std::cout << MENUBORDERSYM;                                         //
    std::cout << std::endl << MENUBORDERSYM;                            //
    for(int i = 0; i < LENGHTMENU - 2; i++){                            //
        std::cout << ' ';                                               //
    }                                                                   //
    std::cout << MENUBORDERSYM;                             /////////////4

    if (n == 3) str = STR55;
    else str = STR5;                                        ////////////5
    lenghtStr = strlen(str.c_str()) + 2;                               //
    std::cout << std::endl << MENUBORDERSYM;                           //
    for(int i = 0; i < tab; i++){                                      //
        std::cout << ' ';                                               //
    }                                                                   //
    std::cout << str;                                                   //
    for(int i = 0; i < (LENGHTMENU - lenghtStr) - tab; i++){         ////
        std::cout << ' ';                                               //
    }                                                                   //
    std::cout << MENUBORDERSYM;                                         //
    std::cout << std::endl << MENUBORDERSYM;                            //
    for(int i = 0; i < LENGHTMENU - 2; i++){                            //
        std::cout << ' ';                                               //
    }                                                                   //
    std::cout << MENUBORDERSYM;                             /////////////5

    if (n == 3){
        str = STR66;                                             ////////////6
        lenghtStr = strlen(str.c_str()) + 2;                               //
        std::cout << std::endl << MENUBORDERSYM;                           //
        for(int i = 0; i < tab; i++){                                      //
            std::cout << ' ';                                               //
        }                                                                   //
        std::cout << str;                                                   //
        for(int i = 0; i < (LENGHTMENU - lenghtStr) - tab; i++){         ////
            std::cout << ' ';                                               //
        }                                                                   //
        std::cout << MENUBORDERSYM;                                         //
        std::cout << std::endl << MENUBORDERSYM;                            //
        for(int i = 0; i < LENGHTMENU - 2; i++){                            //
            std::cout << ' ';                                               //
        }                                                                   //
        std::cout << MENUBORDERSYM;                             /////////////6


        str = STR77;                                             ////////////7
        lenghtStr = str.length() + 2;                                         //
        std::cout << std::endl << MENUBORDERSYM;                           //
        for(int i = 0; i < tab; i++){                                      //
            std::cout << ' ';                                               //
        }                                                                   //
        std::cout << str;                                                   //
        for(int i = 0; i < (LENGHTMENU - lenghtStr) - tab; i++){         ////
            std::cout << ' ';                                               //
        }                                                                   //
        std::cout << MENUBORDERSYM;                                         //
        std::cout << std::endl << MENUBORDERSYM;                            //
        for(int i = 0; i < LENGHTMENU - 2; i++){                            //
            std::cout << ' ';                                               //
        }                                                                   //
        std::cout << MENUBORDERSYM;                             /////////////7
    }

    std::cout << std::endl << MENUBORDERSYM;
    for(int i = 0; i < LENGHTMENU - 2; i++){
        std::cout << ' ';
    }
    std::cout << MENUBORDERSYM << std::endl;
    for(int i = 0; i < LENGHTMENU; i++){
        std::cout << MENUBORDERSYM;
    }
    std::cout << std::endl;


    std::cout << "\n\tВведите соответствующий номер и нажмите Enter\n\n\t---> ";
    std::cin >> temp;

    return temp;
}

void charact::initStruct(){
    /*std::cout << WARNSTR;
    std::cout << INSTR;
    std::cin >> name;
    std::cin >>secName;
    std::cout << INSTR2;
    std::cin >> idVK;
    std::cout << INSTR3;
    std::cin >> countBalls;*/

    initFs();


    //return *this;
}

bool charact::initFs(){
    fstream chfi(DIRINIT, ios::in);

    initTime();

    if(!chfi){
        cerr << FILEERRLINE;
        Sleep(1500);
        cerr << NOTILINE;

        std::filesystem::create_directory(DATAFLDR);
        std::filesystem::create_directory(DATAFLDRLIZA);

        fstream chfo1(DIRINIT, ios::out);
        if(!chfo1){ cerr << FILEERRLINE;
            return false;
        }
        fstream chfo2(DIRDB, ios::out);
        if(!chfo2){ cerr << FILEERRLINE;
            return false;
        }
        Sleep(1500);
        chfo1.close();
        chfo2.close();

    }else{
        bool loop = true;
        charact *tempCh = new charact;
        string tempWrd;
        static int counter = 0;
        //local_id = 0;
        chfi.close();
        chfi.open(DIRDB, ios::in);
        if(!chfi) return false;
        cout << ANALIZLINE;
        while(!chfi.eof()){
                loop = true;
                counter = 0;
                //chfi.get(temp);
                //cout << temp << endl;    DEBUG
                while(loop){

                    getline(chfi, tempWrd, RZDL);
                    if(chfi.eof()) break;

                    switch(counter){
                    case 0:
                        tempCh->id = atoi(tempWrd.c_str());
                        local_id++;
                        if(tempCh->id != local_id) std::cout << ERSYNCID;
                        break;
                    case 1:
                        tempCh->secName = tempWrd;
                        break;
                    case 2:
                        tempCh->name = tempWrd;
                        break;
                    case 3:
                        tempCh->otchName = tempWrd;
                        break;
                    case 4:
                        tempCh->idVK = tempWrd;
                        break;
                    case 5:
                        tempCh->countBalls = atoi(tempWrd.c_str());
                        break;
                    case 6:
                        tempCh->phoneNum = tempWrd;
                        chfi.get();
                        loop = false;
                        break;
                    default:
                        break;
                    }
                    counter++;
                    //getline(chfi, tempWrd, RZDL);
                    //cout << tempWrd << endl;

                }

                charactVec.push_back(*tempCh);
                charactVec.at(local_id - 1).printInfo();
                //cout << charactVec.at(local_id - 1).secName << endl;
        }
        cout << "\tКоличество записей: " << local_id << endl;
        delete tempCh;
        chfi.close();
    }


    return true;
}

bool charact::initTime(){

time_t now = time(0);
    /*std::cout << "Текущее время: " << now << std::endl;
    tm *p = gmtime(&now);
    cout << "days = " << p->tm_yday << endl;
    cout << "hours = " << p->tm_hour << endl;
    cout << "minutes = " << p->tm_min  << endl;
    cout << "seconds = " << p->tm_sec << endl;

    auto start = std::chrono::system_clock::now();
    //
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);*/
    std::cout << "Зафиксировано: " << std::ctime(&now)
              //<< "Затраченное время: " << elapsed_seconds.count() << " сек."
              << std::endl;


    return false;
}

bool charact::writeData(){

    ofstream fout(DIRDB, ios::app);
    if(!fout){
        cerr << FILEERRLINE;
        return false;
    }
    this->upper();
    fout << this->id << RZDL << this->secName << RZDL << this->name << RZDL
        << this->otchName << RZDL << this->idVK << RZDL << this->countBalls << RZDL
        << this->phoneNum << RZDL << endl;

    local_id++;
    cout << "\n\tПроизведена запись № " << this->id << "\n\tСчётчик: "
        << local_id << endl;

    return true;
}
void about::printInfo(){
    /*printf("%4d %15s %15s %20s %20s %13s", this->id, this->secName.c_str(), this->name.c_str()
           , this->otchName.c_str(), this->idVK.c_str(), this->phoneNum.c_str());*/
    std::cout << "\t" << this->secName << "\t" << this ->name << "\t"
        << this->otchName << "\t" << this->idVK << "\t" << this->countBalls << "\t" << this->phoneNum << "\n";
}

int charact::printInfo() {
    if (this == nullptr) {
        std::cerr << "Передан нулевой указатель";
        return 1;
    }
    /*printf("%4d %15s %15s %20s %20s %13s", this->id, this->secName.c_str(), this->name.c_str()
        , this->otchName.c_str(), this->idVK.c_str(), this->phoneNum.c_str(), "\n");*/
    std::cout << this->id << "\t" << this->secName << "\t" << this->name << "\t"
        << this->otchName << "\t" << this->idVK << "\t" << this->countBalls << "\t" << this->phoneNum << "\n";
    return 0;
}

bool charact::upper(){
    std::transform(this->secName.begin(), this->secName.end(), this->secName.begin(), ::toupper);
    std::transform(this->name.begin(), this->name.end(), this->name.begin(), ::toupper);
    std::transform(this->otchName.begin(), this->otchName.end(), this->otchName.begin(), ::toupper);

    return true;
}

charact *charact::searchObj(PersonProperty en = PersonProperty::All, std::string str = ""){
    //using namespace PersonProperty;
    fstream fileDB(DIRDB, ios::in);
    if(str[0] != '@' && str[0] != '+'){
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    }
    if(!fileDB){
        std::cerr << "003";
        return nullptr;
    }


    else{
        if(en == PersonProperty::SecName){
            for(int i = 0; i < charactVec.size(); i++){
                if(str == charactVec.at(i).secName){
                    return &charactVec.at(i);
                }
            }
        }
        if (en == PersonProperty::VK) {
            for (int i = 0; i < charactVec.size(); i++) {
                if (str == charactVec.at(i).idVK) {
                    return &charactVec.at(i);
                }
            }
        }
        if (en == PersonProperty::phone) {
            for (int i = 0; i < charactVec.size(); i++) {
                if (str == charactVec.at(i).phoneNum) {
                    return &charactVec.at(i);
                }
            }
        }
        if (en == PersonProperty::ID) {
            for (int i = 0; i < charactVec.size(); i++) {
                if (str == to_string(charactVec.at(i).id)) {
                    return &charactVec.at(i);
                }
            }
        }
        if (en == PersonProperty::Name) {
            for (int i = 0; i < charactVec.size(); i++) {
                if (str == charactVec.at(i).name) {
                    return &charactVec.at(i);
                }
            }
        }
        if(en == PersonProperty::All){
            if (isdigit(str[0])){
                int temp = atoi(str.c_str());
                std::cout << "\n\tВыполняется поиск по числовому значению\n";
                for(int i = 0; i < charactVec.size(); i++){
                    if(charactVec.at(i).id == temp){
                        std::cout << "\n\tВыполнен поиск по идентификатору\n";
                        return &charactVec.at(i);
                    } else if(charactVec.at(i).countBalls == temp){
                        std::cout << "\n\tВыполнен поиск по количеству очков\n";
                        return &charactVec.at(i);
                    }
                }

            }
            for(int i = 0; i < charactVec.size(); i++){
                if(charactVec.at(i).secName == str){
                    std::cout << "\n\tВыполнен поиск по Фамилии\n";
                    return &charactVec.at(i);
                } else if(charactVec.at(i).name == str){
                    std::cout << "\n\tВыполнен поиск по имени\n";
                    return &charactVec.at(i);
                } else if (charactVec.at(i).idVK == str){
                    std::cout << "\n\tВыполнен поиск по идентификатору ВК\n";
                    return &charactVec.at(i);
                } else if (charactVec.at(i).phoneNum == str){
                    std::cout << "\n\tВыполнен поиск по номеру телефона\n";
                    return &charactVec.at(i);
                }
            }
            std::cout << str;
        }
    }
    return nullptr;
    }


