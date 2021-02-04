import java.io.*;
import java.util.*;

public class Task780D {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class Testcase {
        public void solve(int test) {
            int n = in.nextInt();
            String[] arr = new String[n];
            HashMap<String, ArrayList<Integer>> map = new HashMap<String, ArrayList<Integer>>();
            for (int i = 0; i < n; i++) {
                String a = in.next(), b = in.next();
                arr[i] = a.substring(0, 2) + b.substring(0, 1);
                map.putIfAbsent(a.substring(0, 3), new ArrayList<Integer>());
                map.get(a.substring(0, 3)).add(i);
            }
            Iterator<String> it = map.keySet().iterator();
            LinkedList<String> q = new LinkedList<String>();

            while (it.hasNext()) {
                String e = it.next();
                if (map.get(e).size() > 1) {
                    for (int u : map.get(e)) {
                        q.add(arr[u]);
                    }
                    it.remove();
                }
            }

            while (q.size() > 0) {
                String v = q.poll();
                if (map.get(v) == null)
                    continue;
                for (int u : map.get(v)) {
                    q.add(arr[u]);
                }
                map.remove(v);
            }

            it = map.keySet().iterator();
            while (it.hasNext()) {
                String e = it.next();
                int i = map.get(e).get(0);
                arr[i] = e;
            }

            Set<String> mem = new HashSet<String>();
            for (String s : arr) {
                if (mem.contains(s)) {
                    out.println("NO");
                    return;
                }
                mem.add(s);
            }

            out.println("YES");
            for (String s : arr)
                out.println(s);

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
