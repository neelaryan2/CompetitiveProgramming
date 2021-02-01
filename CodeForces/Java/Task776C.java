import java.io.*;
import java.util.*;

public class Task776C {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;

    static class Testcase {
        public void solve(int test) {
            int n = in.nextInt(), k = in.nextInt();
            long[] p = new long[n + 1];
            p[0] = 0;
            long sum = 0;
            for (int i = 1; i <= n; i++) {
                int a = in.nextInt();
                p[i] = p[i - 1] + a;
                sum += Math.abs(a);
            }
            ArrayList<Long> vals = new ArrayList<Long>();
            long pow = 1;
            vals.add(1L);
            if (k == -1)
                vals.add(-1L);
            else if (k != 1) {
                pow *= k;
                while (Math.abs(pow) <= sum) {
                    vals.add(pow);
                    pow *= k;
                    if (k == 1)
                        break;
                }
            }

            HashMap<Long, Integer> map = new HashMap<Long, Integer>();
            Long ans = 0L;
            for (int i = 0; i <= n; i++) {
                for (long val : vals)
                    ans += map.getOrDefault(p[i] - val, 0);
                int prev = map.getOrDefault(p[i], 0);
                map.put(p[i], prev + 1);
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
