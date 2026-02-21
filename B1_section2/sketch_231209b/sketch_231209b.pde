/*
String scene; //まずはスタート
int speed=10; //落下速度＝フレームレート
int time; //スタート画面を付けてからの時間
int T; //ゲーム開始からの時間
int cx; //下バンズの左上のx座標
int cy=500; //下バンズの左上のx座標
int cw=217; //下バンズの横幅は217
int ch=100; //下バンズの縦幅は100
//1：ハンバーグ、2：チーズ、3：草、4：トマト
int ox1; //左上のx座標
float oy1; //左上のy座標
int t1;
int oWait1; // 待機時間
int ox2; //左上のx座標
float oy2; //左上のy座標
int t2;
int oWait2; // 待機時間
int ox3; //左上のx座標
float oy3; //左上のy座標
int t3;
int oWait3; // 待機時間
int ox4; //左上のx座標
float oy4; //左上のy座標
int t4;
int oWait4; // 待機時間
int ow1=173; //　ハンバーグの横幅は217
int oh1=80; // ハンバーグの縦幅は100
int ow2=217; //　チーズの横幅は217
int oh2=100; // チーズの縦幅は100
int ow3=217; //　草の横幅は217
int oh3=100; // 草の縦幅は100
int ow4=217; //　トマトの横幅は217
int oh4=100; // トマトの縦幅は100
int j ;
int hitY; //重なった一番上
int kaisu1; //1枚目
int kaisu2; 
int kaisu3;  
int sec;
int dx; //上バンズのx座標
int dy; //上バンズのy座標
int dw=173;
int dh=80;

void setup() {
  size(700, 700);
  frameRate(speed);
  scene = "start";
  j = int(random(10));
   time = 0;
  T = 0;
  t1 = 0; // ハンバーグ
  ox1 = int(random(50, 650-ow1));
  oWait1 =int(random(10, 50)); // 待機時間を乱数で初期化
  t2 = 0; // チーズ
  ox2 = int(random(50, 650-ow2));
  oWait2 =int(random(10, 50)); // 待機時間を乱数で初期化
  t3 = 0; // 草
  ox3 = int(random(50, 650-ow3));
  oWait3 =int(random(10, 50)); // 待機時間を乱数で初期化
  t4 = 0; // トマト
  ox4 = int(random(50, 650-ow4));
  oWait4 =int(random(10, 50)); // 待機時間を乱数で初期化
  hitY=0; //まずは下バンズの真ん中
  kaisu1=0;
  kaisu2=0;
  kaisu3=0;
}

void draw() {
  if (scene == "start") {
    start_scene();
  } else if (scene == "game") {
    game_scene();
  } else if (scene == "clear") {
    clear_scene();
  } else if (scene == "thinking") {
    thinking_scene();
  } else if (scene == "fail") {
    fail_scene();
  } else if (scene == "prepare"){
    prepare_scene();
  }else if(scene == "setup"){
    setup_scene();
  }
}

void setup_scene(){
  j = int(random(10));
  time = 0;
  T = 0;
  t1 = 0; // ハンバーグ
  ox1 = int(random(50, 650-ow1));
  oWait1 =int (random(40)); // 待機時間を乱数で初期化
  t2 = 0; // チーズ
  ox2 = int(random(50, 650-ow2));
  oWait2 =int(random(10, 50)); // 待機時間を乱数で初期化
  t3 = 0; // 草
  ox3 = int(random(50, 650-ow3));
  oWait3 =int(random(10, 50)); // 待機時間を乱数で初期化
  t4 = 0; // トマト
  ox4 = int(random(50, 650-ow4));
  oWait4 =int(random(10, 50)); // 待機時間を乱数で初期化
  hitY=0; //まずは下バンズの真ん中
  kaisu1=0;
  kaisu2=0;
  kaisu3=0;
  vy = 0;
  if(time==0){
    scene = "start";}
}

void start_scene() { // スタートシーンの処理
  background(113, 192, 216); //背景水色
  stroke(255);
  rect(25, 25, 650, 650); //背景②白色
  PImage photo1 = loadImage("start_background.jpg");
  image(photo1, 50, 50, 600, 600); //スタート画面のまめっち
  time = time + 1; //時間が進む
  if (time % 8 == 0 || time % 8 == 1 || time % 8 == 2 || time % 8 == 3) {
  PImage photo3 = loadImage("press_start.png");
  image(photo3, 177, 570, 330, 70);
  }  //ゆっくりめに「ボタンをおしてね」が点滅
}

void mousePressed() {  // ゲームシーンへ遷移
  if (scene == "start") scene = "prepare";
  else if (scene == "prepare") scene = "game";
  if (scene == "clear" || scene == "fail") scene = "setup";
}

void prepare_scene(){
  background(113, 192, 216); //背景水色
  stroke(255);
  rect(25, 25, 650, 650); //背景②白色
    if(j == 0){
      PImage ham1 = loadImage("無題26_20231211173738.png");
    image(ham1, 50, -30, 600, 600); 
  }else if(j == 1){
    PImage ham2 = loadImage("無題26_20231211173847.png");
    image(ham2, 50, -30, 600, 600); 
  }else if(j == 2){
     PImage ham3 = loadImage("無題26_20231211173946.png");
   image(ham3, 50, -30, 600, 600);
  }else if(j == 3){
    PImage ham4 = loadImage("無題26_20231211174050.png");
   image(ham4, 50, -30, 600, 600);
  }else if(j == 4){
     PImage ham5 = loadImage("無題26_20231211174144.png");
   image(ham5, 50, -30, 600, 600);
   }else if(j == 5){
     PImage ham6 = loadImage("無題26_20231211174250.png");
   image(ham6, 50, -30, 600, 600);
   }else if(j == 6){
     PImage ham7 = loadImage("無題26_20231211174300.png");
   image(ham7, 50, -30, 600, 600);
   }else if(j == 7){
     PImage ham8 = loadImage("無題26_20231213124813.png");
   image(ham8, 50, -30, 600, 600);
   }else if(j == 8){
     PImage ham9 = loadImage("無題26_20231213124918.png");
   image(ham9, 50, -30, 600, 600);
   }else if(j == 9){
     PImage ham10 = loadImage("無題26_20231213125007.png");
   image(ham10, 50, -30, 600, 600);
   }
   PImage moji = loadImage("無題27_20231211181842.png");
   image(moji,160, 500, 400, 70); 
}

void game_scene() { // ゲームシーンの処理
  PImage photo2 = loadImage("game_background.jpg");
  image(photo2, 50, 50, 600, 600);//ゲーム背景

  //落下物について
  PImage Ingre1 = loadImage("hamburg.png");
  PImage Ingre2 = loadImage("cheese.png");
  PImage Ingre3 = loadImage("grass.png");
  PImage Ingre4 = loadImage("tomato.png");

  t1 = t1+1; // ハンバーグ
  oy1 = 50 + speed * (t1 - oWait1);
  if (oy1 + 100 > 0){
    oy1 = oy1 + 150;
  }  
  if (oy1 + 100 > 650) {
    t1 = 0;
    oy1 = oy1 + 200; 
    ox1 = int(random(50, 650-ow1));
    oWait1 = int(random(10, 50)); // 再度，待機時間を乱数で初期化
  }
  image(Ingre1, ox1, oy1, ow1, oh1); 
  
  t2 = t2+1; // チーズ
  oy2 = 50 + speed * (t2 - oWait2);
  if (oy2 + 100 > 0){
    oy2 = oy2 + 150;
  }  
  if (oy2 + 100 > 650) {
    t2 = 0;
    oy2 = oy2 + 200; 
    ox2 = int(random(50, 650-ow2));
    oWait2 = int(random(10, 50)); // 再度，待機時間を乱数で初期化
  }
  image(Ingre2, ox2, oy2, ow2, oh2); 
  
  t3 = t3+1; // 草
  oy3 = 50 + speed * (t3 - oWait3);
  if (oy3 + 100 > 0){
    oy3 = oy3 + 150;
  }  
  if (oy3 + 100 > 650) {
    t3 = 0;
    oy3 = oy3 + 200; 
    ox3 = int(random(50, 650-ow3));
    oWait3 = int(random(10, 50)); // 再度，待機時間を乱数で初期化
  }
  image(Ingre3, ox3, oy3, ow3, oh3); 
  
  t4 = t4+1; // トマト
  oy4 = 50 + speed * (t4 - oWait4);
  if (oy4 + 100 > 0){
    oy4 = oy4 + 150;
  }  
  if (oy4 + 100 > 650) {
    t4 = 0;
    oy4 = oy4 + 200; 
    ox4 = int(random(50, 650-ow4));
    oWait4 = int(random(10, 50)); // 再度，待機時間を乱数で初期化
  }
  image(Ingre4, ox4, oy4, ow4, oh4); 
  
    //下バンズ移動
  cx = mouseX - cw / 2;
  if ((cx+cw)>650) {//ゲーム背景を右にはみ出さないように
    cx = 650 - cw;
  }
  if (cx<50) {//ゲーム背景を左にはみ出さなように
    cx = 50;
  }
  PImage photo4 = loadImage("buns_under.png");
  image(photo4, cx, cy, cw, ch); //下バンズ設置
  
  //解答例提示
  PImage huki =loadImage("hukidashi.png");
  image(huki, -20, -30, 320, 306);
  if(j == 0){
  PImage ham1 = loadImage("無題26_20231211173738.png");
  image(ham1, -10, -40, 300, 300); 
  }else if(j == 1){
    PImage ham2 = loadImage("無題26_20231211173847.png");
    image(ham2, -10, -40, 300, 300); 
  }else if(j == 2){
    PImage ham3 = loadImage("無題26_20231211173946.png");
   image(ham3, -10, -40, 300, 300);
  }else if(j == 3){
    PImage ham4 = loadImage("無題26_20231211174050.png");
   image(ham4, -10, -40, 300, 300);
  }else if(j == 4){
    PImage ham5 = loadImage("無題26_20231211174144.png");
   image(ham5, -10, -40, 300, 300);
   }else if(j == 5){
     PImage ham6 = loadImage("無題26_20231211174250.png");
   image(ham6, -10, -40, 300, 300);
   }else if(j == 6){
     PImage ham7 = loadImage("無題26_20231211174300.png");
   image(ham7, -10, -40, 300, 300);
   }else if(j == 7){
     PImage ham8 = loadImage("無題26_20231213124813.png");
   image(ham8,  -10, -40, 300, 300);
   }else if(j == 8){
     PImage ham9 = loadImage("無題26_20231213124918.png");
   image(ham9,  -10, -40, 300, 300);
   }else if(j == 9){
     PImage ham10 = loadImage("無題26_20231213125007.png");
   image(ham10,  -10, -40, 300, 300);
   }
   
   //当たり判定
     //1枚目
if(hitY == 0){
   if(ox1-cx<=50 && cx-ox1<=50 && oy1+20==cy){
     kaisu1 = 1;
    image(Ingre1, cx+cw/2-ow1/2, cy-20, ow1, oh1);
     hitY=1;
   }else if(ox2-cx<=40 && cx-ox2<=40 && oy2+20==cy){
     kaisu1 = 2;
     image(Ingre2, cx, cy-25, ow2, oh2);
     hitY=1;
   }else if(ox3-cx<=40 && cx-ox3<=40 && oy3+20==cy){
     kaisu1 = 3;
     image(Ingre3, cx, cy-30, ow3, oh3);
     hitY=1;
   }else if(ox4-cx<=40 && cx-ox4<=40 && oy4+20==cy){
     kaisu1 = 4;
     image(Ingre4, cx, cy-30, ow4, oh4);
     hitY=1;
   }}
   
   if(kaisu1 == 1){
    image(Ingre1, cx+cw/2-ow1/2, cy-20, ow1, oh1);
   }else if(kaisu1 == 2){
     image(Ingre2, cx, cy-25, ow2, oh2);
   }else if(kaisu1 == 3){
     image(Ingre3, cx, cy-25, ow3, oh3);
   }else if(kaisu1 == 4){
     image(Ingre4, cx, cy-30, ow4, oh4);
   }
   
   if(hitY == 1){ //２枚目
   if(ox1-cx<=50 && cx-ox1<=50 && oy1+40==cy){
      kaisu2 = 1;
      image(Ingre1, cx+cw/2-ow1/2, cy-50, ow1, oh1);
      hitY=2;
   }else if(ox2-cx<=40 && cx-ox2<=40 && oy2+40==cy){
     kaisu2 = 2;
     image(Ingre2, cx, cy-50, ow2, oh2);
     hitY=2;
   }else if(ox3-cx<=40 && cx-ox3<=40 && oy3+40==cy){
     kaisu2 = 3;
     image(Ingre3, cx, cy-50, ow3, oh3);
     hitY=2;
   }else if(ox4-cx<=40 && cx-ox4<=40 && oy4+40==cy){
     kaisu2 = 4;
     image(Ingre4, cx, cy-50, ow4, oh4);
     hitY=2;
   }}
   
 if(hitY!=0){  
   if(kaisu2 == 1){
      image(Ingre1, cx+cw/2-ow1/2, cy-50, ow1, oh1);
   }else if(kaisu2 == 2){
     image(Ingre2, cx, cy-50, ow2, oh2);
   }else if(kaisu2 == 3){
     image(Ingre3, cx, cy-50, ow3, oh3);
   }else if(kaisu2 == 4){
     image(Ingre4, cx, cy-50, ow4, oh4);
   }}
   
   if(hitY == 2){ //３枚目
     if(ox1-cx<=50 && cx-ox1<=50 && oy1+60==cy){
     kaisu3 = 1;
     image(Ingre1, cx+cw/2-ow1/2, cy-75, ow1, oh1);
     hitY=3;
   }else if(ox2-cx<=40 && cx-ox2<=40 && oy2+60==cy){
     kaisu3 = 2;
     image(Ingre2, cx, cy-75, ow2, oh2);
     hitY=3;
   }else if(ox3-cx<=40 && cx-ox3<=40 && oy3+60==cy){
     kaisu3 = 3;
     image(Ingre3, cx, cy-75, ow3, oh3);
     hitY=3;
   }else if(ox4-cx<=40 && cx-ox4<=40 && oy4+60==cy){
     kaisu3 = 4;
      image(Ingre4, cx, cy-75, ow4, oh4);
      hitY=3;
   } }
   
     if(kaisu3 == 1){
     image(Ingre1, cx+cw/2-ow1/2, cy-75, ow1, oh1);
   }else if(kaisu3 == 2){
     image(Ingre2, cx, cy-75, ow2, oh2);
   }else if(kaisu3 == 3){
     image(Ingre3, cx, cy-75, ow3, oh3);
   }else if(kaisu3 == 4){
      image(Ingre4, cx, cy-75, ow4, oh4);
   }
   
   if(hitY==3){
     T = T + 1;
     sec = T /(speed);
     dx=cx+12;
      dy = cy-100;
     PImage photo5 = loadImage("buns_over.png");
     image(photo5, dx, dy,dw,dh);
       if(sec==2){
         hitY=4;
       }
     }
     
     if(hitY==4){
        scene = "thinking";
     }
   }



void clear_scene() {
  // クリアシーンの処理
  background(113, 192, 216); //背景水色
  stroke(255);
  rect(25, 25, 650, 650); //背景②白色
  PImage clear = loadImage("S__258531343_0.jpg");
  image(clear, 50, 50, 600, 600);
}

void fail_scene() {
  //失敗処理
  background(113, 192, 216); //背景水色
  stroke(255);
  rect(25, 25, 650, 650); //背景②白色
  PImage fail = loadImage("S__258531344_0.jpg");
  image(fail, 50, 50, 600, 600);
}

void thinking_scene() {
  //ハンバーガーつくり中
  background(113, 192, 216); //背景水色
  stroke(255);
  rect(25, 25, 650, 650); //背景②白色
  T = T + 1;
  PImage think = loadImage("thinking.jpg");
  image(think, 50, 50, 600, 600);
  sec = T /(speed);
  
  if(j==0){
    if(kaisu1==2 && kaisu2==1 && kaisu3==4){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==1){
    if(kaisu1==2 && kaisu2==4 && kaisu3==1){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==2){
  if(kaisu1==1 && kaisu2==2 && kaisu3==4){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==3){
    if(kaisu1==1 && kaisu2==4 && kaisu3==3){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==4){
    if(kaisu1==3 && kaisu2==1 && kaisu3==4){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==5){
    if(kaisu1==1 && kaisu2==3 && kaisu3==2){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==6){
    if(kaisu1==3 && kaisu2==1 && kaisu3==2){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==7){
    if(kaisu1==3 && kaisu2==2 && kaisu3==1){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==8){
    if(kaisu1==2 && kaisu2==3 && kaisu3==4){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==9){
    if(kaisu1==2 && kaisu2==4 && kaisu3==3){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }

}
*/

String scene; //まずはスタート
int speed=10; //落下速度＝フレームレート
float vy; // 加速するスピード
int time; //スタート画面を付けてからの時間
int T; //ゲーム開始からの時間
int cx; //下バンズの左上のx座標
int cy=500; //下バンズの左上のx座標
int cw=217; //下バンズの横幅は217
int ch=100; //下バンズの縦幅は100
//1：ハンバーグ、2：チーズ、3：草、4：トマト
int ox1; //左上のx座標
float oy1; //左上のy座標
float t1;
int oWait1; // 待機時間
int ox2; //左上のx座標
float oy2; //左上のy座標
int t2;
int oWait2; // 待機時間
int ox3; //左上のx座標
float oy3; //左上のy座標
int t3;
int oWait3; // 待機時間
int ox4; //左上のx座標
float oy4; //左上のy座標
int t4;
int oWait4; // 待機時間
int ow1=173; //　ハンバーグの横幅は217
int oh1=80; // ハンバーグの縦幅は100
int ow2=217; //　チーズの横幅は217
int oh2=100; // チーズの縦幅は100
int ow3=217; //　草の横幅は217
int oh3=100; // 草の縦幅は100
int ow4=217; //　トマトの横幅は217
int oh4=100; // トマトの縦幅は100
int j ;
int hitY; //重なった一番上
int kaisu1; //1枚目
int kaisu2; 
int kaisu3;  
int sec;
int dx; //上バンズのx座標
int dy; //上バンズのy座標
int dw=173;
int dh=80;

void setup() {
  size(700, 700);
  frameRate(speed);
  scene = "start";
  j = int(random(10));
   time = 0;
  T = 0;
  t1 = 0; // ハンバーグ
  ox1 = int(random(50, 650-ow1));
  oWait1 =int(random(10, 50)); // 待機時間を乱数で初期化
  t2 = 0; // チーズ
  ox2 = int(random(50, 650-ow2));
  oWait2 =int(random(10, 50)); // 待機時間を乱数で初期化
  t3 = 0; // 草
  ox3 = int(random(50, 650-ow3));
  oWait3 =int(random(10, 50)); // 待機時間を乱数で初期化
  t4 = 0; // トマト
  ox4 = int(random(50, 650-ow4));
  oWait4 =int(random(10, 50)); // 待機時間を乱数で初期化
  hitY=0; //まずは下バンズの真ん中
  kaisu1=0;
  kaisu2=0;
  kaisu3=0;
  vy = 0;
}

void draw() {
  if (scene == "start") {
    start_scene();
  } else if (scene == "game") {
    game_scene();
  } else if (scene == "clear") {
    clear_scene();
  } else if (scene == "thinking") {
    thinking_scene();
  } else if (scene == "fail") {
    fail_scene();
  } else if (scene == "prepare"){
    prepare_scene();
  }else if(scene == "setup"){
    setup_scene();
  }
}

void setup_scene(){
  j = int(random(10));
  time = 0;
  T = 0;
  t1 = 0; // ハンバーグ
  ox1 = int(random(50, 650-ow1));
  oWait1 =int (random(40)); // 待機時間を乱数で初期化
  t2 = 0; // チーズ
  ox2 = int(random(50, 650-ow2));
  oWait2 =int(random(10, 50)); // 待機時間を乱数で初期化
  t3 = 0; // 草
  ox3 = int(random(50, 650-ow3));
  oWait3 =int(random(10, 50)); // 待機時間を乱数で初期化
  t4 = 0; // トマト
  ox4 = int(random(50, 650-ow4));
  oWait4 =int(random(10, 50)); // 待機時間を乱数で初期化
  hitY=0; //まずは下バンズの真ん中
  kaisu1=0;
  kaisu2=0;
  kaisu3=0;
  vy = 0;
  if(time==0){
    scene = "start";}
}

void start_scene() { // スタートシーンの処理
  background(113, 192, 216); //背景水色
  stroke(255);
  rect(25, 25, 650, 650); //背景②白色
  PImage photo1 = loadImage("start_background.jpg");
  image(photo1, 50, 50, 600, 600); //スタート画面のまめっち
  time = time + 1; //時間が進む
  if (time % 8 == 0 || time % 8 == 1 || time % 8 == 2 || time % 8 == 3) {
  PImage photo3 = loadImage("press_start.png");
  image(photo3, 177, 570, 330, 70);
  }  //ゆっくりめに「ボタンをおしてね」が点滅
}

void mousePressed() {  // ゲームシーンへ遷移
  if (scene == "start") scene = "prepare";
  else if (scene == "prepare") scene = "game";
  if (scene == "clear" || scene == "fail") scene = "setup";
}

void prepare_scene(){
  background(113, 192, 216); //背景水色
  stroke(255);
  rect(25, 25, 650, 650); //背景②白色
    if(j == 0){
      PImage ham1 = loadImage("無題26_20231211173738.png");
    image(ham1, 50, -30, 600, 600); 
  }else if(j == 1){
    PImage ham2 = loadImage("無題26_20231211173847.png");
    image(ham2, 50, -30, 600, 600); 
  }else if(j == 2){
     PImage ham3 = loadImage("無題26_20231211173946.png");
   image(ham3, 50, -30, 600, 600);
  }else if(j == 3){
    PImage ham4 = loadImage("無題26_20231211174050.png");
   image(ham4, 50, -30, 600, 600);
  }else if(j == 4){
     PImage ham5 = loadImage("無題26_20231211174144.png");
   image(ham5, 50, -30, 600, 600);
   }else if(j == 5){
     PImage ham6 = loadImage("無題26_20231211174250.png");
   image(ham6, 50, -30, 600, 600);
   }else if(j == 6){
     PImage ham7 = loadImage("無題26_20231211174300.png");
   image(ham7, 50, -30, 600, 600);
   }else if(j == 7){
     PImage ham8 = loadImage("無題26_20231213124813.png");
   image(ham8, 50, -30, 600, 600);
   }else if(j == 8){
     PImage ham9 = loadImage("無題26_20231213124918.png");
   image(ham9, 50, -30, 600, 600);
   }else if(j == 9){
     PImage ham10 = loadImage("無題26_20231213125007.png");
   image(ham10, 50, -30, 600, 600);
   }
   PImage moji = loadImage("無題27_20231211181842.png");
   image(moji,160, 500, 400, 70); 
}

void game_scene() { // ゲームシーンの処理
  PImage photo2 = loadImage("game_background.jpg");
  image(photo2, 50, 50, 600, 600);//ゲーム背景

  //落下物について
  PImage Ingre1 = loadImage("hamburg.png");
  PImage Ingre2 = loadImage("cheese.png");
  PImage Ingre3 = loadImage("grass.png");
  PImage Ingre4 = loadImage("tomato.png");

  t1 = t1+1; // ハンバーグ
  oy1 = -oWait1 + t1*t1 ;
  if (oy1 + 100 > 0){
    oy1 = oy1 + 150;
  }  
  if (oy1 + 100 > 650) {
    t1 = 0;
    oy1 = oy1 + 200; 
    ox1 = int(random(50, 650-ow1));
    oWait1 = int(random(10, 50)); // 再度，待機時間を乱数で初期化
  }
  image(Ingre1, ox1, oy1, ow1, oh1); 
  
  t2 = t2+1; // チーズ
  oy2 = -oWait2*2 + t2*t2;
  if (oy2 + 100 > 0){
    oy2 = oy2 + 150;
  }  
  if (oy2 + 100 > 650) {
    t2 = 0;
    oy2 = oy2 + 200; 
    ox2 = int(random(50, 650-ow2));
    oWait2 = int(random(10, 50)); // 再度，待機時間を乱数で初期化
  }
  image(Ingre2, ox2, oy2, ow2, oh2); 
  
  t3 = t3+1; // 草
  oy3 = -oWait3*2 + t3*t3;
  if (oy3 + 100 > 0){
    oy3 = oy3 + 150;
  }  
  if (oy3 + 100 > 650) {
    t3 = 0;
    oy3 = oy3 + 200; 
    ox3 = int(random(50, 650-ow3));
    oWait3 = int(random(10, 50)); // 再度，待機時間を乱数で初期化
  }
  image(Ingre3, ox3, oy3, ow3, oh3); 
  
  t4 = t4+1; // トマト
  oy4 = -oWait4*2 + t4*t4;
  if (oy4 + 100 > 0){
    oy4 = oy4 + 150;
  }  
  if (oy4 + 100 > 650) {
    t4 = 0;
    oy4 = oy4 + 200; 
    ox4 = int(random(50, 650-ow4));
    oWait4 = int(random(10, 50)); // 再度，待機時間を乱数で初期化
  }
  image(Ingre4, ox4, oy4, ow4, oh4); 
  
    //下バンズ移動
  cx = mouseX - cw / 2;
  if ((cx+cw)>650) {//ゲーム背景を右にはみ出さないように
    cx = 650 - cw;
  }
  if (cx<50) {//ゲーム背景を左にはみ出さなように
    cx = 50;
  }
  PImage photo4 = loadImage("buns_under.png");
  image(photo4, cx, cy, cw, ch); //下バンズ設置
  
  //解答例提示
  PImage huki =loadImage("hukidashi.png");
  image(huki, -20, -30, 320, 306);
  if(j == 0){
  PImage ham1 = loadImage("無題26_20231211173738.png");
  image(ham1, -10, -40, 300, 300); 
  }else if(j == 1){
    PImage ham2 = loadImage("無題26_20231211173847.png");
    image(ham2, -10, -40, 300, 300); 
  }else if(j == 2){
    PImage ham3 = loadImage("無題26_20231211173946.png");
   image(ham3, -10, -40, 300, 300);
  }else if(j == 3){
    PImage ham4 = loadImage("無題26_20231211174050.png");
   image(ham4, -10, -40, 300, 300);
  }else if(j == 4){
    PImage ham5 = loadImage("無題26_20231211174144.png");
   image(ham5, -10, -40, 300, 300);
   }else if(j == 5){
     PImage ham6 = loadImage("無題26_20231211174250.png");
   image(ham6, -10, -40, 300, 300);
   }else if(j == 6){
     PImage ham7 = loadImage("無題26_20231211174300.png");
   image(ham7, -10, -40, 300, 300);
   }else if(j == 7){
     PImage ham8 = loadImage("無題26_20231213124813.png");
   image(ham8,  -10, -40, 300, 300);
   }else if(j == 8){
     PImage ham9 = loadImage("無題26_20231213124918.png");
   image(ham9,  -10, -40, 300, 300);
   }else if(j == 9){
     PImage ham10 = loadImage("無題26_20231213125007.png");
   image(ham10,  -10, -40, 300, 300);
   }
   
   //当たり判定
     //1枚目
if(hitY == 0){
   if(ox1-cx<=50 && cx-ox1<=50 && oy1+20==cy){
     kaisu1 = 1;
    image(Ingre1, cx+cw/2-ow1/2, cy-20, ow1, oh1);
     hitY=1;
   }else if(ox2-cx<=40 && cx-ox2<=40 && oy2+20==cy){
     kaisu1 = 2;
     image(Ingre2, cx, cy-25, ow2, oh2);
     hitY=1;
   }else if(ox3-cx<=40 && cx-ox3<=40 && oy3+20==cy){
     kaisu1 = 3;
     image(Ingre3, cx, cy-30, ow3, oh3);
     hitY=1;
   }else if(ox4-cx<=40 && cx-ox4<=40 && oy4+20==cy){
     kaisu1 = 4;
     image(Ingre4, cx, cy-30, ow4, oh4);
     hitY=1;
   }}
   
   if(kaisu1 == 1){
    image(Ingre1, cx+cw/2-ow1/2, cy-20, ow1, oh1);
   }else if(kaisu1 == 2){
     image(Ingre2, cx, cy-25, ow2, oh2);
   }else if(kaisu1 == 3){
     image(Ingre3, cx, cy-25, ow3, oh3);
   }else if(kaisu1 == 4){
     image(Ingre4, cx, cy-30, ow4, oh4);
   }
   
   if(hitY == 1){ //２枚目
   if(ox1-cx<=50 && cx-ox1<=50 && oy1+40==cy){
      kaisu2 = 1;
      image(Ingre1, cx+cw/2-ow1/2, cy-50, ow1, oh1);
      hitY=2;
   }else if(ox2-cx<=40 && cx-ox2<=40 && oy2+40==cy){
     kaisu2 = 2;
     image(Ingre2, cx, cy-50, ow2, oh2);
     hitY=2;
   }else if(ox3-cx<=40 && cx-ox3<=40 && oy3+40==cy){
     kaisu2 = 3;
     image(Ingre3, cx, cy-50, ow3, oh3);
     hitY=2;
   }else if(ox4-cx<=40 && cx-ox4<=40 && oy4+40==cy){
     kaisu2 = 4;
     image(Ingre4, cx, cy-50, ow4, oh4);
     hitY=2;
   }}
   
 if(hitY!=0){  
   if(kaisu2 == 1){
      image(Ingre1, cx+cw/2-ow1/2, cy-50, ow1, oh1);
   }else if(kaisu2 == 2){
     image(Ingre2, cx, cy-50, ow2, oh2);
   }else if(kaisu2 == 3){
     image(Ingre3, cx, cy-50, ow3, oh3);
   }else if(kaisu2 == 4){
     image(Ingre4, cx, cy-50, ow4, oh4);
   }}
   
   if(hitY == 2){ //３枚目
     if(ox1-cx<=50 && cx-ox1<=50 && oy1+60==cy){
     kaisu3 = 1;
     image(Ingre1, cx+cw/2-ow1/2, cy-75, ow1, oh1);
     hitY=3;
   }else if(ox2-cx<=40 && cx-ox2<=40 && oy2+60==cy){
     kaisu3 = 2;
     image(Ingre2, cx, cy-75, ow2, oh2);
     hitY=3;
   }else if(ox3-cx<=40 && cx-ox3<=40 && oy3+60==cy){
     kaisu3 = 3;
     image(Ingre3, cx, cy-75, ow3, oh3);
     hitY=3;
   }else if(ox4-cx<=40 && cx-ox4<=40 && oy4+60==cy){
     kaisu3 = 4;
      image(Ingre4, cx, cy-75, ow4, oh4);
      hitY=3;
   } }
   
     if(kaisu3 == 1){
     image(Ingre1, cx+cw/2-ow1/2, cy-75, ow1, oh1);
   }else if(kaisu3 == 2){
     image(Ingre2, cx, cy-75, ow2, oh2);
   }else if(kaisu3 == 3){
     image(Ingre3, cx, cy-75, ow3, oh3);
   }else if(kaisu3 == 4){
      image(Ingre4, cx, cy-75, ow4, oh4);
   }
   
   if(hitY==3){
     T = T + 1;
     sec = T /(speed);
     dx=cx+12;
      dy = cy-100;
     PImage photo5 = loadImage("buns_over.png");
     image(photo5, dx, dy,dw,dh);
       if(sec==2){
         hitY=4;
       }
     }
     
     if(hitY==4){
        scene = "thinking";
     }
   }



void clear_scene() {
  // クリアシーンの処理
  background(113, 192, 216); //背景水色
  stroke(255);
  rect(25, 25, 650, 650); //背景②白色
  PImage clear = loadImage("S__258531343_0.jpg");
  image(clear, 50, 50, 600, 600);
}

void fail_scene() {
  //失敗処理
  background(113, 192, 216); //背景水色
  stroke(255);
  rect(25, 25, 650, 650); //背景②白色
  PImage fail = loadImage("S__258531344_0.jpg");
  image(fail, 50, 50, 600, 600);
}

void thinking_scene() {
  //ハンバーガーつくり中
  background(113, 192, 216); //背景水色
  stroke(255);
  rect(25, 25, 650, 650); //背景②白色
  T = T + 1;
  PImage think = loadImage("thinking.jpg");
  image(think, 50, 50, 600, 600);
  sec = T /(speed);
  
  if(j==0){
    if(kaisu1==2 && kaisu2==1 && kaisu3==4){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==1){
    if(kaisu1==2 && kaisu2==4 && kaisu3==1){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==2){
  if(kaisu1==1 && kaisu2==2 && kaisu3==4){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==3){
    if(kaisu1==1 && kaisu2==4 && kaisu3==3){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==4){
    if(kaisu1==3 && kaisu2==1 && kaisu3==4){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==5){
    if(kaisu1==1 && kaisu2==3 && kaisu3==2){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==6){
    if(kaisu1==3 && kaisu2==1 && kaisu3==2){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==7){
    if(kaisu1==3 && kaisu2==2 && kaisu3==1){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==8){
    if(kaisu1==2 && kaisu2==3 && kaisu3==4){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }else if(j==9){
    if(kaisu1==2 && kaisu2==4 && kaisu3==3){
      if(sec == 5){scene ="clear";}
    }else{ if(sec == 5){scene ="fail";}}
  }

}
