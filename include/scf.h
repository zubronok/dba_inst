#pragma once

//
// 
// SCF - Standart C++ Functions
//
//

#include <string>
#include <vector>
#include <ctime>
#include <iostream>

#define csize const size_t
#define __ftext size_t i = 0; i < size; i++
#define __ftextm size_t i = 0; i < size-1; i++
#define __temp template <typename _T>
#define __tvect vector<_T>
#define __ifor(a) size_t i = 0; i < a; i++

#define intv vector<int>
#define strv vector<string>

using std::string;
using std::vector;
using std::cout;
using std::endl;


// �������
// in:		
// out:		void: -


// sfunct (��������� �������)

// ������� ������ ������� �������� � ��������� indexFst � indexScd � ������� vct
// in:		 vct:	������, � ������� ����� ������ ��������
//		indexFst:	������ ������� ��������
// 		indexScd:	������ ������� ��������		(������� ��������� �� �����)
// out:  __tvect:	��� �� ������, �� � ����������� ����������

__temp
__tvect itemswap(__tvect vct, int indexFst, int indexScd)
{
	_T temp = vct[indexFst];
	vct[indexFst] = vct[indexScd];
	vct[indexScd] = temp;
	return vct;
}

// string


// ������� ��������� ������ �� ��������� �� �����������.
// in:	text:			�����, ������� ����� ���������
//		delimeter:		������-����������� (�� ��������� - ������, ���������� ������ �� �����)
// out: vector<string>:	������ vector � ������������ �������� ��������� (� ������ �������� �������)

vector<string> split(string text, char delimeter = ' ')
{
	size_t pointer = 0;
	vector<string> vct;
	csize size = text.size();
	for (__ftextm)
	{
		if (text[i] == delimeter && i != 0)
		{
			string _text = "";
			for (size_t j = pointer; j < i; j++)
			{
				_text += text[j];
			}
			pointer = i;
			if (vct.size() >= 1) {
				vct.push_back(_text.substr(1, _text.size()));
			}
			else {
				vct.push_back(_text);
			}
			
		}
	}
	string _text;
	_text = "";
	for (size_t j = pointer; j < size; j++)
	{
		_text += text[j];
	}
	vct.push_back(_text.substr(1, _text.size()));
	return vct;
}



// ������� �������� ��� ������� wRep �� tRep � ������ text
// in:		text:		�����, � ������� ����� �������� �������
//			wRep:		������, ������� ����� ��������
//			tRep:		������, ������� ����� ��������
// out:		string:		����� � ����������� ���������

string replace(string text, char wRep, char tRep = '\0')
{
	csize size = text.size();
	for (__ftext)
	{
		if (text[i] == wRep) text[i] = tRep;
	}
	return text;
}



// prints

// ������� ������� text �� �����
// in:		text: �����, ������� ����� �������	
// out:		void: -

__temp
void print(_T text)
{
	cout << text;
}

// ������� ������� text �� ����� � ��������� �� ����� ������
// in:		text: �����, ������� ����� �������	
// out:		void: -

__temp
void printLn(_T text)
{
	cout << text << endl;
}

// ������� ������� ������ vct �� �����
// in:		vct: ������ ������ ��� ������
// out:		void: -

__temp
void print(__tvect vct)
{
	size_t size = vct.size();
	print("[");
	for (__ftextm)
	{
		print(vct[i]);
		cout << ", ";
	}
	print(vct[size - 1]);
	cout << "]";
}

// ������� ������� ������ vct �� ����� � ��������� �� ����� ������
// in:		vct: ������ ������ ��� ������
// out:		void: -

__temp
void printLn(__tvect vct)
{
	size_t size = vct.size();
	print("[");
	for (__ftextm)
	{
		print(vct[i]);
		cout << ", ";
	}
	print(vct[size - 1]);
	cout << "]" << endl;
}

// ������� ������� ������� vct �� �����
// in:		vct: ������ ������ ��� ������
// out:		void: -

__temp
void printMatrix(vector <__tvect> vect)
{
	csize size = vect.size();
	cout << "[\t" << endl;
	for (__ftext)
	{
		cout << "\t";
		print(vect[i]);
		cout << endl;
	}
	cout << "]\t" << endl;
}

// convert

// ������� ������������ ������ � ���������� ���� int � ������ � ���������� ���� string
// in:		vct:			������ ������ � ���������� int
// out:		vector<string>:	������ ������ � ���������� string

vector<string> convertV(vector<int> vct)
{
	csize size = vct.size();
	vector<string> vect;
	for (size_t i = 0; i < size; i++)
	{
		vect.push_back(std::to_string(vct[i]));
	}
	return vect;
}

// ������� ������������ ������ � ���������� ���� string � ������ � ���������� ���� int
// in:		vct:			������ ������ � ���������� string
// out:		vector<string>:	������ ������ � ���������� int

vector<int> convertV(vector<string> vct)
{
	csize size = vct.size();
	vector<int> vect;
	for (size_t i = 0; i < size; i++)
	{
		vect.push_back(std::stoi(vct[i]));
	}
	return vect;
}

// generate

// ������� ���������� ������ � ���������� ���� int �������� size, �������� � ������� ����������� ����� ��� ste[
// in:		size:		������ ������������� �������
//			startpos:	����������� �������� (�� �������� ����� ���������)
//			step:		���. ����� ������� ����� ����������� ��������
// out:		intv:		C�������������� ������

intv generatesv(size_t size, int startpos = 0, int step = 1)
{
	intv vect;
	for (size_t i = 0; i < size * step; i += step)
	{
		vect.push_back(i + startpos);
	}
	return vect;
}

// ������� ���������� ������ � 0 �������� size
// in:		size:		������ ������������� �������
// out:		intv:		C�������������� ������

intv generate0(size_t size)
{
	intv vect;
	for (__ifor(size))
	{
		vect.push_back(0);
	}
	return vect;
}

// ������� ���������� ������ � ���������� ���� int �������� size, � ��������� ��� ���������� ���������� �� minVal �� maxVal (��� ������������)
// in:		size:		������ ������������� �������
//			minVal:		���������� ���������� �������� ��������� (������������)
//			maxVal:		����������� ���������� �������� ��������� (������������)
// out:		intv:		��������������� ������

intv generaternd(size_t size, int minVal, int maxVal)
{
	intv vect;
	if (minVal >= 0)
	{
		for (__ifor(size))
		{
			vect.push_back(minVal + rand() % (maxVal + 1));
		}
	}
	return vect;
}

// sort/mix

// ������� ������������ �������� � �������
// in:		vct:		������, � ������� ����� ��������� ��������
// out:		__tvect:	��� �� ������ � ������������� ����������

__temp
__tvect mix(__tvect vct)
{
	csize size = vct.size();
	for (__ftext)
	{
		vct = itemswap(vct, i, (rand() % size));
		if (i % 2 == 0) vct = itemswap(vct, (rand() % size), (rand() % size));
	}
	return vct;
}

//	��������� ���������� ������!
//	����������