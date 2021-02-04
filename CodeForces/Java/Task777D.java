import java.io.*;
import java.util.*;

public class Task777D {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;

    static class Testcase {
        StringBuilder[] arr;

        public void modify(int l, int r, int lvl) {
            if (l >= r)
                return;
            int nxt = inf, i;
            for (i = r; i >= l; i--) {
                if (lvl >= arr[i].length())
                    break;
                int cur = (int) arr[i].charAt(lvl);
                if (cur > nxt)
                    break;
                nxt = cur;
            }
            for (int j = l; j <= i; j++) {
                arr[j].setLength(Math.min(lvl, arr[j].length()));
            }
            for (int j = i + 1; j <= r;) {
                char c = arr[j].charAt(lvl);
                int idx = j;
                while (idx <= r && arr[idx].charAt(lvl) == c)
                    idx++;
                modify(j, idx - 1, lvl + 1);
                j = idx;
            }
        }

        public void solve(int test) {
            int n = in.nextInt();
            arr = new StringBuilder[n];
            for (int i = 0; i < n; i++)
                arr[i] = new StringBuilder(in.next());
            modify(0, n - 1, 1);
            for (int i = 0; i < n; i++)
                out.println(arr[i]);
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
