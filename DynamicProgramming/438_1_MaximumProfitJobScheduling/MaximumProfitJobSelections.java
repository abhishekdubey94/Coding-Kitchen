import java.util.*;

public class MaximumProfitJobSelections {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];
        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        Arrays.sort(jobs, Comparator.comparingInt(a -> a[1]));
        int[] dp = new int[n + 1];
        for (int i = 0; i < n; i++) {
            dp[i + 1] = Math.max(dp[i], dp[i + 1]);
            int lo = 0, hi = i;
            while (lo < hi - 1) {
                int m = lo + (hi - lo) / 2;
                if (jobs[m][1] <= jobs[i][0]) {
                    lo = m;
                } else {
                    hi = m;
                }
            }
            dp[i + 1] = Math.max(dp[i + 1], ((jobs[lo][1] <= jobs[i][0]) ? dp[lo + 1] : 0) + jobs[i][2]);
        }
        return dp[n];
    }

    public static void main(String[] args) {
        MaximumProfitJobSelections obj = new MaximumProfitJobSelections();
        int startTime[] = { 1, 2, 3, 3 };
        int endTime[] = { 3, 4, 5, 6 };
        int profit[] = { 50, 10, 40, 70 };

        System.out.println(obj.jobScheduling(startTime, endTime, profit));

    }
}