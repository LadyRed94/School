import sqlite3

dbConnection = sqlite3.connect("/Users/alex/Desktop/Desktop/Evergreen State College/Winter_2021/Databases/PythonStuff/sTunes.db")

curs = dbConnection.cursor()
curs.execute("""
            SELECT Title, Name
            FROM albums
            Left JOIN artists ON artists.ArtistId = albums.ArtistId
            """)

testList = curs.fetchall()

#print(curs.fetchone())
#print(curs.fetchmany())
#print(curs.fetchall())

for i in testList:
    print(i)

curs.close()
dbConnection.commit()

dbConnection.close()
print("I did it!")