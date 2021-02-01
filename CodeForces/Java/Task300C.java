import java.io.*;
import java.util.*;

public class Task300C {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;

    static class Modular {
        static int[] fact, invfact;
        // static final int kMod = 998244353;
        static final int kMod = (int) 1e9 + 7;
        // kMod should prime for this to work
        // inv = new int[n + 1];
        // for (int i = 2; i <= n; i++)
        // inv[i] = sub(kMod, mul(inv[kMod % i], (kMod / i)));

        public static int lgpow(int b, long e) {
            e %= (kMod - 1);
            if (e < 0)
                e += kMod - 1;
            int r = 1;
            for (; e > 0; e >>= 1, b = mul(b, b))
                if (e % 2 == 1)
                    r = mul(r, b);
            return r;
        }

        public static int add(int... nums) {
            int a = 0;
            for (int b : nums) {
                a += b;
                if (a >= kMod)
                    a -= kMod;
            }
            return a;
        }

        public static int sub(int a, int b) {
            a -= b;
            if (a < 0)
                a += kMod;
            return a;
        }

        public static int mul(int... nums) {
            int a = 1;
            for (int b : nums)
                a = (int) ((1L * a * b) % kMod);
            return a;
        }

        public static int div(int a, int b) {
            int inv = lgpow(b, -1L);
            return mul(a, inv);
        }

        public static void factorials(int n) {
            fact = new int[n + 1];
            invfact = new int[n + 1];
            fact[0] = 1;
            for (int i = 1; i <= n; i++)
                fact[i] = mul(fact[i - 1], i);
            invfact[n] = lgpow(fact[n], -1);
            for (int i = n - 1; i >= 0; i--)
                invfact[i] = mul(invfact[i + 1], i + 1);
        }

        public static int choose(int n, int k) {
            if (n < 0 || k < 0 || k > n)
                return 0;
            return mul(fact[n], invfact[k], invfact[n - k]);
        }
    }

    static class Testcase {
        public void solve(int test) {
            int a = in.nextInt(), b = in.nextInt();
            int n = in.nextInt(), digits = 0;
            boolean[] dp = new boolean[b * n + 1];
            Arrays.fill(dp, false);
            for (int num = b * n; num > 0; num /= 10)
                digits++;
            for (int len = 1; len <= digits; len++) {
                for (int i = 0; i < (1 << len); i++) {
                    int cur = 0;
                    for (int j = 0; j < len; j++) {
                        cur = 10 * cur + (((i >> j) & 1) == 1 ? a : b);
                    }
                    if (cur <= b * n)
                        dp[cur] = true;
                }
            }
            int ans = 0;
            for (int i = 0; i <= n; i++) {
                int sum = i * a + (n - i) * b;
                if (dp[sum])
                    ans = Modular.add(ans, Modular.choose(n, i));
            }
            out.println(ans);
        }
    }

    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out, autoFlush);
        Modular.factorials((int) 1e6);
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
