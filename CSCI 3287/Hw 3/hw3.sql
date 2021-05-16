-- 1
CREATE DATABASE IF NOT EXISTS ClassAssignment; 
CREATE SCHEMA IF NOT EXISTS ClassAssignment; 

-- 2
CREATE TABLE Projects (
	project_num INT(10) NOT NULL PRIMARY KEY, 
    project_code CHAR(4), 
    project_title VARCHAR(45), 
    first_name VARCHAR(45),  
    last_name VARCHAR(45),  
    project_budget DECIMAL(5,2 )
    );

-- 3
ALTER TABLE project_num AUTO_INCREMENT = 10;

-- 4
ALTER TABLE Projects MODIFY project_budget DECIMAL(10,2);

-- 5
Insert INTO PROJECTS (project_code, project_title, first_name, last_name, project_budget)
VALUES (PC01, DIA, John, Smith, 10000.99);

Insert INTO PROJECTS (project_code, project_title, first_name, last_name, project_budget)
VALUES (PC02, CHF, Tim, Cook, 12000.50);


Insert INTO PROJECTS (project_code, project_title, first_name, last_name, project_budget)
VALUES (PC03, AST, Rhonda, Smith, 8000.4);


-- 6
CREATE TABLE payroll  (
	employee_num INT(10) PRIMARY KEY AUTO_INCREMENT,
    job_id INT(10) NOT NULL,
    job_des VARCHAR(40),
    emp_pay DECIMAL (10,2)
    );


-- 7
-- i
ALTER TABLE payroll ADD CONSTRAINT emp_pay CHECK (emp_pay >= 10000);


-- ii
ALTER TABLE payroll ALTER job_des SET DEFAULT 'Data Analyst';


-- iii
ALTER TABLE payroll ADD COlUMN pay_date DATE AFTER job_desc;


-- 8
ALTER TABLE payroll ADD CONSTRAINT  FK_jobIDToProjectNum FOREIGN KEY (job_id) REFERENCES Projects(project_num);


-- 9 
Insert INTO payroll (job_id, pay_date, emp_pay)
VALUES (10, CURRENT_TIMESTAMP(), 12000.99);

Insert INTO payroll (job_id, pay_date, emp_pay)
VALUES (11, CURRENT_TIMESTAMP(), 14000.99);

Insert INTO payroll (job_id, pay_date, emp_pay)
VALUES (12, CURRENT_TIMESTAMP(), 16000.99);


-- 10
UPDATE payroll SET emp_pay = emp_pay + (emp_pay * 0.10) WHERE employee_num = 2;


-- 11
CREATE TABLE Project_backup
(SELECT * FROM Projects WHERE last_name = 'Smith');


-- 12
CREATE VIEW PayRoll_View AS SELECT job_id, job_desc, pay_date FROM payroll WHERE job_id > 10;


-- 13
CREATE INDEX PayRollIndex on payroll (pay_date);


-- 14
DELETE FROM Project_backup;


-- 15
DELETE FROM Projects WHERE project_num = 10;


