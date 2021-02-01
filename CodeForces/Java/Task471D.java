import java.io.*;
import java.util.*;

public class Task471D {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;

    static class KMP {
        public int[][] aut;

        // wont work on primitive types
        static <T> int[] kmp(T[] s) {
            int n = s.length;
            int[] lps = new int[n];
            Arrays.fill(lps, 0);
            for (int i = 1; i < n; i++) {
                int j = lps[i - 1];
                while (j > 0 && s[i] != s[j])
                    j = lps[j - 1];
                if (s[i] == s[j])
                    j++;
                lps[i] = j;
            }
            return lps;
        }

        public void kmp_aut(String st) {
            char base = 'a';
            int n = st.length();
            Character[] s = new Character[n + 1];
            for (int i = 0; i < n; i++)
                s[i] = st.charAt(i);
            s[n] = '#';
            n++;
            int[] pi = kmp(s);
            aut = new int[n][26];
            for (int i = 0; i < n; i++) {
                for (int c = 0; c < 26; c++) {
                    if (i > 0 && base + c != s[i])
                        aut[i][c] = aut[pi[i - 1]][c];
                    else
                        aut[i][c] = i + (base + c == s[i] ? 1 : 0);
                }
            }
        }
    }

    static class Testcase {
        public void solve(int test) {
            int n = in.nextInt(), w = in.nextInt();
            int[] a = new int[n], b = new int[w];
            for (int i = 0; i < n; i++)
                a[i] = in.nextInt();
            for (int i = 0; i < w; i++)
                b[i] = in.nextInt();
            if (w == 1) {
                out.println(n);
                return;
            } else if (n < w) {
                out.println(0);
                return;
            }
            Integer[] arr = new Integer[n + w - 1];
            for (int i = 1; i < w; i++)
                arr[i - 1] = b[i] - b[i - 1];
            arr[w - 1] = inf;
            for (int i = 1; i < n; i++)
                arr[w + i - 1] = a[i] - a[i - 1];

            int[] lps = KMP.kmp(arr);
            int ans = 0;
            for (int i = w; i < n + w - 1; i++)
                if (lps[i] == w - 1)
                    ans++;
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
