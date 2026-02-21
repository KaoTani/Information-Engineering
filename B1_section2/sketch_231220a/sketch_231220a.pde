/* //演習❶
float vy; //下向きを正とした速度
int ox; //物体の左上端の座標 x
float oy; //物体の左上端の座標 y
void setup() {
size(400, 400);
vy = 0;
ox = 200;
oy = 100;
frameRate(100);
}
void draw() {
background(200, 200, 200);
line(0, 300, 400, 300);
rect(ox, oy, 30, 30);
vy = vy + 0.2;
oy = oy + vy;
if (oy > 300 - 30) {
oy = 300 - 30;
vy = -vy;
}
}*/


/*　//演習❷
int vx; //右向きを正とした速度
int vy; //下向きを正とした速度
int ox; //物体の左上端の座標 x
int oy; //物体の左上端の座標 y
void setup() {
size(400, 400);
vx = 4;
vy = 0;
ox = 100;
oy = 100;
frameRate(10);
}
void draw() {
background(200, 200, 200);
rect(100, 100, 200, 200);
fill(200, 200, 200);
rect(ox, oy, 30, 30);
vy = vy + 2;
oy = oy + vy;
if (oy > 300 - 30) {
oy = 300 - 30;
vy = -vy;
}
ox = ox + vx;
if(ox < 100 || ox > 270){
  vx = -vx;
} 
}
*/

/* //演習❸
int f; //フレーム番号
float x; //ボールの中心の座標 x
float y; //ボールの中心の座標 y
void setup(){
  size(400, 400);
  f = 0;
  x = 300.0;
  y = 200.0;
  frameRate(10);
}
void draw(){
 background(200, 200, 200);
 ellipse(x, y, 30, 30);
 line(200, 200, x, y);
 f = f + 1;
 x = 200 + 100 * cos(0.05 * f);
 y = 200 + 100 * sin(0.05 * f);
}
*/

/*
//ローディング
int f; //フレーム番号
float[] xx1 = new float[5]; //残像用 x
float[] yy1 = new float[5]; //残像用 y
float x1; //ボールの中心の座標 x
float y1; //ボールの中心の座標 y
float[] xx2 = new float[5]; //残像用 x
float[] yy2 = new float[5]; //残像用 y
float x2; //ボールの中心の座標 x
float y2; //ボールの中心の座標 y
float[] xx3 = new float[5]; //残像用 x
float[] yy3 = new float[5]; //残像用 y
float x3; //ボールの中心の座標 x
float y3; //ボールの中心の座標 y
void setup() {
size(400, 400);
f = 0;
for (int i = 0; i < 5; i++) {
xx1[i] = 300.0;
yy1[i] = 200.0;
xx2[i] = 300.0 * cos(0.5);
yy2[i] = 200.0 * sin(0.5);
xx3[i] = 300.0 * cos(1);
yy3[i] = 200.0 * sin(1);
}
x1 = 300.0;
y2 = 200.0;
x2 = 300.0 * cos(0.5);
y2 = 200.0 * sin(0.5);
x3 = 300.0 * cos(1);
y3 = 200.0 * sin(1);
noStroke(); //枠線を描画しない
frameRate(100);
}
void draw() {
background(255, 255, 255);
for (int i = 0; i < 5; i++) {
fill(250 - 20 * i, 250 - 20 * i, 250 - 20 * i);
ellipse(xx1[4 - i], yy1[4 - i], 30, 30);
}
fill(0, 0, 0);
ellipse(x1, y1, 30, 30);
for (int i = 0; i < 5; i++) {
fill(250 - 20 * i, 250 - 20 * i, 250 - 20 * i);
ellipse(xx2[4 - i], yy2[4 - i], 30, 30);
}
fill(20, 20, 20);
ellipse(x2, y2, 30, 30);
for (int i = 0; i < 5; i++) {
fill(250 - 20 * i, 250 - 20 * i, 250 - 20 * i);
ellipse(xx3[4 - i], yy3[4 - i], 30, 30);
}
fill(40, 40, 40);
ellipse(x3, y3, 30, 30);
f = f + 1;
x1 = 200 + 100 * cos(0.05 * f);
y1 = 200 + 100 * sin(0.05 * f);
x2 = 200 + 100 * cos(0.5 + 0.05 * f);
y2 = 200 + 100 * sin(0.5 + 0.05 * f);
x3 = 200 + 100 * cos(1 + 0.05 * f);
y3 = 200 + 100 * sin(1 + 0.05 * f);
for (int i = 0; i < 4; i++) {
xx1[4 - i] = xx1[4 - i - 1];
yy1[4 - i] = yy1[4 - i - 1];
xx2[4 - i] = xx2[4 - i - 1];
yy2[4 - i] = yy2[4 - i - 1];
xx3[4 - i] = xx3[4 - i - 1];
yy3[4 - i] = yy3[4 - i - 1];
}
xx1[0] = x1;
yy1[0] = y1;
xx2[0] = x2;
yy2[0] = y2;
xx3[0] = x3;
yy3[0] = y3;
}*/


/* //演習❹の①
float vy; //下向きを正とした速度
int ox; //物体の左上端の座標 x
float oy; //物体の左上端の座標 y
float[] yy = new float[5]; //残像用 y
void setup() {
size(400, 400);
vy = 0;
ox = 200;
oy = 100;
for (int i = 0; i < 5; i++) {
  yy[i] = 100;
}
frameRate(100);
}
void draw() {
background(200, 200, 200);
line(0, 300, 400, 300);
vy = vy + 0.2;
oy = oy + vy;
if (oy > 300 - 30) {
oy = 300 - 30;
vy = -vy;
}
for (int i = 0; i < 5; i++) {
fill(125 - 10 * i);
rect(ox, yy[4 - i], 30, 30);
}
fill(0);
rect(ox, oy, 30, 30);
for (int i = 0; i < 4; i++) {
yy[4 - i] = yy[4 - i - 1];
}
yy[0] = oy;
} */

//演習❹の②
float vx; //右向きを正とした速度
float vy; //下向きを正とした速度
float ox; //物体の左上端の座標 x
float oy; //物体の左上端の座標 y
float[] xx = new float[5]; //残像用 x
float[] yy = new float[5]; //残像用 y
void setup() {
size(400, 400);
vx = 4.0;
vy = 0.0;
ox = 0;
oy = 100.0;
for (int i = 0; i < 5; i++) {
  xx[i] = 0;
  yy[i] = 100;
}
frameRate(10);
}
void draw() {
background(200, 200, 200);
for (int i = 0; i < 5; i++) {
  fill(95 + i * 40, 175 + i * 20, 175 + i * 20);
  rect(xx[4 - i], yy[4 - i], 30, 30);
}
fill(255);
rect(ox, oy, 30, 30);
if(ox<0 || ox>400-30){
  vx = -vx;
}
ox = ox + vx;
if (oy > 300.0 - 30.0) {
vy = -vy;
} else {
vy = vy + 200.0 * 0.1;
}
oy = oy + vy * 0.1;
for (int i = 0; i < 4; i++) {
yy[4 - i] = yy[4 - i - 1];
xx[4 - i] = xx[4 - i - 1];
}
xx[0] = ox;
yy[0] = oy;
}
