import java.io.*;
import java.util.*;

public class Task540C {
    private static InputReader in;
    private static PrintWriter out;
    private static boolean autoFlush = false;
    static final int inf = (int) 1e9 + 7;
    static final long infL = (long) 1e18 + 7;

    static class Testcase {
        boolean[][] g, vis;
        int r1, c1;
        int r2, c2;
        static int[] dx = new int[] { -1, 0, 1, 0 };
        static int[] dy = new int[] { 0, -1, 0, 1 };

        public boolean dfs(int x, int y) {
            vis[x][y] = true;
            // dbg(vis);
            if (x == r2 && y == c2)
                return true;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (vis[nx][ny])
                    continue;
                if (dfs(nx, ny)) {
                    g[x][y] = true;
                    return true;
                }
            }
            return false;
        }

        public void dbg(boolean[][] a) {
            for (int i = 1; i < a.length - 1; i++) {
                for (int j = 1; j < a[i].length - 1; j++) {
                    System.err.print(a[i][j] ? 'X' : '.');
                }
                System.err.println();
            }
            System.err.println();
        }

        public void solve(int test) {
            int n = in.nextInt(), m = in.nextInt();
            g = new boolean[n + 2][m + 2];
            vis = new boolean[n + 2][m + 2];
            for (int i = 0; i <= n + 1; i++) {
                Arrays.fill(g[i], true);
                Arrays.fill(vis[i], true);
            }

            for (int i = 1; i <= n; i++) {
                String s = in.next();
                for (int j = 1; j <= m; j++) {
                    g[i][j] = (s.charAt(j - 1) == 'X');
                    vis[i][j] = g[i][j];
                }
            }

            r1 = in.nextInt();
            c1 = in.nextInt();
            r2 = in.nextInt();
            c2 = in.nextInt();

            // dbg(vis);
            vis[r1][c1] = vis[r2][c2] = false;

            // dbg(vis);
            boolean b = dfs(r1, c1);

            // dbg(vis);

            if (!b) {
                out.println("NO");
                return;
            }
            if (!(r1 == r2 && c1 == c2) && g[r2][c2]) {
                out.println("YES");
            } else {
                for (int i = 0; i < 4; i++) {
                    int nx = r2 + dx[i];
                    int ny = c2 + dy[i];
                    if (!g[nx][ny]) {
                        out.println("YES");
                        return;
                    }
                }
                out.println("NO");
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
