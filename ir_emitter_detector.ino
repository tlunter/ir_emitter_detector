const int leds = 4;
const int samples = 10.0;

int avg_led[leds];
int curr_led[leds];

void setup() {
  Serial.begin(9600);

  delay(3000);

  Serial.println("Now sampling");

  for (int i = 0; i < leds; i++) {
    int pre_avg = 0;

    for (int j = 0; j < samples; j++) {
      pre_avg += analogRead(i);
      delay(250);
    }
    avg_led[i] = pre_avg / samples;

    Serial.print("Average for ");
    Serial.print(i);
    Serial.print(" is ");
    Serial.println(avg_led[i]);
  }
}

void loop() {
  Serial.print("LEDs: ");

  for (int i = 0; i < leds; i++) {
    curr_led[i] = analogRead(i);
    if (curr_led[i] > (1.5 * avg_led[i])) {
      Serial.print(i);
      Serial.print(" is on\t");
    }
    else
    {
      Serial.print("\t");
    }
  }
  Serial.println("");
  for (int i = 0; i < leds; i++) {
    Serial.print(curr_led[i]);
    Serial.print("\t");
  }
  Serial.println("");
  delay(500);
}
