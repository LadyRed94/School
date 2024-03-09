import sqlite3

dbConnection = sqlite3.connect("AlexandraProjectPY.db")
curs = dbConnection.cursor()
curs.execute("""PRAGMA foreign_keys = ON;""")

def makeTables():

    #Creates Flight Table
    #Come back to this and adjust keys
    curs.execute("""
        CREATE TABLE IF NOT EXISTS Flights
        (flightID INT CHECK (flightID > 0 AND flightID == staffGroupID),
        destination TEXT NOT NULL DEFAULT 'Dulles International Airport',
        leftFrom TEXt NOT NULL DEFAULT 'Dulles INternational Airport',
        staffGroupID INT NOT NULL REFERENCES StaffGroup(staffGroupID),
        PRIMARY KEY (flightID)
        );
        """)

    #Creates Patrons Table
    curs.execute("""
        CREATE TABLE IF NOT EXISTS Patrons
        (patronID INT,
        firstName TEXT NOT NULL,
        lastName TEXT NOT NULL,
        flightID INT NOT NULL REFERENCES FLIGHTS(flightID),
        PRIMARY KEY (patronID)
        );
        """)    

    #Table to track arrivals and departures
    #Check about datetime creation
    curs.execute("""
        CREATE TABLE IF NOT EXISTS Schedule
        (flightID INT,
        arrivalTime datetime DEFAULT NULL,
        departureTime datetime DEFAULT NULL,
        PRIMARY KEY (flightID),
        FOREIGN KEY (flightID) REFERENCES Flights(flightID)
        );
        """)

    #Creates Seats Table
    curs.execute("""
        CREATE TABLE IF NOT EXISTS Seats
        (SeatID INT NOT NULL,
        patronID INT DEFAULT NULL,
        quality TEXT CHECK (quality IS 'first' OR quality IS 'business' OR quality IS 'coach'),
        flightID NOT NULL,
        FOREIGN KEY (patronID) REFERENCES Patrons (patronID),
        FOREIGN KEY (flightID) REFERENCES Flights (flightID)
        );
        """)

    #Creates StaffGroup Table
    curs.execute("""
        CREATE TABLE IF NOT EXISTS StaffGroup
        (staffGroupID INT,
        flightID INT UNIQUE NOT NULL,
        PRIMARY KEY (staffGroupID),
        FOREIGN KEY (flightID) REFERENCES Flights(flightID)
        );
        """)

    #Creates Staff Table
    curs.execute("""
        CREATE TABLE IF NOT EXISTS Staff
        (staffID INT,
        firstName TEXT NOT NULL,
        lastName TEXT NOT NULL,
        staffGroupID INT NULL,
        PRIMARY KEY (staffID)
        );
        """)

    #Trigger to assign staff to flights in StaffGroup Table
    curs.execute("""
        CREATE TRIGGER IF NOT EXISTS assign_staff BEFORE INSERT 
        ON Flights
        BEGIN
            INSERT INTO StaffGroup
            VALUES (new.staffGroupID, new.flightID);
        END;
        """)

def dummyData():

    #Generates Data for flight table
    numOfFlights = 10

    i = 0
    j = 1 + i

    airports = ["Seattle-Tacoma International Airport", "Washington Dulles International Airport", "Ronald Reagan Washington National Airport", "Los Angeles International Airport"]
    for x in range(1,numOfFlights+1):
 
        if (i > 2):
            i = 0

        if (j > 3):
            j = 0
        
        params = (x, airports[i], airports[j], x)

        sql ="""INSERT INTO Flights
            VALUES (?,?,?,?);"""
    
        curs.execute(sql, params)

        i = 1 + i
        j = j + 2

    #Generates 10 staff members for Staff Table
    f_names = ["Aileen","Melvin","Gerardo","Dale","Jimmy","Ansley","Alannah","Taylor","Misael","Chris"]
    l_names = ["Meadows", "Yates", "Escobar", "Mcintosh", "Sexton", "Parrish", "Le", "Heath", "Velazquez", "Bender"]

    for z in range(0,9):

        params = (z , f_names[z], l_names[z], numOfFlights - z)

        sql = """INSERT INTO Staff
            VALUES (?,?,?,?);"""

        curs.execute(sql, params)

    #Generates passengers for Patrons table
    numOfPatrons = 100
    f_names = ["Heidy","Regan","Lewis","Avery","Angeline","Bryson","Destiney","Julia","Barbara","Nicolas","Litzy","Diego","Isabela","Jakayla","Jesse","Zander","Jeramiah","Haylie","Taylor","Clark"]
    l_names = ["Kirby","Holmes","Welch","Rosales","Clay","Oconnell","Rogers","Hutchinson","Mayo","Bray","Franklin","Barton","Key","Mccarty","Chase","Fields","Nash","Kerr","Curtis","Molina"]
    i = 0
    j = 0
    flightnum = 1

    for z in range(1,numOfPatrons+1):

        if (i > 19):
            i = 0

        if (j > 19):
            j = 0

        if (flightnum > numOfFlights-1):
            flightnum = 1

        params = (z , f_names[i], l_names[j], flightnum)

        sql = """INSERT INTO Patrons
            VALUES (?,?,?,?);"""

        curs.execute(sql, params)

        i = i+1
        j = j+2
        flightnum = flightnum + 1

    #Generates data for the seats table
    #No idea why this generates so many business class seats, 
    #but it really doesn't matter too much so I'm leaving it
    curs.execute("""
        SELECT patronID, flightID FROM Patrons;
        """)
    
    info = curs.fetchall()


    Quality = ["business", "coach","first"]

    for z in range(1, numOfPatrons+1):

        qual = Quality[0]

        if z%7 == 0:
            qual = Quality[1]
        
        if z%10 == 0:
            qual = Quality[2]

        params = (z, info[z-1][0], qual, info[z-1][1])

        sql ="""INSERT INTO Seats
                VALUES (?,?,?,?);"""
    
        curs.execute(sql, params)

def createViews():

    #Creates a view to see where each Patron is flying to
    #Returns: patronID, flightID, Patron Name, Flight Destination
    curs.execute("""
        CREATE VIEW PatronDestination AS
        SELECT Patrons.patronID, Patrons.flightID, Patrons.firstName || " " || Patrons.lastName AS "Name", Flights.destination 
        FROM Patrons
        JOIN Flights ON Flights.flightID = Patrons.flightID
        GROUP BY Name
        ORDER BY Name;
        """)

    #Creates a view to see where each Patron is sitting on their respective flight
    #Returns: FlightID, PatronID, Patron Name, SeatID
    curs.execute("""
        CREATE VIEW PatronSeat AS
        SELECT Seats.flightID, Patrons.patronID, Patrons.firstName || " " || Patrons.lastName AS "Name", Seats.SeatID
        FROM Seats
        JOIN Patrons ON Seats.flightID = Patrons.flightID
        GROUP BY Name
        ORDER BY Name;
        """)


    #Creates a view to see a staff member that could provide potential in flight service to these customers for flight 1
    #Returns: FlightID, Patron Name, In Flight Staff Name
    curs.execute("""
        CREATE VIEW InFlightStaff AS
        SELECT Patrons.flightID, Patrons.firstName || " " || Patrons.lastName AS "Name", Staff.firstName || " " || Staff.lastName AS "InFlightStaff"
        FROM Patrons
        JOIN StaffGroup, Staff ON StaffGroup.flightID = Patrons.flightID AND StaffGroup.staffGroupID = Staff.staffID
        GROUP BY Name
        HAVING Patrons.flightID = 1
        ORDER BY Name;
        """)

def main():
    makeTables()
    dummyData()
    createViews()

main()

curs.close()
dbConnection.commit()
dbConnection.close()