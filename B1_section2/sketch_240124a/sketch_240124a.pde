float x;
float y;
float z;
float a1;
float a2;
float a3;
float a4;
int k1;
int k2;
int [][] s= {{0,1,0,1,1,1,0,0,0,0}, 
{0,1,0,0,0,1,1,1,0,1}, 
{0,1,1,1,0,1,0,0,0,0}, 
{0,0,0,1,0,1,0,1,1,0}, 
{1,1,0,1,0,1,0,1,0,0}, 
{0,1,0,1,0,0,0,1,0,0}, 
{0,1,0,1,0,1,1,1,0,1}, 
{0,0,0,1,0,1,0,0,0,1}, 
{0,1,1,1,0,1,0,1,1,1}, 
{0,0,0,0,0,1,0,0,0,0}}; 

void setup(){
size(300,300);
frameRate(10);
x=0;
y=0;
z=2;
a1=0;
a2=0;
k1=0;
k2=0;
}

void keyPressed(){
  if(key==CODED){
    if(keyCode==UP){
      k2 = 0;
      a1 = a1 + 0.005;
      y = y - a1*a1;
      k1 = 1;
    }else if(keyCode==DOWN){
      k2 = 0;
      a2 = a2 + 0.005;
      y = y + a2*a2;
      k1 = 2;
    }else if(keyCode==LEFT){
      k1 = 0;
      a3 = a3 + 0.005;
      x = x - a3*a3;
      k2 = 1;
    }else if(keyCode==RIGHT){
      k1 = 0;
      a4 = a4 + 0.005;
      x = x + a4*a4;
      k2 = 2;
    }
  }
}

void draw(){

 int i; 
 int j; 
for(i=0; i<10; i++){ 
for(j=0; j<10; j++){ 
 if(s[i][j]==1){ 
fill(0,0,0); 
 } 
else{ 
fill(255,255,255);
} 
rect(30*j, 30*i, 30, 30); 
 }
}

if(k1==1){
  a2 = 0;
  y = y - a1*a1;
}else if(k1==2){
  a1 = 0;
  y = y + a2*a2;
}
if(k2==1){
  a4 = 0;
  x = x - a3*a3;
}else if(k2==2){
  a3 = 0;
  x = x + a4*a4;
}
   fill(255,0,0);
   rect(30*x,30*y,30,30);
  
}
