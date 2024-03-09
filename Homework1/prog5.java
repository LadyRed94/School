import static java.lang.System.out;
import java.util.Scanner;

//Runs for loop

public class prog5{

public static void main (String[] args){

   //Gets numerical condition
   System.out.println("Enter a value: ");
   Scanner s1 = new Scanner(System.in);
   int num1 = s1.nextInt();
   
   // make sure num1 is not negative
   if( num1 < 0) {
      num1 = -num1;
   }
   
   for (int i = 0; i < num1; i++) {
    System.out.printf(i + " %n");
  }
}
}