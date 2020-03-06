int laserSendPin = 10;
int laserReceiverPin =6;

void setup ()
{
   pinMode (laserSendPin, OUTPUT); // define the digital output interface 13 feet
   pinMode (laserReceiverPin, INPUT);
   digitalWrite (laserSendPin, HIGH); // Turn Laser On
   //delay (1000); // On For Half a Second
   //digitalWrite (laserSendPin, LOW); // Turn Laser Off
   //delay (500); // Off for half a second
   Serial.begin(9600);
   
}
void loop () {
  
   boolean val = digitalRead(laserReceiverPin);

   Serial.println(val);
}
