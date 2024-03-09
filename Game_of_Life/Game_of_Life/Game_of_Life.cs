using System;

namespace Game_of_Life
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            GameOfLife(5, 5, 3);
            //Console.WriteLine("I am finished");
        }

        
        public static void GameOfLife(int length, int width, int alive)
        {
            Board board = new Board(length, width, alive);
            board.PrintBoard();
        }

        /*
        public static Board Update(Board board)
        {
            int[][] replace = board.content;

            for (int i = 0; i < board.len; i++)
            {
                for (int i = 0; i < board.wid; i++)
                {
                    if(board.content[i][j] == 0)
                    {
                        int count = 0;
                        for()
                    }
                }
            }
        } */

    }

    class Board
    {
        //public variables
        public int len;
        public int wid;
        public int alive;
        public int[][] content;

        //Creates and populates Board
        public Board(int length, int width, int ToLive)
        {
            len = length;
            wid = width;
            alive = ToLive;

            content = new int[length][];

            for (int i = 0; i < length; i++)
            {
                content[i] = new int[width];
            }

            if (alive != 0)
            {
                int count = 0;
                int chance = 5;
                Random rnd = new Random();

                while (count != alive)
                {
                    for (int i = 0; i < length; i++)
                    {
                        if (count == alive)
                        {
                            continue;
                        }

                        for (int j = 0; j < length; j++)
                        {
                            if (count == alive)
                            {
                                continue;
                            }

                            if (chance > rnd.Next(0, 100))
                            {
                                content[i][j] = 1;
                                count++;
                                if (count == alive)
                                {
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
        
        }

        //prints the state of the board
        public void PrintBoard()
        {
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < wid; j++)
                {
                    Console.Write(" " + content[i][j]);
                }

                Console.WriteLine(" ");

            }
        }
    }
}