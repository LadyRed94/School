using System;


// Names: Alexandra Feely, Mitchell White, Andrew CHamberlain

namespace DSA_Lab_3
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            int[] toSearch = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 10, 10 };
            Console.WriteLine(Problem_1(toSearch));
            string Stuff = "Hello there children";
            Console.WriteLine(Problem_2(Stuff.ToCharArray()));
            Problem_3(5);
        }

        //There is some way to get binary search speed
        public static int Problem_1 (int [] sorted)
        {
            int even = 0;
            int odd = 1;

            while (true)
            {
                if(sorted[even] != sorted[odd])
                {
                    return sorted[even];
                }

                else
                {
                    //Console.Write(even + " ");
                    //Console.WriteLine(odd + " ");
                    even += 2;
                    odd += 2;
                }

            }
        }

        //Apparantly we misundertood the requirements as we could use more space than we thought
        //Alexandra's fault (She's writing this), 
        public static char[] Problem_2 (char[] reverse)
        {
            Array.Reverse(reverse);
            string delimiter = " ";

            for (int i = 0; i<reverse.Length; i++)
            {

            }

            while (true)
            {

            }
        }

        //didn't get to thins, but we believe that it is a binary search algorithm
        public static int Problem_3 (int K)
        {
            return K;
        }
    }
}
