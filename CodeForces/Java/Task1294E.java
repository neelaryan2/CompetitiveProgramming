import java.io.*;
import java.util.*;

public class Task1294E {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class Testcase {
        public int ssolve(int[] b) {
            int n = b.length;
            int[] a = new int[2 * n];
            for (int i = 0; i < n; i++)
                a[i] = a[i + n] = b[i];

            int[] cnt = new int[3 * n];
            Arrays.fill(cnt, 0);
            for (int i = 0; i < 2 * n; i++) {
                a[i] += 2 * n - i - 1;
                if (i < n && a[i] < 3 * n)
                    cnt[a[i]]++;
            }

            int ans = n;
            for (int i = 0; i < n; i++) {
                ans = Math.min(ans, i + n - cnt[2 * n - i - 1]);
                if (a[i + n] < 3 * n)
                    cnt[a[i + n]]++;
                if (a[i] < 3 * n)
                    cnt[a[i]]--;
            }

            return ans;
        }

        public void solve(int test) {
            int n = in.nextInt(), m = in.nextInt();
            int[][] g = new int[m][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int cur = in.nextInt() - j - 1;
                    g[j][i] = (cur % m == 0) ? cur / m : inf;
                }
            }
            int ans = 0;
            for (int i = 0; i < m; i++) {
                ans += ssolve(g[i]);
            }
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
