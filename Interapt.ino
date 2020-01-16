void timer_event() {                            //Процедура Обработка прерывания таймера
	key_event(key_press());		//Ожидаем нажатия клавиш
	if (++s2 == 6)
	{
		result = sensor.read(A1);                   // нужно указать № вывода (сейчас A1 pin)
		if (result == DHT_OK)
		{
			sreenRealTempHum();						// выводим текущую температуру и влажность на дисплей
			
			if (start_) controls();                // Проверка на запуск управления
		}
		else
		{
			Serial.println((String)"<E01>" + result); //отправляем в ПК если ошибка DHT
		}
		s2 = 0;
	}
	
	lcd.setCursor(0, 1);									// устанавливаем курсор в 2-ом
	switch (menu_item_) {									//выбор индикации
	case 1:      screenTime(0);              break;         //Вывод реального времени на дисплей
	case 2:      screenTime(menu_item1_);    break;         //Вывод установки времени и даты на дисплей
	case 3:      screenReadSET();    break;					//Вывод заданных параметров температуры и влажности на дисплей
	case 4:		screenTempSET();	break;
	case 5:		screenHumSET();		break;
	}
}
