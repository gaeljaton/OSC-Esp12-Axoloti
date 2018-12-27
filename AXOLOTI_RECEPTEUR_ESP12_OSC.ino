/*---------------------------------------------------------------------------------------------
  Based on Open Sound Control (OSC) library for the ESP8266/ESP32
  https://github.com/CNMAT/OSC
  Receiving open sound control (OSC) bundles on the ESP8266/ESP32
  and serial com to Axoloti DSP
  Gael Jaton 2018
  code is in the public domain.
  --------------------------------------------------------------------------------------------- */
#ifdef ESP8266
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>

char ssid[] = "NUMERICABLE-A7A6";            // your network SSID (name)
char pass[] = "DD0258CE42F43E8AE7EACD4D4D";  // your network password
byte serialData[4] = { 0 };
//byte inbyte = 0;
unsigned long nextmillis = 50;
// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;
//const IPAddress outIp(192, 168, 0, 255);     // remote IP of your computer
//const unsigned int outPort = 8888;         // remote port to receive OSC
const unsigned int localPort = 8000;        // local port to listen for OSC packets (actually not used for sending)
OSCErrorCode error;
int ledState;              // LOW means led is *on*
#define BUILTIN_LED 2


void setup() {
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, ledState);    // turn *on* led
  Serial.begin(115200);
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(BUILTIN_LED, 1);
    delay(100);
    digitalWrite(BUILTIN_LED, 0);
    delay(100);
    Serial.print(".");
  }
  //    IPAddress ip(192, 168, 0, 11); ////////////////////////////////////////////
  //    IPAddress routeur(192, 168, 0, 1);
  //    IPAddress subnet(255, 255, 255, 0);
  //    WiFi.config(ip, routeur, subnet);
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
#ifdef ESP32
  Serial.println(localPort);
#else
  Serial.println(Udp.localPort());
#endif
}

void serialSendToAxo(byte startByte, uint32_t msg32) { // send to axoloti start byte include message number 128 + axoNumber, then send 4 messages of 7bit data
  serialData[0] = msg32 >> 26 & B01111111; // pack into buf string as 4 x 7bit bytes
  serialData[1] = msg32 >> 19 & B01111111;
  serialData[2] = msg32 >> 12 & B01111111;
  serialData[3] = msg32 >> 5 & B01111111;
  Serial.write((byte)startByte); Serial.write((byte)serialData[0]); Serial.write((byte)serialData[1]); Serial.write((byte)serialData[2]); Serial.write((byte)serialData[3]);
}

void axo1(OSCMessage &msg) {
  uint32_t msg32 = msg.getFloat(0) * 0xffffffff;
  int ledState = 1023 - 1023 * msg.getFloat(0);
  analogWrite(BUILTIN_LED, ledState); // Fade built in led on /axo1 value
  serialSendToAxo(129, msg32); // 129 = 128 + axo1...
}
void axo2(OSCMessage &msg) {  uint32_t msg32 = msg.getFloat(0) * 0xffffffff; serialSendToAxo(130, msg32); }
void axo3(OSCMessage &msg) {  uint32_t msg32 = msg.getFloat(0) * 0xffffffff; serialSendToAxo(131, msg32); }
void axo4(OSCMessage &msg) {  uint32_t msg32 = msg.getFloat(0) * 0xffffffff; serialSendToAxo(132, msg32); }
void axo5(OSCMessage &msg) {  uint32_t msg32 = msg.getFloat(0) * 0xffffffff; serialSendToAxo(133, msg32); }
void axo6(OSCMessage &msg) {  uint32_t msg32 = msg.getFloat(0) * 0xffffffff; serialSendToAxo(134, msg32); }
void axo7(OSCMessage &msg) {  uint32_t msg32 = msg.getFloat(0) * 0xffffffff; serialSendToAxo(135, msg32); }
void axo8(OSCMessage &msg) {  uint32_t msg32 = msg.getFloat(0) * 0xffffffff; serialSendToAxo(136, msg32); }
void axo9(OSCMessage &msg) {  uint32_t msg32 = msg.getFloat(0) * 0xffffffff; serialSendToAxo(137, msg32); }
void axo10(OSCMessage &msg) { uint32_t msg32 = msg.getFloat(0) * 0xffffffff; serialSendToAxo(138, msg32); }
void axo11(OSCMessage &msg) { uint32_t msg32 = msg.getFloat(0) * 0xffffffff; serialSendToAxo(139, msg32); }
void axo12(OSCMessage &msg) { uint32_t msg32 = msg.getFloat(0) * 0xffffffff; serialSendToAxo(140, msg32); }
void axo13(OSCMessage &msg) { uint32_t msg32 = msg.getFloat(0) * 0xffffffff; serialSendToAxo(141, msg32); }
void axo14(OSCMessage &msg) { uint32_t msg32 = msg.getFloat(0) * 0xffffffff; serialSendToAxo(142, msg32); }
void axo15(OSCMessage &msg) { uint32_t msg32 = msg.getFloat(0) * 0xffffffff; serialSendToAxo(143, msg32); }
void axo16(OSCMessage &msg) { uint32_t msg32 = msg.getFloat(0) * 0xffffffff; serialSendToAxo(144, msg32); }

void loop() {
  OSCBundle bundle;
  int size = Udp.parsePacket();
  if (size > 0) {
    while (size--) { bundle.fill(Udp.read()); }
    if (!bundle.hasError()) {
      bundle.dispatch("/axo1", axo1);
      bundle.dispatch("/axo2", axo2);
      bundle.dispatch("/axo3", axo3);
      bundle.dispatch("/axo4", axo4);
      bundle.dispatch("/axo5", axo5);
      bundle.dispatch("/axo6", axo6);
      bundle.dispatch("/axo7", axo7);
      bundle.dispatch("/axo8", axo8);
      bundle.dispatch("/axo9", axo9);
      bundle.dispatch("/axo10", axo10);
      bundle.dispatch("/axo11", axo11);
      bundle.dispatch("/axo12", axo12);
      bundle.dispatch("/axo13", axo13);
      bundle.dispatch("/axo14", axo14);
      bundle.dispatch("/axo15", axo15);
      bundle.dispatch("/axo16", axo16);
    }
    else {
      error = bundle.getError();
      //Serial.print("error: ");
      //Serial.println(error);
    }
  }
  if (WiFi.status() != 3 ) { // Blink built in led if wifi deconnect
    analogWrite(BUILTIN_LED, 1023);
    delay(100);
    analogWrite(BUILTIN_LED, 0);
    delay(100);
  }
}
