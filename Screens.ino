void screenTime(int x) {
	time.blinktime(x);                            // мигаем устанавливаемым параметром (если menu_item_ больше 0)
	lcd.print(time.gettime("H:i d-m-Y"));
}

void screenReadSET() {
	lcd.setCursor(0, 1);
	lcd.print((String)"t" + temperature_ + "C  H" + humid_ + "%"); // выводим заданную температуру и влажность на дисплей
}

void sreenRealTempHum() {
	lcd.setCursor(0, 0);
	lcd.print((String)"t" + sensor.tem + "C  H" + sensor.hum + "%"); // выводим текущую температуру и влажность на дисплей
}

void screenTempSET() {
	lcd.setCursor(0, 1);
	lcd.print((String)"SET  t" + temperature_ + "C    "); // выводим заданную температуру на дисплей
}

void screenHumSET() {
	lcd.setCursor(0, 1);
	lcd.print((String)"SET  H" + humid_ + "%    "); // выводим заданную влажность на дисплей
}
