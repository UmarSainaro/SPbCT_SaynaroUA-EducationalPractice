#include <iostream>
#include <fstream>
using namespace std;
#define LINES 100 // максимальное количество строк в файле
int main() {
  system("chcp 1251");
  system("cls");
  char line[LINES][100];
  char str[30];
  char s[] = "|                              |                |                              |";
  // Ввод данных для размещаемой строки
  cout << "ФИО: ";
  cin.getline(str, 30); // вводим ФИО
  for (int i = 0; str[i] != '\0'; i++) // копируем в строку без 0
    s[i + 2] = str[i];               // начиная с указанной позиции
  cout << "Дата: ";
  cin.getline(str,30);
  for (int i = 0; str[i] != '\0'; i++)
    s[i + 33] = str[i];
  cout << "Хобби: ";
  cin.getline(str,30);
  for (int i = 0; str[i] != '\0'; i++)
    s[i + 50] = str[i];
  
  fstream inOut;
  inOut.open("file.txt",  ios::in); // открываем файл для ввода
  // Считываем из файла имеющиеся данные
  int count = 0;
  while (inOut.getline(line[count], 100)) count++;
  inOut.close(); // закрываем файл
  
  inOut.open("file.txt", ios::out); // открываем файл для вывода
  inOut << "--------------------------------------------------------------------------------" << endl;
  inOut << "|   ФИО                        |  Дата          | Хобби                        |" << endl;
  inOut << "--------------------------------------------------------------------------------" << endl;
  inOut << s << endl; // выводим сформированную строку
  inOut << "--------------------------------------------------------------------------------" << endl;
  // Выводим обратно в файл все строки кроме "шапки" (первые 3 строки)
  for (int j = 3; j < count; j++)
  {
    inOut << line[j] << endl;
  }
  inOut.close();
  cin.get();
  return 0;
}