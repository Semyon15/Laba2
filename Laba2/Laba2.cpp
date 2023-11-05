#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <map>

void initializeVectors(std::vector<std::string>& names, std::vector<short>& grades) {
	short choice;

	std::cout << "Что вы хотите сделать?" << std::endl;
	std::cout << "Введите 1 для демонстрационного варианта" << std::endl;
	std::cout << "Введите 2 для случаной инициализации" << std::endl;
	std::cout << "Введите 3 для самостоятельного ввода" << std::endl;
	std::cin >> choice;
	if (choice == 1) {
		names = { "Antony", "Carmela", "Madow", "Kristopher", "Poly", "Jackie", "Alex", "Frank", "Ralph", "Junior"};
		grades = { 90, 98, 95, 75, 55, 65, 89, 87, 78, 94 };
	}
	else if (choice == 2) {
		std::cout << "Введите желаем размер: " << std::endl;
		short size;
		std::cin >> size;
		std::vector<short> random_grades(size);
		srand(time(0));
		for (int i = 0; i < size; i++) {
			random_grades[i] = rand() % 101;
			
		}
	}
	else if (choice == 3) {
		short size, grade;
		std::string name;
		std::cout << "Введите количество студентов: " << std::endl;
		std::cin >> size;
		for (int i = 0; i < size; i++) {
			std::cout << "Вводите имена: " << std::endl;
			std::cin >> name;
			names.push_back(name);
			std::cout << "Вводите оценки: " << std::endl;
			std::cin >> grade;
			grades.push_back(grade);

		}
	}
	
}

void cout_index(std::vector<std::string>&names, std::vector<short>&grades) {
	for (int i = 0; i < names.size(); i++) {
		std::cout << names[i] << " , ";

	}
	std::cout << std::endl; 
	for (int i = 0; i < grades.size(); i++) {
		std::cout << grades[i] << " , "; 
	}
}
void cout_iterator(std::vector<std::string>& names, std::vector<short>& grades) {
	for (auto i = names.begin(); i != names.end(); i++)
		std::cout << *i << " , ";
	std::cout << std::endl;
	for (auto i = grades.begin(); i != grades.end(); i++)
		std::cout << *i << " , ";
	std::cout << std::endl;

}

void cout_RangeBasedFor(std::vector<std::string>& names, std::vector<short>& grades) { //без использования индексов
	for (std::string name : names) 
		std::cout << name << " , ";
	std::cout << std::endl;
	for (int grade : grades)
		std::cout << grade << " , ";
	std::cout << std::endl;
}

//поменять short на int (если не будет работать)

double avg_computing(std::vector<short>& grades){ 
	return grades.empty() ? 0.0 :
		(std::accumulate(grades.begin(), grades.end(), 0.0)) / grades.size();
}



double mediana_computing(std::vector<short>& grades) {
	short size{};
	if (grades.empty())
		return 0;
	std::sort(grades.begin(), grades.end());
	return (size % 2 == 0) ? (double)(grades[(size / 2) - 1] + grades[(size / 2)]) / 2.0 : (double)grades[size / 2];
}


//double moda_computing(std::vector<short>& grades) {
//	short mode = grades[0];
//	short maxgrade = 1;
//	std::sort(grades.begin(), grades.end());
//	short count = 1;
//	for (int i = 0; i < grades.size(); i++) {
//		if (grades[i] < grades[i - 1])
//			count++;
//		else {
//			if (count > maxgrade) {
//				maxgrade = count;
//				mode = grades[i - 1];
//
//			}
//			count = 1;
//		}
//	}
//	if (count > maxgrade)
//		mode = grades[grades.size() - 1];
//	std::cout << "Мода: " << mode << std::endl;
//	
//	//std::map <short, short> gradesfreq; //ключи - оценки, значения - кол-во раз, которое они встречаются
//	//for (short grade : grades) { //перебираю все оценки
//	//	gradesfreq[grade]++;
//	//}
//	//short 
//}

double moda_computing(std::vector<short>& grades) {
	if (grades.empty()) {
		std::cout << "Вектор оценок пуст." << std::endl;
		return 0;
	}

	std::sort(grades.begin(), grades.end());
	short mode = grades[0];
	short maxgrade = 1;
	short count = 1;

	for (int i = 1; i < grades.size(); i++) {
		if (grades[i] == grades[i - 1]) {
			count++;
		}
		else {
			if (count > maxgrade) {
				maxgrade = count;
				mode = grades[i - 1];
			}
			count = 1;
		}
	}

	if (count > maxgrade) {
		mode = grades[grades.size() - 1];
	}

	std::cout << "Мода: " << mode << std::endl;
	return mode;
}


int main() {
	setlocale(LC_ALL, "RU");
	std::vector<std::string> names;
	std::vector<short> grades;
	short choice;
	initializeVectors(names, grades);
	while (true) {
		std::cout << "1) Вывести векторы методом index" << std::endl;
		std::cout << "2) Вывести веторы методом Iterator" << std::endl;
		std::cout << "3) Вывести векторы методом Range-based for-loop" << std::endl;
		std::cout << "4) Вычислить медиану оценок" << std::endl;
		std::cout << "5) Вычислить моду оценок" << std::endl;
		std::cout << "6) Вычислить среднее значение оценок" << std::endl;
		std::cout << "0) Выход" << std::endl;
		std::cin >> choice;
		if (choice == 0) {
			break;
		}
		switch (choice) {
			case 1: cout_index(names, grades); break;
			case 2:cout_iterator(names, grades); break;
			case 3:cout_RangeBasedFor(names, grades); break;
			case 4:mediana_computing(grades); break;
			case 5:moda_computing(grades); break;
			case 6:avg_computing(grades); break;
				
		}
	}
}