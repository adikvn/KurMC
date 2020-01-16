void screenTime(int x) {
	time.blinktime(x);                            // ������ ��������������� ���������� (���� menu_item_ ������ 0)
	lcd.print(time.gettime("H:i d-m-Y"));
}

void screenReadSET() {
	lcd.setCursor(0, 1);
	lcd.print((String)"t" + temperature_ + "C  H" + humid_ + "%"); // ������� �������� ����������� � ��������� �� �������
}

void sreenRealTempHum() {
	lcd.setCursor(0, 0);
	lcd.print((String)"t" + sensor.tem + "C  H" + sensor.hum + "%"); // ������� ������� ����������� � ��������� �� �������
}

void screenTempSET() {
	lcd.setCursor(0, 1);
	lcd.print((String)"SET  t" + temperature_ + "C    "); // ������� �������� ����������� �� �������
}

void screenHumSET() {
	lcd.setCursor(0, 1);
	lcd.print((String)"SET  H" + humid_ + "%    "); // ������� �������� ��������� �� �������
}
