#pragma once
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <set>
#include <type_traits>

const unsigned int min = 10, max = 50; // использование констант для большей понятливости

// Структура сравнения, sort не нужен

bool compare (std::string const& a, std::string const& b)
{
	return a.size() < b.size();
}

void CompareOfString() 
{
	using Compare = std::integral_constant<decltype(&compare), &compare>; // использование сравнениня
	std::multiset <std::string, Compare> stroka; // создание multiset
	try // обработка ошибки выделения памяти
	{
		std::ifstream fin("C://Users/andbo/source/repos/Lab2(STL 1)/Debug/input.txt"); // открытия файла для чтения
		if (!fin.is_open()) // если файл не открыт
			std::cout << "Файл не может быть открыт!\n"; // сообщить об этом
		else
		{
			std::string symb;
			while (std::getline(fin, symb)) // читаем строки до конца файла
			{
				if (symb.size() > min && symb.size() < max)
				{
					stroka.insert(symb); // добавляем строку в multiset, вроде можно класть ссылки, но я не знаю как
				}
			}
			fin.close(); // закрываем файл
			std::ofstream fout("C://Users/andbo/source/repos/Lab2(STL 1)/Debug/output.txt"); // открываем файл для записи
			std::multiset <std::string> ::iterator it = stroka.begin(); // созздаем итератор
			for (it = stroka.begin(); it != stroka.end(); it++)
			{
				fout << *it << std::endl; // выводим в файл
			}
			fout.close(); // закрываем файл
		}
	}
	catch (std::bad_alloc) {
		std::cout << "Не удалось выделить память";
	}
}