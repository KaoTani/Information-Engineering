int ox; // 障害物の左上端のx座標 (ox: object_x)
int oy; // 障害物の左上端のy座標 (oy: object_y)
int cx; // 車の左上端のx座標 (cx: car_x)
int t; // 開始からの時間（フレーム） = 障害物の落下時間
int T; // 開始からの時間（フレーム）（開始からの時間をリセットせずにカウント）
float sec; // 開始からの時間（秒）

// あとで変更する可能性がある変数はパラメータ化しておくと便利．
int speed = 10; // 落下速度 = フレームレート
int ow = 30; // 障害物の幅
int oh = 30; // 障害物の高さ
int cw = 120; // 車の幅
int ch = 30; // 車の高さ

void setup() {
  size(500, 500);
  t=0;
  T=0;
  sec=0;
  ox=int(random(width-ow)); // windowの幅の中に障害物が入る範囲
  frameRate(speed);
}

void draw() {
   color c1 = color(251, 190, 131);
  color c2 = color(208, 98, 16);
  for(float h = 0; h < height; h += 5){
      color c = lerpColor(c1, c2, width-ch / width);
  background(200, 200, 200);
  t = t+1;
  T = T+1;
  oy = speed*t; // 落下速度*開始からの時間 = 時刻tでの障害物の高さ．

  // 障害物の描画
  if (oy > height) { // oyの値が障害物の上部の高さと等しいので，windowの高さを超えたらtとoxを初期化する．
    t = 0;
    ox=int(random(width-ow)); // windowの幅の中に障害物が入る範囲
  }
  fill(255, 255, 255);
  rect(ox, oy, ow, oh); // 障害物の描画を実行

  // 車の描画
  cx = mouseX; // マウスポインタのx座標の取得
  if ((cx+cw) > width) { // 車の右端（px+pw）の座標がウィンドウの幅（width）よりも大きければ車の幅（cw）だけ左に戻す．
    cx = width - cw;
  }
  fill(255, 184, 113);
  rect(cx, width-ch, cw, ch, 0, 0, 100, 100); // 車の描画を実行

  // 衝突判定
  // x軸方向の条件: (ox < cx+cw && ox+ow > cx)
  // y軸方向の条件: (oy+oh > height-ch && oy < height)
  if ((ox < cx+cw && ox+ow > cx)&&(oy+oh > height-ch && oy < height)) { // 衝突した場合
    // 衝突した物体の初期化
    t = 0;
    oy = 0;
    ox=int(random(width-ow)); // windowの幅の中に障害物が入る範囲

    fill(255, 0, 0);
    T = 0;
  } else { // 衝突しない場合
      fill(c);
  }
  rect(cx, width-ch, cw, ch, 0, 0, 100, 100);
  
      rect(0, h, 5, height);
  // 衝突判定後にもう一度車の描画を実行（衝突している場合は色が変わる）

  // ゲームのプレイ時間の描画
  textSize(20);
  fill(0, 0, 0);
  sec = (float)T/speed; // フレームレートから秒への変換．フレームレート = 1秒間の描画回数．
  text("Time: "+sec+" [sec]", 0, 20);
}
