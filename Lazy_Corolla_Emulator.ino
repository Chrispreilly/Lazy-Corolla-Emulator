
//Lazy Emulator
//Fingerprint Openpilot using 1 CAN message. 

#include <SPI.h> 
#include <mcp_can.h>

MCP_CAN CAN(10);         

unsigned int goldenCAN = 0x7e1;  //CAN message is unique to only corolla LE
unsigned char blank8[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


void setup() {

  Serial.begin(115200);

//init CAN controller, wait until successful
START_INIT:

 if (CAN_OK == CAN.begin(CAN_500KBPS))
  {
    Serial.println("CAN BUS Shield init ok!");
  }
  else
  {
    goto START_INIT;
  }
}


void loop() {

//Setup wheelspeed

uint8_t wheel = 100; // not exact conversion, 100 here = 118mph on openpilot

unsigned char wheelCAN[] = {wheel, wheel, wheel, wheel, wheel, wheel, wheel, wheel}; //create CAN message for wheel speed
unsigned char vehCAN[] = {0x0, 0x0, 0x0, 0x0, wheel, wheel, 0x0}; //create CAN message for vehicle speed

 
// Send Golden CAN message to instantly fingerprint as corolla LE

CAN.sendMsgBuf(goldenCAN, 0, 8, blank8);
delay(10);


//Send some wheel speed data to OP

CAN.sendMsgBuf(0xaa, 0, 8, wheelCAN);
    delay(10);
CAN.sendMsgBuf(0xb4, 0, 8, vehCAN);
    delay(10);
    
}
