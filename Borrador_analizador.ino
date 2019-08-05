#include <LiquidCrystal.h> // Incluye la Libreria LiquidCrystal
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Crea un Objeto LC. Parametros: (rs, enable, d4, d5, d6, d7)
void setup() {   
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
    
 }
