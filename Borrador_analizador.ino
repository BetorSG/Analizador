#include <LiquidCrystal.h> // Incluye la Libreria LiquidCrystal
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Crea un Objeto LC. Parametros: (rs, enable, d4, d5, d6, d7)
const int EchoPin = 11;
const int TriggerPin = 12;
const int LedPinVerde = 8;
const int LedPinBlanco = 9;
float distancia;
long tiempo;

void setup() {  
  pinMode(LedPinVerde, OUTPUT);
  pinMode(LedPinBlanco, OUTPUT);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
    
  lcd.begin(16,2); // Inicializa la interface para el LCD screen, and determina sus dimensiones (ancho y alto) del display
  lcd.print("   Bienvenido");
  delay(3000);
  lcd.clear();
  delay(3000);

  lcd.print(" Roberto Rosas"); // Imprime "LCD Tutorial" sobre el LCD
  delay(3000);   // 3 segundos de espera
  lcd.setCursor(0,1); // Seteamos la ubicacion texto 0 linea 1 que sera escrita sobre el LCD
  
  lcd.print("    FI UNAM");
  delay(4000);
  lcd.clear(); // Limpia la pantalla
  delay(1500);

  lcd.print("Quantum Analizer");
   
  lcd.setCursor(0,1); 
  lcd.print("Bioresonance");
  delay(5000);
  lcd.clear(); // 
  delay(2000);
}

void loop() {   
  /*lcd.blink(); // Displayamos el Blinking del Cursor sobre el LCD
  delay(3000);
  lcd.noBlink();*/ // Apagamos el Blinking del Cursor sobre el LCD
  
  lcd.print("Analizando..."); 
  delay(1000);   
  lcd.clear();
  delay(1000);  

   
  digitalWrite(TriggerPin, HIGH);  //se envía un pulso para activar el sensor
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  // medimos el pulso de respuesta
  tiempo = (pulseIn(EchoPin, HIGH)/2); 
  
  // dividido por 2 por que es el 
  // tiempo que el sonido tarda
  // en ir y en volver
  // ahora calcularemos la distancia en cm
  // sabiendo que el espacio es igual a la velocidad por el tiempo
  // y que la velocidad del sonido es de 343m/s y que el tiempo lo 
  // tenemos en millonesimas de segundo
  
  distancia = float(tiempo * 0.0343);
  Serial.print("Distancia: "); // imprime la distancia en el Monitor Serie
  Serial.println(distancia);
  
  if (distancia >= 50) {
    digitalWrite(LedPinVerde , HIGH);
    digitalWrite(LedPinBlanco , LOW);
  }
  else if(distancia <= 49){
    digitalWrite(LedPinVerde , LOW);
    digitalWrite(LedPinBlanco , HIGH);
        
  }  
  
  delay(500);

 }
