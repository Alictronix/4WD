#include "U8glib.h"

U8GLIB_SH1106_128X64 u8g(13, 11, 10, 9, 8);  // (CLK)D0=13, (MOSI)D1=11, CS=10, DC=9, Reset=8
char iB;
void draw(void) {
u8g.setFont(u8g_font_unifont);  // select font
u8g.drawStr(0, 30, "DIR:");  // put string of display at position X, Y
u8g.drawStr(0, 50, "SPD:");
u8g.setPrintPos(50, 30);  // set position
u8g.print(iB,0);
u8g.drawStr(100, 30, "<>");
u8g.setPrintPos(50, 50);
u8g.drawStr(100, 50, "m/s");
}
void setup(void) {
  Serial.begin(9600);
  
}
void loop(void) {
u8g.firstPage();  
if (Serial.available() > 0) {  // if the data came
    iB = Serial.read();
}// read byte
do {
draw();
} while( u8g.nextPage() );
delay(1000);  
}
