#include <Arduino.h>
#include <avr/pgmspace.h>

String prefixDevice1 = "\n\r\e[0;31m AVR--->";
String prefixDevice2 = "\n\r\e[0;32m ESP--->";

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial.println("Sniffer start");
}

bool directionFromSerial1=false, oldDirectionFromSerial1=true;

void loop() {
  if (Serial1.available( ))
  {
    directionFromSerial1 = true;
    if(oldDirectionFromSerial1 == false) Serial.print(prefixDevice1);
    Serial.print(Serial1.read()); Serial.print(" ");
  }
   
  if (Serial2.available( ))
  {
    directionFromSerial1 = false;
    if(oldDirectionFromSerial1 == true) Serial.print(prefixDevice2);
    Serial.print(Serial2.read()); Serial.print(" ");
  }
  
  oldDirectionFromSerial1 = directionFromSerial1;

}


/*
################################
### Colors ###
################################

BLACK='\e[0;30m'
BLUE='\e[0;34m'
GREEN='\e[0;32m'
CYAN='\e[0;36m'
RED='\e[0;31m'
PURPLE='\e[0;35m'
BROWN='\e[0;33m'
LIGHTGRAY='\e[0;37m'
DARKGRAY='\e[1;30m'
LIGHTBLUE='\e[1;34m'
LIGHTGREEN='\e[1;32m'
LIGHTCYAN='\e[1;36m'
LIGHTRED='\e[1;31m'
LIGHTPURPLE='\e[1;35m'
YELLOW='\e[1;33m'
LIGHTYELLOW='\e[0;33m'
WHITE='\e[1;37m'
NC='\e[0m' # No Color


# Set Less Colors for Man Pages
if [ -x /usr/bin/less ]; then
export LESS_TERMCAP_mb=$'\E[01;31m' # begin blinking
export LESS_TERMCAP_md=$'\E[01;38;5;74m' # begin bold
export LESS_TERMCAP_me=$'\E[0m' # end mode
export LESS_TERMCAP_se=$'\E[0m' # end standout-mode
export LESS_TERMCAP_so=$'\E[38;5;246m' # begin standout-mode - info box
export LESS_TERMCAP_ue=$'\E[0m' # end underline
export LESS_TERMCAP_us=$'\E[04;38;5;146m' # begin underline
fi

# NEW. FANCY PROMPT
if [[ $EUID == 0 ]] ; then
PS1='\[\033[01;31m\]\u\[\033[01;30m\]@\[\033[01;34m\]\h\[\033[01;30m\]:\[\033[01;34m\]\w\[\033[00m\]\$' #RED
else
PS1='\[\033[01;32m\]\u\[\033[01;30m\]@\[\033[01;34m\]\h\[\033[01;30m\]:\[\033[01;34m\]\w\[\033[00m\]\$' #Green

# PS1='\[\033[01;34m\]\u\[\033[01;30m\]@\[\033[01;34m\]\h\[\033[01;30m\]:\[\033[01;34m\]\w\[\033[00m\]\$' #Blue
fi
*/