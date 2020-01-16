void timer_event() {                            //��������� ��������� ���������� �������
	key_event(key_press());		//������� ������� ������
	if (++s2 == 6)
	{
		result = sensor.read(A1);                   // ����� ������� � ������ (������ A1 pin)
		if (result == DHT_OK)
		{
			sreenRealTempHum();						// ������� ������� ����������� � ��������� �� �������
			
			if (start_) controls();                // �������� �� ������ ����������
		}
		else
		{
			Serial.println((String)"<E01>" + result); //���������� � �� ���� ������ DHT
		}
		s2 = 0;
	}
	
	lcd.setCursor(0, 1);									// ������������� ������ � 2-��
	switch (menu_item_) {									//����� ���������
	case 1:      screenTime(0);              break;         //����� ��������� ������� �� �������
	case 2:      screenTime(menu_item1_);    break;         //����� ��������� ������� � ���� �� �������
	case 3:      screenReadSET();    break;					//����� �������� ���������� ����������� � ��������� �� �������
	case 4:		screenTempSET();	break;
	case 5:		screenHumSET();		break;
	}
}
