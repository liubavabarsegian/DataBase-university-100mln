DO
$$
BEGIN
	TRUNCATE students RESTART IDENTITY CASCADE;
	for i in 1..1000000 loop
		insert into students (group_attributes, status, av_grade, name)
		values (
			'{  }',
			(array['Обучается', 'Отчислен', 'Академ.отпуск'])[floor(random() * 3 + 1)],
			round(cast(random() * 5 as numeric), 2),
			(array['Барсегян Л.', 'Варняга М.', 'Спасскова К.', 'Христокьян М.', 'Степура А.', 
					'Ларин А.', 'Курицын Я.', 'Еферов Н.', 'Китаев Т.', 
				   'Ягмуров И.', 'Полубояров В.', 'Угаров Р.', 'Фасхутдинов А.', 'Синявина А.', 'Омельченко Е.'])[floor(random() * 12 + 1)]);
	end loop;
END
$$;

update students
set group_attributes = group_attributes || jsonb_build_object(
    'group_attributes', (array['ИУ6', 'СМ1', 'ПС2', 'ИУ8', 'ИУ7', 'Э2', 'ЮР2', 'БМТ4', 'ИБМ5'])[floor(random() * 9 + 1)],
    'semester', (array[1, 2, 3, 4, 5, 6, 7, 8, 9])[floor(random() * 9 + 1)],
	'group', (array[1, 2, 3, 4, 5, 6])[floor(random() * 6 + 1)],
	'degree', (array['М', 'Б', ''])[floor(random() * 9 + 1)]
)