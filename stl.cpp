#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <fstream>
using namespace std;
int main()
{
    cout<<"Функция sort(): ";
    std::vector<int> vect;
    vect.push_back(4);
    vect.push_back(8);
    vect.push_back(-3);
    vect.push_back(3);
    vect.push_back(-8);
    vect.push_back(12);
    vect.push_back(5);
 
    std::sort(vect.begin(), vect.end()); // выполняем сортировку элементов вектора
 
    std::vector<int>::const_iterator it; // объявляем итератор
    for (it = vect.begin(); it != vect.end(); ++it) // выводим с помощью цикла и итератора элементы вектора
        std::cout << *it << ' ';
 
    std::cout << '\n';

    cout<<endl;
    string str = "geeksforgeeks";
    cout<<"Функция count(): ";
    cout << "Сколько раз встречается буква E в слове geeksforgeeks: "
         << count(str.begin(), str.end(), 'e');
    cout<<endl;
     
    cout<<endl;
    cout<<"Функция accumulate(): ";
    int init = 100;
    int numbers[] = {10,20,30};
    
    std::cout << std::accumulate(std::begin(numbers), std::end(numbers), init) << "\n";
    cout<<endl;
    cout<<"Функция replace():"<<endl;
    string str1 ="This is C language"; 
    string str3= "java language";  
    cout <<"До замены: "<<str1<<'\n';  
    str1.replace(8,1,str3,0,4);   
    cout<<"После замены: "<<str1<<'\n';
  return 0;
}
