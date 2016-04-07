public class Solution {
    public void nextPermutation(int[] num) {
        if(num.length == 0) return;
        int i = num.length - 2;
        while(i >= 0 && num[i] >= num[i+1]) i--;
        if(i < 0) {
            Arrays.sort(num);
            return;
        }
        for(int j = num.length - 1; j >= 0; j--) {
            if(num[j] > num[i]) {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
                Arrays.sort(num, i+1, num.length);
                break;
            }
        }
    }
}