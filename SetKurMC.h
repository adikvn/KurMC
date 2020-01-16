#pragma once
//#include <DHT.h>                              //Подключаем библиотеку для работы с датчиком температуры и влажности
//#include <LiquidCrystal.h>                    //Подключаем библиотеку для работы с LCD
//#include <iarduino_RTC.h>
//#include <MsTimer2.h>                         //Подключаем библиотеку для работы с тамером 2
//#include <Wire.h>                             //Подключаем библиотеку для связи по scl sda
//#include <EEPROM.h>

#define temper_out 2							//Pin2 управление температурой
#define ventel_out 3							//Pin3 управление вентиляцией
#define humid_out 12							//Pin12 управление влажность
#define key_kontrol_out A1

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);          // инициализируем LCD, указывая управляющие контакты
DHT  sensor;
iarduino_RTC  time(RTC_DS3231);

const String PROGMEM &ver = "ver0.0 12.01.2020";
const char PROGMEM clear_line[17] = "                ";


float temperature_ = 0;
float humid_ = 0;
bool settem = false;
bool sethum = false;

int menu_item_ = 1;                           //выбор меню
int menu_item1_ = 2;                          //выбор подменю 1 уровня
int menu_item2_ = 1;                          //выбор подменю 2 уровня
int current_menu_parent_ = 0;                  //выбор текущего уровня меню 


boolean start_ = true;                       // Автоматический режим
boolean key_press_ = false;                   //Флаг нажатой клавиши
int s2 = 0;                                   //затержка в n сек
int result;									  // Результат опроса DHT

///////////////////////////////////////////////////////////////////////////////

//int kod;
//char last_item;
//int current_menu = 0; //Переменная указывает на текущее меню
//int current_poz = 1; //Переменная указывает на текущий пункт меню/подменю
//void goto_menu(void);
//void print_menu(void);
//
//typedef struct _selection
//{
//    //unsigned char* mas; // Указатель на название пункта
//    void (*function)(void); //Указатель на функцию выполняющуюся по нажатии на enter/escape
//    unsigned ent_f : 4; //Флаг входа 4 бита - обычно ID меню в которое надо войти
//    unsigned esc_f : 4; //Флаг выхода 4 бита - обычно ID меню в которое надо вернуться
//}SELECTION;
//
////Структура описывает меню/подменю
//typedef struct _menu {
//    unsigned char id; //Номер меню/подменю
//    unsigned char num_selections; //Количество пунктов данного меню/подменю
//    SELECTION* m; //Указатель намассив пунктов данного меню/подменю
//}MENU;
//
////Номера меню/подменю
//enum __menu__id {
//    MAIN_MENU, //Главное меню
//    SETDATATIME_MENU, //Меню настроек
//    SETTEMPER_MENU,
//    SETHUM_MENU,
//    REALTIME_MENU //Меню отчёта
//};
//
//
////Заголовки функций
//void func1(void);
//void func2(void)
//{
//    // do {
//    // analogButtons.checkButtons();
//    // lcd.clear(); //очистить LCD
//    // lcd.print("Hello World!"); //вывод строки на LCD
//    // delay(1000); //задержка для проверки
//    // } while ( != 5); //Для выхода - ESC
//}
//
//
////Массив хранищий пункты главного меню (структура SELECTION)
//static SELECTION menu_[] = {
//{ goto_menu, SETDATATIME_MENU, MAIN_MENU}, //Punkt 1
//{ goto_menu, SETTEMPER_MENU, MAIN_MENU}, //Punkt 2
//{ goto_menu, SETHUM_MENU, MAIN_MENU}, //Punkt 3
//{ goto_menu, REALTIME_MENU, MAIN_MENU}, //Punkt 4
//};
//
////Главный массив хранит в себе все меню/подменю
////Все меню/подменю должны описываться в таком же порядке как и в enum __menu__id ...
//static MENU menu[] = {
//{MAIN_MENU, 5, menu_}, //Меню 1
//{SETDATATIME_MENU, 1, menu_m0}, //Меню 2 
//{SETTEMPER_MENU, 1, menu_m1},
//{SETHUM_MENU, 1, menu_m2},
//{REALTIME_MENU, 1, menu_m3}
//};
//
//static SELECTION menu_m0[] = {
//{func1, 0, 0}, //Punkt 1
//};
//
//static SELECTION menu_m1[] = {
//{func1, 0, 0}, //Punkt 1
//};
//
//static SELECTION menu_m2[] = {
//{func1, 0, 0}, //Punkt 1
//};
//
//static SELECTION menu_m3[] = {
//{func1, 0, 0}, //Punkt 1
//};
//
/////////////////////////END_menu////////////////////////////////////////
//
//
//void goto_menu(void)
//{
//    switch (kod) {
//    case 1:
//    {current_menu = menu[current_menu].m[current_poz].ent_f;
//    last_item = current_poz;
//    break;
//    }; //enter
//    break;
//    case 2:
//    {current_menu = menu[current_menu].m[current_poz].esc_f;
//    break;
//    }; //escape }
//    break;
//    default:
//        current_poz = 0;
//    }
//}
//
//void print_menu()
//{
//    lcd.clear();
//    lcd.print("> ");
//    //lcd.print(menu[current_menu].m[current_poz].mas);
//
//
//    //тут непонятки "м" was not declare in this score
//    //хотя массив вроде заведен
//
//
//    lcd.print(current_menu);
//    lcd.setCursor(2, 1);
//    if (current_poz == menu[current_menu].num_selections - 1)
//    {
//        // lcd.print(menu[current_menu].m[0].mas);
//        lcd.print("----------------");
//    }
//    else
//    {
//        // lcd_puts(menu[current_menu].m[current_poz+1].mas);
//        kod = menu[current_menu].m[current_poz + 1].mas;
//        lcd.setCursor(menu[current_menu].m[current_poz + 1].mas,0);
//        lcd.print(kod);
//    }
//    delay(100);
//    
//}