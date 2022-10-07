int frequency_output=12;
int voltage_input=A0;
int notes[15] = {262,294,330,349,392,440,494,523,587,659,698,784,880,988,1047};
int maximum_voltage = 1023;

int frequencyFinder(int voltage, int maximum_voltage) {
  int voltage_per_note = maximum_voltage / 15, voltage_checker = voltage_per_note;
  for (int i = 0; i < 15; i++) {
    if(voltage <= voltage_checker)
    {
      return(notes[i]);
    }else if (voltage > voltage_per_note * 15)
    {
      return(notes[14]);
    }
    voltage_checker = voltage_checker + voltage_per_note;
  };
}

void setup() {
  pinMode(frequency_output, OUTPUT);
  pinMode(voltage_input,INPUT);
}

void loop() {
  int v = analogRead(voltage_input);
  int f = frequencyFinder(v, 1030 );
  tone(frequency_output, f, 150);
  delay(10);
}