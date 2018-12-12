//variaveis que irão gerar os valores de ramdom
int Min = 1;
int Max = 7;

//leds e seus respctivos pinos
int led1 = 9;
int led2 = 2;
int led3 = 3;
int led4 = 4;
int led5 = 5;
int led6 = 6;
int led7 = 7;

int botao = 8;
int estado_botao = 0;

//serve para verificar se o botão tá sendo pressionado ou não
int pressionar_botao = 0;

void setup() {
  Serial.begin(9600);  // inicia a comunicação serial

  //pinos de saída
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);

  //pinos de entrada
  pinMode(botao, INPUT);
}

void loop() {

 // le o estado do botao 1 p/ apertado e 0 p/ solto
  estado_botao = digitalRead(botao);     
  Serial.println(estado_botao);

// caso o boto for apertado entre nessa condição
  if (estado_botao == 1)                  
  {
    Serial.println(estado_botao);
    pressionar_botao = 1;
    dado(0);
    delay(300);
  }

  if ((estado_botao == 0) && (pressionar_botao == 1))
  {
    pressionar_botao = 0;
    
    //faz 20 sequências até sortear o valor do dado
    for (int x = 0; x < 20; x++) {
      //sorteia um numero de 0 a 6
      int y = random(Min, Max);
      
      dado(y); //passa o valor que foi sorteado
      delay(100);
    }
  }
}

void dado (int num) {

  if (num == 0) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
  }
  else if (num == 1) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
  }
  else if (num == 2) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, HIGH);
  }
  else if (num == 3) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, HIGH);
  }
  else if (num == 4) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
  }
  else if (num == 5) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
  }
  else if (num == 6) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
  }
}
