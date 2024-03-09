PRAGMA foreign_keys = ON;

--Creates table to hold flight info
CREATE TABLE IF NOT EXISTS Flights
        (flightID INT CHECK (flightID > 0 AND flightID == staffGroupID),
        destination TEXT NOT NULL DEFAULT "Dulles International Airport",
        leftFrom TEXT NOT NULL DEFAULT "Dulles INternational Airport",
        staffGroupID INT NOT NULL REFERENCES StaffGroup(staffGroupID),
        PRIMARY KEY (flightID)
        );

--Creates table to hold patron/passenger info
CREATE TABLE IF NOT EXISTS Patrons
        (patronID INT,
        firstName TEXT NOT NULL,
        lastName TEXT NOT NULL,
        flightID INT NOT NULL REFERENCES FLIGHTS(flightID),
        PRIMARY KEY (patronID)
        );

--This one won"t be used for the project
--Creates table to hold flight info
CREATE TABLE IF NOT EXISTS Schedule
        (flightID INT,
        arrivalTime datetime DEFAULT NULL,
        departureTime datetime DEFAULT NULL,
        PRIMARY KEY (flightID),
        FOREIGN KEY (flightID) REFERENCES Flights(flightID)
        );

--Creates table to hold seating info
CREATE TABLE IF NOT EXISTS Seats
        (SeatID INT NOT NULL,
        patronID INT DEFAULT NULL,
        quality TEXT CHECK (quality IS "first" OR quality IS "business" OR quality IS "coach"),
        flightID NOT NULL,
        FOREIGN KEY (patronID) REFERENCES Patrons (patronID),
        FOREIGN KEY (flightID) REFERENCES Flights (flightID)
        );

--Creates table to hold flight assignments for staff
CREATE TABLE IF NOT EXISTS StaffGroup
        (staffGroupID INT,
        flightID INT UNIQUE NOT NULL,
        PRIMARY KEY (staffGroupID),
        FOREIGN KEY (flightID) REFERENCES Flights(flightID)
        );

--Creates table to hold staff info
CREATE TABLE IF NOT EXISTS Staff
        (staffID INT,
        firstName TEXT NOT NULL,
        lastName TEXT NOT NULL,
        staffGroupID INT NULL,
        PRIMARY KEY (staffID)
        );

--Automatically assigns staff to flight
CREATE TRIGGER IF NOT EXISTS assign_staff BEFORE INSERT 
        ON Flights
        BEGIN
            INSERT INTO StaffGroup
            VALUES (new.staffGroupID, new.flightID);
        END;

--Enters information for Flights table
INSERT INTO Flights
VALUES 
    (1,"Seattle-Tacoma International Airport","Washington Dulles International Airport",1),
    (2,"Los Angeles International Airport","Ronald Reagan Washington National Airport",2),
    (3,"Washington Dulles International Airport","Ronald Reagan Washington National Airport",3),
    (4,"Seattle-Tacoma International Airport","Los Angeles International Airport",4),
    (5,"Los Angeles International Airport","Ronald Reagan Washington National Airport",5),
    (6,"Seattle-Tacoma International Airport","Los Angeles International Airport",6),
    (7,"Ronald Reagan Washington National Airport","Washington Dulles International Airport",7),
    (8,"Seattle-Tacoma International Airport","Los Angeles International Airport",8),
    (9,"Washington Dulles International Airport","Los Angeles International Airport",9),
    (10,"Seattle-Tacoma International Airport","Washington Dulles International Airport",10);

--Enters information for staff for table
INSERT INTO Staff
VALUES 
    (1,"Aileen","Meadows",1),
    (2,"Melvin","Yates",2),
    (3,"Gerardo","Escobar",3),
    (4,"Dale","Mcintosh",4),
    (5,"Jimmy","Mcintosh",5),
    (6,"Ansley","Sexton",6),
    (7,"Alannah","Parrish",7),
    (8,"Chris","Velasquez",8),
    (9,"Aileen","Bender",9),
    (10,"Taylor","Le",10);

--Generates data for patrons
INSERT INTO Patrons
VALUES
    (1,"Heidy","Kirby",3),
    (2,"Regan","Holmes",6),
    (3,"Lewis","Welch",5),
    (4,"Avery","Rosales",3),
    (5,"Angeline","Clay",1),
    (6,"Bryson","Oconnell",9),
    (7,"Destiny","Rogers",10),
    (8,"Julia","Hutchinson",4),
    (9,"Barbara","Mayo",3),
    (10,"Nicolas","Bray",8),
    (11,"Litzy","Franklin",7),
    (12,"Diego","Barton",6),
    (13,"Isabella","Key",9),
    (14,"Jakayla","Mccarty",3),
    (15,"Jesse","Chase",5),
    (16,"Zander","Fields",5),
    (17,"Jeremiah","Nash",3),
    (18,"Haylie","Kerr",4),
    (19,"Taylor","Curtis",2),
    (20,"Clark","Molina",1);

--Creates Data for Seats
INSERT INTO Seats
VALUES 
    (1,5,"first",3),
    (2,3,"coach",6),
    (3,7,"business",5),
    (4,20,"business",3),
    (5,3,"first",1),
    (6,6,"coach",9),
    (7,8,"business",10),
    (8,9,"coach",4),
    (9,1,"coach",3),
    (10,10,"first",8);

--Creates a view to see where each Patron is flying to
--Returns: patronID, flightID, Patron Name, Flight Destination
CREATE VIEW PatronDestination AS
SELECT Patrons.patronID, Patrons.flightID, Patrons.firstName || " " || Patrons.lastName AS "Name", Flights.destination 
FROM Patrons
JOIN Flights ON Flights.flightID = Patrons.flightID
GROUP BY Name
ORDER BY Name;

--Creates a view to see where each Patron is sitting on their respective flight
--Returns: FlightID, PatronID, Patron Name, SeatID
CREATE VIEW PatronSeat AS
SELECT Seats.flightID, Patrons.patronID, Patrons.firstName || " " || Patrons.lastName AS "Name", Seats.SeatID
FROM Seats
JOIN Patrons ON Seats.flightID = Patrons.flightID
GROUP BY Name
ORDER BY Name;

--Creates a view to see a staff member that could provide potential in flight service to these customers for flight 1
--Returns: FlightID, Patron Name, In Flight Staff Name
CREATE VIEW InFlightStaff AS
SELECT Patrons.flightID, Patrons.firstName || " " || Patrons.lastName AS "Name", Staff.firstName || " " || Staff.lastName AS "InFlightStaff"
FROM Patrons
JOIN StaffGroup, Staff ON StaffGroup.flightID = Patrons.flightID AND StaffGroup.staffGroupID = Staff.staffID
GROUP BY Name
HAVING Patrons.flightID = 1
ORDER BY Name;