//int AnalogPin = 0;   // Sensor conectado a Analog 0
int LEDpin = 6;      // LED conectado a Pin 6 (PWM)
int ResRead;         // La Lectura de la Resistencia por División de Tensión
int BrilloLED;

void setup()
{
Serial.begin(9600); // Enviaremos la información de depuración a través del Monitor de Serial
pinMode(LEDpin, OUTPUT);
}
void loop()
{
ResRead = analogRead(A0); // La Resistencia es igual a la lectura del sensor (Analog 0)
Serial.print("Lectura Analogica = ");
Serial.println(ResRead);



if(analogRead(A0)==0){
  digitalWrite(LEDpin, LOW);
  delay(100); //Cien “ms” de espera en cada lectura
  
  
}else{
  digitalWrite(LEDpin, HIGH);
  delay(100); //Cien “ms” de espera en cada lectura
  
}


delay(100); //Cien “ms” de espera en cada lectura
}
