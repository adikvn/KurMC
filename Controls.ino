void controls() {								//Процедура Управление иполнительными устройствами
	if (start_) {
		if (sensor.hum < abs(humid_)) {			//Проверяем влажность
			digitalWrite(12, LOW);				//Увлажняем
			lcd.setCursor(8, 0);
			lcd.print("^");						// выводим индикацию на дисплей

		}
		else {
			digitalWrite(12, HIGH);
			lcd.setCursor(8, 0);
			lcd.print("v");						// выводим индикацию на дисплей

		}
		if (sensor.tem < temperature_) {		//Проверяем температуру
			digitalWrite(2, LOW);				// Подогреваем
			lcd.setCursor(7, 0);
			lcd.print("^");						// выводим индикацию на дисплей

		}
		else {
			digitalWrite(2, HIGH);						// Охлаждаем
			lcd.setCursor(7, 0);
			lcd.print("v");								// выводим индикацию на дисплей
		}

	}
	else {
		digitalWrite(2, HIGH);
		digitalWrite(3, HIGH);
		digitalWrite(12, HIGH);
		digitalWrite(13, HIGH);
	}
}
