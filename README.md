# DataBase-university-100mln
Lab 3 
## инструкция по созданию базы данных "Университет"
  1. запустить create_tables.sql
  
  2.в папке cpp-src лежат .cpp файлы, которые генерируют .sql файлы по 1 млн строк.
    запустить .cpp файлы с помощью g++
    
  3. открыть терминал psql в той директории, где находятся файлы, подключиться к базе данных, запустить три .sql скрипта следующим образом:
  
  \i professors.sql
  
  Это первый способ.
  
  Второй способ реализован полностью в sql, (добавлю позже)
