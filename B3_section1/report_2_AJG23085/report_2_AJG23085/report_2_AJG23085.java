//AJG23085 谷口香央

// ファイル読み込みのためのimport
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Collection;
import java.util.Random;
import java.util.Arrays;


public class report_2_AJG23085{
	// 2次元配列を表示する関数
	public static void show(double[][] A) {
		for (int i = 0; i < A.length; i++) {
			for (int j = 0; j < A[0].length; j++) {
				System.out.print(A[i][j] + ", ");
			}
			System.out.println();
		}
	}

	// クラスター中心行列 b のランダム初期化
	// データ行列からC個の行を抽出し，初期クラスター中心行列 b を返す．
	public static double[][] b_init(double[][] X, int C) {
		// 【ここを適切に完成させる】
		int n = X.length;
		int m = X[0].length;
		Random rand = new Random();
		double[][] b = new double[C][m];
		boolean[] sumi = new boolean[n];
		for(int i=0; i<C; i++){
			int d;
			do{
				d = rand.nextInt(n);
			}while(sumi[d]);
			sumi[d] = true;
			b[i] = Arrays.copyOf(X[d], m);
		}

		return b;
	}

	// 最近隣クラスターへの割り当て
	// クラスター中心行列 b とデータ行列 X から2乗距離行列dを算出し，
	// dを元にメンバシップ行列uを算出して返す．
	public static double[][] u_nearest(double[][] b, double[][] X) {
		// 【ここを適切に完成させる】
		int n = X.length;
		int m = X[0].length;
		int C = b.length;
		double[][] u = new double[C][n];

		for(int i=0; i<n; i++){
			int member = -1;
			double d_min = Double.MAX_VALUE;
			for(int j=0; j<C; j++){
				double d_i = 0.0;
				for(int k=0; k<m; k++){
					d_i += Math.pow(X[i][k]-b[j][k], 2);
				}
				if(d_i < d_min){
					d_min = d_i;
					member = j;
				}
			}
			for(int l=0; l<C; l++){
				if(l==member){
					u[l][i] = 1.0;
				}else{
					u[l][i] = 0.0;
				}
			}
		}
		return u;
	}

	// クラスター中心bの算出
	// メンバシップ行列 u とデータ行列 X から
	// 新しいクラスター中心 b を算出して返す．
	public static double[][] b_new(double[][] u, double[][] X) {
		// 【ここを適切に完成させる】
		int n = X.length;
		int m = X[0].length;
		int C = u.length;
		double[][] b = new double[C][m];
		double[] count = new double[C];
	
		for(int i=0; i<n; i++){
			for(int j=0; j<C; j++){
				if(u[j][i]==1.0){
					for(int k=0; k<m; k++){
						b[j][k] += X[i][k];
					}
					count[j] += u[j][i];
				}
			}
		}
		for(int j=0; j<C; j++){
			if(count[j]==0) continue;
			for(int k=0; k<m; k++){
				b[j][k] /= count[j];
			}
		}
		return b;
	}

	// 収束判定
	// u と u_old の差の絶対値によってクラスター割り当ての変化量を求める．
	// 変化がなければ true, そうでないなら false を返す．
	public static boolean convergence(double[][] u, double[][] u_old) {
		// 【ここを適切に完成させる】
		int C = u.length;
		int n = u[0].length;
		boolean con;

		for(int i=0; i<C; i++){
			for(int j=0; j<n; j++){
				if(Math.abs(u_old[i][j]-u[i][j])>0){
					con = false;
				}
			}
		}
		con = true;

		return con;
	}

	public static void kmeans(double[][] X, int C) {
		int n = X.length;
		System.out.println("データ行列 X");
		show(X); // データ行列 X の表示
		double[][] u = new double[C][n]; // メンバシップ行列の宣言
		double[][] b = b_init(X, C); // 初期クラスター中心の設定
		System.out.println("初期クラスター中心 b");
		show(b); // 初期クラスター中心 b の表示
		for (int step = 0; step < 10; step++) {
			System.out.println("Step: " + step);
			double[][] u_old = u.clone(); // 前回のクラスター割り当て
			u = u_nearest(b, X); // 最近隣クラスターへの割り当て
			b = b_new(u, X); // クラスター中心bの算出
			if (convergence(u, u_old)) { // 収束判定
				break;
			}
		}
		System.out.println("クラスター割り当て u");
		show(u);
		System.out.println("クラスター中心 b");
		show(b);
	}

	public static void main(String[] args) {
		// 変数設定
		int n = 150; // 対象数 n
		int m = 4; // 次元数 m
		double[][] X = new double[n][m]; // データ行列 X の宣言

		// データの読込
		try {
			File file = new File("iris.data"); // ファイルのパスを指定する

			// BufferedReaderクラスのreadLineメソッドを使って1行ずつ読み込み表示する
			FileReader fileReader = new FileReader(file);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			String row;
			int i=0;
      		while ((row = bufferedReader.readLine()) != null) {
        		if (row.trim().isEmpty()) {
 					continue; // 空行や空白のみの行はスキップ
 				}
				// データ内容をデータ行列Xへ格納
				// 【ここを適切に完成させる】
				String[] parts = row.split(",");
				for(int j=0; j<m; j++){
					X[i][j] = Double.parseDouble(parts[j]);
				}
				i++;
      		}
			fileReader.close(); // ファイルを閉じてリソースを開放する
		} catch (IOException e) { // 入出力例外発生時の処理
			e.printStackTrace(); // 標準エラー出力へ出力
		}

		// データ X に対し，クラスター数 C=3 として k-means法を実行．
		int C = 3;
		kmeans(X, C);
	}
}