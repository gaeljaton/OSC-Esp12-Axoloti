# OSC-Esp12-Axoloti
Get open sound control (osc) message on ESP12 and transmit to Axoloti DSP through serial gpio (PA3/PA2)<br />
Wiring :<br />
ESP RX <-> TX PA3 Axoloti<br />
ESP TX <-> RX PA2 Axoloti<br />
ESP 3v3 <-> VDD (any) Axoloti<br />
ESP Gnd <-> GND (any) Axoloti<br />
required :<br />
*ESP 12 board (nodemcu, wemos, ESPino...) or ESP32<br />
*Axoloti core board (stand alone digital sound processor) http://www.axoloti.com/ <br />
*arduino IDE with esp8266 board manager installed <br />
*OSC arduino library  https://github.com/CNMAT/OSC<br />
*offline router (optional if use accesPoint mode) <br />
*OSC controller (lemur, TouchOSC...) https://liine.net/en/products/lemur/ --- https://hexler.net/software/touchosc<br />

Wiring diagram :<br />
![alt text](https://github.com/gaeljaton/OSC-Esp12-Axoloti/blob/master/Axoloti_ESP8266.jpg)

° AXOLOTI_RECEPTEUR_ESP12_OSC.ino is the sketch of ESP12 to load from Arduino ide.<br />
° osc.axo is the objet to run in axoloti software to parse serial data from ESP12 <br />
-> Connect controller to wifi and localPort : 8000, send float OSC messages adresses : /axo1 , /axo2 ... /axo16 <br />
-> Float 32bit osc message are converted to kRate signal in axoloti (27 bits) give 0-64 floating point. <br />
-> Use other axoloti object to scale your control (uni to bipolar, mult, div, curve...)<br />
