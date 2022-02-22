 /*
 created 2016
 by Mohamad Farhanuddin Firaq
 */

#include <Keypad.h>
#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"
String str1,str2;
TMRpcm tmrpcm;
const byte ROWS = 3;
const byte COLS = 2;
const byte R=1;
const byte C=1;
const byte r=1;
const byte c=1;
int i=0;
int v=0;
char customKey=0;
char rustomKey=0;
char bustomKey=0;
char volumeKey=0;
char Key=0;
char braille[10];
char selection[10]; 
char hexaKeys[ROWS][COLS] = {
{'1','4'},
{'2','5'},
{'3','6'},
};
char bexaKeys[ROWS][COLS] = {
{'a','d'},
{'b','e'},
{'c','f'},
};
char sexaKeys[ROWS][COLS] = {
{'g','j'},
{'h','k'},
{'i','l'},
};
char upload[R][C]={
  {'X'}
};
char volumekey[r][c]={
  {'Y'}
};
byte rows[R]={5};
byte cols[C]={2};
byte vr[r]={10};
byte vc[c]={3};
byte rowPins[ROWS] = {6,7,8}; 
byte colPins[COLS] = {2,3}; 
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
Keypad rustomKeypad = Keypad( makeKeymap(bexaKeys), rowPins, colPins, ROWS, COLS);
Keypad bustomKeypad = Keypad( makeKeymap(sexaKeys), rowPins, colPins, ROWS, COLS);
Keypad uploadKey=Keypad( makeKeymap(upload),rows,cols,R,C);
Keypad volumeKeypad=Keypad( makeKeymap(volumekey),vr,vc,r,c);
void setup(){
  Serial.begin(9600);
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
}
else Serial.println("success");
}
void loop(){
tmrpcm.speakerPin = 9;
customKey = customKeypad.getKey();
char uploadkey=uploadKey.getKey();
if(customKey){
selection[i++]=customKey;
str1= String (selection);
Serial.println(selection);
}

if(str1=="1")
  { Serial.println("1 selected");
    
    while(1==1)
  {
  char uploadkey=uploadKey.getKey();
  rustomKey = rustomKeypad.getKey();
   if(rustomKey)
    {    
         braille[i++]=rustomKey;
         Serial.println(braille);
    } 
 if (uploadkey)
  { 
 setvolume();
tmrpcm.play(braille);
  braille[0]=(char)0;
  braille[1]=(char)0;
  braille[2]=(char)0;
  braille[3]=(char)0;
  braille[4]=(char)0;
  braille[5]=(char)0;
  braille[6]=(char)0;
   i=0;
}
  }
}
if(str1=="2")
  { Serial.println("1 selected");
    while(1==1)
  {
  char uploadkey=uploadKey.getKey();
  customKey = customKeypad.getKey();
   if(customKey)
    {    
         braille[i++]=customKey;
         Serial.println(braille);
    } 
 if (uploadkey)
  { 
setvolume();
tmrpcm.play(braille);
  braille[0]=(char)0;
  braille[1]=(char)0;
  braille[2]=(char)0;
  braille[3]=(char)0;
  braille[4]=(char)0;
  braille[5]=(char)0;
  braille[6]=(char)0;
   i=0;
}
  }
}
if(str1=="3")
  { Serial.println("1 selected");
    while(1==1)
  {
  char uploadkey=uploadKey.getKey();
  bustomKey = bustomKeypad.getKey();
   if(bustomKey)
    {    
         braille[i++]=bustomKey;
         Serial.println(braille);
    } 
 if (uploadkey)
  { 
setvolume();
tmrpcm.play(braille);
  braille[0]=(char)0;
  braille[1]=(char)0;
  braille[2]=(char)0;
  braille[3]=(char)0;
  braille[4]=(char)0;
  braille[5]=(char)0;
  braille[6]=(char)0;
   i=0;
}
  }
}
}


void setvolume() {
  if (strlen(braille)<=0)
  {
    tmrpcm.setVolume(-5);
  }
  else {
    tmrpcm.setVolume(3);
    Serial.println("playing");
  }
  }


