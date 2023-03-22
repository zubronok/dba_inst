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


// Функция
// in:		
// out:		void: -


// sfunct (служебные функции)

// Функция меняет местами элементы с индексами indexFst и indexScd в массиве vct
// in:		 vct:	Вектор, в котором нужно менять элементы
//		indexFst:	Индекс первого элемента
// 		indexScd:	Индекс второго элемента		(порядок элементов не важен)
// out:  __tvect:	Тот же вектор, но с замененными элементами

__temp
__tvect itemswap(__tvect vct, int indexFst, int indexScd)
{
	_T temp = vct[indexFst];
	vct[indexFst] = vct[indexScd];
	vct[indexScd] = temp;
	return vct;
}

// string


// Функция разбивает строку на подстроки по разделителю.
// in:	text:			Текст, который нужно разделить
//		delimeter:		Символ-разделитель (по умолчанию - пробел, разделение текста на слова)
// out: vector<string>:	Массив vector с разделенными строками раздельно (в каждом элементе массива)

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



// Функция заменяет все символы wRep на tRep в тексте text
// in:		text:		Текст, в котором нужно заменять символы
//			wRep:		Символ, который нужно заменять
//			tRep:		Симолв, которым нужно заменять
// out:		string:		Текст с замененными символами

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

// Функция выводит text на экран
// in:		text: Текст, который нужно вывести	
// out:		void: -

__temp
void print(_T text)
{
	cout << text;
}

// Функция выводит text на экран и переходит на новую строку
// in:		text: Текст, который нужно вывести	
// out:		void: -

__temp
void printLn(_T text)
{
	cout << text << endl;
}

// Функция выводит массив vct на экран
// in:		vct: Массив вектор для вывода
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

// Функция выводит массив vct на экран и переходит на новую строку
// in:		vct: Массив вектор для вывода
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

// Функция выводит матрицу vct на экран
// in:		vct: Массив вектор для вывода
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

// Функция конвертирует вектор с элементами типа int в вектор с элементами типа string
// in:		vct:			Массив вектор с элементами int
// out:		vector<string>:	Массив вектор с элементами string

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

// Функция конвертирует вектор с элементами типа string в вектор с элементами типа int
// in:		vct:			Массив вектор с элементами string
// out:		vector<string>:	Массив вектор с элементами int

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

// Функция генерирует массив с элементами типа int размером size, элементы в порядке возрастания через шаг ste[
// in:		size:		Размер генерируемого массива
//			startpos:	Минимальное значение (от которого нужно заполнять)
//			step:		Шаг. через который будут заполнятсья элементы
// out:		intv:		Cгенерированный массив

intv generatesv(size_t size, int startpos = 0, int step = 1)
{
	intv vect;
	for (size_t i = 0; i < size * step; i += step)
	{
		vect.push_back(i + startpos);
	}
	return vect;
}

// Функция генерирует массив с 0 размером size
// in:		size:		Размер генерируемого массива
// out:		intv:		Cгенерированный массив

intv generate0(size_t size)
{
	intv vect;
	for (__ifor(size))
	{
		vect.push_back(0);
	}
	return vect;
}

// Функция генерирует массив с элементами типа int размером size, и заполняет его случайными элементами от minVal до maxVal (все включительно)
// in:		size:		Размер генерируемого массива
//			minVal:		Минимально допустимое значение элементов (включительно)
//			maxVal:		Максимально допустимое значение элементов (включительно)
// out:		intv:		Сгенерированный массив

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

// Функция перемешивает элементы в массиве
// in:		vct:		Вектор, в котором нужно пермешать элементы
// out:		__tvect:	Тот же вектор с перемешанными элементами

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

//	ПОЛНОСТЬЮ ПЕРЕДЕЛАТЬ РАНДОМ!
//	сортировки