--1

DECLARE
    set_name VARCHAR2(100) := 'Alpha';
BEGIN
    dbms_output.put_line('Name: ' || set_name);
END;
/

--2

SELECT DISTINCT A.ACT_FIRSTNAME, A.ACT_LASTNAME
FROM ACTOR A
JOIN CASTS C ON A.ACT_ID = C.ACT_ID
JOIN MOVIE M ON C.MOV_ID = M.MOV_ID
WHERE 
    INSTR(UPPER(M.MOV_TITLE), UPPER(A.ACT_FIRSTNAME)) > 0
    OR 
    INSTR(UPPER(M.MOV_TITLE), UPPER(A.ACT_LASTNAME)) > 0;


--3


SELECT Dominated_Genre, Male_Actor_Count
FROM (
    SELECT G.GEN_TITLE AS Dominated_Genre, COUNT(*) AS Male_Actor_Count
    FROM GENRES G
    JOIN MTYPE MT ON G.GEN_ID = MT.GEN_ID
    JOIN MOVIE M ON MT.MOV_ID = M.MOV_ID
    JOIN CASTS C ON M.MOV_ID = C.MOV_ID
    JOIN ACTOR A ON C.ACT_ID = A.ACT_ID
    WHERE A.ACT_GENDER = 'M'
    GROUP BY G.GEN_TITLE
    ORDER BY Male_Actor_Count DESC
)
WHERE ROWNUM = 1;


--4
CREATE OR REPLACE PROCEDURE CalculateMovieTime(
    movie_title IN VARCHAR2,
    movie_duration OUT VARCHAR2
)
IS
    v_total_duration NUMBER;
    v_hours NUMBER;
    v_minutes NUMBER;
    v_remaining_duration NUMBER;
BEGIN
    SELECT MOV_TIME INTO v_total_duration
    FROM MOVIE
    WHERE MOV_TITLE = movie_title;
    
    IF v_total_duration <= 30 THEN
        movie_duration := 'Less than 30 minutes';
        RETURN;
    END IF;

    v_hours := FLOOR(v_total_duration / 60);
    v_minutes := v_total_duration - v_hours * 60;
    v_remaining_duration := v_total_duration;

    WHILE v_remaining_duration >= 70 LOOP
        v_remaining_duration := v_remaining_duration - 70;
        IF v_remaining_duration >= 30 THEN
            v_remaining_duration := v_remaining_duration - 15;
        END IF;
    END LOOP;

    v_hours := FLOOR(v_total_duration / 60) - FLOOR(v_remaining_duration / 60);
    v_minutes := v_total_duration - (v_hours * 60 + FLOOR(v_remaining_duration / 60));

    movie_duration := TO_CHAR(v_hours, 'FM00') || ':' || TO_CHAR(v_minutes, 'FM00');
END;
/






