import java.io.*;
import java.util.*;

public class Task1178E {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class Testcase {
        public void solve(int test) {
            char[] s = in.next().toCharArray();
            int n = s.length;
            int l = 0, r = n - 1;
            StringBuilder ans = new StringBuilder();
            while (r - l + 1 > 3) {
                int[] cnt = new int[3];
                Arrays.fill(cnt, 0);
                cnt[s[l] - 'a']++;
                cnt[s[l + 1] - 'a']++;
                cnt[s[r - 1] - 'a']++;
                cnt[s[r] - 'a']++;
                for (int i = 0; i < 3; i++)
                    if (cnt[i] == 2) {
                        ans.append((char) (i + 'a'));
                        break;
                    }
                l += 2;
                r -= 2;
            }
            int k = ans.length();
            if (l <= r)
                ans.append(s[l]);
            for (int i = k - 1; i >= 0; i--)
                ans.append(ans.charAt(i));
            out.println(ans);
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
