import java.io.*;
import java.util.*;

public class Task1305D {
    static InputReader in;
    static PrintWriter out;
    static boolean autoFlush = true;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class Testcase {
        ArrayList<HashSet<Integer>> adj;
        HashSet<Integer> leafs;
        int[] par, depth;

        public void dfs(int v, int p, int d) {
            par[v] = p;
            depth[v] = d;
            for (int u : adj.get(v))
                if (u != p)
                    dfs(u, v, d + 1);
        }

        public void preprocess() {
            int r = 4;
            int n = adj.size();
            par = new int[n];
            depth = new int[n];
            dfs(r - 1, -1, 0);
        }

        public int ask(int u, int v) {
            if (depth[u] < depth[v]) {
                u = u + v;
                v = u - v;
                u = u - v;
            }
            while (depth[u] != depth[v])
                u = par[u];
            while (u != v) {
                u = par[u];
                v = par[v];
            }
            out.println(u + 1);
            return u;
        }

        public int query(int u, int v) {
            out.print("? " + (u + 1));
            out.println(" " + (v + 1));
            // int w = ask(u, v);
            int w = in.nextInt() - 1;
            if (w == -2)
                System.exit(0);
            return w;
        }

        public int removeLeaf(int v) {
            int u = adj.get(v).iterator().next();
            adj.get(v).remove(u);
            adj.get(u).remove(v);
            if (adj.get(u).size() == 1)
                leafs.add(u);
            return v;
        }

        public void solve(int test) {
            int n = in.nextInt();
            adj = new ArrayList<HashSet<Integer>>();
            for (int i = 0; i < n; i++)
                adj.add(new HashSet<Integer>());
            leafs = new HashSet<Integer>();

            for (int i = 1; i < n; i++) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                adj.get(u).add(v);
                adj.get(v).add(u);
            }

            // preprocess();

            for (int i = 0; i < n; i++)
                if (adj.get(i).size() == 1)
                    leafs.add(i);

            while (leafs.size() > 1) {
                int u = leafs.iterator().next();
                leafs.remove(u);
                int v = leafs.iterator().next();
                leafs.remove(v);
                int r = query(u, v);
                if (r == u || r == v) {
                    out.println("! " + (r + 1));
                    return;
                }
                removeLeaf(u);
                removeLeaf(v);
            }
            int r = leafs.iterator().next();
            out.println("! " + (r + 1));
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
