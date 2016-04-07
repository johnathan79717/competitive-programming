import java.util.*;
import java.math.*;

public class Main {
  static String preProcess(String s) {
    char[] str = new char[2 * s.length() + 3];
    str[0] = '^';
    for(int i = 0; i < s.length(); i++) {
      str[2*i+1] = '#';
      str[2*i+2] = s.charAt(i);
    }
    str[2*s.length() + 1] = '#';
    str[2*s.length() + 2] = '$';
    return new String(str);
  }
  static int M = 1000000007;
  static int numPalindromes(String s) {
    long[] sum = new long[1 + s.length()];
    long[] pow = new long[1 + s.length()];
    HashSet<Long> set = new HashSet<Long>();
    pow[0] = 1;
    for(int i = 0; i < s.length(); i++) {
      sum[i+1] = (sum[i] * 27 + (s.charAt(i) - 'a' + 1)) % M;
      pow[i+1] = pow[i] * 27 % M;
    }
    String T = preProcess(s);
    int n = T.length();
    int[] P = new int[n];
    int C = 0, R = 0, cnt = 0;
    for(int i = 1; i < n-1; i++) {
      int i_mirror = 2*C - i;
      P[i] = (R > i) ? Math.min(R - i, P[i_mirror]) : 0;
      while(T.charAt(i + 1 + P[i]) == T.charAt(i - 1 - P[i])) {
        P[i]++;
        // palindromes.add(s.substring((i - P[i]) / 2, (i + P[i]) / 2));
        // System.out.println(i);
        // System.out.println(P[i]);
        if(T.charAt(i + P[i]) == '#') {
          int l = (i - P[i]) / 2;
          int r = (i + P[i]) / 2;
          long hash = (sum[r] - sum[l] * pow[r - l]) % M;
          if(hash < 0) hash += M;
          if(!set.contains(hash)) {
            set.add(hash);
            cnt++;
          // System.out.println(s.substring((i - P[i]) / 2, (i + P[i]) / 2));
          }
        }
      }
      if(i + P[i] > R) {
        C = i;
        R = i + P[i];
      }
    }
    // Iterator<String> it = palindromes.iterator();
    // while(it.hasNext())
    //   System.out.println(it.next());
    // return palindromes.size();
    return cnt;
  }

  public static int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String T = sc.next();
    int N = sc.nextInt();
    BigInteger m = BigInteger.valueOf(numPalindromes(T));
    // System.out.println(m);
    BigInteger ans = BigInteger.valueOf(0);
    for(int i = 0; i < N; i++) {
      ans = ans.add(m.pow(gcd(i, N)));
      // System.out.println(ans);
    }
    if(N % 2 == 1)
      ans = ans.add(m.pow(N / 2 + 1).multiply(BigInteger.valueOf(N)));
    else {
      ans = ans.add(m.pow(N / 2).multiply(BigInteger.valueOf(N / 2)));
      ans = ans.add(m.pow(N / 2 + 1).multiply(BigInteger.valueOf(N / 2)));
    }
    ans = ans.divide(BigInteger.valueOf(N * 2));
    System.out.println(ans);
  }
}