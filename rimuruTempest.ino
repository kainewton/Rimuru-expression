#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
}

void loop() {
  blink(); //ngedip
  delay(300);  
  flat(); //datar
  delay(1500);
  blink();
  delay(150);
  angry(); //marah
  delay(1500);
  blink();
  delay(150);
  sad(); //sedih
  delay(1500);
  blink();
  delay(150);
  happy(); //seneng
  delay(1500);
}

void blink() {
  display.clearDisplay();
  // left eye closed
  display.fillRoundRect(20, 38, 40, 4, 2, SSD1306_WHITE); 
  // right eye closed
  display.fillRoundRect(70, 38, 40, 4, 2, SSD1306_WHITE); 
  display.display();
}

void flat() {
  display.clearDisplay();
  // left eye
  display.fillRoundRect(20, 20, 40, 40, 8, SSD1306_WHITE); 
  // right eye
  display.fillRoundRect(70, 20, 40, 40, 8, SSD1306_WHITE); 
  display.display();
}

void angry() {
  display.clearDisplay();
  display.fillRoundRect(20, 20, 40, 40, 8, SSD1306_WHITE); 
  display.fillRoundRect(70, 20, 40, 40, 8, SSD1306_WHITE); 
  display.fillTriangle(20, 20, 60, 20, 60, 40, SSD1306_BLACK); 
  display.fillTriangle(70, 20, 70, 40, 110, 20, SSD1306_BLACK); 
  display.display();
}

void sad() {
  display.clearDisplay();
  display.fillRoundRect(20, 20, 40, 40, 8, SSD1306_WHITE); 
  display.fillRoundRect(70, 20, 40, 40, 8, SSD1306_WHITE); 
  display.fillTriangle(60, 20, 20, 20, 20, 40, SSD1306_BLACK); 
  display.fillTriangle(70, 20, 110, 40, 110, 20, SSD1306_BLACK); 
  display.display();
}

void happy() {
  display.clearDisplay();
  display.fillRoundRect(20, 20, 40, 40, 8, SSD1306_WHITE); 
  display.fillRoundRect(70, 20, 40, 40, 8, SSD1306_WHITE); 
  display.fillTriangle(60, 60, 20, 60, 20, 40, SSD1306_BLACK); 
  display.fillTriangle(70, 60, 110, 60, 110, 40, SSD1306_BLACK); 
  display.display();
}

// VCC -5v
// GND -GND
// SCL -A5
// SDA -A4
