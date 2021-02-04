import java.io.*;
import java.util.*;

public class Task671B {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class Testcase {
        int n, k;
        int[] a;

        public boolean check(int x, boolean is_min) {
            long small = 0, big = 0;
            for (int e : a) {
                small += Math.max(0, x - e);
                big += Math.max(0, e - x);
            }
            if (is_min) {
                small = small + big;
                big = small - big;
                small = small - big;
            }
            return (Math.min(small, k) >= big);
        }

        public void solve(int test) {
            n = in.nextInt();
            k = in.nextInt();
            a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = in.nextInt();
            int lo = 1, hi = (int) 1e9 + 1, mid;
            while (lo < hi - 1) {
                mid = lo + (hi - lo) / 2;
                if (check(mid, true))
                    lo = mid;
                else
                    hi = mid;
            }
            int mn = lo;
            lo = 0;
            hi = (int) 1e9;
            while (lo < hi - 1) {
                mid = lo + (hi - lo) / 2;
                if (check(mid, false))
                    hi = mid;
                else
                    lo = mid;
            }
            int mx = hi;
            out.println(mx - mn);
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
