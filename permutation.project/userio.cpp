
#include "userio.h"
#include "permutation.lib.h"

int printMenu() {
	std::cout << "\n#############################################################\n";
	std::cout << "\t\tMenu options:\n";
	std::cout << "-------------------------------------------------------------\n";
	std::cout << "EX.1\t1 -> Define a two-dimensional dynamic array\n";
	std::cout << "EX.2\t2 -> Define a function of C ++ filling of a two-dimensional array\n";
	std::cout << "EX.3\t3 -> Check if a function is an injection\n";
	std::cout << "EX.4\t4 -> Check if a function is a surjection\n";
	std::cout << "EX.5\t5 -> Check if a function is permutation\n";
	std::cout << "EX.6\t6 -> Reveil the number of permutations in the set\n";
	std::cout << "EX.7\t7 -> Check if there are any fixed points\n";
	std::cout << "EX.8\t8 -> Reveil the number of fixed points\n";
	std::cout << "EX.9\t9 -> Chech if a function is identity\n";
	std::cout << "EX.10\t10 -> Permutation to cycle notation\n";
	std::cout << "EX.11\t11 -> Cycle notation lenght\n";
	std::cout << "EX.12\t12 -> Cycle notation to set\n";
	std::cout << "EX.13\t13 -> Composition of two permutations to set\n";
	std::cout << "EX.14\t14 -> Find reverse permutation\n";
	std::cout << "EX.15\t15 -> Composition to reverse permutation and check whether it is identity or not\n";
	std::cout << "EX.16\t16 -> Check if two non-identity permutations are noncommutative\n";
	std::cout << "EX.17\t17 -> The number of iterations to reach identity\n";
	std::cout << "-------------------------------------------------------------\n";
	std::cout << "\t0 -> EXIT\n";
	std::cout << "#############################################################\n";
	return 0;
}

int checkValidData() {
	
	return 0;
}

int menu() {
	printMenu();

	int option = -1;
	std::cout << "\nEnter your choice: ";
	std::cin >> option;

	switch (option) {
	case 0: return 0;
	case 1: zad1and2base(); break;
	case 2: zad1and2base(); break;
	case 3: zad3to10base(option); break;
	case 4: zad3to10base(option); break;
	case 5: zad3to10base(option); break;
	case 6: zad3to10base(option); break;
	case 7: zad3to10base(option); break;
	case 8: zad3to10base(option); break;
	case 9: zad3to10base(option); break;
	case 10: zad3to10base(option); break;
	case 11: zad11base(); break;
	case 12: zad12base(); break;
	case 13: zad13base(); break;
	case 14: zad14base(); break;
	case 15: zad15base(); break;
	case 16: zad16base(); break;
	case 17: zad17specify(); break;
	default: std::cout << "There is not such option!\n";
	}

	anotherOption();

	return 0;
}

int printAnotherOption() {
	std::cout << "\n\n#############################################################\n";
	std::cout << "\t\tWant to go back to the menu?\n";
	std::cout << "-------------------------------------------------------------\n";
	std::cout << "\t\t1 - YES!\n";
	std::cout << "\t\t2 - NO!\n";
	std::cout << "#############################################################\n";
	return 0;
}

int anotherOption() {
	printAnotherOption();
	int option = -1;
	std::cout << "\nEnter your choice: ";
	std::cin >> option;
	switch (option) {
	case 1: menu(); break;
	case 2: 
		return 0; 
		break;
	default: 
		std::cout << "There is not such option! You should choose between 1 and 2!\n";
		anotherOption();
		break;
	}
	return 0;
}

int zad17specify() {
	int option;
	std::cout << "\n\n#############################################################\n";
	std::cout << "\t\tHow do you want to calc the exercise?\n";
	std::cout << "-------------------------------------------------------------\n";
	std::cout << "\t\t1 - Sequential check\n";
	std::cout << "\t\t2 - LCM (bulgarian - \"NOK\")\n";
	std::cout << "#############################################################\n";

	std::cin >> option;
	if (option < 1 || option >2) {
		std::cout << "There is not such option! Choose again:";
		zad17specify();
	}

	zad17base(option);

	return 0;
}