import sqlite3

dbConnection = sqlite3.connect("/Users/alex/Desktop/Desktop/Evergreen State College/Winter_2021/Databases/PythonStuff/wow.db")

curs = dbConnection.cursor()
curs.execute("""
            SELECT *
            FROM products
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