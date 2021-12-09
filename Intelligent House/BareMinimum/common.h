/*
 * common.h
 *
 * Created: 08/12/2021 12.25.06
 *  Author: jan
 */ 


#ifndef COMMON_H_
#define COMMON_H_

#include <Arduino.h>			// Core 
#include <LiquidCrystal.h>		// LCD Display
#include <Adafruit_SSD1306.h>	// OLED Display
#include <Keypad.h>				// 4x4 keypad
#include <Servo.h>				// Servo
#include <SPI.h>				// SPI comms
#include <Wire.h>				// I2C comms
#include <MFRC522.h>			// RFID reader
#include <DS3231.h>				// RTC
//#include "lcd_icon.h"			// Custom LCD icons
#include "alarm/alarm.h"		// Alarm functions
#include "climate/climate.h"	// Climate functions

// Misc defines
#define LED_RED 3
#define LED_GREEN 4
#define LED_BLUE 5
#define SERVO_WINDOW 11
#define SERVO_GARAGE 12
#define WINDOW 0
#define GARAGE 1
// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4
// RFID
#define RST_PIN 13
#define SS_PIN 53
// KEYPAD
#define ROWS 4												// Number of rows in keypad
#define COLS 4

// Initial functions
void Init_Displays();
void Init_Servo();
void Init_Sensors();
void Init_Comms();

// On-demand functions
void PrintLCD(int place, int line, String text);			// Prints a text on the LCD from the given placement
void WriteLCD(int place, int line, byte icon);				// Prints an icon on the LCD at the given placement
void RunServo(int servo, int angle);						// Runs servo on the given angle
String AdjustZero(int val);									// Ads leading zero on less than 10 numbers
String GetTime();											// Gets time from RTC and parses it as HH:MM:SS
String GetDate();											// Gets date from RTC and parses it as DD/MM/YYYY
String GetTimestamp();										// Returns a string with YY/MM/DD HH:MM:SS
void PrintOLED(int x, int y, String text, int textSize = 1);// Prints text on the OLED at pixel placement (!!)
void SerialLog(String logEvent, String device,
						bool error = false);				// Writes important events through the serial port (115200 baud)
bool Hysterese(float val, float high, float low = 0);		// Returns true if value is good

// Loop functions
void Entry(int interval);									// Checks the entry point if alarm is active
void KeyIn();												// Controls the keypad input device
void UpdateOLED(int interval);								// Loops around and clears the OLED and updates timestamp

// Nested functions
String Sensor_Card();										// Checks for valid RFID card
void EnterPassword(char key);								// Enables possibility to enter password
bool CheckPassword();										// Checks the entered password
void Unlock();												// Disables alarm, unlocks etc.

#endif /* COMMON_H_ */