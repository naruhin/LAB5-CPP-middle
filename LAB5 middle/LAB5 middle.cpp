//Вариант 17
//Дан файл f, все компоненты которого являются целыми числами. Получить в файле g все компоненты файла f, делящиеся на 3 
// и не делящиеся на 7

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.H>

using namespace std;

template <typename Stream>
bool read_num(Stream& stream, int& number)
{
	char c = 0;
	string buf;
	while (true)
	{
		stream.read(&c, 1);
		if (c == ' ' || stream.eof())
		{
			if (!buf.empty())
			{
				number = atoi(buf.c_str());
				return true;
			}
		}
		else
		{
			buf += c;
		}
	}

	return false;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	fstream fin;
	string inputPath = "C:\\Users\\user\\Desktop\\input.txt";
	string outputPath = "C:\\Users\\user\\Desktop\\output.txt";


	fin.open(inputPath);

	vector <int> numbers;
	
	if (fin.is_open()) {
		while (!fin.eof())
		{
			int num;

			if (read_num(fin, num))
				numbers.push_back(num);// тут можно складывать в список


			
		}
		
	}
	else {
		cout << "Ошибка открытия файла!" << endl;
		return 1;
	}
	fin.close();
	
	cout << "Числа из текстового файла : " << endl;
	for (int num : numbers)
		cout << num << " ";
	

	ofstream fout;          // поток для записи
	fout.open(outputPath); // окрываем файл для записи
	

	fout << "Числа, которые делятся на 3 и не делятся на 7 :" << endl;
	for (int num : numbers)
		if (num % 3 == 0 && num % 7 != 0) {
			fout << num << " ";
			
		}
			
		
	
	fout.close();

	return 0;
}

