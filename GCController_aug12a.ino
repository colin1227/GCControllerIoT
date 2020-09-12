#include "arduino_secrets.h"

/* 
CloudSwitch back;
CloudSwitch debug;
CloudSwitch down1;
CloudSwitch down3;
CloudSwitch ff30;
CloudSwitch left1;
CloudSwitch left2;
CloudSwitch left5;
CloudSwitch pause;
CloudSwitch rewind30;
CloudSwitch right1;
CloudSwitch right2;
CloudSwitch right5;
CloudSwitch up1;
CloudSwitch up3;

  Properties which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/
#include <Arduino.h>
#include "wiring_private.h"
#include "thingProperties.h"
#include <IRremote.h>

IRsend irsend;
const int lightpin = 2;
const int otherLightPin = 13;
Uart mySerial (&sercom0, 5, 6, SERCOM_RX_PAD_1, UART_TX_PAD_0);

void SERCOM0_Handler()
{
    mySerial.IrqHandler();
}

void setup() {
  Serial.begin(9600);
  pinMode(lightpin, OUTPUT);
  pinMode(otherLightPin, OUTPUT);

  delay(1500);
  
  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  delay(1500); 
  pinPeripheral(5, PIO_SERCOM_ALT);
  pinPeripheral(6, PIO_SERCOM_ALT);

  mySerial.begin(9600);

  setDebugMessageLevel(4);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  if (pause) {
    pause = false;
    digitalWrite(2, HIGH);
    onPauseChange();
    delay(500);
    Serial.println("pause");
    
  } else if (rewind30) {
    rewind30 = false;
    digitalWrite(2, HIGH);
    onRewind30Change();
    delay(500);
    Serial.println("r30");
    
  } else if (back) {
    back = false;
    digitalWrite(2, HIGH);
    onBackChange();
    delay(500);
    Serial.println("Back");
    
  } else if (debug) {
    debug = false;
    digitalWrite(2, HIGH);
    onDebugChange();
    delay(500);
    Serial.println("debug");
    
  } else if (ff30) {
    ff30 = false;
    digitalWrite(2, HIGH);
    onFf30Change();
    delay(500);
    Serial.println("ff30");
    
  } else if (back) {
    back = false;
    digitalWrite(2, HIGH);
    onBackChange();
    delay(500);
    Serial.println("Back");
    
  } else if (left1) {
    left1 = false;
    digitalWrite(2, HIGH);
    onLeft1Change();
    delay(500);
    Serial.println("left1");
    
  } else if (left2) {
    left2 = false;
    digitalWrite(2, HIGH);
    onLeft2Change();
    delay(500);
    Serial.println("left2");
    
  } else if (left5) {
    left5 = false;
    digitalWrite(2, HIGH);
    onLeft5Change();
    delay(500);
    Serial.println("left5");
    
  } else if (right1) {
    right1 = false;
    digitalWrite(2, HIGH);
    onRight1Change();
    delay(500);
    Serial.println("right1");
    
  } else if (right2) {
    right2 = false;
    digitalWrite(2, HIGH);
    onRight2Change();
    delay(500);
    Serial.println("right2");
    
  } else if (right5) {
    right5 = false;
    digitalWrite(2, HIGH);
    onRight5Change();
    delay(500);
    Serial.println("right5");
    
  } else if (up1) {
    up1 = false;
    digitalWrite(2, HIGH);
    onUp1Change();
    delay(500);
    Serial.println("up1");
    
  } else if (up3) {
    up3 = false;
    digitalWrite(2, HIGH);
    onUp3Change();
    delay(500);
    Serial.println("up3");
    
  } else if (down1) {
    down1 = false;
    digitalWrite(2, HIGH);
    onDown1Change();
    delay(500);
    Serial.println("down1");
    
  } else if (down3) {
    down3 = false;
    digitalWrite(2, HIGH);
    onDown3Change();
    delay(500);
    Serial.println("down3");
    
  } else if (m) {
    m = false;
    digitalWrite(2, HIGH);
    onMChange();
    delay(500);
    Serial.println("m");  
  }
  else {
    digitalWrite(2, LOW);
  }
}

void onPauseChange() {
  mySerial.write("1");
}

void onBackChange() {
  mySerial.write("4");
}

void onRewind30Change() {
  mySerial.write("30");
}

void onDebugChange() {
  mySerial.write("77");
}

void onFf30Change() {
  mySerial.write("60");
}

void onLeft1Change() {
    mySerial.write("71");
}

void onLeft2Change() {
  mySerial.write("72");
}

void onLeft5Change() {
  mySerial.write("75");
}

void onRight1Change() {
  mySerial.write("81");
}

void onRight2Change() {
  mySerial.write("82");
}

void onRight5Change() {
  mySerial.write("85");
}

void onUp1Change() {
  mySerial.write("91");
}

void onUp3Change() {
  mySerial.write("93");
}

void onDown1Change() {
  mySerial.write("101");
}

void onDown3Change() {
  mySerial.write("103");
}

void onMChange() {
  // Do something
  mySerial.write("3");
}
