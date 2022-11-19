#include <bits/stdc++.h>

using namespace std;

const string degree[] = {"М", "Б", ""};
const string fac[] = {"ИУ", "СМ", "ПС", "Э", "РЛ", "МТ", "РК", "ЛТ"};
const string num[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
const string number_of_students[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13",
                                "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26",
                                "27", "28", "29", "30"};

string RandomRecord(int item)
{
        string result = "('";
        // //department
        // result += fac[rand() % 8] + num[rand() % 8];
        // result += "','";
        // //degree
        // result += degree[rand() % 3];
        // result += "','";
        // //semester
        // result += num[rand() % 12];
        // result += "','";
        // //number of group
        // result += num[rand() % 6];
        // result += "','";

        //group_code
        result += fac[rand() % 8] + num[rand() % 8] 
                + '-' + num[rand() % 12] + num[rand() % 6] + degree[rand() % 3];
        result += "','";
        //number of students
        result += number_of_students[rand() % 30];
        if (item == 10)
            result += "');";
        else
            result += "'),";
        return result;
}

int main()
{
    srand(time(NULL));
    std::ofstream out;          // поток для записи
    out.open("../groups10.sql"); // окрываем файл для записи
    out << "INSERT INTO groups (group_code, number_of_students)\n";
    out << "VALUES\n";
    for (int i = 1; i <= 10; i++) {
        if (i % 1000 == 0)
            std::cout << i << std::endl;
        out << RandomRecord(i) << "\n";
    }
    out.close();
    cout << "END";
    return 0;
}
