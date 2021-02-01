import java.io.*;
import java.util.*;

public class Task371D {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;

    static class Testcase {
        public static int root(int v, int[] par) {
            if (v == par[v])
                return v;
            int p = root(par[v], par);
            par[v] = p;
            return p;
        }

        public void solve(int test) {
            int n = in.nextInt();
            int[] a = new int[n], par = new int[n + 1], left = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
                left[i] = a[i];
                par[i] = i;
            }
            par[n] = n;
            int m = in.nextInt();
            for (int i = 0; i < m; i++) {
                int t = in.nextInt(), p = in.nextInt() - 1;
                if (t == 1) {
                    int x = in.nextInt();
                    for (int j = root(p, par); j < n; j = root(j, par)) {
                        if (left[j] > x) {
                            left[j] -= x;
                            break;
                        }
                        x -= left[j];
                        left[j] = 0;
                        par[j] = j + 1;
                    }
                } else {
                    out.println(a[p] - left[p]);
                }
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
