#define AGC 9 //milliseconds
#define AGC_PAUSE 4500 //microseconds
#define PREDROP 625 ///microseconds
#define ZERO 500 //microseconds
#define ONE 1600 //microseconds

#define OUTPIN 10

int address = 0x0000;
byte instruction = 0x78;

void ir_send(int address, byte instruction){
  int i;
  //send AGC preamble
  digitalWrite(OUTPIN, LOW);
  delay(AGC);
  digitalWrite(OUTPIN, HIGH);
  delayMicroseconds(AGC_PAUSE);
  
  //send address
  for (i = 15; i >= 0; i--){
    digitalWrite(OUTPIN, LOW);
    delayMicroseconds(PREDROP);
    digitalWrite(OUTPIN, HIGH);
    if (bitRead(address,i)) delayMicroseconds(ONE);
    else delayMicroseconds(ZERO);
  }

  //send instruction
  for (i = 7; i >= 0; i--){
    digitalWrite(OUTPIN, LOW);
    delayMicroseconds(PREDROP);
    digitalWrite(OUTPIN, HIGH);
    if (bitRead(instruction,i)) delayMicroseconds(ONE);
    else delayMicroseconds(ZERO);
  }

  //send inverse instruction
   for (i = 7; i >= 0; i--){
    digitalWrite(OUTPIN, LOW);
    delayMicroseconds(PREDROP);
    digitalWrite(OUTPIN, HIGH);
    if (bitRead(instruction,i)) delayMicroseconds(ZERO);
    else delayMicroseconds(ONE);
  }
  //Close Final Bit
  digitalWrite(OUTPIN, LOW);
  delayMicroseconds(PREDROP);
  digitalWrite(OUTPIN, HIGH);
}


void setup() {
  pinMode(OUTPIN, OUTPUT);
  digitalWrite(OUTPIN, HIGH);
}

void loop() {
  TXLED1;
  ir_send(address, instruction);
  delay(40);
  //second instruction - instruction + 1
  ir_send(address, instruction + 1);
  if (address==0xFFFF) exit(0);
  else address++;
  TXLED0;
  delay(60);
}
