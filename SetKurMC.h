#pragma once
//#include <DHT.h>                              //���������� ���������� ��� ������ � �������� ����������� � ���������
//#include <LiquidCrystal.h>                    //���������� ���������� ��� ������ � LCD
//#include <iarduino_RTC.h>
//#include <MsTimer2.h>                         //���������� ���������� ��� ������ � ������� 2
//#include <Wire.h>                             //���������� ���������� ��� ����� �� scl sda
//#include <EEPROM.h>

#define temper_out 2							//Pin2 ���������� ������������
#define ventel_out 3							//Pin3 ���������� �����������
#define humid_out 12							//Pin12 ���������� ���������
#define key_kontrol_out A1

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);          // �������������� LCD, �������� ����������� ��������
DHT  sensor;
iarduino_RTC  time(RTC_DS3231);

const String PROGMEM &ver = "ver0.0 12.01.2020";
const char PROGMEM clear_line[17] = "                ";


float temperature_ = 0;
float humid_ = 0;
bool settem = false;
bool sethum = false;

int menu_item_ = 1;                           //����� ����
int menu_item1_ = 2;                          //����� ������� 1 ������
int menu_item2_ = 1;                          //����� ������� 2 ������
int current_menu_parent_ = 0;                  //����� �������� ������ ���� 


boolean start_ = true;                       // �������������� �����
boolean key_press_ = false;                   //���� ������� �������
int s2 = 0;                                   //�������� � n ���
int result;									  // ��������� ������ DHT

///////////////////////////////////////////////////////////////////////////////

//int kod;
//char last_item;
//int current_menu = 0; //���������� ��������� �� ������� ����
//int current_poz = 1; //���������� ��������� �� ������� ����� ����/�������
//void goto_menu(void);
//void print_menu(void);
//
//typedef struct _selection
//{
//    //unsigned char* mas; // ��������� �� �������� ������
//    void (*function)(void); //��������� �� ������� ������������� �� ������� �� enter/escape
//    unsigned ent_f : 4; //���� ����� 4 ���� - ������ ID ���� � ������� ���� �����
//    unsigned esc_f : 4; //���� ������ 4 ���� - ������ ID ���� � ������� ���� ���������
//}SELECTION;
//
////��������� ��������� ����/�������
//typedef struct _menu {
//    unsigned char id; //����� ����/�������
//    unsigned char num_selections; //���������� ������� ������� ����/�������
//    SELECTION* m; //��������� �������� ������� ������� ����/�������
//}MENU;
//
////������ ����/�������
//enum __menu__id {
//    MAIN_MENU, //������� ����
//    SETDATATIME_MENU, //���� ��������
//    SETTEMPER_MENU,
//    SETHUM_MENU,
//    REALTIME_MENU //���� ������
//};
//
//
////��������� �������
//void func1(void);
//void func2(void)
//{
//    // do {
//    // analogButtons.checkButtons();
//    // lcd.clear(); //�������� LCD
//    // lcd.print("Hello World!"); //����� ������ �� LCD
//    // delay(1000); //�������� ��� ��������
//    // } while ( != 5); //��� ������ - ESC
//}
//
//
////������ �������� ������ �������� ���� (��������� SELECTION)
//static SELECTION menu_[] = {
//{ goto_menu, SETDATATIME_MENU, MAIN_MENU}, //Punkt 1
//{ goto_menu, SETTEMPER_MENU, MAIN_MENU}, //Punkt 2
//{ goto_menu, SETHUM_MENU, MAIN_MENU}, //Punkt 3
//{ goto_menu, REALTIME_MENU, MAIN_MENU}, //Punkt 4
//};
//
////������� ������ ������ � ���� ��� ����/�������
////��� ����/������� ������ ����������� � ����� �� ������� ��� � � enum __menu__id ...
//static MENU menu[] = {
//{MAIN_MENU, 5, menu_}, //���� 1
//{SETDATATIME_MENU, 1, menu_m0}, //���� 2 
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
//    //��� ��������� "�" was not declare in this score
//    //���� ������ ����� �������
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