import java.util.*;

public class CoinsOfByteland {
  int[] c;
  int n;
  final int M = 1000000007;
  public int countCoinSystems(int[] maxSum) {
    c = maxSum;
    n = maxSum.length;
    int[] lb = new int[n];
    int[] ub = new int[n];
    dfs(lb, ub, n - 1);
	}

  public void dfs(int[] lb, int[] ub, int j) {
    if(j < 0) {
      long cnt = 0;
      for(int i = 0; i < n; i++) {
        if(ub[i] >= lb[i])
          cnt = cnt * (ub[i] - lb[i] + 1) % M;
      }
      ans = (ans + cnt) % M;
    }
  }
};


// Powered by FileEdit
