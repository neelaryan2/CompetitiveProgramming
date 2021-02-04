import java.io.*;
import java.util.*;

public class Task1244D {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class Testcase {
        ArrayList<ArrayList<Integer>> adj;
        int[][] c;
        int[] tmp;

        public long dfs(int v, int p, int cid, int x) {
            cid = (cid + 3) % 3;
            tmp[v] = cid + 1;
            long ret = c[v][cid];
            for (int u : adj.get(v))
                if (u != p)
                    ret += dfs(u, v, cid + x, x);
            return ret;
        }

        public void solve(int test) {
            int n = in.nextInt();
            c = new int[n][3];
            for (int j = 0; j < 3; j++)
                for (int i = 0; i < n; i++)
                    c[i][j] = in.nextInt();
            adj = new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i < n; i++)
                adj.add(new ArrayList<Integer>());
            for (int i = 1; i < n; i++) {
                int u = in.nextInt() - 1;
                int v = in.nextInt() - 1;
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
            int root = -1;
            for (int i = 0; i < n; i++) {
                int sz = adj.get(i).size();
                if (sz > 2) {
                    out.println(-1);
                    return;
                }
                if (sz == 1)
                    root = i;
            }

            long ans = infL;
            tmp = new int[n];
            int[] cols = tmp;
            for (int i = 0; i < 3; i++) {
                for (int j = -1; j < 2; j += 2) {
                    Long cur = dfs(root, -1, i, j);
                    if (ans > cur) {
                        ans = cur;
                        cols = tmp.clone();
                    }
                }
            }
            out.println(ans);
            for (int i = 0; i < n; i++)
                out.print(cols[i] + " ");
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
