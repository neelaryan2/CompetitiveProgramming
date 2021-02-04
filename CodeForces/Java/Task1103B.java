import java.io.*;
import java.util.*;

public class Task1103B {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = true;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class Testcase {
        public boolean ask(int x, int y) {
            int a = 1;
            boolean b = (x % a < y % a);
            out.println(b ? "y" : "x");
            return b;
        }

        public boolean query(int x, int y) {
            // return x mod a < y mod a
            out.print("? " + x);
            out.println(" " + y);
            // return ask(x, y);
            String s = in.next();
            return s.equals("y");
        }

        public void solve(int test) {
            int l = 0, r = 1;
            while (query(l, r)) {
                l <<= 1;
                r <<= 1;
                if (l == 0)
                    l++;
            }
            // l mod a >= r mod a
            // a in [l+1,r]
            int lo = l, hi = r, mid;
            while (lo < hi - 1) {
                mid = lo + (hi - lo) / 2;
                if (query(l, mid))
                    lo = mid;
                else
                    hi = mid;
            }
            out.println("! " + hi);
        }
    }

    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out, autoFlush);
        int t = 1;
        // t = in.nextInt();
        while (true) {
            Testcase solver = new Testcase();
            String s = in.next();
            if (!s.equals("start"))
                break;
            // out.printf("Case #%d: ", i);
            solver.solve(t++);
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
