void setup(){
  size(500, 500);
  noStroke();
  color c1 = color(251, 190, 131);
  color c2 = color(208, 98, 16);
  for(float h = 400; h < 450; h += 5){
      color c = lerpColor(c1, c2, (100+h) / (200+450));
      fill(c);
      rect(100, 400, 200, 50, 0, 0,100, 100);
  }
}
