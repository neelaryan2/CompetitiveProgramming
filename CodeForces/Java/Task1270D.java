import java.io.*;
import java.util.*;

public class Task1270D {
    static InputReader in;
    static PrintWriter out;
    static boolean autoFlush = true;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class Testcase {
        public int pos, val;
        public int[] idx;

        public void ask() {
            int[] arr = new int[] { 321376743, 64146243, 670700897, 575471266, 303438330, 113152943, 114637600,
                    468461998, 868859319, 744812570 };
            int m = 1;
            ArrayList<Integer> tmp = new ArrayList<Integer>();
            for (int i : idx)
                tmp.add(arr[i]);
            Collections.sort(tmp);
            val = tmp.get(m - 1);
            for (int i = 0; i < arr.length; i++)
                if (arr[i] == val)
                    pos = i;
            out.println((pos + 1) + " " + val);
        }

        public void query() {
            out.print("?");
            for (int i : idx)
                out.print(" " + (i + 1));
            out.println();
            // ask();
            pos = in.nextInt() - 1;
            if (pos == -2)
                System.exit(0);
            val = in.nextInt();
        }

        public void solve(int test) {
            int n = in.nextInt(), k = in.nextInt();
            // int n = 10, k = 9;
            idx = new int[k];
            for (int i = 0; i < k; i++)
                idx[i] = i;
            query();
            int ref = pos, refval = val, t = 0;
            for (int i = 0; i < k; i++) {
                if (i == ref)
                    continue;
                idx[i] = k;
                query();
                idx[i] = i;
                if (pos == ref)
                    t++;
            }
            idx[ref] = k;
            query();
            if (val < refval)
                out.println("! " + (t + 1));
            else
                out.println("! " + (k - t));
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
