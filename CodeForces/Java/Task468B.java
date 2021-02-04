import java.io.*;
import java.util.*;

public class Task468B {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class Testcase {
        HashMap<Integer, Integer> map;
        ArrayList<ArrayList<Integer>> adj;
        int[] arr;
        boolean[] vis;
        ArrayList<Integer> path;

        public void dfs(int v) {
            vis[v] = true;
            path.add(v);
            for (int u : adj.get(v)) {
                if (vis[u])
                    continue;
                dfs(u);
            }
        }

        public void solve(int test) {
            int n = in.nextInt(), a = in.nextInt(), b = in.nextInt();
            arr = new int[n];
            map = new HashMap<>();
            adj = new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i < n; i++) {
                arr[i] = in.nextInt();
                map.put(arr[i], i);
                adj.add(new ArrayList<Integer>());
            }
            int[] ans = new int[n];
            if (a == b) {
                Arrays.fill(ans, 0);
                for (int i = 0; i < n; i++) {
                    if (!map.containsKey(a - arr[i])) {
                        out.println("NO");
                        return;
                    }
                }
            } else {
                int[] self = new int[n];
                Arrays.fill(self, -1);
                for (int i = 0; i < n; i++) {
                    if (map.containsKey(a - arr[i]) && a != 2 * arr[i])
                        adj.get(i).add(map.get(a - arr[i]));
                    if (map.containsKey(b - arr[i]) && b != 2 * arr[i])
                        adj.get(i).add(map.get(b - arr[i]));
                    if (2 * arr[i] == a)
                        self[i] = 0;
                    if (2 * arr[i] == b)
                        self[i] = 1;
                }

                vis = new boolean[n];
                path = new ArrayList<Integer>();

                for (int i = 0; i < n; i++) {
                    if (self[i] != -1 && !vis[i]) {
                        path.clear();
                        dfs(i);
                        if (path.size() % 2 == 1) {
                            ans[path.get(0)] = self[path.get(0)];
                            path.remove(0);
                        }
                        for (int j = 0; j + 1 < path.size(); j += 2) {
                            int cur = 0;
                            if (arr[path.get(j)] + arr[path.get(j + 1)] == b)
                                cur = 1;
                            ans[path.get(j)] = cur;
                            ans[path.get(j + 1)] = cur;
                        }
                    }
                }
                for (int i = 0; i < n; i++) {
                    if (adj.get(i).size() == 1 && !vis[i]) {
                        path.clear();
                        dfs(i);
                        if (path.size() % 2 == 1) {
                            out.println("NO");
                            return;
                        }
                        for (int j = 0; j + 1 < path.size(); j += 2) {
                            int cur = 0;
                            if (arr[path.get(j)] + arr[path.get(j + 1)] == b)
                                cur = 1;
                            ans[path.get(j)] = cur;
                            ans[path.get(j + 1)] = cur;
                        }
                    }
                }
                for (int i = 0; i < n; i++) {
                    if (!vis[i]) {
                        path.clear();
                        dfs(i);
                        if (path.size() % 2 == 1) {
                            out.println("NO");
                            return;
                        }
                        for (int j = 0; j < path.size(); j += 2) {
                            int cur = 0;
                            if (arr[path.get(j)] + arr[path.get(j + 1)] == a)
                                cur = 1;
                            ans[path.get(j)] = cur;
                            ans[path.get(j + 1)] = cur;
                        }
                    }
                }
            }
            out.println("YES");
            for (int i : ans)
                out.print(i + " ");
            out.println();
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
