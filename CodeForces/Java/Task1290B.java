import java.io.*;
import java.util.*;

public class Task1290B {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;

    static class Testcase {
        public void solve(int test) {
            StringBuilder s = new StringBuilder(in.next());
            int n = s.length();
            int[][] cnt = new int[n + 1][26];
            Arrays.fill(cnt[0], 0);
            for (int i = 1; i <= n; i++) {
                int c = s.charAt(i - 1) - 'a';
                for (int j = 0; j < 26; j++)
                    cnt[i][j] = cnt[i - 1][j];
                cnt[i][c]++;
            }
            int m = in.nextInt();
            for (int i = 0; i < m; i++) {
                int l = in.nextInt();
                int r = in.nextInt();
                boolean yes = false;
                int count = 0;
                for (int j = 0; j < 26; j++)
                    if (cnt[r][j] - cnt[l - 1][j] > 0)
                        count++;
                if (r == l)
                    yes = true;
                else if (s.charAt(l - 1) != s.charAt(r - 1))
                    yes = true;
                else if (count > 2)
                    yes = true;
                out.println(yes ? "Yes" : "No");
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
