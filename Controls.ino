void controls() {								//��������� ���������� �������������� ������������
	if (start_) {
		if (sensor.hum < abs(humid_)) {			//��������� ���������
			digitalWrite(12, LOW);				//���������
			lcd.setCursor(8, 0);
			lcd.print("^");						// ������� ��������� �� �������

		}
		else {
			digitalWrite(12, HIGH);
			lcd.setCursor(8, 0);
			lcd.print("v");						// ������� ��������� �� �������

		}
		if (sensor.tem < temperature_) {		//��������� �����������
			digitalWrite(2, LOW);				// �����������
			lcd.setCursor(7, 0);
			lcd.print("^");						// ������� ��������� �� �������

		}
		else {
			digitalWrite(2, HIGH);						// ���������
			lcd.setCursor(7, 0);
			lcd.print("v");								// ������� ��������� �� �������
		}

	}
	else {
		digitalWrite(2, HIGH);
		digitalWrite(3, HIGH);
		digitalWrite(12, HIGH);
		digitalWrite(13, HIGH);
	}
}
