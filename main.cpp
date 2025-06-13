#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

class Point
{
public:
	Point()
		:_x(0), _y(0), _z(0)
	{
	}
	Point(int x, int y, int z)
		:_x(x), _y(y), _z(z)
	{
	}
	virtual ~Point() {}

	void Print()
	{
		std::cout << "X: " << _x <<
			"\tY: " << _y << "\tZ: " <<
			_z << '\n';
	}
	friend std::ostream& operator<<(std::ostream& os, const Point& point);
	friend std::istream& operator>>(std::istream& is, Point& point);
private:
	int _x, _y, _z;
};

std::ostream& operator<<(std::ostream& os, const Point& point)
{
	os << point._x << " " << point._y << " " << point._z << '\n';
	return os;
}

std::istream& operator>>(std::istream& is, Point& point)
{
	is >> point._x >> point._y >> point._z;
	return is;
}

int main()
{
	setlocale(LC_ALL, "rus");

	clock_t start_time = clock();

	/*std::string path = "myFile.txt";

	std::ofstream fout;
	fout.open(path, std::ofstream::app);

	if (!fout.is_open())
	{
		std::cout << "Ошибка открытия файла\n";
	}
	else
	{
		int n = 0;
		std::cout << "Введите количество значений:\n";
		std::cin >> n;
		for (int i = 0; i < n; i++)
		{
			std::cout << "Введите значение:\n";
			int val = 0;
			std::cin >> val;
			fout << '\n' << val;
		}
	}
	fout.close();/*

	/*std::ifstream fin;
	fin.open(path, std::ifstream::app);

	if (!fin.is_open())
	{
		std::cout << "Ошибка открытия файла\n";
	}
	else
	{
		printf("Файл открыт\n");
		std::string str = "";
		//char str[50];

		while (!fin.eof())
		{
			str = "";
			//fin >> str;
			std::getline(fin, str);
			//fin.getline(str, 50);
			std::cout << str << '\n';
		}
	}

	fin.close();*/

	std::string path = "myFile.txt";
	//Point pt(4676, 322, 12);
	//std::cout << pt;
	/*Point pt1(456, 121, 985);
	pt1.Print();
	std::ofstream fout;
	fout.open(path, std::ofstream::app);

	if (!fout.is_open())
	{
		std::cout << "Ошибка открытия файла\n";
	}
	else
	{
		std::cout << "Файл открыт!\n";
		fout.write((char*)&pt1, sizeof(Point));
	}
	fout.close();*/
	/*Point pt2;
	std::ifstream fin;
	fin.open(path, std::ifstream::app);

	if (!fin.is_open())
	{
		std::cout << "Ошибка открытия файла\n";
	}
	else
	{
		printf("Файл открыт\n");
		while (fin.read((char*)&pt2, sizeof(Point)))
		{
			pt2.Print();
		}
	}
	fin.close();*/

	std::fstream fs;
	fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);

	if (!fs.is_open())
	{
		std::cout << "File isn't opened\n";
	}
	else
	{
		/*std::cout << "The file is open!\n";
		int value = 0;
		std::string msg;
		std::cout << "Input 1 to write to file:\n";
		std::cout << "Input 2 to read from file:\n";
		std::cin >> value;
		switch (value)
		{
		case 1:
			std::cout << "Writing for a file\n";
			std::cin >> msg;
			fs << msg << '\n';
			break;
		case 2:
			while (!fs.eof())
			{
				msg = "";
				std::cout << "Enter your value\n";
				fs >> msg;
				std::cout << msg << '\n';
			}
			break;
		case 0:
		default:
			printf("Enter a number!\n");
			break;
		}*/
		std::cout << "The file is open\n";
		//fs << pt << '\n';
		while (!fs.eof())
		{
			Point pt;
			fs >> pt;
			std::cout << pt << '\n';
		}
	}

	fs.close();

	clock_t end_time = clock();
	double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	std::cout << "\nВремя выполнения: " << time_taken << " секунд\n";

	return EXIT_SUCCESS;
}