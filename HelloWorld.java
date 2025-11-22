package Sakurakokan;
import java.util.Scanner;
public class HelloWorld{
    public static boolean isprime(int num){
        for(int i=2;i<=Math.sqrt(num);i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        if(isprime(num)){
            System.out.println("Yes");
        }else System.out.println("No");
    }
}