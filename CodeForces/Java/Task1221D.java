import java.io.*;
import java.util.*;

public class Task1221D {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class Testcase {
        public void solve(int test) {
            int n = in.nextInt();
            int[] a = new int[n + 1], b = new int[n + 1];
            long[][] dp = new long[n + 1][3];
            a[0] = -inf;
            for (int j = 0; j < 3; j++)
                dp[0][j] = 0;
            for (int i = 1; i <= n; i++) {
                a[i] = in.nextInt();
                b[i] = in.nextInt();
                for (int j = 0; j < 3; j++)
                    dp[i][j] = infL;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < 3; j++) {
                    long cur = 1L * j * b[i];
                    for (int k = 0; k < 3; k++) {
                        if (a[i] + j != a[i - 1] + k)
                            dp[i][j] = Math.min(dp[i][j], cur + dp[i - 1][k]);
                    }
                }
            }
            long ans = infL;
            for (int i = 0; i < 3; i++)
                ans = Math.min(ans, dp[n][i]);
            out.println(ans);
        }
    }

    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out, autoFlush);
        int t = 1;
        t = in.nextInt();
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
