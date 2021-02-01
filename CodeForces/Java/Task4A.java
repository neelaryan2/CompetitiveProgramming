import java.io.*;
import java.util.*;

public class Task4A {
    private static InputReader in;
    private static PrintWriter out;

    private static boolean autoFlush = false;

    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out, autoFlush);
        int t = 1;
        // t = in.nextInt();
        Testcase solver = new Testcase();
        for (int i = 1; i <= t; i++) {
            // out.printf("Case #%d: ", i);
            solver.solve(i);
        }
        out.close();
    }

    static class Testcase {
        public void solve(int test) {
            int w = in.nextInt();
            if (w != 2 && (w & 1) != 1)
                out.println("YES");
            else
                out.println("NO");
        }
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
}
