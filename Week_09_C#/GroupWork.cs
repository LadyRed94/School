using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SQLite;

// GROUP MEMBERS: JunBo Park, Alexandra Freely, Paul Morris

namespace sqliteStuff
{
    class GroupWork
    {
        public static void GroupWork1()
        {
            string connectionString = "Data Source = sTunes.db;";
            using var connection1 = new SQLiteConnection(connectionString);
            connection1.Open();
            SQLiteCommand command1 = connection1.CreateCommand();
           

            command1.CommandText = @" SELECT alb.Title, ar.Name
                                    FROM albums AS alb
                                    JOIN artists AS ar
                                    ON alb.artistId = ar.artistId;";

            using var reader1 = command1.ExecuteReader();

            while (reader1.Read())
            {
                Console.WriteLine($"{reader1.GetString(0)} {reader1.GetString(1)}");
            }

        }

        public static void GroupWork2()
        {
            string connectionString = "Data Source = sTunes.db;";
            using var connection1 = new SQLiteConnection(connectionString);
            connection1.Open();
            SQLiteCommand command1 = connection1.CreateCommand();


            command1.CommandText = @" SELECT ar.Name, COUNT(alb.Name)
                                    FROM albums AS alb
                                        JOIN artists AS ar
                                        ON alb.artistId = ar.artistId
                                    GROUP BY ar.Name;";

            using var reader1 = command1.ExecuteReader();

            while (reader1.Read())
            {
                Console.WriteLine($"{reader1.GetString(0)} {reader1.GetString(1)}");
            }

        }



    }
}
