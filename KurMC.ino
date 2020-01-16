
//  Количество опрашиваемых сенсоров ограничено количеством свободных выводов и самих сенсоров.
//  Библиотека DHT.h сама определяет тип сенсора (DHT11, DHT21, DHT22)


#include <EEPROM.h>
#include <Wire.h>
#include <MsTimer2.h>
#include <RTC.h>
#include <LiquidCrystal.h>
#include <iarduino_RTC.h>
#include <DHT.h>
#include "SetKurMC.h"





void setup() {

	temperature_ = EEPROM_float_read(0);
	humid_ = EEPROM_float_read(4);
	lcd.begin(16, 2);                           // задаем размерность дисплея
	//Serial.begin(9600);
	pinMode(temper_out, OUTPUT);                //Нагрев
	pinMode(ventel_out, OUTPUT);                //вентиляция
	pinMode(humid_out, OUTPUT);                 //увлажнение
	pinMode(13, OUTPUT);                        //Поворот
	pinMode(key_kontrol_out, OUTPUT);

	digitalWrite(temper_out, HIGH);
	digitalWrite(ventel_out, HIGH);
	digitalWrite(humid_out, HIGH);
	digitalWrite(13, HIGH);
	digitalWrite(key_kontrol_out, HIGH);
	time.begin();                               // на базе чипа DS3231 модуль подключается к аппаратным выводам I2C
	lcd.clear();                                //очистка экрана
	MsTimer2::set(500, timer_event);           // 1000ms период таймера
	MsTimer2::start();
}
void loop() {
	
	
}
