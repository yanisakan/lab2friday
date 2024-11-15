#include <Arduino.h>

int buttonPin = 2;    // ปุ่มเชื่อมต่อกับขา 2
int ledPin = 13;      // LED เชื่อมต่อกับขา 13
int buttonState = 0;  // สถานะของปุ่มเริ่มต้นที่ 0

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);  // ตั้งค่าขาเป็นอินพุต พร้อมตัวต้านทาน pull-up
    pinMode(ledPin, OUTPUT);           // ตั้งค่าขา LED เป็นเอาต์พุต
    Serial.begin(9600);                // เริ่มต้นการสื่อสารผ่าน Serial Monitor ที่ความเร็ว 9600 บอด
}

void loop() {
    buttonState = digitalRead(buttonPin);  // อ่านค่าสถานะของปุ่ม

    if (buttonState == LOW) {  // ถ้าปุ่มถูกกด (LOW เนื่องจากมี pull-up)
        digitalWrite(ledPin, HIGH);  // เปิดไฟ LED
        Serial.println("Button pressed, LED ON");  // แสดงข้อความเมื่อปุ่มถูกกด
    } else {
        digitalWrite(ledPin, LOW);   // ปิดไฟ LED
        Serial.println("Button not pressed, LED OFF");  // แสดงข้อความเมื่อปุ่มไม่ถูกกด
    }

    delay(100);  // หน่วงเวลาเล็กน้อยเพื่อป้องกันการกระพริบของสัญญาณ (debounce)
}
