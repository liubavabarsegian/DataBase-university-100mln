#include <bits/stdc++.h>
#include <string.h>

using namespace std;

const string name[] = {"Дифференциальные уравнения", "Интегралы", "Кратные интегралы", "Теория поля", 
					"Сопротивление материалов", "Теоретическая механика", "Основы программирования",
					"Языки интернет-программирования", "Электротехника", "Электроника", "Иностранный язык",
					"Правоведение", "Социология", "Физика", "Линейная алгебра"};
const string fac[] = {"ИУ", "СМ", "ПС", "Э", "РЛ", "МТ", "РК", "ЛТ"};
const string num[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
const string hours[] = {};//rand
const string check_type[] = {"Дифференциальный зачет", "Экзамен", "Распределенный экзамен", "Зачет"};
const string obligation[] = {"Обязательный предмет", "Предмет по выбору"};

string RandomRecord(int item)
{
        string result = "('";
		//name
        result += name[rand() % 15];
        result += "','";
        //department
        result += fac[rand() % 8] + num[rand() % 8];
        result += "','";
        //hours rand
        result += to_string(rand() % 500 + 1);
        result += "','";
		//check type
        result += check_type[rand() % 3];
        result += "','";
        //obligation
        result += obligation[rand() % 2];
        if (item == 1000000)
            result += "');";
        else
            result += "'),";
        return result;
}

int main()
{
    srand(time(NULL));
    std::ofstream out;          // поток для записи
    out.open("../subjects.sql"); // окрываем файл для записи
    out << "INSERT INTO subjects (name,department,hours,check_type, obligation)\n";
    out << "VALUES\n";
    for (int i = 1; i <= 1000000; i++) {
        if (i % 1000 == 0)
            std::cout << i << std::endl;
        out << RandomRecord(i) << "\n";
    }
    out.close();
    cout << "END";
    return 0;
}
