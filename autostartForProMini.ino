/* HOH S.A.S.
29-SEP-2016
For device: Arduino Pro Mini
On Tools/Board/ -> Select "Arduino Duemilanove or Diecimilia"
Autostart device **FINAL VERSION**
Reads start button state to power-on BBB*/

const int start = 12;//Retention from relay board
const int s1 = 13; //Auto-manual operation switch
const int t2 = 11; //Plant's Start button 
const int power_on = 5;
const int s1_timer = 4;
//const int bbb_signal = 9;
boolean sense = true;
boolean sense2 = true;
const int bbb = 7; //Takes BBB P9_42 "Start_Relay" as an input
int time = 0;

void setup()
{
  pinMode(start, INPUT);
  pinMode(s1, INPUT);
  pinMode(t2, INPUT);
        //pinMode(bbb_signal, INPUT);
  pinMode(power_on, OUTPUT);
  pinMode(s1_timer, OUTPUT);
        pinMode(bbb, INPUT);
  digitalWrite(power_on, LOW);
  digitalWrite(s1_timer, LOW);
}

void loop()
{
  time = millis();
  while (digitalRead(s1) && sense){   
    while (millis() - time < 3000 && sense){
      digitalWrite(s1_timer, HIGH);
      if (digitalRead(t2) && !digitalRead(start) && sense2){ // && !digitalRead(bbb_signal)
        digitalWrite(power_on, HIGH); 
        delay(1000);
        digitalWrite(power_on, LOW);
                                sense2 = false;
      } 
    }
    sense = false;
                sense2 = true;
    digitalWrite(s1_timer, LOW);
  }
  while(sense2){
                if(!digitalRead(bbb)){
                        sense2 = false;
                } 
                
        }
        while(!sense2){
                if(!digitalRead(start) && !digitalRead(bbb)){
                        digitalWrite(power_on, HIGH); 
            delay(1000);
      digitalWrite(power_on, LOW);
                        delay(60000);
                        sense2 = true;
                }
        }
        
        
}
