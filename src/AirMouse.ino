#include <Wire.h>
#include <MPU6050_tockn.h>
MPU6050 mpu6050(Wire);

// Button pins
const int leftButtonPin = 20;
const int rightButtonPin = 21;
const int scrollUpButtonPin = 22;
const int scrollDownButtonPin = 26;
unsigned long lastLeftClickTime = 0;

// WiFi (ESP-01 AT commands)
String ssid = "YOUR_WIFI_NAME";
String password = "YOUR_WIFI_PASSWORD";
void setup() {
 Serial.begin(115200);    // Debug
 Serial1.begin(9600);    // HC-05
 Serial2.begin(115200); // ESP-01
  
 Wire.begin();

 pinMode(leftButtonPin, INPUT_PULLUP);
 pinMode(rightButtonPin, INPUT_PULLUP);
 pinMode(scrollUpButtonPin, INPUT_PULLUP);
 pinMode(scrollDownButtonPin, INPUT_PULLUP);

 mpu6050.begin();
 mpu6050.calcGyroOffsets(true);
 Serial.println("Air Mouse Ready...");

 // ESP8266 Setup
 sendESP("AT");
 sendESP("AT+CWMODE=1"); // Station mode
 String cmd = "AT+CWJAP=\"" + ssid + "\",\"" + password + "\"";
 sendESP(cmd);
 Serial.println("ESP Connected to WiFi");
}

void loop() {
 mpu6050.update();
  
 float angleX = mpu6050.getAngleX();
 float angleY = mpu6050.getAngleY();
  
 int mouseX = map(angleY, -90, 90, -20, 20);
 int mouseY = map(angleX, 90, -90, 20, -20);
 int leftClick = 0;
 int rightClick = 0;
 int scrollUp = 0;
 int scrollDown = 0;

 if (digitalRead(leftButtonPin) == LOW && (millis() - lastLeftClickTime > 100)) {
  leftClick = 1;
  lastLeftClickTime = millis();
 }

 if (digitalRead(rightButtonPin) == LOW) rightClick = 1;

 if (digitalRead(scrollUpButtonPin) == LOW) scrollUp = 1;

 if (digitalRead(scrollDownButtonPin) == LOW) scrollDown = 1;

 // Create data string
 String data = String(mouseX) + "," + String(mouseY) + "," +
              String(leftClick) + "," + String(rightClick) + "," +
              String(scrollUp) + "," + String(scrollDown);

 //   🔵 Send via HC-05 (Bluetooth)
 Serial1.println(data);

 //   🌐 Send via ESP-01 (WiFi)
 sendToWiFi(data);

 // Debug
 Serial.println("TX: " + data);
 delay(20);
}

// Function to send AT commands
void sendESP(String cmd) {
 Serial2.println(cmd);
 delay(2000);

 while (Serial2.available()) {
  Serial.write(Serial2.read());
 }
}

// Send data over WiFi (TCP example)

void sendToWiFi(String data) {
 String cmd = "AT+CIPSTART=\"TCP\",\"192.168.1.100\",5000";
 sendESP(cmd);
 cmd = "AT+CIPSEND=" + String(data.length());
 sendESP(cmd);
 Serial2.print(data);
 delay(1000);
 sendESP("AT+CIPCLOSE");

}
