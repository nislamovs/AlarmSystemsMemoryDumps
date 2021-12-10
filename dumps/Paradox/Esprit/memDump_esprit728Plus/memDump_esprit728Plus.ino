#include <M93Cx6.h>

/******************************************************************************
 **
 **  M93Cx6 Test Program
 **
 **  Pin-Out:
 **                       _____
 **  Chip Select (cs)  --|1   8|--  (pwr) Vcc
 ** Serial Clock (sk)  --|2   7|--
 **      Data In (di)  --|3   6|--  (org) Organization Select
 **     Data Out (do)  --|4   5|--  (gnd) Vss/Ground
 **                       -----
 **
 **  Arduino Connection:
 **    Vcc          - +5v (or Pin 9 as an option)
 **    Vss          - GND
 **    Chip Select  - Pin 10
 **    Serial Clock - Pin 13
 **    Data In      - Pin 11
 **    Data Out     - Pin 12
 **    Org Select   - Pin 8
 **
 *****************************************************************************/


#define PWR_PIN   6
#define CS_PIN    13
#define SK_PIN    12
#define DO_PIN    2
#define DI_PIN    7
#define ORG_PIN   11
#define ORG       ORG_8
#define CHIP      M93C86

M93Cx6 eeprom = M93Cx6(PWR_PIN, CS_PIN, SK_PIN, DO_PIN, DI_PIN, ORG_PIN);

void test() {
      int r = eeprom.read(145);


    Serial.println();
    Serial.println(" yoyoyo ");
    if (r < 16) Serial.print("0");
    Serial.print(r, HEX);
    Serial.print(" ");
    Serial.println();
}

void setup() {
  Serial.begin(115200);


  eeprom.setChip(CHIP);    // set chip 93C86
  eeprom.setOrg(8);  // 8-bit data organization

//Set installer lock (ahahahah ...)
  eeprom.writeEnable();
  eeprom.write(58, 147);
  eeprom.writeDisable();


//  read string from eeprom
  for (int i = 0; i < 2048; i++) {
    int r = eeprom.read(i);
    if (i%16 == 0) Serial.println();


    if (r < 16) Serial.print("0");
    Serial.print(r, HEX);
    Serial.print(" ");
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}