#include "ae7seg.h"
#include <NewThermal.h>

int printer_RX_Pin = 1; // 未使用
int printer_TX_Pin = 0; // サーマルプリンタの緑線をArduinoの3に接続

NewThermal printer(printer_RX_Pin, printer_TX_Pin, 9600);


#define PIN_SDI1 2 // 7セグ1のピン設定
#define PIN_SCK1 8
#define PIN_LATCH1 14
#define BUTTON_PIN1 20 // タクトスイッチ1のピン設定

#define PIN_SDI2 3 // 7セグ2のピン設定
#define PIN_SCK2 9
#define PIN_LATCH2 15
#define BUTTON_PIN2 21// タクトスイッチ2のピン設定

#define PIN_SDI3 4 // 7セグ3のピン設定
#define PIN_SCK3 10
#define PIN_LATCH3 16
#define BUTTON_PIN3 22// タクトスイッチ2のピン設定

#define PIN_SDI4 5 // 7セグ4のピン設定
#define PIN_SCK4 11
#define PIN_LATCH4 17
#define BUTTON_PIN4 23// タクトスイッチ2のピン設定

#define PIN_SDI5 6 // 7セグ5のピン設定
#define PIN_SCK5 12
#define PIN_LATCH5 18
#define BUTTON_PIN5 24// タクトスイッチ2のピン設定

#define PIN_SDI6 7 // 7セグ6のピン設定
#define PIN_SCK6 13
#define PIN_LATCH6 19
#define BUTTON_PIN6 25 // タクトスイッチ2のピン設定

#define BUTTON_PIN7 26// タクトスイッチ設定用のピン設定

#define INTERVAL 500

AE7SEGGPIO ae7seg1(PIN_LATCH1, PIN_SDI1, PIN_SCK1); // 7セグ1のインスタンス
AE7SEGGPIO ae7seg2(PIN_LATCH2, PIN_SDI2, PIN_SCK2); // 7セグ2のインスタンス
AE7SEGGPIO ae7seg3(PIN_LATCH3, PIN_SDI3, PIN_SCK3); // 7セグ2のインスタンス
AE7SEGGPIO ae7seg4(PIN_LATCH4, PIN_SDI4, PIN_SCK4); // 7セグ2のインスタンス
AE7SEGGPIO ae7seg5(PIN_LATCH5, PIN_SDI5, PIN_SCK5); // 7セグ2のインスタンス
AE7SEGGPIO ae7seg6(PIN_LATCH6, PIN_SDI6, PIN_SCK6); // 7セグ2のインスタンス

int count1 = 0;
int count2 = 0;
int count3 = 0;
int count4 = 0;
int count5 = 0;
int count6 = 0;

void setup() {
  printer.printlnJapanese("printer initialize");

  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  pinMode(BUTTON_PIN3, INPUT_PULLUP);
  pinMode(BUTTON_PIN4, INPUT_PULLUP);
  pinMode(BUTTON_PIN5, INPUT_PULLUP);
  pinMode(BUTTON_PIN6, INPUT_PULLUP);
  pinMode(BUTTON_PIN7, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Press the buttons to increment the counts.");
}

void loop() {
  int buttonState1 = digitalRead(BUTTON_PIN1);
  int buttonState2 = digitalRead(BUTTON_PIN2);
  int buttonState3 = digitalRead(BUTTON_PIN3);
  int buttonState4 = digitalRead(BUTTON_PIN4);
  int buttonState5 = digitalRead(BUTTON_PIN5);
  int buttonState6 = digitalRead(BUTTON_PIN6);

  if (buttonState1 == LOW) {
    delay(20); // タクトスイッチ1のデバウンス用の短い遅延
    if (buttonState1 == LOW) {
      count1++;
      if (count1 > 9) {
        count1 = 0;
      }

      ae7seg1.beginWrite();
      ae7seg1.writeNumber(count1);
      ae7seg1.endWrite();

      Serial.print("Count 1: ");
      Serial.println(count1);
      delay(INTERVAL);
    }
  }

  if (buttonState2 == LOW) {
    delay(20); // タクトスイッチ2のデバウンス用の短い遅延
    if (buttonState2 == LOW) {
      count2++;
      if (count2 > 9) {
        count2 = 0;
      }

      ae7seg2.beginWrite();
      ae7seg2.writeNumber(count2);
      ae7seg2.endWrite();

      Serial.print("Count 2: ");
      Serial.println(count2);
      delay(INTERVAL);
    }
  }

  if (buttonState3 == LOW) {
    delay(20); // タクトスイッチ3のデバウンス用の短い遅延
    if (buttonState3 == LOW) {
      count3++;
      if (count3 > 9) {
        count3 = 0;
      }

      ae7seg3.beginWrite();
      ae7seg3.writeNumber(count3);
      ae7seg3.endWrite();

      Serial.print("Count 3: ");
      Serial.println(count3);
      delay(INTERVAL);
    }
  }

  if (buttonState4 == LOW) {
    delay(20); // タクトスイッチ2のデバウンス用の短い遅延
    if (buttonState4 == LOW) {
      count4++;
      if (count4 > 9) {
        count4 = 0;
      }

      ae7seg4.beginWrite();
      ae7seg4.writeNumber(count4);
      ae7seg4.endWrite();

      Serial.print("Count 4: ");
      Serial.println(count4);
      delay(INTERVAL);
    }
  }
if (buttonState5 == LOW) {
    delay(20); // タクトスイッチ2のデバウンス用の短い遅延
    if (buttonState5 == LOW) {
      count5++;
      if (count5 > 9) {
        count5 = 0;
      }

      ae7seg5.beginWrite();
      ae7seg5.writeNumber(count5);
      ae7seg5.endWrite();

      Serial.print("Count 5: ");
      Serial.println(count5);
      delay(INTERVAL);
    }
  }

  if (buttonState6 == LOW) {
    delay(20); // タクトスイッチ2のデバウンス用の短い遅延
    if (buttonState6 == LOW) {
      count6++;
      if (count6 > 9) {
        count2 = 0;
      }

      ae7seg6.beginWrite();
      ae7seg6.writeNumber(count6);
      ae7seg6.endWrite();

      Serial.print("Count 6: ");
      Serial.println(count6);
      delay(INTERVAL);
    }
  }

int buttonState7 = digitalRead(BUTTON_PIN7);
if (buttonState7 == LOW) {
    delay(20); // タクトスイッチ

// 6桁の生年月日を文字列として入力
  String input = String(count1) + String(count2) + String(count3) + String(count4) + String(count5) + String(count6); 

  // 最初の2桁が23より大きい場合は"19"、それ以外の場合は"20"とする
  String century_str;
  int firstTwoDigits = input.substring(0, 2).toInt();
  if (firstTwoDigits > 23) {
    century_str = "19";
  } else {
    century_str = "20";
  }

  // 生年月日を"19"または"20"と結合
  String fullDate = century_str + input;

  // 生年月日の各桁を1桁まで足し合わせる
  int sum = 0;
  for (int i = 0; i < fullDate.length(); i++) {
    sum += (fullDate.charAt(i) - '0');
  }

  // 結果を1桁になるまで繰り返し計算
  while (sum >= 10) {
    int tempSum = 0;
    while (sum > 0) {
      tempSum += sum % 10;
      sum /= 10;
    }
    sum = tempSum;
  }

  // 結果をシリアルモニターに出力
  Serial.print("6桁の生年月日を1桁まで足し合わせた結果: ");
  Serial.println(sum);

   switch(sum){
    case 1:
      kabaraResult1();
      break;
    case 2:
      kabaraResult2();
      break;
    case 3:
      kabaraResult3();
      break;
    case 4:
      kabaraResult4();
      break;
    case 5:
      kabaraResult5();
      break;
    case 6:
      kabaraResult6();
      break;
 }

  // 無限ループを避けるために適度に待つ
  delay(1000);
}

}


void kabaraResult1(){
  Serial.print("kabaraResult1");
  printer.printlnJapanese("カバラ数は1です");
 }

void kabaraResult2(){
  Serial.print("kabaraResult2");
  printer.printlnJapanese("カバラ数は2です");
 }
void kabaraResult3(){
  Serial.print("kabaraResult3");
  printer.printlnJapanese("カバラ数は3です");
 }

void kabaraResult4(){
  Serial.print("kabaraResult4");
  printer.printlnJapanese("カバラ数は4です");
 }

void kabaraResult5(){
  Serial.print("kabaraResult5");
  printer.printlnJapanese("カバラ数は5です");
 }

void kabaraResult6(){
  Serial.print("kabaraResult6");
  printer.printlnJapanese("カバラ数は6です");
 }




