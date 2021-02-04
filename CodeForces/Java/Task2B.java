import java.io.*;
import java.util.*;

public class Task2B {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class Testcase {
        int zeros;

        public char[] ssolve(int[][] g) {
            int n = g.length;
            char[] ans = new char[2 * n - 2];
            int[][] par = new int[n][n];
            par[0][0] = -1;
            for (int i = 1; i < n; i++) {
                g[i][0] += g[i - 1][0];
                par[i][0] = (i - 1) * n + 0;
            }
            for (int i = 1; i < n; i++) {
                g[0][i] += g[0][i - 1];
                par[0][i] = 0 * n + (i - 1);
            }
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < n; j++) {
                    if (g[i - 1][j] < g[i][j - 1]) {
                        g[i][j] += g[i - 1][j];
                        par[i][j] = (i - 1) * n + j;
                    } else {
                        g[i][j] += g[i][j - 1];
                        par[i][j] = i * n + j - 1;
                    }
                }
            }
            int v = n * n - 1;
            int ptr = 2 * n - 2;
            while (v > 0) {
                int i = v / n, j = v % n;
                int u = par[i][j];
                int pi = u / n;
                ans[--ptr] = (pi == i) ? 'R' : 'D';
                v = u;
            }
            zeros = g[n - 1][n - 1];
            return ans;
        }

        public void print(String s, int n) {
            out.print(String.join("", Collections.nCopies(n, s)));
        }

        public void solve(int test) {
            int n = in.nextInt();
            int[][] a = new int[n][n];
            int[][] b = new int[n][n];
            int zi = -1, zj = -1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int cur2 = in.nextInt();
                    int cur5 = cur2;
                    if (cur2 == 0) {
                        a[i][j] = b[i][j] = inf;
                        zi = i;
                        zj = j;
                        continue;
                    }
                    a[i][j] = b[i][j] = 0;
                    while (cur2 % 2 == 0) {
                        cur2 /= 2;
                        a[i][j]++;
                    }
                    while (cur5 % 5 == 0) {
                        cur5 /= 5;
                        b[i][j]++;
                    }
                }
            }
            char[] ans2 = ssolve(a);
            int z2 = zeros;
            char[] ans5 = ssolve(b);
            int z5 = zeros;
            if (zi != -1 && z2 > 0 && z5 > 0) {
                out.println(1);
                print("R", zj);
                print("D", n - 1);
                print("R", n - 1 - zj);
                out.println();
                return;
            } else if (z2 < z5) {
                out.println(z2);
                out.println(ans2);
            } else {
                out.println(z5);
                out.println(ans5);
            }
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
