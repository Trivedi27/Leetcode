class Solution {
    static class Cell {
        int v;
        char d; // 'H' for none, 'U' for up, 'S' for side, 'D' for diagonal
    }

    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();
        Cell[][] cost = new Cell[m + 1][n + 1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                cost[i][j] = new Cell();
                if (i == 0 || j == 0) {
                    cost[i][j].v = 0;
                    cost[i][j].d = 'H';
                } else if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    cost[i][j].v = cost[i - 1][j - 1].v + 1;
                    cost[i][j].d = 'D';
                } else {
                    if (cost[i - 1][j].v > cost[i][j - 1].v) {
                        cost[i][j].v = cost[i - 1][j].v;
                        cost[i][j].d = 'U';
                    } else {
                        cost[i][j].v = cost[i][j - 1].v;
                        cost[i][j].d = 'S';
                    }
                }
            }
        }
        int count = printLCS(m, n, cost, text1, text2);
        return count;
    }

    int printLCS(int i, int j, Cell[][] cost, String text1, String text2) {
        if (i == 0 || j == 0)
            return 0;
        if (cost[i][j].d == 'D') {
            int count = printLCS(i - 1, j - 1, cost, text1, text2) + 1;
            System.out.print(text1.charAt(i - 1));
            return count;
        } else if (cost[i][j].d == 'U') {
            return printLCS(i - 1, j, cost, text1, text2);
        } else { // 'S'
            return printLCS(i, j - 1, cost, text1, text2);
        }
    }
}