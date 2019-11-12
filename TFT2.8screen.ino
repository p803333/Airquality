
#include <Adafruit_GFX.h>   //core library for graphix
#include <MCUFRIEND_kbv.h> // library for the Opensmart TFT screen
MCUFRIEND_kbv tft;       
#if defined(__SAM3X8E__)
#undef __FlashStringHelper::F(string_literal)
#define F(string_literal) string_literal
#endif


uint16_t identifier; // 색 상수 선언
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF


void setup() {
  // put your setup code here, to run once:
  tft.begin(9600); // 디스플레이 9600 통신속도
  tft.reset(); // LCD 화면 리셋
  identifier = tft.readID(); // here is where we used the declared identifier above.
  tft.begin(identifier); //ok we start the tft screen again
   tft.setRotation(1); // 화면 가로모드 세로모드 설정
   tft.fillScreen(BLACK); // 화면 배경 색
   tft.setCursor(60, 90); // 화면에글자지정, I am using 320x240 screen. 
  
 

 
}

void loop() { // to enable color changing text I add command lines in the function void loop to loop the process as stated below this line
  // put your main code here, to run repeatedly:
  tft.setCursor(20, 20);      // X:20 Y:20에
  tft.setTextColor(WHITE);    // 글자색 하얀색
  tft.setTextSize(3);         // 글자 크기 3
  tft.print("CO2 : ");        // "CO2 : " 화면에 출력
  tft.setCursor(20, 60);      // X:20 Y:60에
  tft.setTextColor(WHITE);    // 글자색 하얀색
  tft.setTextSize(3);         // 글자 크기 3
  tft.print("SOONGOO : ");    // 출력 테스트를 위하여 "SOONGOO : " 출력
  delay(1000);                // 1초 대기
}
