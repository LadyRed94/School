import static java.lang.System.out;
import java.util.Scanner;

//Runs while loop

public class prog4{

public static void main (String[] args){

   //Gets numerical condition
   System.out.println("Enter a value: ");
   Scanner s1 = new Scanner(System.in);
   int num1 = s1.nextInt();
   int val = 1;
   
   // make sure num1 is not negative
   if( num1 < 0) {
      num1 = -num1;
   }
   
   //runs the while loop
   while(val < num1) {
      System.out.printf(val + "%n");
      val = val*2;
   }
}
}