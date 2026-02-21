//AJG23085 谷口香央

import java.net.URL;
import java.net.HttpURLConnection;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Set;
import java.util.TreeSet;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
  public static void main(String[] args) {
    try {
      // ターゲットURL
      URL url = new URL("https://www.omu.ac.jp/");
      HttpURLConnection http = (HttpURLConnection) url.openConnection();
      http.setRequestMethod("GET");
      http.connect();
      String httpcontext = url.toString();
      System.out.println("Links in " + httpcontext); 

      // HTMLの内容を読み込む
      InputStreamReader isr = new InputStreamReader(http.getInputStream(), "UTF-8");
      BufferedReader br = new BufferedReader(isr);

      StringBuilder htmlContent = new StringBuilder();
      String line;
      while ((line = br.readLine()) != null) {
        htmlContent.append(line);
      }

      br.close();
      isr.close();
      http.disconnect();

      // 正規表現によるリンクの抽出
      String html = htmlContent.toString();
      Pattern pattern = Pattern.compile("href=\"(http[s]?://[^\"]+)\"|href=\'(http[s]?://[^\']+)\\'");
      Matcher matcher = pattern.matcher(html);

      Set<String> links = new TreeSet<>();
      while (matcher.find()) {
        if (matcher.group(1) != null) {
          links.add(matcher.group(1));
        } else if (matcher.group(2) != null) {
          links.add(matcher.group(2));
        }
      }

      // 辞書順に昇順ソートされたリンクを表示
      int index = 1;
      for (String link : links) {
        System.out.println(index + ": " + link);
        index++;
      }

    } catch (Exception e) {
        e.printStackTrace();
    }
  }
}
