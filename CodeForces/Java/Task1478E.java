import java.io.*;
import java.util.*;

public class Task1478E {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    // performs range assignment and range sum queries
    static class SegTreeLazy {
        static final int NEUTRAL = 0;
        static final int NO_OP = Integer.MIN_VALUE;
        int[] t, d;
        public int n, h;

        public SegTreeLazy() {
        }

        static int MSB(int n) {
            int ndx = 0;
            for (; n > 1; n >>= 1)
                ndx++;
            return ndx;
        }

        void init(int m) {
            n = m;
            h = MSB(n) + 1;
            d = new int[n];
            t = new int[2 * n];
            Arrays.fill(d, NO_OP);
            Arrays.fill(t, NEUTRAL);
        }

        void build(char[] a) {
            init(a.length);
            for (int i = 0; i < n; i++)
                t[i + n] = a[i] - '0';
            push_up(0, n - 1);
        }

        // c is the size of segment
        void calc(int p, int c) {
            // pull from children
            if (d[p] == NO_OP)
                t[p] = t[p << 1] + t[p << 1 | 1];
            else
                t[p] = d[p] * c;
        }

        void apply(int p, int value, int c) {
            // apply to children
            if (p < n)
                d[p] = value;
            t[p] = value * c;
        }

        void push_up(int l, int r) {
            if (r == -1)
                r = l;
            l += n;
            r += n;
            for (int k = 2; l > 1; k <<= 1) {
                l >>= 1;
                r >>= 1;
                for (int i = r; i >= l; --i)
                    calc(i, k);
            }
        }

        void push_down(int l, int r) {
            int s = h, k = 1 << (h - 1);
            for (l += n, r += n; s > 0; --s, k >>= 1) {
                for (int i = l >> s; i <= r >> s; ++i) {
                    if (d[i] == NO_OP)
                        continue;
                    apply(i << 1, d[i], k);
                    apply(i << 1 | 1, d[i], k);
                    d[i] = NO_OP;
                }
            }
        }

        void assign(int l, int r, int v) {
            if (r < l || r >= n || l < 0)
                return;
            int _l = l, _r = r;
            l += n;
            r += n + 1;
            push_down(_l, _l);
            push_down(_r, _r);
            for (int c = 1; l < r; l >>= 1, r >>= 1, c <<= 1) {
                if ((l & 1) == 1)
                    apply(l++, v, c);
                if ((r & 1) == 1)
                    apply(--r, v, c);
            }
            push_up(_l, _l);
            push_up(_r, _r);
        }

        int query(int l, int r) {
            int resl = NEUTRAL;
            int resr = NEUTRAL;
            if (r < l || r >= n || l < 0)
                return resl;
            push_down(l, l);
            push_down(r, r);
            l += n;
            r += n + 1;
            for (; l < r; l >>= 1, r >>= 1) {
                if ((l & 1) == 1)
                    resl = resl + t[l++];
                if ((r & 1) == 1)
                    resr = t[--r] + resr;
            }
            return resl + resr;
        }
    };

    static class Testcase {
        public void solve(int test) {
            SegTreeLazy tree = new SegTreeLazy();
            int n = in.nextInt(), q = in.nextInt();
            char[] s = in.next().toCharArray();
            char[] f = in.next().toCharArray();
            tree.build(f);
            int[] l = new int[q], r = new int[q];
            for (int i = 0; i < q; i++) {
                l[i] = in.nextInt() - 1;
                r[i] = in.nextInt() - 1;
            }
            for (int i = q - 1; i >= 0; i--) {
                int sum = tree.query(l[i], r[i]);
                int len = r[i] - l[i] + 1;
                if (len == 2 * sum) {
                    out.println("NO");
                    return;
                }
                tree.assign(l[i], r[i], (2 * sum > len ? 1 : 0));
            }
            for (int i = 0; i < n; i++) {
                int cur = tree.query(i, i);
                if (cur != s[i] - '0') {
                    out.println("NO");
                    return;
                }
            }
            out.println("YES");
        }
    }

    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out, autoFlush);
        int t = 1;
        t = in.nextInt();
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
