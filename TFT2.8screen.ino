
#include <Adafruit_GFX.h>   //core library for graphix
#include <MCUFRIEND_kbv.h> // library for the Opensmart TFT screen
MCUFRIEND_kbv tft;       
#if defined(__SAM3X8E__)
#undef __FlashStringHelper::F(string_literal)
#define F(string_literal) string_literal
#endif


uint16_t identifier; //will be used for reading the ID of tft
#define BLACK   0x0000 // colors declaration which are defined in the library
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF


void setup() {
  // put your setup code here, to run once:
  tft.begin(9600); // this will start the tft lcd a command 
  tft.reset(); // resets the LCD
  identifier = tft.readID(); // here is where we used the declared identifier above.
  tft.begin(identifier); //ok we start the tft screen again
   tft.setRotation(1); // here I set the rotation to landscape, you can used 0 = portrait, 1 = landscape
   tft.fillScreen(BLACK); // this will fill your screen with color red
   tft.setCursor(60, 90); // this command wil set the coordinate of the text in your tft screen , I am using 320x240 screen. 
  
 

 
}

void loop() { // to enable color changing text I add command lines in the function void loop to loop the process as stated below this line
  // put your main code here, to run repeatedly:
  tft.setCursor(20, 20);      
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("CO2 : ");
  tft.setCursor(20, 60);   
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print("SOONGOO : ");
  delay(800);
}
