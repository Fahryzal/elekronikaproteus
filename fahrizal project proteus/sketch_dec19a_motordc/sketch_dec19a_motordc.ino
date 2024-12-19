// Pin konfigurasi
const int potPin = A0;    // Pin untuk potensiometer
const int motorPin = 9;   // Pin PWM untuk kontrol motor

int potValue = 0;         // Menyimpan nilai potensiometer
int motorSpeed = 0;       // Menyimpan nilai PWM untuk motor

void setup() {
  pinMode(motorPin, OUTPUT);  // Pin motor sebagai OUTPUT
  Serial.begin(9600);         // Untuk monitoring nilai potensiometer
}

void loop() {
  // Membaca nilai potensiometer (0-1023)
  potValue = analogRead(potPin);
  
  // Mengonversi nilai potensiometer ke nilai PWM (0-255)
  motorSpeed = map(potValue, 0, 1023, 0, 255);

  // Mengirimkan nilai PWM ke motor
  analogWrite(motorPin, motorSpeed);

  // Monitoring nilai di Serial Monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(" | Motor Speed (PWM): ");
  Serial.println(motorSpeed);

  delay(50);  // Delay untuk stabilitas pembacaan
}
