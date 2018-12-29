# OSC-Esp12-Axoloti
get open sound control (osc) message and transmit to Axoloti DSP through serial gpio (PA3/PA2)<br />
Wiring :<br />
ESP RX <-> TX PA3 Axoloti<br />
ESP TX <-> RX PA2 Axoloti<br />
ESP 3v3 <-> VDD (any) Axoloti<br />
ESP Gnd <-> GND (any) Axoloti<br />
required :/>
*ESP 12 board (nodemcu, wemos, ESPino...)<br />
*Axoloti core board (stand alone digital sound processor) http://www.axoloti.com/ <br />
*arduino IDE with esp8266 board manager installed <br />
*OSC arduino library  https://github.com/CNMAT/OSC<br />
*offline router (optional if use accesPoint mode) <br />
*OSC controller (lemur, TouchOSC...) https://liine.net/en/products/lemur/ --- https://hexler.net/software/touchosc<br />

Wiring diagram : />
![alt text](https://github.com/gaeljaton/OSC-Esp12-Axoloti/blob/master/Axoloti_ESP8266.jpg)
