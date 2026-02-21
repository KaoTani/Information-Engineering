//AJG23085 谷口香央

// ファイル読み込みのためのimport
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class report_3_AJG23085 {
	// double型2次元配列を表示する関数
	public static void show(double[][] A) {
		for (int i = 0; i < A.length; i++) {
			for (int j = 0; j < A[0].length; j++) {
				System.out.print(A[i][j] + ", ");
			}
			System.out.println();
		}
	}

	// String型1次元配列を表示する関数
	public static void show(String[] a) {
		for (int i = 0; i < a.length; i++) {
			System.out.print(a[i] + ", ");
		}
		System.out.println();
	}

	// k近傍法
	// X, yを訓練データとし，入力xに対しk近傍法を実行し，予測結果を返す．
	public static String knn(double[][] X, String[] y, int k, double[] x) {
		// ここを適切に完成させる
		int n = X.length;
		int m = X[0].length;
		double[] min = new double[k];
		int[] num = new int[k];
		for(int i=0; i<k; i++){
			min[i] = Double.MAX_VALUE;
		}
		for(int i=0; i<n; i++){
			double dist = 0;
			for(int j=0; j<m; j++){
				dist += Math.pow(x[j]-X[i][j], 2);
			}
			for(int j=0; j<k; j++){
				if(min[j] > dist){
					for(int l=k-1; l>j; l--){
						min[l] = min[l-1];
						num[l] = num[l-1];
					}
					min[j] = dist;
					num[j] = i;
					break;
				}
			}
		}
		Map<String, Integer> count = new HashMap<>();
		ArrayList<String> y_list = new ArrayList<>();
		for(int i=0; i<k; i++){
			String str = y[num[i]];
			count.put(str, count.getOrDefault(str, 0) + 1);
			y_list.add(str);
		}
		String Most = null;
		int Max = 0;
		for(Map.Entry<String, Integer> entry : count.entrySet()){
			if(entry.getValue() > Max){
				Most = entry.getKey();
				Max = entry.getValue();
			}
		}
		System.out.println(Most + ": " + y_list);

		return Most;
	}

	public static void main(String[] args) {
		// 変数設定
		int n = 150; // 対象数 n
		int m = 4; // 次元数 m
		double[][] X = new double[n][m]; // データ行列 X の宣言
		String[] y = new String[n]; // 教師ラベルの配列

		// データの読込
		try {
			File file = new File("iris.data"); // ファイルのパスを指定する

			// BufferedReaderクラスのreadLineメソッドを使って1行ずつ読み込み表示する
			FileReader fileReader = new FileReader(file);
			BufferedReader bufferedReader = new BufferedReader(fileReader);
			String row;

			// ここで X と y にデータを格納する (ここを適切に完成させる)
			// 何らかの処理
			int index = 0;
			while ((row = bufferedReader.readLine()) != null) {
				if (row.trim().isEmpty()) {
					continue; // 空行や空白のみの行はスキップ
				}
				// 何らかの処理
				String[] data = row.split(",");
				for(int i=0; i<m; i++){
					X[index][i] = Double.parseDouble(data[i]);
				}
				y[index] = data[m];
				index++;
			}
			fileReader.close(); // ファイルを閉じてリソースを開放する
		} catch (IOException e) {
			e.printStackTrace();
		}

		// データ行列 X と正解ラベル y の表示
		show(X);
		show(y);

		// パラメータ k を定める．
		int k = 5;

		// 以下でleave-one-out交差検証法でk近傍法の性能を確認する．(ここを適切に完成させる)
		int c=0;
		for(int i=0; i<n; i++){
			double[] x = X[i];
			String y_ans = y[i];

			double[][] X_temp = new double[n-1][m];
			String[] y_temp = new String[n-1];
			for(int j=0; j<n; j++){
				if(j < i){
					X_temp[j] = X[j];
					y_temp[j] = y[j];
				}else if(j > i){
					X_temp[j-1] = X[j];
					y_temp[j-1] = y[j];
				}
			} 
			String y_pred = knn(X_temp, y_temp, k, x);
			if(y_pred.equals(y_ans)){
				c++;
			}
		}
		double loocv = (double)c/n;
		System.out.println("Prediction Accuracy = " + loocv);
	}
}
