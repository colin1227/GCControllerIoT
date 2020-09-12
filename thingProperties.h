#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[] = "9cb784b0-cf3c-4564-9160-08e29ba46522";

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)

void onBackChange();
void onDebugChange();
void onDown1Change();
void onDown3Change();
void onFf30Change();
void onLeft1Change();
void onLeft2Change();
void onLeft5Change();
void onMChange();
void onPauseChange();
void onRewind30Change();
void onRight1Change();
void onRight2Change();
void onRight5Change();
void onUp1Change();
void onUp3Change();

CloudSwitch back;
CloudSwitch debug;
CloudSwitch down1;
CloudSwitch down3;
CloudSwitch ff30;
CloudSwitch left1;
CloudSwitch left2;
CloudSwitch left5;
CloudSwitch m;
CloudSwitch pause;
CloudSwitch rewind30;
CloudSwitch right1;
CloudSwitch right2;
CloudSwitch right5;
CloudSwitch up1;
CloudSwitch up3;

void initProperties(){

  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(back, READWRITE, ON_CHANGE, onBackChange);
  ArduinoCloud.addProperty(debug, READWRITE, ON_CHANGE, onDebugChange);
  ArduinoCloud.addProperty(down1, READWRITE, ON_CHANGE, onDown1Change);
  ArduinoCloud.addProperty(down3, READWRITE, ON_CHANGE, onDown3Change);
  ArduinoCloud.addProperty(ff30, READWRITE, ON_CHANGE, onFf30Change);
  ArduinoCloud.addProperty(left1, READWRITE, ON_CHANGE, onLeft1Change);
  ArduinoCloud.addProperty(left2, READWRITE, ON_CHANGE, onLeft2Change);
  ArduinoCloud.addProperty(left5, READWRITE, ON_CHANGE, onLeft5Change);
  ArduinoCloud.addProperty(m, READWRITE, ON_CHANGE, onMChange);
  ArduinoCloud.addProperty(pause, READWRITE, ON_CHANGE, onPauseChange);
  ArduinoCloud.addProperty(rewind30, READWRITE, ON_CHANGE, onRewind30Change);
  ArduinoCloud.addProperty(right1, READWRITE, ON_CHANGE, onRight1Change);
  ArduinoCloud.addProperty(right2, READWRITE, ON_CHANGE, onRight2Change);
  ArduinoCloud.addProperty(right5, READWRITE, ON_CHANGE, onRight5Change);
  ArduinoCloud.addProperty(up1, READWRITE, ON_CHANGE, onUp1Change);
  ArduinoCloud.addProperty(up3, READWRITE, ON_CHANGE, onUp3Change);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
