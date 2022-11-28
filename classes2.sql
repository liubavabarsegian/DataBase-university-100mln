DROP TABLE IF EXISTS "classes2";

CREATE TABLE "classes2" (
	id SERIAL PRIMARY KEY,
	subject_name varchar(255) default NULL,
	date DATE,
	time TIME,
	group_code varchar(255) default NULL,
	class_type varchar(255) default NULL,
	professor_id integer NULL,
	classroom integer NULL
);

--/////////////////////////// L E S S O N S ////////////////////////// 
DO
$$
BEGIN
	TRUNCATE classes RESTART IDENTITY CASCADE;
	for i in 1..100000000 loop
		insert into classes2 (date, time, group_code, class_type, subject_name, professor_id, classroom)
		values (
			timestamp with time zone '2015-04-02 12:00' + random() * (interval '4000 days') + '0 days',
			date_trunc('minute', TIMESTAMP '2015-04-02 12:00' +
			random() * (interval '2200 hours'))::time,
			(array['ИУ6', 'СМ1', 'ПС2', 'ИУ8', 'ИУ7', 'Э2', 'ЮР2', 'БМТ4', 'ИБМ5'])[floor(random() * 9 + 1)],
			(array['Лабораторная работа', 'Лекция', 'Семинар'])[floor(random() * 3 + 1)],
			(array['Дифференциальные уравнения', 'Интегралы', 'Кратные интегралы', 'Теория поля',
				'Сопротивление материалов', 'Теоретическая механика', 'Основы программирования',
				'Языки интернет-программирования', 'Электротехника', 'Электроника', 
				'Иностранный язык', 'Правоведение', 'Социология', 'Физика', 
				'Линейная алгебра'])[floor(random() * 15 + 1)],
			round(cast(random() * 999999 + 1 as numeric)),
			random() * 1200 + 1);
	end loop;
END
$$;