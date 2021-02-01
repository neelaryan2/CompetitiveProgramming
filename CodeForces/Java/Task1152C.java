import java.io.*;
import java.util.*;

public class Task1152C {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;

    static class Testcase {
        public void solve(int test) {
            int a = in.nextInt(), b = in.nextInt();
            int n = Math.abs(a - b), g, kans = 0, k;
            long cur, ans = (long) 1e18;
            for (int i = 1; i * i <= n; i++) {
                if (n % i != 0)
                    continue;
                g = i;
                k = (g - a % g) % g;
                cur = 1L * ((a + k) / g) * (b + k);
                if (ans > cur) {
                    ans = cur;
                    kans = k;

                }
                g = n / i;
                k = (g - a % g) % g;
                cur = 1L * ((a + k) / g) * (b + k);
                if (ans > cur) {
                    ans = cur;
                    kans = k;
                }
            }
            out.println(kans);
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
