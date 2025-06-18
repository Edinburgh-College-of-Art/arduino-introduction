//===================================================================
// File: SerialMonitor_Connect4.ino
//
// Play connect 4 in the Serial Monitor
//===================================================================

#define WIDTH 9   // must be between 4-9
#define HEIGHT 7  // must be between 4-9

//===================================================================
// ASSERTIONS

#if WIDTH < CONNECT || HEIGHT < CONNECT
#error Matrix must be at least CONNECT elements wide and CONNECT elements tall
#endif
#if WIDTH > 9 || HEIGHT > 9
#error Matrix must not exceed 9 elements in width or height
#endif

//===================================================================
// VARIABLES AND CONSTANTS

uint8_t direction[4][2] = {
  { 0, 1 },
  { 1, 0 },
  { 1, 1 },
  { -1, 1 }
};

#define VERTICAL 0
#define HORIZONTAL 1
#define DIAGONAL 2
#define R_DIAGONAL 3

uint8_t board[WIDTH][HEIGHT];
bool player = true;

//===================================================================
// SETUP

void setup() {
  Serial.begin(9600);  // Start serial connection
  resetGame();         // Start game
}

//===================================================================
// LOOP

void loop() {
  // If Serial Message received
  if (Serial.available()) {
    int8_t move = Serial.parseInt(); // Get player input

    // Add move to board
    if (!playMove(move, player)) {
      Serial.print("\n\nOut of bounds. Try again.\n\n");
      return;
    }

    draw();
    player = !player; // Swap players

    // Check if game has finished
    if (gameOver(analyse()))
      resetGame();
    else
      printTurn();
  }
}

//===================================================================
// ANALYSIS

/// Check for 4 in  a row
/// @return -1=board full, 0=no win, 1=player1 win, 2=player2 win
int8_t analyse() {
  bool boardFull = true;

  // Iterate through matrix...
  for (uint8_t row = 0; row < HEIGHT; row++) {
    for (uint8_t col = 0; col < WIDTH; col++) {
      uint8_t currentCell = board[col][row];  // Get current cell value

      // Ignore 0 cells
      if (currentCell == 0) {
        boardFull = false;  // existence of 0 cell means board is not full
        continue;
      }

      // Check verticals
      if (row < HEIGHT - 3)  // only check cells 4 away from matrix max height
        if (check(currentCell, col, row, VERTICAL)) return currentCell;

      //  Check horizontals
      if (col < WIDTH - 3)  // only check cells 4 away from matrix edge
        if (check(currentCell, col, row, HORIZONTAL)) return currentCell;

      // Diagonals
      if (col < WIDTH - 3       // only check cells 4 away from matrix edge
          && row < HEIGHT - 3)  // ... and 4 away from matrix max height
        if (check(currentCell, col, row, DIAGONAL)) return currentCell;

      // Reverse diagonals
      if (row < HEIGHT - 3  // only check cells 4 away from matrix min height
          && col > 2)       // ... and 4 away from matrix edge
        if (check(currentCell, col, row, R_DIAGONAL)) return currentCell;
    }
  }

  if (boardFull)
    return -1;  // if no space
  else
    return 0;  // if there are still empty cells
}

/// Check if connect 4 has been acheived
/// @param currentCell (uint8_t) value at current cell
/// @param row (uint8_t) current row
/// @param col (uint8_t) current column
/// @param dir (uint8_t) direction - 0=Vert., 1=Horiz., 2=Diag., 3=Reverse Diag.
/// @return (bool) true=win
bool check(uint8_t currentCell, uint8_t col, uint8_t row, uint8_t dir) {
  for (int8_t i = 0; i < 4; i++) {
    int8_t dx = direction[dir][0] * i;
    int8_t dy = direction[dir][1] * i;

    if (board[col + dx][row + dy] != currentCell) return false;
  }
  return true;
}

//===================================================================
// GAME MECHANICS

/// Reset game ready to start again
void resetGame() {
  // Empty board
  for (uint8_t row = 0; row < HEIGHT; row++) {
    for (uint8_t col = 0; col < WIDTH; col++) {
      board[col][row] = 0;
    }
  }

  // Start with player 1
  bool player = true;

  // Draw new board
  Serial.print("\n\n\n\nNew Game!");
  draw();
  printTurn();
}

/// Play next move
/// @param move (uint8_t) column to place next cell
/// @param player (bool) true=player1, false=player2
/// @return (bool) true=move played, false=out of bounds
bool playMove(int8_t move, bool player) {
  // Check if move is in bounds
  if (move < 1 || move > WIDTH) return false;

  uint8_t symbol = player ? 1 : 2;

  uint8_t col = move - 1;
  for (int8_t row = HEIGHT - 1; row >= 0; row--) {
    // If empty space found, place symbol in that space
    if (board[col][row] == 0) {
      board[col][row] = symbol;
      return true;
    }

    Serial.println();
  }

  // If no empty space found, must be out of bounds
  return false;
}

//===================================================================
// DISPLAY FUNCTIONS

/// Game over handler
/// @param status (uint8_t) 0=no win, 1=player1 win, 2=player2 win
/// @return (bool) true=game over
bool gameOver(uint8_t status) {
  switch (status) {
    case 0:
      return false;
    case 1:
      Serial.println("\n\nPlayer 1 Wins!");
      break;
    case 2:
      Serial.println("\n\nPlayer 2 Wins!");
      break;
  }

  delay(1000);
  Serial.print("Restarting in...");

  for (uint8_t i = 5; i > 0; i--) {
    Serial.print(i);
    Serial.print("...");
    delay(1000);
  }
  return true;
}

/// Print whos turn it is
void printTurn() {
  if (player)
    Serial.print("\nPlayer 1's Turn...\n\n");
  else
    Serial.print("\nPlayer 2's Turn...\n\n");
}

/// Draw updated board
void draw() {
  // Print top line
  Serial.print("\n\n");

  for (uint8_t col = 0; col < WIDTH; col++)
    Serial.print("   -");

  Serial.println();

  // Run through each row
  for (uint8_t row = 0; row < HEIGHT; row++) {

    // Print y label
    Serial.print(" | ");

    // Print columns in current row
    for (uint8_t col = 0; col < WIDTH; col++) {
      Serial.print(board[col][row]);
      Serial.print(" | ");  // Seperate by vertical lines
    }
    Serial.println();

    // Print bottom line of each row
    for (uint8_t col = 0; col < WIDTH; col++)
      Serial.print("   -");

    Serial.println();
  }

  // Print x labels
  for (uint8_t col = 0; col < WIDTH; col++) {
    Serial.print("   ");
    Serial.print(col + 1);
  }

  Serial.println();
}