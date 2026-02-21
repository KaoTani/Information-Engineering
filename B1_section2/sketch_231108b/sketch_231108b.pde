int ox; // 障害物の左上端のx座標（ox: object_x）
int oy; // 障害物の左上端のy座標（oy: object_y）
int cx; // 車の左上端のx座標（cx: car_x）
int t; // 開始からの時間（フレーム）= 障害物の落下時間
int T; // 開始からの時間（フレーム）（開始からの時間をリセットせずにカウント）
float sec;  // 開始からの時間（秒）

// あとで変更する可能性がある変数はパラメーター化しておくと便利。
int speed = 10; // 落下速度 = フレームレート
int ow = 30; // 障害物の幅
int oh = 30; // 障害物の高さ
int cw = 30; // 車の幅（cw: car_width）
int ch = 30; // 車の高さ（ch: car_height）

void setup() {
  size(300,300);
  t=0;
  T=0;
  sec=0;
  ox=int(random(width-ow)); // windowの幅の中に障害物が入る範囲
  frameRate(speed);
}
void draw() {
  background(200,200,200);
  t = t+1; 
  T = T+1;
  oy = speed * t; // 落下速度*開始からの時間 = 時刻tでの障害物の高さ
  
  // 障害物の描画
  // oyの値が障害物の上部の高さと等しいので、windowの高さを超えたらtとoxを初期化する。
  if(oy > height) {
    t=0;
    ox=int(random(width-ow)); // windowの幅の中に障害物が入る範囲
  }
  fill(255,255,255);
  rect(ox, oy, ow, oh);
  
  // 車の描画
  cx = mouseX;
  //車の右端（cx+cw）の座標ｇウィンドウの幅（width）よりも大きければ車の幅（cw）だけ左に戻す
  if(cx+cw > width){
    cx = width - cw;
  }
  fill(255,255,255);
  rect(cx, width-ch, cw, ch);
  
  //　衝突判定
  // x軸方向の条件:（ox < cx+cw && ox+ow > cx）
  // y軸方向の条件:（oy+oh > height-ch && oy < height）
if(ox < cx+cw && ox+ow > cx && oy+oh > height-ch && oy < height){
  fill(255,0,0);}
else{fill(255,255,255);}
  rect(cx, width-ch, cw, ch);
  
  // ゲームのプレイ時間の表示
textSize(24);
fill(0,0,0);
sec = T/(float)speed; // フレームレートから秒への変換．フレームレート = 1秒間の描画回数。
text("Time: "+sec+" [sec]", 0, 20);
}
