/* Car parking sensor*/
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define echoPin 3 // Echo Pin
#define trigPin 2 // Trigger Pin
#define LEDPin 13 // LED
Adafruit_SSD1306 display(128, 64, &Wire, -1); //display

const int buzzer = 9;
int maximumRange = 50;
int beware = 20;
long duration
long distance;

void setup() {
    Serial.begin (9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(LEDPin, OUTPUT);
  //Sound
    pinMode(buzzer, OUTPUT);
  //display
    display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
    display.setTextColor(SSD1306_WHITE);
    }

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration / 58.2;

  // START BEWARE
    if (distance <= beware) {
    //0-30
    digitalWrite(LEDPin, HIGH);
    //Sound
    tone(buzzer, 1000); 
    delay(500);        
    noTone(buzzer);     
    delay(500);        // ...for 1sec
      //display
        display.clearDisplay();
        display.setCursor(43, 25);
        display.print("BEWARE");
        display.display();
    }

  //BEWARE
    else if (beware < distance && distance <= 30) {
    digitalWrite(LEDPin, HIGH);
    //Sound
    tone(buzzer, 1000); 
    delay(900);        
    noTone(buzzer);     
    delay(900);
      //display
        display.clearDisplay();
        display.setCursor(44, 25);
        display.print("DANGER");
        display.display();
    }

  //DANGER
    else if (30 < distance && distance <= 40) {
    digitalWrite(LEDPin, HIGH);
    //Sound
    tone(buzzer, 1000); 
    delay(800);        
    noTone(buzzer);     
    delay(800);
      //display
        display.clearDisplay();
        display.setCursor(44, 25);
        display.print("DANGER");
        display.display();
    }
    
  //DANGER
    else if (40 < distance && distance <= maximumRange) {
    digitalWrite(LEDPin, HIGH);
    //Sound
    tone(buzzer, 1000); 
    delay(1200);        
    noTone(buzzer);     
    delay(1200);
      //display
        display.clearDisplay();
        display.setCursor(44, 25);
        display.print("DANGER");
        display.display();
    }

  //SAFE
    else {
    Serial.println(distance);
    digitalWrite(LEDPin, LOW);
      //display
        display.clearDisplay();
        display.setCursor(45, 25);
        display.print("SAFE");
        display.display();
    }
    delay(100);
}
