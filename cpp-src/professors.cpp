#include <bits/stdc++.h>

using namespace std;

const string science_degree[] = {"Бакалаврт", "Магистр", "Кандидат наук", "Доктор наук"};
const string fac[] = {"ИУ", "СМ", "ПС", "Э", "РЛ", "МТ", "РК", "ЛТ"};
const string num[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
const string position[] = {"Лаборант", "Семинарист", "Лектор"};
const string work_status[] = {"Стажируется", "Работает", "Уволился", "Уволен"};
const string full_name[] = {"Подзорова М.И.", "Чуев А.С", "Птицына И.В", "Мугла Д.Р", 
						"Ласковая Т.А", "Горяинов В.Б.", "Константинов М.Ю.", "Фомин М.М.","Иванова Г.С"};
const string universities[] = {"Московский государственный университет имени М.В. Ломоносова",
        "Московский физико-технический институт",
        "Национальный исследовательский ядерный университет «МИФИ»",
        "Национальный исследовательский университет «Высшая школа экономики»",
        "Московский государственный институт международных отношений (Университет) МИД России",
        "Российский экономический университет имени Г.В. Плеханова",
        "Университет науки и технологий МИСИС",
        "Национальный исследовательский университет «МЭИ»",
        "Московский авиационный институт"};

string RandomRecord(int item)
{
        string result = "('";
		//full name
        result += full_name[rand() % 9];
        result += "','";
        //department
        result += fac[rand() % 8] + num[rand() % 8];
        result += "','";
        //degree
        result += science_degree[rand() % 3];
        result += "','";
        //work status
        result += work_status[rand() % 4];
        result += "','";
        //position
        result += position[rand() % 3];
        result += "',";

        //universities
        int rand_unis;
        rand_unis = rand() % 9 + 1;
        result += "'{";
        for (int i = 1; i <= rand_unis; i++)
        {
            result += "\"";
            result += universities[rand() % 9];
            if (i == rand_unis)
                result += "\"";
            else
                result += "\",";
        }
        result += "}'";
        if (item == 1000000)
            result += ");";
        else
            result += "),";
        return result;
}

int main()
{
    srand(time(NULL));
    std::ofstream out;          // поток для записи
    out.open("../professors.sql"); // окрываем файл для записи
    out << "INSERT INTO professors (full_name,department,science_degree,work_status,position, other_universities)\n";
    out << "VALUES\n";
    for (int i = 1; i <= 1000000; i++) {
        if (i % 100000 == 0)
            std::cout << i << std::endl;
        out << RandomRecord(i) << "\n";
    }
    out.close();
    cout << "END";
    return 0;
}
