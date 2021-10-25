#define POT A0
#define BOTON 8
#define Potencia 3
#define Entrada1 2
#define Entrada2 7
#define LED_HORARIO 12
#define LED_ANTI_HORARIO 13

int valorPot = 0;
int velocidade = 0;
int estadoButton = 0;
   
void setup()  
{  
  //Define os pinos como saida
  Serial.begin(9600);
  pinMode(POT, INPUT);
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(LED_HORARIO, OUTPUT); 
  pinMode(LED_ANTI_HORARIO, OUTPUT); 
  pinMode(Potencia, OUTPUT); 
  pinMode(Entrada1, OUTPUT);  
  pinMode(Entrada2, OUTPUT);  
}  
   
void loop()  
{  
  //Lê o valor de potenciometro
  valorPot = analogRead (POT);
  
  //Converte o valor do potenciometro
  velocidade = map(valorPot ,0 ,1023, 0, 255);

  //Lê o valor de buttonPin e armazena em estadoButton
   estadoButton = digitalRead (BOTON);
  
  //Define a velocidade de rotacao  
  analogWrite(Potencia, velocidade);   
  
  //Aciona o motor no sentido horário 
  if (estadoButton == HIGH){
   		analogWrite(LED_HORARIO, 250);
    	analogWrite(LED_ANTI_HORARIO, 0);
  		digitalWrite(Entrada1, LOW);  
 		digitalWrite(Entrada2, HIGH);  
  
  }
 
  //Aciona o motor no sentido anti horário   
  else{
    	analogWrite(LED_ANTI_HORARIO, 250);
    	analogWrite(LED_HORARIO, 0);
 		digitalWrite(Entrada1, HIGH);  
  		digitalWrite(Entrada2, LOW); 
  
  }
}  