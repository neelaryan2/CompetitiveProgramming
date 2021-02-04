import java.io.*;
import java.util.*;

public class Task808D {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class Testcase {
        boolean check(int[] a) {
            long tot = 0;
            int n = a.length;
            for (int i = 0; i < n; i++)
                tot += a[i];
            if (tot % 2 == 0) {
                tot /= 2;
                long sum = 0;
                HashSet<Long> s = new HashSet<Long>();
                s.add(0L);
                for (int k = 0; k < n; k++) {
                    sum += a[k];
                    if (s.contains(sum - tot))
                        return true;
                    s.add((long) a[k]);
                }
            }
            return false;
        }

        public void solve(int test) {
            int n = in.nextInt();
            int[] a = new int[n], b = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
                b[n - i - 1] = a[i];
            }
            if (check(a) || check(b))
                out.println("YES");
            else
                out.println("NO");
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
