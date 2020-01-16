void key_event(int key_num) {
	switch (key_num)
	{
	case 1: key_right(); break;
	case 2: key_up(); break;
	case 3: key_down(); break;
	case 4: key_left(); break;
	case 5: key_select(); break;
	default:
		break;
	}
	
}
void key_left() {                               //Процедура Реакция на клавишу в лево
	//--menu_item_ == 0 ? menu_item_ = 4 : menu_item_;
	switch (menu_item_) {
	case 1:
		if (settem) {								//Записиваем новое значение температуры
			//eeprom_write_float(0, temperature_);
		}
		if (sethum) {							//Записиваем новое значение влажности
			//eeprom_write_float(0, humid_);
		}
		break;
	case 2:
		menu_item1_ -= 1;                       //перебор меню
		if (menu_item1_ == 1) {
			menu_item1_ = 6;
		}
		break;
	}
}

void key_right() {                              //Процедура Реакция на клавишу в право
	switch (menu_item_) {
	case 1:
		if (settem == false && sethum == false) {
			settem = !settem;
		}
		if (settem == true && sethum == false) {
			settem = !settem;
			sethum = !sethum;
		}
		if (settem == false && sethum == true) {
			sethum = !sethum;
		}
		break;
	case 2:
		menu_item1_ += 1;                       //перебор меню
		if (menu_item1_ == 7) {
			menu_item1_ = 2;
		}
		break;
	}
}

void key_up() {                               //Процедура Реакция на клавишу в вверх
	switch (menu_item_) {
	case 1:
		if (settem) {

		}
		break;
	case 2:
		SetDateTimeUp(menu_item1_);
		break;
	}
}

void key_down() {                             //Процедура Реакция на клавишу в вниз
	switch (menu_item_) {
		//case 1:          break;
	case 2:
		SetDateTimeDown(menu_item1_);
		break;
	}
}

void key_select() {                           //Процедура Реакция на клавишу выбор
	++menu_item_ == 6 ? menu_item_ = 1 : menu_item_;
}

int key_press() {                            //Процедура ПРоверка нажатой клавиши
	int x = 0;
	int key = 0;
	x = analogRead(0);
	//lcd.setCursor(0, 0);
	//lcd.print(x);
	
	if ((x < 60) & (!key_press_)) {
		//key_right();                              //Нажата клавиша в право
		key = 1;
		key_press_ = true;                        //клавиша была нажата-предотвращение поторной обработки
		return key;
	}
	else if ((x < 200) & (!key_press_)) {
		//key_up();                                 //Нажата клавиша в верх
		key = 2;
		key_press_ = true;                        //клавиша была нажата-предотвращение поторной обработки
		return key;
	}
	else if ((x < 400) & (!key_press_)) {
		//key_down();                               //Нажата клавиша в низ
		key = 3;
		key_press_ = true;                        //клавиша была нажата-предотвращение поторной обработки
		return key;
	}
	else if ((x < 600) & (!key_press_)) {
		//key_left();                               //Нажата клавиша в лево
		key = 4;
		key_press_ = true;                        //клавиша была нажата-предотвращение поторной обработки
		return key;
	}
	else if ((x < 800) & (!key_press_)) {			//Нажата клавиша в select
		key = 5;
		key_press_ = true;                        //клавиша была нажата-предотвращение повторной обработки
		return key;
	}
	else if (x >= 800)  key_press_ = false; return key;       //Нет нажатых клавиш
	
}

int SetDateTimeUp(int menu_item1) {
	switch (menu_item1) {
	/* мин */ case 2: time.settime(-1, (time.minutes == 59 ? 0 : time.minutes + 1), -1, -1, -1, -1, -1); break;
	/* час */ case 3: time.settime(-1, -1, (time.Hours == 23 ? 0 : time.Hours + 1), -1, -1, -1, -1); break;
	/* дни */ case 4: time.settime(-1, -1, -1, (time.day == 31 ? 1 : time.day + 1), -1, -1, -1); break;
	/* мес */ case 5: time.settime(-1, -1, -1, -1, (time.month == 12 ? 1 : time.month + 1), -1, -1); break;
	/* год */ case 6: time.settime(-1, -1, -1, -1, -1, (time.year == 99 ? 0 : time.year + 1), -1); break;
	}
}
int SetDateTimeDown(int menu_item1) {
	switch (menu_item1) {
	/* мин */ case 2: time.settime(-1, (time.minutes == 0 ? 59 : time.minutes - 1), -1, -1, -1, -1, -1); break;
	/* час */ case 3: time.settime(-1, -1, (time.Hours == 0 ? 23 : time.Hours - 1), -1, -1, -1, -1); break;
	/* дни */ case 4: time.settime(-1, -1, -1, (time.day == 1 ? 31 : time.day - 1), -1, -1, -1); break;
	/* мес */ case 5: time.settime(-1, -1, -1, -1, (time.month == 1 ? 12 : time.month - 1), -1, -1); break;
	/* год */ case 6: time.settime(-1, -1, -1, -1, -1, (time.year == 0 ? 99 : time.year - 1), -1); break;
	}
}