int bit;
int a, b;

void setup() {
  size(250, 200);
}

void draw() {
  background(240);

  if ((bit&(1<<0))>0) a+=1;
  if ((bit&(1<<1))>0) a-=1;
  if ((bit&(1<<2))>0) b+=1;
  if ((bit&(1<<3))>0) b-=1;
  fill(30);
  text(binary(bit, 4), 20, 20);
  text(a, 20, 40);
  text(b, 20, 60);
}

void keyPressed() {
  if (keyCode == RIGHT) bit |= (1<<0); //00000001
  if (keyCode == LEFT)  bit |= (1<<1); //00000010
  if (keyCode == UP)    bit |= (1<<2); //00000100
  if (keyCode == DOWN)  bit |= (1<<3); //00001000
}

void keyReleased() {
  if (keyCode == RIGHT) bit &= ~(1<<0);
  if (keyCode == LEFT)  bit &= ~(1<<1);
  if (keyCode == UP)    bit &= ~(1<<2);
  if (keyCode == DOWN)  bit &= ~(1<<3);
}
