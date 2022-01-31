boolean numbers[10][7] = {
   {1,1,1,1,1,1,0},  // 0
   {0,1,1,0,0,0,0},  // 1
   {1,1,0,1,1,0,1},  // 2
   {1,1,1,1,0,0,1},  // 3
   {0,1,1,0,0,1,1},  // 4
   {1,0,1,1,0,1,1},  // 5
   {1,0,1,1,1,1,1},  // 6
   {1,1,1,0,0,0,0},  // 7
   {1,1,1,1,1,1,1},  // 8
   {1,1,1,1,0,1,1}   // 9
};

const int buttons[] = { 23,25,27,29,31,33,35 };
bool isPress = false;
int counter = 1;

void setup() {
    for (int i=2;i<=8;i++) pinMode(i,OUTPUT);          // D2~D8を出力に
    for (int button : buttons) pinMode( button , INPUT_PULLUP );
    boot();
}

void loop() {
    if(counter == 8) counter = 1;
    start();
}

void start(){
    for (int button : buttons) {
        if (digitalRead(button) == 0 && isPress == false) isPress = true;
        if (isPress) NumberPrint(counter);
        else counter++;
    }
}

// LED表示関数
void NumberPrint(int j){
    for(int i = 0; i <= 6; i++) digitalWrite(i + 2, !numbers[j][i]);
}

void boot() {
    for(int i=0; i<=9; i++){
    NumberPrint(i);
    delay(100);
    }
NumberPrint(0);
}
