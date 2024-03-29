﻿using System;

namespace Week1Algrorithms
{
    class Car
    {
        public string vin;
    }
    class MainClass
    {
        static void Main(string[] args)
        {
            Car myCar = new Car();
            myCar.vin = "TESC";
            Console.WriteLine(myCar.vin);

            int[] storeValue = new int[5];

            //Console.WriteLine(IsPrime(1));
            //Console.WriteLine(IsPrime(2));
            //Console.WriteLine(IsPrime(3));
            //Console.WriteLine(IsPrime(4));
            //Console.WriteLine(IsPrime(5));
            //Console.WriteLine(IsPrime(6));
            //Console.WriteLine(IsPrime(7));
            //Console.WriteLine(IsPrime(8));
            //Console.WriteLine(IsPrime(9));

            PrintPrimes(2, 30);
            PrintNextPrimes(2020, 5);

            for (int i = 0; i < storeValue.Length; i++)
            {
                //Different ways format text in C#
                //Console.Write("Enter Today's sales for store "+ (i + 1) + ":");
                //Console.Write("Enter Today's sales for store {0}: ", i + 1);
                Console.Write($"Enter Today's sales for store {i + 1}: ");

                //will display number with 2 decimal places because of the F2
                //Console.Write("Enter Today's sales for store {0:F2}: ", i + 1);

                //LOOK AT SLIDES FOR MORE EXAMPLES!!!!

                //Read User's input
                storeValue[i] = int.Parse(Console.ReadLine());

            }

            Console.WriteLine("SALES BAR CHART\n(Each * = 100$)");

            for (int i = 0; i < storeValue.Length; i++)
            {
                Console.WriteLine($"Store {i + 1}: {DisplayAsterisk(storeValue[i]/100)}");
            }
        }

        #region
        static string DisplayAsterisk(int num)
        {
            string answer = "";
            for (int i = 0; i < num; i++)
            {
            //Console.Write("*");
            answer += "*";
            }

            return answer;
        }
        #endregion

        static void PrintNextPrimes(int start, int amount)
        {
            int tally = 0;
            int current = start;

            while(tally < amount) //search for prime number
            {
                if(IsPrime(current))
                {
                    tally++; //found a prime
                    Console.WriteLine(current); //Display Prime
                }

                current++; //move to next number
            }
        }

        static void PrintPrimes(int start, int end)
        {
            for(int i = start; i <= end; i++)
            {
                if(IsPrime(i))
                {
                    Console.WriteLine(i);
                }
            }
        }

        static bool IsPrime(int num)
        {
            if(num == 2)
            {
                return true;
            }

            else if(num % 2 == 0) //checks for even numbers
            {
                return false;
            }

            for (int i = 3; i <= Math.Sqrt(num); i += 2)
            {
                if (num % i == 0) //check if i divides num
                {
                    return false; //proper divisor found
                }
            }

            return true;
        }
        
    }
}
