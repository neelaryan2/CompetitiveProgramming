import java.io.*;
import java.util.*;

public class Task920F {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class FenwickTree {
        private long[] B;

        public FenwickTree(int n) {
            B = new long[n];
            Arrays.fill(B, 0);
        }

        public void add(int i, long x) {
            int n = B.length;
            for (; i < n; i += i & (-i))
                B[i] += x;
        }

        public long sum(int i) {
            long sum = 0;
            for (; i > 0; i -= i & (-i))
                sum += B[i];
            return sum;
        }

        public long get(int i) {
            if (i <= 0)
                return 0;
            long val = B[i];
            int z = i - (i & -i);
            for (--i; i != z; i -= i & (-i))
                val -= B[i];
            return val;
        }

        public int bit_search(int val) {
            long sum = 0;
            int pos = 0, i = 0, s = B.length;
            while ((1 << i) <= s)
                i++;
            for (i = i - 1; i >= 0; i--) {
                int d = (1 << i);
                if (pos + d < s && sum + B[pos + d] < val) {
                    pos = pos + d;
                    sum = sum + B[pos];
                }
            }
            return pos + 1;
        }
    }

    static class Testcase {
        public static int root(int v, int[] par) {
            if (v == par[v])
                return v;
            int p = root(par[v], par);
            par[v] = p;
            return p;
        }

        public void solve(int test) {
            int n = in.nextInt(), m = in.nextInt();
            int[] par = new int[n + 1], a = new int[n];
            FenwickTree tree = new FenwickTree(n + 1);
            int mx = -1;
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
                tree.add(i + 1, a[i]);
                par[i] = i;
                mx = Math.max(mx, a[i]);
            }

            int[] div = new int[mx + 1];

            par[n] = n;
            div[0] = 0;

            for (int i = 1; i <= mx; i++)
                for (int j = i; j <= mx; j += i)
                    div[j]++;

            for (int i = 0; i < m; i++) {
                int t = in.nextInt();
                int l = in.nextInt() - 1;
                int r = in.nextInt() - 1;
                if (t == 1) {
                    for (int j = root(l, par); j <= r; j = root(j, par)) {
                        int nv = div[a[j]];
                        if (nv != a[j]) {
                            tree.add(j + 1, nv - a[j]);
                            a[j] = nv;
                        }
                        if (nv > 2)
                            j++;
                        else
                            par[j] = j + 1;
                    }
                }
                if (t == 2) {
                    long ans = tree.sum(r + 1) - tree.sum(l);
                    out.println(ans);
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
