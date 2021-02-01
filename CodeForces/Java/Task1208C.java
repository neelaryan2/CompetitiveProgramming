import java.io.*;
import java.util.*;

public class Task1208C {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;

    static class Testcase {
        public void solve(int test) {
            int[][] base = new int[4][4];
            base[0] = new int[] { 8, 9, 1, 13 };
            base[1] = new int[] { 3, 12, 7, 5 };
            base[2] = new int[] { 0, 2, 4, 11 };
            base[3] = new int[] { 6, 10, 15, 14 };
            int n = in.nextInt();
            int[][] ans = new int[n][n];
            int k = n / 4;
            for (int r = 0; r < k; r++)
                for (int c = 0; c < k; c++)
                    for (int i = 0; i < 4; i++)
                        for (int j = 0; j < 4; j++)
                            ans[i + 4 * r][j + 4 * c] = 16 * (r * k + c) + base[i][j];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    out.print(ans[i][j] + " ");
                out.println();
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
