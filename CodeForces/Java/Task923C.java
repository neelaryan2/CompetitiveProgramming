import java.io.*;
import java.util.*;

public class Task923C {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;

    static class Vertex {
        int[] nxt;
        int cnt;

        public Vertex() {
            nxt = new int[2];
            Arrays.fill(nxt, -1);
            cnt = 0;
        }
    }

    static class Trie {
        static final int D = 30;
        ArrayList<Vertex> t;

        public Trie() {
            t = new ArrayList<Vertex>();
            t.add(new Vertex());
        }

        void add(int num) {
            int v = 0;
            for (int i = D - 1; i >= 0; i--) {
                int c = (num >> i) & 1;
                if (t.get(v).nxt[c] == -1) {
                    t.get(v).nxt[c] = t.size();
                    t.add(new Vertex());
                }
                v = t.get(v).nxt[c];
                t.get(v).cnt++;
            }
        }

        int query(int num) {
            int v = 0, ret = 0;
            for (int i = D - 1; i >= 0; i--) {
                int c = (num >> i) & 1;
                int u = t.get(v).nxt[c];
                if (u == -1 || t.get(u).cnt == 0) {
                    u = t.get(v).nxt[c ^ 1];
                    ret ^= (1 << i);
                }
                t.get(u).cnt--;
                v = u;
            }
            return ret;
        }
    }

    static class Testcase {
        public void solve(int test) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = in.nextInt();
            Trie trie = new Trie();
            for (int i = 0; i < n; i++)
                trie.add(in.nextInt());
            for (int i = 0; i < n; i++)
                out.print(trie.query(a[i]) + " ");
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
