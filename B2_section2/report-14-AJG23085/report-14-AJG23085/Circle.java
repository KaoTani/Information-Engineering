//AJG23085 谷口香央

public class Circle extends Shape{
  double x, y, radius;
  
  Circle(double x, double y, double radius){
    this.x = x;
    this.y = y;
    this.radius = radius;
  }

  public String toString(){
    return "円：(" + x + ", " + y + "), radius=" + radius;
  }

  public double area(){
    return Math.PI * radius * radius;
  }

  public double perimeter(){
    return 2 * Math.PI * radius;
  }
}