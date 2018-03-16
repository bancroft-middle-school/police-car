#include <BlockDriver.h>
#include <FreeStack.h>
#include <MinimumSerial.h>
#include <SdFat.h>
#include <SdFatConfig.h>
#include <SysCall.h>

#include <SFEMP3Shield.h>
#include <SFEMP3ShieldConfig.h>
#include <SFEMP3Shieldmainpage.h>

SdFat sd; // Create SDFat object. 

SFEMP3Shield MP3player; // Create SFEMP3Shield object

//Settings for MP3 player
const uint8_t volume = 37; // MP3 Player volume 0=max, 255=lowest (off)
const uint16_t monoMode = 1;  // Mono setting 0=off, 3=max


int trackNumber = 100;

//In void setup you need two functions which are defined below


void setup()  {
  pinMode (A0, OUTPUT);
  pinMode (A1, INPUT);
  

  Serial.begin(9600);
  initSD();  // Initialize the SD card
  initMP3Player(); // Initialize the MP3 Shield
}
void loop() {

int distance = getDistance(A0, A1);

  Serial.print("Distance: ");
  Serial.println(distance);




//if (distance < 56) {trackNumber = 0;
//}

/*
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

if (trackNumber == 0) {
  
  MP3player.playTrack(0); //plays track 0 (track000.mp3)
  delay(3000); //delay for a little sanity between sounds
}
 else if (trackNumber == 1) {

 MP3player.playTrack(1); //plays track 0 (track000.mp3)
  delay(3000); //delay for a little sanity between sounds
 }
  else if (trackNumber == 2) {

 MP3player.playTrack(2); //plays track 0 (track000.mp3)
  delay(3000); //delay for a little sanity between sounds
  } 
 else if (trackNumber == 3) {

 MP3player.playTrack(3); //plays track 0 (track000.mp3)
  delay(3000); //delay for a little sanity between sounds
 }
 else if (trackNumber == 4) {

 MP3player.playTrack(4); //plays track 0 (track000.mp3)
  delay(3000); //delay for a little sanity between sounds
 }
 
}
//function to intialize SD card. Leave it alone unless you know what you're doing.

void initSD()
{
  //Initialize the SdCard.
  if(!sd.begin(SD_SEL, SPI_HALF_SPEED)) 
    sd.initErrorHalt();
  if(!sd.chdir("/")) 
    sd.errorHalt("sd.chdir");
}


//function to intialize MP3 player. Leave it alone unless you know what you're doing

void initMP3Player()
{
  uint8_t result = MP3player.begin(); // init the mp3 player shield
  if(result != 0) // check result, see readme for error codes.
  {
    // Error checking can go here!
  }
  MP3player.setVolume(volume, volume);
  MP3player.setMonoMode(monoMode);
}




