/* Lab DSA 7
 * 
 * Alexandra Feely, Tai Nguyen, George Meloy, Krystine Thai
 * 
 */

using System;
using System.Collections;
using System.Collections.Generic;

namespace LabDSA_Week7
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter a number n: ");
            int n = Int32.Parse(Console.ReadLine());

            //PROBLEM 1:
            //Console.WriteLine("Enter the passwords that you want to to check:");

            //string[] pass = new string[n];

            //ArrayList violations = new ArrayList();

            //for (int i = 0; i < n; i++)
            //{
            //    pass[i] = Console.ReadLine();
            //}
            //for (int i = 0; i < n; i++)
            //{
            //    violations = PasswordStrength(pass[i]);

            //    if(violations.Count == 0)
            //        Console.WriteLine($"Password {i+1} is valid");
            //    else
            //    {
            //        Console.Write($"Password {i+1} is invalid by rules(s) ");
            //        foreach(var v in violations)
            //            Console.Write(v + " ");
            //    }
            //    Console.WriteLine();
            //}

            //PROBLEM 5:
            Console.WriteLine("Enter some sentences: ");
            string[] input5 = new string[n];

            for (int i = 0; i < n; i++)
            {
                input5[i] = Console.ReadLine();
            }

            for (int i = 0; i < n; i++)
            {
                if (StarWars(input5[i]))
                    Console.WriteLine($"Sentence {i + 1} is Star War Compliant.");
                else
                    Console.WriteLine($"Sentence {i + 1} is not Star War Compliant.");
            }


        }

        public static ArrayList PasswordStrength(string input)
        {
            ArrayList violations = new ArrayList();
            

            if (input.Length < 6 && input.Length > 20)
            {
                violations.Add (1);//rule 1
            }

            bool IsUpper = false;
            bool IsLower = false;
            bool IsDigit = false;
            bool Symbol = false;
            bool BlankSpace = false;

            foreach (char c in input)
            {
                if (char.IsLower(c))
                    IsLower = true;

                if (char.IsUpper(c))
                    IsUpper = true;

                if (char.IsDigit(c))
                    IsDigit = true;

                if (c != '$' && (char.IsSymbol(c) || char.IsPunctuation(c)))
                    Symbol = true;

                if (c == ' ')
                    BlankSpace = true;

            }

            if(IsUpper ==false && IsLower==false)
                violations.Add(2);//rule 2

            if (IsDigit == false)
                violations.Add(3); //rule 3

            if (Symbol == false)
                violations.Add(4); //rule 4

            if (BlankSpace == true)
                violations.Add(5); //rule 5

            return violations;
        }

        public static bool StarWars(string input)
        {
            bool IsStarWarCompliant = false;
            input = input.ToLower();

            int r = 0;
            int d = 0;
            int c = 0;
            int p = 0;
            int o = 0;

            foreach (char ch in input)
            {
                if (char.ToLower (ch) == 'r')
                    r++;

                if (char.ToLower(ch) == 'd')
                    d++;

                if (char.ToLower(ch) == 'c')
                    c++;

                if (char.ToLower(ch) == 'p')
                    p++;

                if (char.ToLower(ch) == 'o')
                    o++;

            }

            //rule 5
            bool IsDup =false;
            string[] arrInput = input.Split(' ');

            for (int i = 0; i < arrInput .Length; i++)
            {
                for (int j = i+1; j < arrInput .Length; j++)
                {
                    if (arrInput[i] == arrInput[j])
                        IsDup = true;
                }
            }

            if (r == 2 && d == 2 && c == 3 && p == 1 && o == 1 && !IsDup)
                IsStarWarCompliant = true;
            

            return IsStarWarCompliant;
        }

        public static bool IsLatinSquare(int [,] input)
        {
            bool IsLatinSquare = false;
            bool IsDup = false;

            Dictionary<int, int> firstRow = new Dictionary<int,int>();
            for (int i = 0; i < input.GetLength(1); i++)
            {
                //add the first row's elements to the firstRow dict
                //...
            }

            for (int i = 0; i < input.GetLength(0); i++)
            {
                for (int j = 0; j < input.GetLength (1); j++)
                {
                    
                }
            }


            return IsLatinSquare;
        }
    }
}
 