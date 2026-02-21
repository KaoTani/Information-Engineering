int cx; // 車の左上端のx座標（cx: car_x）
int cw = 30; // 車の幅（cw: car_width）
int ch = 30; // 車の高さ（ch: car_height）

void setup() {
  size(300,300);
  frameRate(10);
}
void draw() {
  background(200,200,200);
  cx = mouseX;
  //車の右端（cx+cw）の座標ｇウィンドウの幅（width）よりも大きければ車の幅（cw）だけ左に戻す
  if(cx+cw > width){
    cx = width - cw;
  }
  rect(cx, 270, 30, 30);
}
