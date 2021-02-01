import java.io.*;
import java.util.*;

public class Task1151C {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int mod = (int) 1e9 + 7;

    static class Testcase {
        public int get(long x) {
            long c = 1;
            long even = 0, odd = 0;
            int iter = 0;
            while (odd + even < x) {
                if (iter % 2 == 0)
                    odd += Math.min(c, x - odd - even);
                else
                    even += Math.min(c, x - odd - even);
                c <<= 1;
                iter++;
            }
            odd %= mod;
            even %= mod;
            odd = (odd * odd) % mod;
            even = (even * even + even) % mod;
            return (int) ((odd + even) % mod);
        }

        public void solve(int test) {
            long l = in.nextLong(), r = in.nextLong();
            int ans = get(r) - get(l - 1);
            if (ans < 0)
                ans += mod;
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
