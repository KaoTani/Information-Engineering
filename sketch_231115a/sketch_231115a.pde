/* int ox1; // 1個目　// 障害物の左上端のx座標 (ox: object_x)
int oy1; // 障害物の左上端のy座標 (oy: object_y)
int t1; // 開始からの時間（フレーム） = 障害物の落下時間
int oWait1; // 待機時間
int ox2; //　2個目
int oy2; 
int t2;
int oWait2; // 待機時間
int ox3; //　2個目
int oy3;
int t3; */

//1次元配列で変数をまとめる
//配列の大きさが固定であれば、数値で指定もOK
//int [] ox = new int[3]
int n0bj = 500; //落下する障害物の和
int [] ox = new int[n0bj];
int [] oy = new int[n0bj];
int [] t = new int[n0bj]; //障害物の落下時間
int [] oWait = new int[n0bj]; //障害物ぼ落下タイミング調整用

// あとで変更する可能性がある変数はパラメータ化しておくと便利．
int speed = 10; // 落下速度 = フレームレート
int ow = 30; // 障害物の幅
int oh = 30; // 障害物の高さ

/* void setup() {
  size(300, 300);
  t1=0; // 1個目
  ox1=int(random(width-ow)); // windowの幅の中に障害物が入る範囲
  oWait1=int(random(10,50));
  t2=0; // 2個目
  ox2=int(random(width-ow));
  oWait2=int(random(10,50));
  t3=0; // 3個目
  ox3=int(random(width-ow));
  oWait3=int(random(10,50));
  frameRate(speed);
} */

void setup(){
  size(300,300);
  //障害物の個数分だけ初期化
  for(int i=0;i<n0bj;i++){
    t[i]=0;
    ox[i]=int(random(width-ow)); // windowの幅の中に障害物が入る範囲
    oWait[i]=int(random(10,50)); //障害物落下の待機時間
  }
  frameRate(speed);
}

/* void draw() {
  background(200, 200, 200);
  t1 = t1+1; // 1個目
  oy1 = speed*t1; // 落下速度*開始からの時間 = 時刻tでの障害物の高さ
  t2 = t2+1; // 2個目
  oy2 = speed*t2;
  t3 = t3+1; // 2個目
  oy3 = speed*t3;

  // oyの値が障害物の上部の高さと等しいので，windowの高さを超えたらtとoxを初期化する．
  // 1個目
  if (oy1 > height) {
    t1 = 0;
    ox1=int(random(width-ow)); // windowの幅の中に障害物が入る範囲
    //再度、待機時間を乱数で初期化
     oWait1 = int(random(10,50));
  }
  rect(ox1, oy1, ow, oh);
  println(oy1);
  
   // 2個目
  if (oy2 > height) {
    t2 = 0;
    ox2=int(random(width-ow));
    oWait2 = int(random(10,50));
  }
  rect(ox2, oy2, ow, oh);
  println(oy2);
  
   // 3個目
  if (oy3 > height) {
    t3= 0;
    ox3=int(random(width-ow));
    oWait3 = int(random(10,50));
  }
  rect(ox3, oy3, ow, oh);
  println(oy3);
} */

void draw() {
  background(200, 200, 200);
  for(int i=0;i<n0bj;i++){
  t[i] = t[i]+1; // 1個目
  oy[i] = speed*(t[i]-oWait[i]); // 落下速度*(開始からの時間-待機時間) = 時刻tでの障害物の高さ
  if (oy[i] > height) {
    t[i] = 0;
    ox[i]=int(random(width-ow)); // windowの幅の中に障害物が入る範囲
    oWait[i] = int(random(10,50)); //障害物落下の待機時間
    }
    rect(ox[i], oy[i], ow, oh);
  }
  println(oy[0], oy[1], oy[2]);
}
