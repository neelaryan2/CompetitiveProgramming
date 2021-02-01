import java.io.*;
import java.util.*;

public class Task1286B {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;

    static class FenwickTree {
        private int[] B;

        public FenwickTree(int n) {
            B = new int[n];
        }

        public void add(int i, int x) {
            int n = B.length;
            for (; i < n; i += i & (-i))
                B[i] = B[i] + x;
        }

        public int sum(int i) {
            int sum = 0;
            for (; i > 0; i -= i & (-i))
                sum = sum + B[i];
            return sum;
        }

        public int get(int i) {
            if (i <= 0)
                return 0;
            int val = B[i];
            int z = i - (i & -i);
            for (--i; i != z; i -= i & (-i))
                val = val - B[i];
            return val;
        }

        public int bit_search(int val) {
            int sum = 0, pos = 0;
            int i = 0, s = B.length;
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

    static class RangeFenwickTree {
        FenwickTree B1, B2;

        public RangeFenwickTree(int n) {
            B1 = new FenwickTree(n + 1);
            B2 = new FenwickTree(n + 1);
        }

        public void range_add(int l, int r, int x) {
            if (r < l)
                return;
            B1.add(l, x);
            B1.add(r + 1, -x);
            B2.add(l, x * (l - 1));
            B2.add(r + 1, -x * r);
        }

        int range_sum(int l, int r) {
            int res = 0;
            if (r < l)
                return res;
            res = res + B1.sum(r) * r;
            res = res - B2.sum(r);
            res = res + B1.sum(l - 1) * (l - 1);
            res = res - B2.sum(l - 1);
            return res;
        }
    }

    static class Testcase {
        ArrayList<ArrayList<Integer>> adj;
        FenwickTree bit;
        int[] c, a, siz;

        public void dfs(int v) {
            a[v] = bit.bit_search(c[v] + 1);
            bit.add(a[v], -1);
            for (int u : adj.get(v))
                dfs(u);
        }

        public void dfs_size(int v) {
            siz[v] = 1;
            for (int u : adj.get(v)) {
                dfs_size(u);
                siz[v] += siz[u];
            }
        }

        public void solve(int test) {
            int n = in.nextInt();
            bit = new FenwickTree(n + 1);

            c = new int[n];
            a = new int[n];
            siz = new int[n];
            adj = new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i < n; i++)
                adj.add(new ArrayList<Integer>());

            int par, root = -1;
            for (int i = 0; i < n; i++) {
                bit.add(i + 1, 1);
                par = in.nextInt() - 1;
                c[i] = in.nextInt();
                if (par == -1) {
                    root = i;
                } else {
                    adj.get(par).add(i);
                }
            }
            dfs_size(root);

            for (int i = 0; i < n; i++) {
                if (c[i] >= siz[i]) {
                    out.println("NO");
                    return;
                }
            }

            dfs(root);
            out.println("YES");
            for (int i = 0; i < n; i++)
                out.print(a[i] + " ");
            out.println();

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
