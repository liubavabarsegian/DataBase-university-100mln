DROP TABLE IF EXISTS "classes";

CREATE TABLE "classes" (
	id SERIAL PRIMARY KEY,
	subject_name varchar(255) default NULL,
	date DATE,
	time TIME,
	group_code varchar(255) default NULL,
	class_type varchar(255) default NULL,
	professor_id integer NULL,
	FOREIGN KEY (professor_id) REFERENCES professors (id),
	classroom integer NULL
);

DROP TABLE IF EXISTS "groups";

CREATE TABLE "groups" (
	id SERIAL PRIMARY KEY,
	group_code varchar(255) default NULL,
	number_of_students integer NULL
);

DROP TABLE IF EXISTS "professors";

CREATE TABLE "professors" (
	id SERIAL PRIMARY KEY,
	full_name varchar(255) default NULL,
	department varchar(255) default NULL,
	science_degree varchar(255) default NULL,
	work_status varchar(255) default NULL, --работает, уволился
	position varchar(255) default NULL,
	other_universities text[] default NULL
);

DROP TABLE IF EXISTS "subjects";

CREATE TABLE "subjects" (
	id SERIAL PRIMARY KEY,
	name varchar(255) default NULL,
	department varchar(255) default NULL,
	hours integer NULL,
	check_type varchar(255) default NULL,
	obligation varchar(255) default NULL
);

DROP TABLE IF EXISTS "students";

CREATE TABLE "students" (
	id SERIAL PRIMARY KEY,
	group_attributes jsonb NULL,
	name varchar(255) default NULL,
	status varchar(255) default NULL,
	av_grade float NULL
);