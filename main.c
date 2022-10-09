/*
 * LCD_Example.c
 *
 * Created: 20.09.2022 19:57:20
 * Author : erenz
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#define LCD_Port PORTD // LCD portunu tanýmla (PORTD).
#define LCD_DataPin DDRD // 4-bit pinleri tanýmla (PORTD4-PORTD7).
#define RS PD0 // RS pinini tanýmla.
#define EN PD1 // E pinini tanýmla

void LCD_Komut( unsigned char komut ) // LCD çalýþma kodlarý
{
	LCD_Port = (LCD_Port & 0x0F) | (komut & 0xF0); //Veri portuna komut gönderildi.
	LCD_Port &= ~(1 << RS); //RS=0, gönderilecek bilginin komut olduðu bildirildi.
	LCD_Port |= (1 << EN); //E=1
	_delay_us(1);
	LCD_Port &= ~ (1 << EN); //E=0
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (komut << 4);
	LCD_Port |= (1 << EN);
	_delay_us(1);
	LCD_Port &= ~(1 << EN);
	_delay_ms(2);
}

void LCD_Baslat (void)
{
	LCD_DataPin = 0xFF; // LCD pinlerini kontrol et (PORTD4-PORTD7)
	_delay_ms(15); // LCD etkinleþtirilinceye kadar bekle
	LCD_Komut(0x02); // 4-bit kontrol
	LCD_Komut(0x28); // Kontrol matris ayarý
	LCD_Komut(0x0c); // Ýmleç devre dýþý
	LCD_Komut(0x06); // Ýmleci taþý
	LCD_Komut(0x01); // LCD’yi temizle
	_delay_ms(2); // 2 ms bekle
}

void LCD_Yaz (char *str) // Karakter dizisini LCD’ye yaz
{
	int i;
	for(i=0; str[i]!=0; i++)
	{
		LCD_Port = (LCD_Port & 0x0F) | (str[i] & 0xF0);
		LCD_Port |= (1 << RS);
		LCD_Port|= (1 << EN);
		_delay_us(1);
		LCD_Port &= ~ (1 << EN);
		_delay_us(200);
		LCD_Port = (LCD_Port & 0x0F) | (str[i] << 4);
		LCD_Port |= (1 << EN);
		_delay_us(1);
		LCD_Port &= ~(1 << EN);
		_delay_ms(2);
	}
}

void LCD_Temizle() // LCD temizleme.
{
	LCD_Komut (0x01); // LCD’yi temizle.
	_delay_ms(2); // LCD temizlenene kadar bekle.
	LCD_Komut (0x80); // Ýmleci 1. satýr, 1. sütun pozisyonuna getir.
}


int main(void)
{
	 DDRB = 0x01;
	//int durum;
		LCD_Baslat(); // LCD’yi baþlat.
		LCD_Yaz("Sisteme Hosgeldiniz"); // LCD’ye “LCD EKRAN” yaz.
		LCD_Komut(0xC0); // 2. satýr, 1. sütuna imleci konumlandýr.
		LCD_Yaz("UYGULAMASI"); // LED’ye “UYGULAMASI” yaz.
	while (1)
	{
		PORTB = 0b00000001;
			_delay_ms(100); // Gecikme 10 000 milisaniyedir (10 saniye).
		PORTB = 0b00000000;
			_delay_ms(100); // Gecikme 10 000 milisaniyedir (10 saniye).

	}
	
	/*
	switch(){
	case 1:
	
	break;
	case 2:
	
	break;
	case 3:
	
	break;
	case 4:
	
	break;
	}
	*/
		return 0;
}

