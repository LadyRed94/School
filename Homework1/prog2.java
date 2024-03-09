import static java.lang.System.out;
import java.math.*;
import java.util.Scanner;

//Adds 2 numbers and prints the result

public class prog2{

public static void main (String[] args){

   //Gets 1st number
   System.out.println("Enter a number: ");
   Scanner s1 = new Scanner(System.in);
   int num1 = s1.nextInt();

   //Gets second number
   System.out.println("Enter another: ");
   Scanner s2 = new Scanner(System.in);
   int num2 = s2.nextInt();
   
   //prints the sum of the two numbers
   System.out.printf(num1 + " + " + num2 + " = " + Integer.sum(num1,num2));
   
   return;
   }
}