import java.io.*;
import java.util.*;

public class Task1304D {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class Testcase {
        public void solve(int test) {
            int n = in.nextInt();
            String s = in.next();
            int[] ans = new int[n];
            int num = n, last = 0;
            for (int i = 0; i < n; i++) {
                if (i == n - 1 || s.charAt(i) == '>') {
                    for (int j = i; j >= last; j--)
                        ans[j] = num--;
                    last = i + 1;
                }
            }
            for (int i = 0; i < n; i++)
                out.print(ans[i] + " ");
            out.println();
            num = 1;
            last = 0;
            for (int i = 0; i < n; i++) {
                if (i == n - 1 || s.charAt(i) == '<') {
                    for (int j = i; j >= last; j--)
                        ans[j] = num++;
                    last = i + 1;
                }
            }
            for (int i = 0; i < n; i++)
                out.print(ans[i] + " ");
            out.println();
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
