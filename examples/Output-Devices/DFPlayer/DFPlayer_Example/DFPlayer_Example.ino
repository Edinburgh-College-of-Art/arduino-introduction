//===================================================================
// File: DFPlayer_Example.ino
//
// Description:
//    - Run through MP3 files on DFPlayer
//    - Play one file every 3 seconds before moving onto the next
//===================================================================

#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

#define DFPlayer_RX 2  // Pin connected to RX on DFPlayer
#define DFPlayer_TX 3  // Pin connected to TX on DFPlayer

SoftwareSerial softwareSerial(DFPlayer_TX, DFPlayer_RX);  // Object for serial comms with DFPlayer
DFRobotDFPlayerMini dfplayer;                             // Object for controlling MP3 files

void setup() {
  // Begin (regular) serial comminucation - for Serial Monitor
  Serial.begin(9600);

  // Start software serial communication - for DFPlayer
  softwareSerial.begin(9600);

  // Initialise DFPlayer
  if (!dfplayer.begin(softwareSerial, true, true)) {
    Serial.println("Error: Failed to initialise DFPlayer.");
    while (true) {}  // Do not continue if init fails
  }

  // Set volume value (0-30).
  dfplayer.volume(15);    
}

void loop() {
  static unsigned long timestamp = millis();

  if (millis() - timestamp > 3000) {
    timestamp = millis();
    dfplayer.next();  // Play next file every 3 second
  }
}
