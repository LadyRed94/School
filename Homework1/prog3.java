import static java.lang.System.out;
import java.util.Scanner;

//Prints biggest number from user

public class prog3{

public static void main (String[] args){

   //Gets 1st number
   System.out.println("Enter the 1st number: ");
   Scanner s1 = new Scanner(System.in);
   int num1 = s1.nextInt();

   //Gets second number
   System.out.println("Enter the 2nd number: ");
   Scanner s2 = new Scanner(System.in);
   int num2 = s2.nextInt();
   
   //Prints largest number
   if(num1>num2){
      System.out.printf(num1 + " is bigger%n");
      num2=num1;
      }
   else{
      System.out.printf(num2 + " is bigger%n");
      num1=num2;
      } 
              
   return;
   }
}