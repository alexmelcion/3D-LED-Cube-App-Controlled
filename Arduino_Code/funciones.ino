void ledWrite(int Led1, int Led2, int Led3, int Led4){
   shiftOut(pinData, pinClock, LSBFIRST, Led4);
   shiftOut(pinData, pinClock, LSBFIRST, Led3);
   shiftOut(pinData, pinClock, LSBFIRST, Led2);
   shiftOut(pinData, pinClock, LSBFIRST, Led1);
   digitalWrite(pinLatch, HIGH);
   digitalWrite(pinLatch, LOW);
}

void capas(int a, int b, int c, int d, int e){
  digitalWrite(c5,e);
  digitalWrite(c4,d);
  digitalWrite(c3,c);
  digitalWrite(c2,b);
  digitalWrite(c1,a);
}

void cruz(){
  capas(1,1,1,1,1);
  ledWrite(0b11111000,0,0,0);
  delay(100);
  ledWrite(0b00000111,0b11000000,0,0);
  delay(100);
  ledWrite(0,0b00111110,0,0);
  delay(100);
  ledWrite(0,0b00000001,0b11110000,0);
  delay(100);
  ledWrite(0,0,0b00001111,128);
  delay(100);
  
  ledWrite(0b00001000,0b01000010,0b00010000,128);
  delay(100);
  ledWrite(0b00010000,0b10000100,0b00100001,0);
  delay(100);
  ledWrite(0b00100001,0b00001000,0b01000010,0);
  delay(100);
  ledWrite(0b01000010,0b00010000,0b10000100,0);
  delay(100);
  ledWrite(0b10000100,0b00100001,0b00001000,0);
  delay(100);

  ledWrite(0,0,0b00001111,128);
  delay(100);
  ledWrite(0,0b00000001,0b11110000,0);
  delay(100);
  ledWrite(0,0b00111110,0,0);
  delay(100);
  ledWrite(0b00000111,0b11000000,0,0);
  delay(100);
  ledWrite(0b11111000,0,0,0);
  delay(100);

  ledWrite(0b10000100,0b00100001,0b00001000,0);
  delay(100);
  ledWrite(0b01000010,0b00010000,0b10000100,0);
  delay(100);
  ledWrite(0b00100001,0b00001000,0b01000010,0);
  delay(100);
  ledWrite(0b00010000,0b10000100,0b00100001,0);
  delay(100);
  ledWrite(0b00001000,0b01000010,0b00010000,128);
  delay(100);
}

void aristas(){
  capas(1,0,0,0,1);
  ledWrite(252,99,31,128);
  delay(5);
  capas(1,1,1,1,1);
  ledWrite(136,0,8,128);
  delay(5);
}

void full(){
  capas(1,1,1,1,1);
  ledWrite(255,255,255,128);
  delay(10);
}

void fullblack(){
  capas(0,0,0,0,0);
  ledWrite(0,0,0,0);
  delay(10);
}

int cub[8][2][5]={
    {{1,0,0,0,1},{252,99,31,128}},
    {{1,1,1,1,1},{136,0,8,128}},
    {{0,1,0,1,0},{3,148,224,0}},
    {{0,0,1,0,0},{2,128,160,0}},
    {{0,0,1,0,0},{0,8,0,0}},
    {{0,0,1,0,0},{0,8,0,0}},
    {{0,1,0,1,0},{3,148,224,0}},
    {{0,0,1,0,0},{2,128,160,0}}
};

void cubo(){
  for (int j=0;j<8;j+=2){
    for (int i=0;i<20;i++){
      capas(cub[j][0][0],cub[j][0][1],cub[j][0][2],cub[j][0][3],cub[j][0][4]);
      ledWrite(cub[j][1][0],cub[j][1][1],cub[j][1][2],cub[j][1][3]);
      delay(5);
      capas(cub[j+1][0][0],cub[j+1][0][1],cub[j+1][0][2],cub[j+1][0][3],cub[j+1][0][4]);
      ledWrite(cub[j+1][1][0],cub[j+1][1][1],cub[j+1][1][2],cub[j+1][1][3]);
      delay(5);
    }
  }
}

int lCapas1[17][5]={
  {1,0,0,0,0},
  {1,1,0,0,0},
  {1,1,1,0,0},
  {1,1,1,1,0},
  {1,1,1,1,1},
  {0,1,1,1,1},
  {0,0,1,1,1},
  {0,0,0,1,1},
  {0,0,0,0,1},
  {0,0,0,1,1},
  {0,0,1,1,1},
  {0,1,1,1,1},
  {1,1,1,1,1},
  {1,1,1,1,0},
  {1,1,1,0,0},
  {1,1,0,0,0},
  {1,0,0,0,0}
};

int lCapas2[8][5]={
  {1,0,0,0,0},
  {0,1,0,0,0},
  {0,0,1,0,0},
  {0,0,0,1,0},
  {0,0,0,0,1},
  {0,0,0,1,0},
  {0,0,1,0,0},
  {0,1,0,0,0}
};

void capas1(){
  ledWrite(255,255,255,128);
  for (int i=0;i<17;i++){
    capas(lCapas1[i][0],lCapas1[i][1],lCapas1[i][2],lCapas1[i][3],lCapas1[i][4]);
    delay(125);
  }
}

void capas2(){
  ledWrite(255,255,255,128);
  for (int i=0;i<8;i++){
    capas(lCapas2[i][0],lCapas2[i][1],lCapas2[i][2],lCapas2[i][3],lCapas2[i][4]);
    delay(125);
  }
}

void random1(){
  capas(random(2),random(2),random(2),random(2),random(2));
  ledWrite(random(0,256),random(0,256),random(0,256),random(0,256));
  delay(200);
}

void random2(){
  int lcapa[5];
  int nchip=rand() % 4;
  int nbit;
  if (nchip==4){
    nbit=0;
  }
  else{
    nbit=rand() % 8;
  }
  int ncapa=rand() % 5;
  for (int i=0;i<5;i++){
    if (i==ncapa){
      lcapa[i]=1;
    }
    else{
      lcapa[i]=0;
    }
  }
  capas(lcapa[0],lcapa[1],lcapa[2],lcapa[3],lcapa[4]);
  byte byterandom=0;
  for (int i=0;i<8;i++){
    if (i==nbit){
      bitWrite(byterandom,i,1);
    }
    else{
      bitWrite(byterandom,i,0);
    }
  }
  int lchip[4];
  for (int i=0;i<4;i++){
    if (i==nchip){
      lchip[i]=byterandom;
    }
    else{
      lchip[i]=0;
    }
  }
  ledWrite(lchip[0],lchip[1],lchip[2],lchip[3]);
  delay(100);
}

void ledLibre(){
  capas(0,0,0,0,0);
  if (readString.substring(4,5)=="0"){
    ledWrite(0,0,0,0);
  }
  else {
    int nled=readString.substring(4,readString.length()-1).toInt()-1;
    int chip=0;
    int capa=readString.substring(readString.length()-1,readString.length()).toInt()-1;
    while (nled>7){
      nled-=8;
      chip+=1;
    }
    byte cuboselect=0;
    for (int i=0;i<8;i+=1){
      if (i==nled){
        bitWrite(cuboselect,7-i,1);
      }
      else{
        bitWrite(cuboselect,7-i,0);
      }
    }
    int Lchip[4];
    for (int i=0;i<4;i++){
      if (i==chip){
        Lchip[i]=cuboselect;
      }
      else{
        Lchip[i]=0;
      }
    }
    ledWrite(Lchip[0],Lchip[1],Lchip[2],Lchip[3]);
    int Lcapa[5];
    for (int i=0;i<5;i++){
      if (i==capa){
        Lcapa[i]=1;
      }
      else{
        Lcapa[i]=0;
      }
    }
    capas(Lcapa[0],Lcapa[1],Lcapa[2],Lcapa[3],Lcapa[4]);
  }
  delay(5);
}
