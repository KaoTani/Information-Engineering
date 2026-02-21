//行列演算クラス
public class Mat{
  // コンストラクタ
  public Mat() {

  }

  // 行列 A を表示する．
  public void show(double[][] A) {
    System.out.println("---");
    for (int i = 0; i < A.length; i++) {
      for (int j = 0; j < A[0].length; j++) {
        System.out.print(A[i][j] + ", ");
      }
      System.out.println();
    }
    System.out.println("---");
  }

  public double[][] add(double[][] A, double[][] B){
    double[][] C = new double[A.length][A[0].length];
    for(int i=0; i<A.length; i++){
      for(int j=0; j<A[0].length; j++){
        C[i][j] = A[i][j] + B[i][j];
      }
    }    
    return C;
  }

  public double[][] sub(double[][] A, double[][] B){
    double[][] C = new double[A.length][A[0].length];
    for(int i=0; i<A.length; i++){
      for(int j=0; j<A[0].length; j++){
        C[i][j] = A[i][j] - B[i][j];
      }
    }    
    return C;
  }

  public double[][] mul(double[][] A, double[][] B){
    double[][] C = new double[A.length][A[0].length];
    for(int i=0; i<A.length; i++){
      for(int j=0; j<A[0].length; j++){
        C[i][j] = A[i][j] * B[i][j];
      }
    }
    return C;
  }

  public double[][] div(double[][] A, double[][] B){
    double[][] C = new double[A.length][A[0].length];
    for(int i=0; i<A.length; i++){
      for(int j=0; j<A[0].length; j++){
        C[i][j] = A[i][j] / B[i][j];
      }
    }
    return C;
  }

  public double[][] sc(double[][] A, double s){
    double[][] C = new double[A.length][A[0].length];
    for(int i=0; i<A.length; i++){
      for(int j=0; j<A[0].length; j++){
        C[i][j] = A[i][j] * s;
      }
    }
    return C;
  }

  public double[][] T(double[][] A){
    double[][] C = new double[A[0].length][A.length];
    for(int i=0; i<A[0].length; i++){
      for(int j=0; j<A.length; j++){
        C[i][j] = A[j][i];
      }
    }
    return C;
  }

  public double[][] matmul(double[][] A, double[][] B){
    double[][] C = new double[A.length][A.length];
    for(int i=0; i<A.length; i++){
      for(int j=0; j<A.length; j++){
        for(int k=0; k<A[0].length; k++){
            C[i][j] += A[i][k] * B[k][j];     
        }
      }
    }
    return C;
  }
}