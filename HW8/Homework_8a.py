import sqlite3

sqlite3.connect("VISITORS.db")
dbConnection = sqlite3.connect("VISITORS.db")
curs = dbConnection.cursor()

#Ensures tables exist in database
def checkTable():

    #Creates visits table
    curs.execute("""
        CREATE TABLE IF NOT EXISTS VISITS
        (firstname TEXT,
        lastname TEXT,
        visit TEXT);
        """)

    #Creats logs table
    curs.execute("""
        CREATE TABLE IF NOT EXISTS LOGS
        (firstname TEXT,
        lastname TEXT,
        visit TEXT);
        """)
    
    #Checks for trigger
    curs.execute("""
        CREATE TRIGGER IF NOT EXISTS updateVisitsDate AFTER UPDATE
        ON VISITS
        BEGIN
            INSERT INTO LOGS
            VALUES(NEW.firstname, NEW.lastname, NEW.visit);
        END;
        """)

checkTable()

def main ():

    #runs if visitor is new
    def newVisitor():

        #adds new visitor to the database
        curs.execute("""
                INSERT INTO VISITS
                VALUES(?, ?, CURRENT_TIMESTAMP)
                """, (firstName, lastName))

        #Creates log of initial visit
        curs.execute("""
                INSERT INTO LOGS
                VALUES(?, ?, CURRENT_TIMESTAMP)
                """, (firstName, lastName))

        #Welcomes the new visitor
        print("Welcome " + firstName +". It's the first time we see you!")
    
    #updates database with latest visit
    def updateDatabase():

        #adds new visit from known visitor
        curs.execute("""
                UPDATE VISITS
                SET visit = CURRENT_TIMESTAMP
                WHERE firstname = ? AND lastname = ?
                """, (firstName, lastName))

        print("Welcome back " + firstName + ". It's good to see you again!")

    #grabs name from user
    firstName = input("What is your first name?: ")
    lastName = input("What is your last name?: ")

    firstName = firstName.upper()
    lastName = lastName.upper()

    #checks if visitor come before
    curs.execute("""
                SELECT COUNT(*)
                FROM VISITS
                WHERE firstname = ? and lastname = ?
                """, (firstName, lastName))

    #if visitor is not in database
    if (curs.fetchone()[0] == 0):
        newVisitor()
    
    #otherwise update database
    else:
        updateDatabase()

main()

curs.close()
dbConnection.commit()
dbConnection.close()