void setup() 
{
  pinMode(13,OUTPUT);  // Relay Pin as a OUTPUT
  pinMode(A0,INPUT_PULLUP);  // Button Pin as a INPUT PULLUP
}

void loop() 
{
  if(digitalRead(A0)==LOW)  // If Button is Pressed
  {
    digitalWrite(13,HIGH);  // Turn ON the Relay to Start the Motor
  }
  else
  {
    digitalWrite(13,LOW);  // Turn OFF the Relay to Stop the Motor
  }
}
