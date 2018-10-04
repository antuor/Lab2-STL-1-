#pragma once
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <set>
#include <type_traits>

const unsigned int min = 10, max = 50; // ������������� �������� ��� ������� ������������

// ��������� ���������, sort �� �����

bool compare (std::string const& a, std::string const& b)
{
	return a.size() < b.size();
}

void CompareOfString() 
{
	using Compare = std::integral_constant<decltype(&compare), &compare>; // ������������� ����������
	std::multiset <std::string, Compare> stroka; // �������� multiset
	try // ��������� ������ ��������� ������
	{
		std::ifstream fin("C://Users/andbo/source/repos/Lab2(STL 1)/Debug/input.txt"); // �������� ����� ��� ������
		if (!fin.is_open()) // ���� ���� �� ������
			std::cout << "���� �� ����� ���� ������!\n"; // �������� �� ����
		else
		{
			std::string symb;
			while (std::getline(fin, symb)) // ������ ������ �� ����� �����
			{
				if (symb.size() > min && symb.size() < max)
				{
					stroka.insert(symb); // ��������� ������ � multiset, ����� ����� ������ ������, �� � �� ���� ���
				}
			}
			fin.close(); // ��������� ����
			std::ofstream fout("C://Users/andbo/source/repos/Lab2(STL 1)/Debug/output.txt"); // ��������� ���� ��� ������
			std::multiset <std::string> ::iterator it = stroka.begin(); // �������� ��������
			for (it = stroka.begin(); it != stroka.end(); it++)
			{
				fout << *it << std::endl; // ������� � ����
			}
			fout.close(); // ��������� ����
		}
	}
	catch (std::bad_alloc) {
		std::cout << "�� ������� �������� ������";
	}
}