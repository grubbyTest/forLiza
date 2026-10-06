#include <fstream>
//#include <unistd.h>
#include <time.h>
#include <chrono>
#include <ctime>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cctype>

#define INSTR "\tВведите имя и фамилию пользователя: "
#define INSTR2 "\tВведите идентификатор ВК: "
#define INSTR3 "\tВведите количество баллов : "
#define WARNSTR "\n\n\n\t\t\tПосле ввода запрашиваемых данных, нажмите Enter\n\n"
#define FILEERRLINE "\n\t\t\tОшибка создания файлового потока!"
#define NOTILINE "\n\t\t\tЕсли программа запущена впервые, то готовятся необходимые файлы!"
#define RZDL ';'
#define ANALIZLINE "\n\t\t\tЗапускается анализ базы данных...\n"
#define ERSYNCID "\n\t\tОшибка синхронизации значений ID!"
#define INITFSDONE "\n\tИнициализация файловой системы прошла успешно\n"
#define INITFSERR "\n\tОшибка инициализации файловой системы\n"

#define MENUBORDERSYM '#'
#define STR1 "1.- Добавить данные пользователя"
#define STR2 "2.- Вывести все данные пользователей"
#define STR3 "3.- Поиск данных"
#define STR4 "4.- О программном обеспечении"
#define STR5 "5.- Выход из программы"

#define STR11 "1.- Выполнить поиск по Фамилии "
#define STR22 "2.- Общий поиск "
#define STR33 "3.- Поиск по ВК идннтификатору "
#define STR44 "4.- Поиск по номеру телефона "
#define STR55 "5.- Поиск по идентификатору"
#define STR66 "6.- Поиск по имени"
#define STR77 "0.- <-- НАЗАД"

#define ABOUTAPP "\n\tПрограмма учёта данных пользователя \n\n\tВерсия: b0.0.1А \n\n\tПочта для связи: ybrbnf080699@gmail.com\n"

#define SEARCHALL "\n\n\t\t\t\t***ПОИСК***\n\n\t\tВведите вводную информацию для поиска: "
#define SEARCHSECNAME "\n\n\t\t\t\t***ПОИСК***\n\n\t\tВведите фамилию пользователя для поиска: "
#define SEARCHVK "\n\n\t\t\t\t***ПОИСК***\n\n\t\tВведите идентификатор ВК пользователя для поиска: "
#define SEARCHNUM "\n\n\t\t\t\t***ПОИСК***\n\n\t\tВведите номер телефона пользователя для поиска: "
#define SEARCHID "\n\n\t\t\t\t***ПОИСК***\n\n\t\tВведите программный идентификатор пользователя для поиска: "
#define SEARCHNAME "\n\n\t\t\t\t***ПОИСК***\n\n\t\tВведите имя пользователя для поиска: "



#define LENGHTMENU 100
#define TAB 15


#ifdef __linux__
#define DATADIR "/home/liza"
#define DIRINIT "/home/liza/log_data.anv"
#define DIRDB "/home/liza/db.anv"
#define SCREENCLR "clear"
#elif _WIN32
#define DATAFLDR "C:\\UserProgs"
#define DATAFLDRLIZA "C:\\UserProgs\\liza"
#define DIRINIT "C:\\UserProgs\\liza\\log_data.anv"
#define DIRDB "C:\\UserProgs\\liza\\db.anv"
#define SCREENCLR "cls"
#define PAUSE system("pause")

#include <Windows.h>
#endif


