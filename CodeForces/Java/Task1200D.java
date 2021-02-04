import java.io.*;
import java.util.*;

public class Task1200D {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class Testcase {
        public void solve(int test) {
            int n = in.nextInt(), k = in.nextInt();
            char[][] g = new char[n][n];
            for (int i = 0; i < n; i++)
                g[i] = in.next().toCharArray();
            int[][] dp = new int[n + 1][n + 1];
            for (int[] r : dp)
                Arrays.fill(r, 0);
            for (int i = 0; i < n; i++) {
                int l = 0, r = n - 1;
                while (l < n && g[i][l] == 'W')
                    l++;
                while (r >= 0 && g[i][r] == 'W')
                    r--;
                if (l == n) {
                    dp[0][0]++;
                    continue;
                }
                if (r - l + 1 > k)
                    continue;
                int i1 = Math.max(i - k + 1, 0), i2 = i + 1;
                int j1 = Math.max(r - k + 1, 0), j2 = l + 1;
                dp[i1][j1]++;
                dp[i2][j2]++;
                dp[i1][j2]--;
                dp[i2][j1]--;
            }
            for (int i = 0; i < n; i++) {
                int l = 0, r = n - 1;
                while (l < n && g[l][i] == 'W')
                    l++;
                while (r >= 0 && g[r][i] == 'W')
                    r--;
                if (l == n) {
                    dp[0][0]++;
                    continue;
                }
                if (r - l + 1 > k)
                    continue;
                int i1 = Math.max(r - k + 1, 0), i2 = l + 1;
                int j1 = Math.max(i - k + 1, 0), j2 = i + 1;
                dp[i1][j1]++;
                dp[i2][j2]++;
                dp[i1][j2]--;
                dp[i2][j1]--;
            }
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dp[i][j + 1] += dp[i][j];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dp[i + 1][j] += dp[i][j];
            int ans = 0;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    ans = Math.max(ans, dp[i][j]);
            out.println(ans);
        }
    }

    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out, autoFlush);
        int t = 1;
        // t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            Testcase solver = new Testcase();
            // out.printf("Case #%d: ", i);
            solver.solve(i);
        }
        out.close();
    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public InputReader(FileReader file) throws FileNotFoundException {
            reader = new BufferedReader(file, 32768);
            tokenizer = null;
        }

        public String readLine() {
            String str = "";
            try {
                str = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            return str;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens())
                tokenizer = new StringTokenizer(readLine());
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public float nextFloat() {
            return Float.parseFloat(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void trace(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }
}
