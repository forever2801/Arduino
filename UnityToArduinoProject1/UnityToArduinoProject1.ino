  const int ledPin = 13;

void setup() {

  Serial.begin(115200);
  
}

void loop() {
  pinMode(ledPin, OUTPUT);
  //digitalWrite(ledPin, HIGH);
  //String keyPressed = String(char(Serial.read()));
  action(char(Serial.read()));
  /*if(Serial.available() > 0){
    String incomingData = String(Serial.read());
    Serial.println(incomingData);
  }*/
  /*Serial.println("1");
  delay(200);
  Serial.println("2");
  delay(200);*/
}

void action(char keyPressed){
  if(keyPressed == '1'){
    digitalWrite(ledPin, HIGH);
  }
  else if(keyPressed == '2'){
    digitalWrite(ledPin, LOW);
  }
}
