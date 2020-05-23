import java.util.ArrayList;
import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Integer> nums = new ArrayList<Integer>();


        while(input.hasNext()){
            int num = input.nextInt();
            if(num != -999999) {
                nums.add(num);
            }
            else {
                BigInteger res = BigInteger.valueOf(Integer.MIN_VALUE);
                BigInteger temp;
                for(int i=0;i<nums.size();i++){
                    temp = BigInteger.valueOf(1);
                    for(int j=i;j<nums.size();j++) {
                        BigInteger temp_num = BigInteger.valueOf(nums.get(j));
                        temp = temp.multiply(temp_num);
                        if (res.compareTo(temp) <0) {
                            res = temp;
                        }
                    }
                }
                System.out.println(res.toString());
                nums.clear();
            }
        }
    }
}