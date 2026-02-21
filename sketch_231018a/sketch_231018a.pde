int a,b;
void setup(){
  size(300,30);
  frameRate(1);
  a=0;
}
void draw(){
  int i;
  for(i=0;i<10;i++){
    if(i==a){
      fill(255,0,0);}
    else{
    fill(255,255,255);}
  rect(30*i,0,30,30);}
    if(a==0){
      b=1;}
    else if(a==9){
      b=-1;}
  a=a+b;
}
