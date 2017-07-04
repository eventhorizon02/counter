/* 4 digit 7 segmet counter
This sample code is public domain
created November 2014
by Benny Abramovici
*/


// the setup function runs once when you press reset or power the board
void setup()
{
  // initialize pins 0 to 7 as output for the segments control
  for (int i = 0; i <= 13; i++)
  {
  pinMode(i, OUTPUT);
  digitalWrite(i,HIGH);
  }
  digitalWrite (9, LOW);
 }
int counter[10] = {63,6,91,79,102,109,125,7,127,111}; // decimal represantation of seven segments binary LED's
int number = 9999; // counter initiliazion number

// the loop function runs over and over again forever
void loop()
{
  unsigned long starttime,endtime;
  
  
    starttime = millis();
    endtime = starttime;
    while ((endtime - starttime) <= 1000) //display a number up to 1000 milliseconds
    {
      displayThousands(number);
      endtime = millis();
    }
    number--;
    playTone(500,5);
    if (number < 0)
    number = 9999;
  
}
      

 
 void displayThousands (int num)
 {
   
   digitalWrite(13,LOW);
   int thousands = (int) num/1000;
   PORTD = counter[thousands];
   delay(5);
   digitalWrite(13,HIGH);
   displayHundrands (num - 1000*thousands);
  }
 
 
 void displayHundrands (int num)
 {
   digitalWrite(12,LOW);
   int hundrands = (int) num/100;
   PORTD = counter[hundrands];
   delay(5);
   digitalWrite(12,HIGH);
   displayTenths (num - 100*hundrands);
  
 }
 
 void displayTenths (int num )
 {
   digitalWrite(11,LOW);
   int tenths = (int) num/10;
   PORTD = counter[tenths];
   delay(5);
   digitalWrite(11,HIGH);
   displaySingles (num - 10*tenths);
 }
 
 void displaySingles (int num)
 {
   digitalWrite(10,LOW);
   PORTD = counter[num];
   delay(5);
   digitalWrite(10,HIGH);
 }
 
 void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(9, HIGH);
    delayMicroseconds(tone);
    digitalWrite(9, LOW);
    delayMicroseconds(tone);
  }
}
 
 
 
 
 

