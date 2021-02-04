import java.io.*;
import java.util.*;

public class Task706D {
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
        static final int D = 31;
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

        void remove(int num) {
            int v = 0;
            for (int i = D - 1; i >= 0; i--) {
                int c = (num >> i) & 1;
                v = t.get(v).nxt[c];
                t.get(v).cnt--;
            }
        }

        int query(int num) {
            int v = 0, ret = 0;
            for (int i = D - 1; i >= 0; i--) {
                int c = (num >> i) & 1;
                int u = t.get(v).nxt[c ^ 1];
                if (u == -1 || t.get(u).cnt == 0)
                    u = t.get(v).nxt[c];
                else
                    ret ^= (1 << i);
                v = u;
            }
            return ret;
        }
    }

    static class Testcase {
        public void solve(int test) {
            Trie trie = new Trie();
            trie.add(0);
            int q = in.nextInt();
            for (int i = 0; i < q; i++) {
                String t = in.next();
                int x = in.nextInt();
                if (t.equals("+"))
                    trie.add(x);
                if (t.equals("-"))
                    trie.remove(x);
                if (t.equals("?"))
                    out.println(trie.query(x));
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
