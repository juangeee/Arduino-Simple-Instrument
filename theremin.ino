int buzzer=2;
int pot=A0;
int notes[14] = {262,294,330,349,392,440,494,523,587,659,698,784,880,988};
int maxV = 1023;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(pot,INPUT);
  Serial.begin(9600);
}

void loop() {
  int volts=analogRead(pot);
  int vPerN = maxV / 14;
  int expPer = vPerN;
  int counter = 0;
  boolean cond = true;
  while (cond)
  {
    if(volts <= expPer)
    {
      cond = false;
      int noteFrec = notes[counter];
      tone(buzzer, noteFrec,150);
      Serial.println(notes[counter]);
    }else if (volts > vPerN * 14)
    {
      cond = false;
      tone(buzzer, notes[13], 150);
      Serial.println(notes[13]);
    }
    expPer = expPer + vPerN;
    counter++;
  };
  delay(10);
}