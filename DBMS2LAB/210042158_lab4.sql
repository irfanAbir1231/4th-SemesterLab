drop table prereq;
drop table time_slot;
drop table advisor;
drop table takes;
drop table student;
drop table teaches;
drop table section;
drop table instructor;
drop table course;
drop table department;
drop table classroom;



create table classroom
	(building		varchar(15),
	 room_number		varchar(7),
	 capacity		numeric(4,0),
	 primary key (building, room_number)
	);

create table department
	(dept_name		varchar(20), 
	 building		varchar(15), 
	 budget		        numeric(12,2) check (budget > 0),
	 primary key (dept_name)
	);

create table course
	(course_id		varchar(8), 
	 title			varchar(50), 
	 dept_name		varchar(20),
	 credits		numeric(2,0) check (credits > 0),
	 primary key (course_id),
	 foreign key (dept_name) references department (dept_name)
		on delete set null
	);

create table time_slot
	(time_slot_id		varchar(4),
	 day			varchar(1),
	 start_hr		numeric(2) check (start_hr >= 0 and start_hr < 24),
	 start_min		numeric(2) check (start_min >= 0 and start_min < 60),
	 end_hr			numeric(2) check (end_hr >= 0 and end_hr < 24),
	 end_min		numeric(2) check (end_min >= 0 and end_min < 60),
	 primary key (time_slot_id, day, start_hr, start_min)
	);

create table prereq
	(course_id		varchar(8), 
	 prereq_id		varchar(8),
	 primary key (course_id, prereq_id),
	 foreign key (course_id) references course (course_id)
		on delete cascade,
	 foreign key (prereq_id) references course (course_id)
	);

create table instructor
	(ID			varchar(5), 
	 name			varchar(20) not null, 
	 dept_name		varchar(20), 
	 salary			numeric(8,2) ,
	 primary key (ID),
	 foreign key (dept_name) references department (dept_name)
		on delete set null
	);




create table section
	(course_id		varchar(8), 
         sec_id			varchar(8),
	 semester		varchar(6)
		check (semester in ('Fall', 'Winter', 'Spring', 'Summer')), 
	 year			numeric(4,0) check (year > 1701 and year < 2100), 
	 building		varchar(15),
	 room_number		varchar(7),
	 time_slot_id		varchar(4),
	 primary key (course_id, sec_id, semester, year),
	 foreign key (course_id) references course (course_id)
		on delete cascade,
	 foreign key (building, room_number) references classroom (building, room_number)
		on delete set null
	);

create table teaches
	(ID			varchar(5), 
	 course_id		varchar(8),
	 sec_id			varchar(8), 
	 semester		varchar(6),
	 year			numeric(4,0),
	 primary key (ID, course_id, sec_id, semester, year),
	 foreign key (course_id, sec_id, semester, year) references section (course_id, sec_id, semester, year)
		on delete cascade,
	 foreign key (ID) references instructor (ID)
		on delete cascade
	);

create table student
	(ID			varchar(5), 
	 name			varchar(20) not null, 
	 dept_name		varchar(20), 
	 tot_cred		numeric(3,0) check (tot_cred >= 0),
	 primary key (ID),
	 foreign key (dept_name) references department (dept_name)
		on delete set null
	);

create table takes
	(ID			varchar(5), 
	 course_id		varchar(8),
	 sec_id			varchar(8), 
	 semester		varchar(6),
	 year			numeric(4,0),
	 grade		        varchar(2),
	 primary key (ID, course_id, sec_id, semester, year),
	 foreign key (course_id, sec_id, semester, year) references section (course_id, sec_id, semester, year)
		on delete cascade,
	 foreign key (ID) references student (ID)
		on delete cascade
	);

create table advisor
	(s_ID			varchar(5),
	 i_ID			varchar(5),
	 primary key (s_ID),
	 foreign key (i_ID) references instructor (ID)
		on delete set null,
	 foreign key (s_ID) references student (ID)
		on delete cascade
	);

    delete from prereq;
delete from time_slot;
delete from advisor;
delete from takes;
delete from student;
delete from teaches;
delete from section;
delete from instructor;
delete from course;
delete from department;
delete from classroom;
insert into classroom values ('Packard', '101', '500');
insert into classroom values ('Painter', '514', '10');
insert into classroom values ('Taylor', '3128', '70');
insert into classroom values ('Watson', '100', '30');
insert into classroom values ('Watson', '120', '50');
insert into department values ('Biology', 'Watson', '90000');
insert into department values ('Comp. Sci.', 'Taylor', '100000');
insert into department values ('Elec. Eng.', 'Taylor', '85000');
insert into department values ('Finance', 'Painter', '120000');
insert into department values ('History', 'Painter', '50000');
insert into department values ('Music', 'Packard', '80000');
insert into department values ('Physics', 'Watson', '70000');
insert into course values ('BIO-101', 'Intro. to Biology', 'Biology', '4');
insert into course values ('BIO-301', 'Genetics', 'Biology', '4');
insert into course values ('BIO-399', 'Computational Biology', 'Biology', '3');
insert into course values ('CS-101', 'Intro. to Computer Science', 'Comp. Sci.', '4');
insert into course values ('CS-190', 'Game Design', 'Comp. Sci.', '4');
insert into course values ('CS-315', 'Robotics', 'Comp. Sci.', '3');
insert into course values ('CS-319', 'Image Processing', 'Comp. Sci.', '3');
insert into course values ('CS-347', 'Database System Concepts', 'Comp. Sci.', '3');
insert into course values ('EE-181', 'Intro. to Digital Systems', 'Elec. Eng.', '3');
insert into course values ('FIN-201', 'Investment Banking', 'Finance', '3');
insert into course values ('HIS-351', 'World History', 'History', '3');
insert into course values ('MU-199', 'Music Video Production', 'Music', '3');
insert into course values ('PHY-101', 'Physical Principles', 'Physics', '4');
insert into instructor values ('10101', 'Srinivasan', 'Comp. Sci.', '65000');
insert into instructor values ('12121', 'Wu', 'Finance', '90000');
insert into instructor values ('15151', 'Mozart', 'Music', '40000');
insert into instructor values ('22222', 'Einstein', 'Physics', '95000');
insert into instructor values ('32343', 'El Said', 'History', '60000');
insert into instructor values ('33456', 'Gold', 'Physics', '87000');
insert into instructor values ('45565', 'Katz', 'Comp. Sci.', '75000');
insert into instructor values ('58583', 'Califieri', 'History', '62000');
insert into instructor values ('76543', 'Singh', 'Finance', '80000');
insert into instructor values ('76766', 'Crick', 'Biology', '72000');
insert into instructor values ('83821', 'Brandt', 'Comp. Sci.', '92000');
insert into instructor values ('98345', 'Kim', 'Elec. Eng.', '80000');
insert into section values ('BIO-101', '1', 'Summer', '2017', 'Painter', '514', 'B');
insert into section values ('BIO-301', '1', 'Summer', '2018', 'Painter', '514', 'A');
insert into section values ('CS-101', '1', 'Fall', '2017', 'Packard', '101', 'H');
insert into section values ('CS-101', '1', 'Spring', '2018', 'Packard', '101', 'F');
insert into section values ('CS-190', '1', 'Spring', '2017', 'Taylor', '3128', 'E');
insert into section values ('CS-190', '2', 'Spring', '2017', 'Taylor', '3128', 'A');
insert into section values ('CS-315', '1', 'Spring', '2018', 'Watson', '120', 'D');
insert into section values ('CS-319', '1', 'Spring', '2018', 'Watson', '100', 'B');
insert into section values ('CS-319', '2', 'Spring', '2018', 'Taylor', '3128', 'C');
insert into section values ('CS-347', '1', 'Fall', '2017', 'Taylor', '3128', 'A');
insert into section values ('EE-181', '1', 'Spring', '2017', 'Taylor', '3128', 'C');
insert into section values ('FIN-201', '1', 'Spring', '2018', 'Packard', '101', 'B');
insert into section values ('HIS-351', '1', 'Spring', '2018', 'Painter', '514', 'C');
insert into section values ('MU-199', '1', 'Spring', '2018', 'Packard', '101', 'D');
insert into section values ('PHY-101', '1', 'Fall', '2017', 'Watson', '100', 'A');
insert into teaches values ('10101', 'CS-101', '1', 'Fall', '2017');
insert into teaches values ('10101', 'CS-315', '1', 'Spring', '2018');
insert into teaches values ('10101', 'CS-347', '1', 'Fall', '2017');
insert into teaches values ('12121', 'FIN-201', '1', 'Spring', '2018');
insert into teaches values ('15151', 'MU-199', '1', 'Spring', '2018');
insert into teaches values ('22222', 'PHY-101', '1', 'Fall', '2017');
insert into teaches values ('32343', 'HIS-351', '1', 'Spring', '2018');
insert into teaches values ('45565', 'CS-101', '1', 'Spring', '2018');
insert into teaches values ('45565', 'CS-319', '1', 'Spring', '2018');
insert into teaches values ('76766', 'BIO-101', '1', 'Summer', '2017');
insert into teaches values ('76766', 'BIO-301', '1', 'Summer', '2018');
insert into teaches values ('83821', 'CS-190', '1', 'Spring', '2017');
insert into teaches values ('83821', 'CS-190', '2', 'Spring', '2017');
insert into teaches values ('83821', 'CS-319', '2', 'Spring', '2018');
insert into teaches values ('98345', 'EE-181', '1', 'Spring', '2017');
insert into student values ('00128', 'Zhang', 'Comp. Sci.', '102');
insert into student values ('12345', 'Shankar', 'Comp. Sci.', '32');
insert into student values ('19991', 'Brandt', 'History', '80');
insert into student values ('23121', 'Chavez', 'Finance', '110');
insert into student values ('44553', 'Peltier', 'Physics', '56');
insert into student values ('45678', 'Levy', 'Physics', '46');
insert into student values ('54321', 'Williams', 'Comp. Sci.', '54');
insert into student values ('55739', 'Sanchez', 'Music', '38');
insert into student values ('70557', 'Snow', 'Physics', '0');
insert into student values ('76543', 'Brown', 'Comp. Sci.', '58');
insert into student values ('76653', 'Aoi', 'Elec. Eng.', '60');
insert into student values ('98765', 'Bourikas', 'Elec. Eng.', '98');
insert into student values ('98988', 'Tanaka', 'Biology', '120');
insert into takes values ('00128', 'CS-101', '1', 'Fall', '2017', 'A');
insert into takes values ('00128', 'CS-347', '1', 'Fall', '2017', 'A-');
insert into takes values ('12345', 'CS-101', '1', 'Fall', '2017', 'C');
insert into takes values ('12345', 'CS-190', '2', 'Spring', '2017', 'A');
insert into takes values ('12345', 'CS-315', '1', 'Spring', '2018', 'A');
insert into takes values ('12345', 'CS-347', '1', 'Fall', '2017', 'A');
insert into takes values ('19991', 'HIS-351', '1', 'Spring', '2018', 'B');
insert into takes values ('23121', 'FIN-201', '1', 'Spring', '2018', 'C+');
insert into takes values ('44553', 'PHY-101', '1', 'Fall', '2017', 'B-');
insert into takes values ('45678', 'CS-101', '1', 'Fall', '2017', 'F');
insert into takes values ('45678', 'CS-101', '1', 'Spring', '2018', 'B+');
insert into takes values ('45678', 'CS-319', '1', 'Spring', '2018', 'B');
insert into takes values ('54321', 'CS-101', '1', 'Fall', '2017', 'A-');
insert into takes values ('54321', 'CS-190', '2', 'Spring', '2017', 'B+');
insert into takes values ('55739', 'MU-199', '1', 'Spring', '2018', 'A-');
insert into takes values ('76543', 'CS-101', '1', 'Fall', '2017', 'A');
insert into takes values ('76543', 'CS-319', '2', 'Spring', '2018', 'A');
insert into takes values ('76653', 'EE-181', '1', 'Spring', '2017', 'C');
insert into takes values ('98765', 'CS-101', '1', 'Fall', '2017', 'C-');
insert into takes values ('98765', 'CS-315', '1', 'Spring', '2018', 'B');
insert into takes values ('98988', 'BIO-101', '1', 'Summer', '2017', 'A');
insert into takes values ('98988', 'BIO-301', '1', 'Summer', '2018', null);
insert into advisor values ('00128', '45565');
insert into advisor values ('12345', '10101');
insert into advisor values ('23121', '76543');
insert into advisor values ('44553', '22222');
insert into advisor values ('45678', '22222');
insert into advisor values ('76543', '45565');
insert into advisor values ('76653', '98345');
insert into advisor values ('98765', '98345');
insert into advisor values ('98988', '76766');
insert into time_slot values ('A', 'M', '8', '0', '8', '50');
insert into time_slot values ('A', 'W', '8', '0', '8', '50');
insert into time_slot values ('A', 'F', '8', '0', '8', '50');
insert into time_slot values ('B', 'M', '9', '0', '9', '50');
insert into time_slot values ('B', 'W', '9', '0', '9', '50');
insert into time_slot values ('B', 'F', '9', '0', '9', '50');
insert into time_slot values ('C', 'M', '11', '0', '11', '50');
insert into time_slot values ('C', 'W', '11', '0', '11', '50');
insert into time_slot values ('C', 'F', '11', '0', '11', '50');
insert into time_slot values ('D', 'M', '13', '0', '13', '50');
insert into time_slot values ('D', 'W', '13', '0', '13', '50');
insert into time_slot values ('D', 'F', '13', '0', '13', '50');
insert into time_slot values ('E', 'T', '10', '30', '11', '45 ');
insert into time_slot values ('E', 'R', '10', '30', '11', '45 ');
insert into time_slot values ('F', 'T', '14', '30', '15', '45 ');
insert into time_slot values ('F', 'R', '14', '30', '15', '45 ');
insert into time_slot values ('G', 'M', '16', '0', '16', '50');
insert into time_slot values ('G', 'W', '16', '0', '16', '50');
insert into time_slot values ('G', 'F', '16', '0', '16', '50');
insert into time_slot values ('H', 'W', '10', '0', '12', '30');
insert into prereq values ('BIO-301', 'BIO-101');
insert into prereq values ('BIO-399', 'BIO-101');
insert into prereq values ('CS-190', 'CS-101');
insert into prereq values ('CS-315', 'CS-101');
insert into prereq values ('CS-319', 'CS-101');
insert into prereq values ('CS-347', 'CS-101');
insert into prereq values ('EE-181', 'PHY-101');

set serveroutput on

-- (1) Print your name.
DECLARE
  v_name VARCHAR2(50);
BEGIN
  v_name := 'Md Irfan Hakim Bhuiyan';
  DBMS_OUTPUT.PUT_LINE('My name is: ' || v_name);
END;
/

-- (2) Take your student ID as input and print its length.
DECLARE
  v_student_id VARCHAR2(20);
BEGIN
  -- Assuming you want to take input interactively
  DBMS_OUTPUT.PUT('Enter your student ID: ');
  v_student_id := '&student_id';
  DBMS_OUTPUT.PUT_LINE('Length of student ID: ' || LENGTH(v_student_id));
END;
/

--2a

DECLARE
    v_instructor_count NUMBER;
BEGIN

    FOR instructor_rec IN (SELECT ID, COALESCE(SUM(credits), 0) AS total_credits
                           FROM teaches t
                           JOIN course c ON t.course_id = c.course_id
                           GROUP BY ID)
    LOOP
        
        BEGIN
           
            DECLARE
                v_new_salary NUMBER := 9000 * instructor_rec.total_credits;
            BEGIN
               
                IF v_new_salary < 29000 THEN
                    v_new_salary := 29000;
                END IF;

               
                UPDATE instructor
                SET salary = v_new_salary
                WHERE ID = instructor_rec.ID;

             
                COMMIT;

               
                IF SQL%ROWCOUNT = 0 THEN
                    DBMS_OUTPUT.PUT_LINE('Instructor with unchanged salary: ' || instructor_rec.ID);
                END IF;
            END;
        EXCEPTION
            WHEN OTHERS THEN
              
                DBMS_OUTPUT.PUT_LINE('Error updating salary for Instructor ID: ' || instructor_rec.ID);
        END;
    END LOOP;

   
    SELECT COUNT(*) INTO v_instructor_count
    FROM instructor
    WHERE salary < 29000;

    IF v_instructor_count = 0 THEN
        DBMS_OUTPUT.PUT_LINE('All instructors have updated salaries.');
    END IF;
END;
/

-- Task 2b: Print course titles and eligible student names based on prerequisites
DECLARE
    v_course_id course.course_id%TYPE;
    v_course_title course.title%TYPE;
    v_prereq_id course.course_id%TYPE;
    v_prereq_title course.title%TYPE;
BEGIN
    -- Cursor to fetch course titles and their prerequisites
    FOR course_rec IN (
        SELECT c.course_id, c.title, p.prereq_id, (SELECT title FROM course WHERE course_id = p.prereq_id) AS prereq_title
        FROM course c
        LEFT JOIN prereq p ON c.course_id = p.course_id
        ORDER BY c.course_id
    ) LOOP
        v_course_id := course_rec.course_id;
        v_course_title := course_rec.title;
        v_prereq_id := course_rec.prereq_id;
        v_prereq_title := course_rec.prereq_title;

        -- If no prerequisite, print all students eligible for the course
        IF v_prereq_id IS NULL THEN
            DBMS_OUTPUT.PUT_LINE('Course: ' || v_course_title);
            -- Retrieve and print student names eligible for the course
            FOR student_rec IN (
                SELECT s.name
                FROM student s
                LEFT JOIN takes t ON s.ID = t.ID
                LEFT JOIN prereq p ON t.course_id = p.prereq_id
                WHERE t.course_id IS NULL OR p.course_id = v_course_id
            ) LOOP
                DBMS_OUTPUT.PUT_LINE(' - ' || student_rec.name);
            END LOOP;
            DBMS_OUTPUT.PUT_LINE('--------------------------------');
        ELSE
            -- Print only if students have completed the prerequisite(s)
            FOR student_rec IN (
                SELECT s.name
                FROM student s
                JOIN takes t ON s.ID = t.ID
                WHERE t.course_id = v_prereq_id
            ) LOOP
                DBMS_OUTPUT.PUT_LINE('Course: ' || v_course_title);
                DBMS_OUTPUT.PUT_LINE('Prerequisite: ' || v_prereq_title || ' (' || v_prereq_id || ')');
                DBMS_OUTPUT.PUT_LINE(' - ' || student_rec.name);
                DBMS_OUTPUT.PUT_LINE('--------------------------------');
            END LOOP;
        END IF;
    END LOOP;
END;
/


-- Task 2c: Print the weekly routine for a student
DECLARE
    v_student_name student.name%TYPE;
    v_student_id student.ID%TYPE;
BEGIN
    -- Take input from the user for the student's name
    DBMS_OUTPUT.PUT('Enter the student name: ');
    v_student_name := UPPER('&student_name');

    -- Retrieve the student's ID based on the entered name
    BEGIN
        SELECT ID INTO v_student_id FROM student WHERE UPPER(name) = v_student_name;
    EXCEPTION
        WHEN NO_DATA_FOUND THEN
            DBMS_OUTPUT.PUT_LINE('Student not found.');
            RETURN;
    END;

    -- Cursor to fetch the student's weekly schedule
    FOR schedule_rec IN (
        SELECT ts.day, ts.start_hr, ts.start_min, ts.end_hr, ts.end_min,
               sec.course_id, c.title, s.building, s.room_number
        FROM takes t
        JOIN section sec ON t.course_id = sec.course_id AND t.sec_id = sec.sec_id
        JOIN time_slot ts ON sec.time_slot_id = ts.time_slot_id
        JOIN course c ON sec.course_id = c.course_id
        JOIN classroom s ON sec.building = s.building AND sec.room_number = s.room_number
        WHERE t.ID = v_student_id
        ORDER BY ts.day, ts.start_hr, ts.start_min
    ) LOOP
        -- Print the schedule information
        DBMS_OUTPUT.PUT_LINE(schedule_rec.day);
        DBMS_OUTPUT.PUT_LINE(schedule_rec.start_hr || ':' || LPAD(schedule_rec.start_min, 2, '0') || ' - ' ||
                             schedule_rec.end_hr || ':' || LPAD(schedule_rec.end_min, 2, '0'));
        DBMS_OUTPUT.PUT_LINE(schedule_rec.course_id || ' - ' || schedule_rec.title);
        DBMS_OUTPUT.PUT_LINE(schedule_rec.building || ' - ' || schedule_rec.room_number);
        DBMS_OUTPUT.PUT_LINE('------------------------');
    END LOOP;
END;
/


-- Task 2d: Find instructors with no students assigned and assign them students
DECLARE
    v_department_id department.dept_name%TYPE;
    v_instructor_id instructor.ID%TYPE;
    v_student_id student.ID%TYPE;
    v_lowest_cred student.tot_cred%TYPE;
BEGIN
    -- Cursor to find instructors with no students assigned
    FOR instructor_rec IN (SELECT ID, dept_name FROM instructor WHERE ID NOT IN (SELECT DISTINCT ID FROM advisor)) LOOP
        v_instructor_id := instructor_rec.ID;
        v_department_id := instructor_rec.dept_name;

        -- Find a student with the lowest total credits from the same department and without any advisor
        SELECT s.ID, s.tot_cred INTO v_student_id, v_lowest_cred
        FROM student s
        WHERE s.dept_name = v_department_id
        AND s.ID NOT IN (SELECT DISTINCT s_ID FROM advisor)
        ORDER BY s.tot_cred ASC;

        -- Assign the student to the instructor
        INSERT INTO advisor (s_ID, i_ID) VALUES (v_student_id, v_instructor_id);
    END LOOP;

    -- Print the names of instructors still without any students assigned
    FOR instructor_rec IN (SELECT ID FROM instructor WHERE ID NOT IN (SELECT DISTINCT ID FROM advisor)) LOOP
        DBMS_OUTPUT.PUT_LINE('Instructor ID without any students: ' || instructor_rec.ID);
    END LOOP;
END;
/

-- Task 2e: Insert a new instructor named 'John Doe'
DECLARE
    v_department_id department.dept_name%TYPE;
    v_new_instructor_id instructor.ID%TYPE;
    v_average_salary instructor.salary%TYPE;
BEGIN
    -- Find the department with the highest number of students
    SELECT dept_name INTO v_department_id
    FROM (
        SELECT dept_name, COUNT(*) AS num_students
        FROM student
        GROUP BY dept_name
        ORDER BY COUNT(*) DESC
    )
    WHERE ROWNUM = 1;

    -- Find the lowest ID value among existing instructors
    SELECT MIN(ID) INTO v_new_instructor_id FROM instructor;

    -- Calculate the average salary of instructors in the department
    SELECT AVG(salary) INTO v_average_salary
    FROM instructor
    WHERE dept_name = v_department_id;

    -- Insert the new instructor
    INSERT INTO instructor (ID, name, dept_name, salary)
    VALUES (v_new_instructor_id - 1, 'John Doe', v_department_id, v_average_salary);

    -- Print the information of the new instructor
    DBMS_OUTPUT.PUT_LINE('New instructor inserted:');
    DBMS_OUTPUT.PUT_LINE('ID: ' || (v_new_instructor_id - 1));
    DBMS_OUTPUT.PUT_LINE('Name: John Doe');
    DBMS_OUTPUT.PUT_LINE('Department: ' || v_department_id);
    DBMS_OUTPUT.PUT_LINE('Salary: ' || v_average_salary);
END;
/



