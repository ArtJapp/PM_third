// Считывать показания с переменного резистора, используя АЦП.
// Отображать уровень считанного сигнала, используя светодиоды.
// Чем больше уровень, тем больше светодиодов загорается.

#define POT_PIN A0
#define COUNT_OF_DIODS 8

int ports[COUNT_OF_DIODS] = {1, 2, 3, 4, 6, 7, 8, 9};

int currentFire = 0;

void setup() {
  for (int i = 0; i < COUNT_OF_DIODS; i++) {
    pinMode(ports[i], OUTPUT);
  }
  pinMode(POT_PIN, INPUT);
}

void loop() {
  calculateCount();
  makeStep();
}

void calculateCount() {
    int rotation = analogRead(POT_PIN);
    double percentage = rotation / 1019.0;
    int newFire = COUNT_OF_DIODS * percentage;
    if (newFire != currentFire) {
      fadeAll();
    }
    currentFire = newFire;
}

void makeStep() { 
  for (int i = 0; i < currentFire; i++) {
    fire(ports[i]); 
  }
}

void fire(int port) {
    digitalWrite(port, HIGH);
}

void fade(int port) {
    digitalWrite(port, LOW);
}

void fadeAll() {
  for (int i = 0; i < COUNT_OF_DIODS; i++) {
    fade(ports[i]);
  }
}
