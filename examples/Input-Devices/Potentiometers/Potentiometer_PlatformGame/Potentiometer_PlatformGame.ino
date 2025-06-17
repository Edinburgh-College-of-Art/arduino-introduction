//===================================================================
// Potentiometer Platform Game
//
// - Connect potentiometer to pin A0
// - Upload sketch
// - Open Serial Monitor for instructions 
// - Open Serial Plotter
//===================================================================

// Store pin number
int potPin = A0;

// Set lower and upper limits
int minVal = 0;
int maxVal = 1023;

// Platform variables
int platformFloor = 0, platformCeiling = 1023;
int targetFloor = 0, targetCeiling = 1023;
int gap;

// Timing Variables
unsigned long gameStart;
unsigned long timer;
int interval = 3000;

// Game variables
int potValue;

//==================================================================
// SETUP

void setup() {
  // Start serial monitor
  Serial.begin(9600);

  // Start timer values
  timer = millis();
  gameStart = millis();
}

//==================================================================
// LOOP

void loop() {
  // Get potentiometer value
  potValue = analogRead(potPin);

  movePlatforms(); // Move platforms to next position

  // Randomise platform values
  if (millis() - timer > interval) {
    timer = millis();
    randomiseValues();
  }

  // Print next frame of data points
  printNextFrame();

  // If potentiometer value crosses platform, GAME OVER
  if (potValue > platformCeiling || potValue < platformFloor)
    gameOver();
}

//==================================================================
// GAME FUNCTIONS

/// Randomise platform height and gap
void randomiseValues() {
  interval = random(1000, 3000);
  gap = random(50, 200);

  targetFloor = random(minVal, maxVal - gap);
  targetCeiling = targetFloor + gap;
}

/// Move platforms to next position
void movePlatforms() {
  // Platform floor
  if (platformFloor < targetFloor) platformFloor++;
  if (platformFloor > targetFloor) platformFloor--;

  // Platform ceiling
  if (platformCeiling < targetCeiling) platformCeiling++;
  if (platformCeiling > targetCeiling) platformCeiling--;
}

/// Print next frame of data points
void printNextFrame() {
  Serial.print(potValue);
  Serial.print(",");
  Serial.print(platformFloor);
  Serial.print(",");
  Serial.print(platformCeiling);
  Serial.print(",");
  Serial.print(minVal);
  Serial.print(",");
  Serial.println(maxVal);
}

/// Game over handler
void gameOver() {
  // Calculate Score
  unsigned long score = (millis() - gameStart) * 0.001;

  // Reset variables
  platformFloor = 0;
  platformCeiling = 1023;
  targetFloor = 0;
  targetCeiling = 1023;
  interval = 3000;

  // Print messages
  Serial.println("\nGame Over\n");
  Serial.print("Your Score: ");
  Serial.println(score);
  Serial.println();
  Serial.println("Go to 0 to restart.");

  // Wait until pot value equals 0 before continuing
  while (analogRead(potPin) > 0) {}

  // Start game timer
  gameStart = millis();
}