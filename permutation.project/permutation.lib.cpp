#include "permutation.lib.h"

#include <iostream>


//zad 2
int fill2Set(int **set, int R, int C) {
	//������� �������� �����

	//for (int r = 0; r < R; r++) {
	//	for (int c = 0; c <= C - 1; c++) {
	//		std::cout << "Enter element[" << r << "][" << c << "]: ";
	//		std::cin >> set[r][c];
	//	}
	//}

	while (checkInput(set, R, C)==false) {
		for (int r = 0; r < R; r++) {
			std::cout << "R[" << r + 1 << "]:\t";
			for (int c = 0; c <= C - 1; c++) {
				std::cin >> set[r][c];
			}
		}
	}

	return 0;
}


//zad 3
bool isInjection(int**set, int R, int C) {
	//��������� ���� ������� ��� ������ ��� �� ��������. ��� �� ��, �� �� � �������, ������ ����������� ��
	//�������� �� �� �������� � � ������ ���. ���
	if (isFunction(set, R, C)) {
		for (int i = 0; i < C; i++) {
			for (int j = i; j < C; j++) {
				if (i != j) {
					if (set[1][i] == set[1][j]) {
						if (set[0][i] != set[0][j]) {
							return false;
						}
					}
				}
			}
		}

		return true;
	}

	//��� �� � �������, ����� �� � �������.
	return false;
}

bool isFunction(int** set, int R, int C) {
	//��������� ���� �����, �������� � �����, �� �������
	//set - �������� �����
	//R - �������� � ���������
	//C - �������� � ���������

	for (int i = 0; i < C; i++) {
		for (int j = i; j < C; j++) {
			if (i != j) {
				if (set[0][i] == set[0][j]) {
					if (set[1][i] != set[1][j]) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

//zad 4
bool isSurjection(int** set, int R, int C) {
	//��������� ���� ������ ������� � ��������
	//��� ���� ���� �� ���������� � ��������, �������� ��� ���� ���� ���������� ������ ����� �� �������
	//set - �������� �����, � ����� � �������� ���������
	//R - �������� � ���������
	//C - �������� � ��������� / ���� �� ���������� � ������������

	if (isFunction(set, R, C)) {
		return true;
	}
	
	return false;
	}

int printSet(int** set, int R, int C){
	//�������� ���������� �������� � �������� �����
	std::cout << std::endl;
	std::cout << "The curent version of the set is:" << std::endl;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c <= C - 1; c++) {
			std::cout << set[r][c] << "\t";
		}
		std::cout << std::endl;
	}
	return 0;
}

//zad5
bool isPermutation(int** set, int R, int C, bool isInjection, bool isSurjection) {
	//��������� ���� ������ ������� � ����������
	
	//������ ����������, � ����� �� ����������� ���������� �� ���� ���� ����� ����� �� ������ ��� ���
	//���� ���������� � ������.

	if (R != 2) {
		std::cout << "R MUST be 2 in this function to work!\n";
		return false;
	}

	bool isThere = false;
	
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C; j++) {
			if (set[1][i] == set[0][j])isThere = true;
		}
		if (isThere == false) return false;
		isThere = false;
	}

	if (isInjection && isSurjection) {
		return true;
	}
	else {
			return false;
	}
	
}

//zad6
int numberOfPermutations(int** set, int C) {
	//������� ���� �� ������������ 

	int count = 1;
	int i, j;
		for (i = 1; i < C; i++) {
			for (j = 0; j < i; j++) {
				if (set[0][i] == set[0][j]) {
					break;
				}
			}
			if (i == j) {
				count++;
			}
		}

		int permutations = 1;
		for (int y = 1; y <= count; y++) {
			permutations *= y;
		}
		return permutations;
}

//zad7
bool anyFixedPoints(int** set, int R, int C) {
	//��������� ���� ��� ������� � �� � ��������� ����� � ������ ����������
	//set - �������� �����, � ����� � �������� ������������
	//R - �������� � ���������
	//C - �������� � ��������� / ���� �� ���������� � ������������

	if (R != 2) {
		std::cout << "The rows should be 2.\n";
		return false;
	}

	bool fixedPoints = false;
	for (int i = 0; i < C; i++) {
		if (set[0][i] == set[1][i]) fixedPoints = true;
	}

	if (fixedPoints) return true;
	else return false;
}

//zad8
int fixedPointsCounter(int** set, int R, int C) {
	//���� ����� ��������� ����� ��� � ������������
	//set - �������� �����, � ����� � �������� ������������
	//R - �������� � ���������
	//C - �������� � ��������� / ���� �� ���������� � ������������
	//�����: cnt - ���� �� ����������� �����

	if (R < 2) {
		std::cout << "The rows should be more than 1.\n";
		return 0;
	}

	int cnt = 0;
	for (int i = 0; i < C; i++) {
		if (set[0][i] == set[1][i])cnt++;
	}

	return cnt;
}

//zad9
bool isIdentity(int**set, int R, int C) {
	//��������� ���� ������������ � ���������
	//set - ������, � ����� � �������� ������������
	//R - �������� � ���������
	//C - �������� � ���������

	if (R < 2) {
		std::cout << "The rows should be more than 1.\n";
		return false;
	}

	bool identity = true;
	for (int i = 0; i < C; i++) {
		if (set[0][i] != set[1][i]) identity = false;
	}

	if (identity) return true;
	else return false;
}

//zad10
int cycleNotation(int**set, char * loops, int C, int loopsSize) {
	//������� ���������� �� ������� � �������� �������
	
	int i = 0;
	int indx = -1;
	char first;
	char last;
	bool isThere = false;

	//�������� ������, � ����� �� ��������� �����������, �� �� �� ����� ��������� � garbage-value-����
	loops[loopsSize] = { 0 };


	while (i<C) {
		//��������� ���� ������� � ����������� � ������ ������
		for (int y = 0; y < loopsSize; y++) {
			if (loops[y]-'0' == set[0][i]) {
				isThere = true;
			}
		}

		//��� �� � �����������, 
		if (isThere == false) {
			first = set[0][i];//��������� x
			last = set[1][i];//��������� f(x)
			loops[++indx] = '(';//�������� ���� �������� �������
			loops[++indx] = first + '0';
			while (first != last) {
				for (int j = 0; j < C; j++) {
					if (set[0][j] == last) {
 						loops[++indx] = last + '0';
						last = set[1][j];
					}

					//�������� ������� � ���� �������;
					//if (set[1][j] == first) { 
					//	loops[++indx] = first;
					//}

				}
			}
			loops[++indx] = ')';
		}
		i++;
		isThere = false;
	}
	loops[++indx] = '\0';
	return 0;
}

//zad11
int cycleSizeCounter(char* loops, int* cycleSize) {
	//���� ��������� �� ������� � �� ������� � �����
	int cnt = 0;
	int i = 0;
	int indx = -1;

	while (loops[i] != '\0') {
		if (loops[i] >= 1 + '0' && loops[i] <= 9 + '0') cnt++;
		if (loops[i] == '(' || loops[i] == ')' || loops[i] == '/0') {
			if (cnt != 0) {
				cycleSize[++indx] = cnt;
				cnt = 0;
			}
		}
		i++;
	}

	cycleSize[++indx] = '\0';
	return 0;
}

int cycleSizePrinter(int* cycleSize) {
	int i = 0;
	while (cycleSize[i] != '\0') {
		std::cout << "The size of the independent cycle [" << i + 1 << "] is " << cycleSize[i] << ".\n";
		i++;
	}
	return 0;
}


//zad12

int fillCycleNotation(char* customLoops, int customLoopsSize) {
	std::cout << "Enter the cyclic notation: ";
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	int finalSize = customLoopsSize + 1;
	std::cin.getline(customLoops, finalSize);
	std::cin.clear();
	return 0;
}

int printCycleNotation(char* customLoops) {
	std::cout << "Your cycle notation is: " << customLoops << '\n';
	return 0;
}

int cycleToSet(char* customLoops, int** customSet) {
	int i = 0;
	int tmp = 0;
	int indx = -1;
	while (customLoops[i] != '\0') {
		if (customLoops[i] == '(' || customLoops[i] == ')') {
			i++;
			continue;
		}
		if (customLoops[i - 1] == '(' && (customLoops[i] >= 1 + '0' && customLoops[i] <= 9 + '0') && (customLoops[i + 1] >= 1 + '0' && customLoops[i + 1] <= 9 + '0')) {
			tmp = customLoops[i];
			customSet[0][++indx] = customLoops[i] - '0';
			customSet[1][indx] = customLoops[i + 1] - '0';
		}
		if ((customLoops[i - 1] >= 1 + '0' && customLoops[i - 1] <= 9 + '0') && (customLoops[i] >= 1 + '0' && customLoops[i] <= 9 + '0') && (customLoops[i + 1] >= 1 + '0' && customLoops[i + 1] <= 9 + '0')) {
			customSet[0][++indx] = customLoops[i] - '0';
			customSet[1][indx] = customLoops[i+1] - '0';
		}
		if ((customLoops[i - 1] >= 1 + '0' && customLoops[i - 1] <= 9 + '0') && (customLoops[i] >= 1 + '0' && customLoops[i] <= 9 + '0') && customLoops[i + 1] == ')') {
			customSet[0][++indx] = customLoops[i] - '0';
			customSet[1][indx] = tmp - '0';
			tmp = 0;
		}
		if (customLoops[i - 1] == '(' && (customLoops[i] >= 1 + '0' && customLoops[i] <= 9 + '0') && customLoops[i + 1] == ')') {
			customSet[0][++indx] = customLoops[i] - '0';
			customSet[1][indx] = customLoops[i] - '0';
		}
		i++;
	}

	return 0;
}

//zad13
int composition(char* customLoops1, int perm1size, char* customLoops2, int perm2size) {
	if (perm1size != perm2size) {
		std::cout << "Error! The program can NOT compile a composition of two permutations with different number of elements!\n";
		return -1;
	}

	const int R = 2;
	int C = perm1size;
	
	//������� �����
	int** perm1set = create2dArray(R, perm1size);
	int** perm2set = create2dArray(R, perm2size);
	int** permRes = create2dArray(R, C);

	cycleToSet(customLoops1, perm1set);
	cycleToSet(customLoops2, perm2set);


	compositionOnly(perm1set, perm2set, permRes, R, C);

	std::cout << "Composition: DONE!\n";

	printSet(permRes, R, C);

	//������������ �������
	delete2dArray(perm1set, R);
	delete2dArray(perm2set, R);
	delete2dArray(permRes, R);

	return 0;
}

int compositionOnly(int** set1, int** set2, int** setRes, int R, int C) {
	//�������, ����� ������� ���������� �� ��� ���������� � �� ������� � ������ �������
	//����� �� ��������� ��� �������
	//set1 - ������� 1
	//set2 - ������� 2
	//set3 - ������� 3

	if (compositionCheck(set1, set2, R, C) == false) {
		std::cout << "These two permutations could not be grouped in a composition.\n";
		return 0;
	}

	if (R < 2) {
		std::cout << "There should be more than two rows in the matrix!\n";
		return 0;
	}

	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C; j++) {
			if (set1[0][j] == set2[1][i]) {
				//������� ������� �� ����������
				int tmpfirstrow = set1[0][j];
				int tmpsecondrow = set1[1][j];
				set1[0][j] = set1[0][i];
				set1[1][j] = set1[1][i];
				set1[0][i] = tmpfirstrow;
				set1[1][i] = tmpsecondrow;
			}
		}
	}

	for (int i = 0; i < C; i++) {
		setRes[0][i] = set2[0][i];
		setRes[1][i] = set1[1][i];
	}

	return 0;
}

bool compositionCheck(int** perm1set, int** perm2set, int R, int C) {
	//��������� ���� � �������� �� �� ������� ���������� �� ����� ����������
	
	bool isThere = false;

	if (R < 2) {
		std::cout << "There should be at least 2 rows in the set.\n";
		return false;
	}
	
	for (int i = 0; i < C; i++) {
		for (int j=0; j < C; j++) {
			if (perm2set[1][i] == perm1set[1][j]) isThere = true;
		}
		if (isThere == false) {
			return false;
		}
		isThere = false;
	}

	return true;
}


//zad14
int reversePermutation(char* customLoopsRev) {
	int i = 0;
	char start;
	char stop;
	char tmp;
	while (customLoopsRev[i] != '\0') {
		if (customLoopsRev[i] == '(') {
			start = i + 1;
			int j = i;
			while (customLoopsRev[j] != ')') {
				stop = j;
				j++;
			}
			while (start < stop)
			{
				tmp = customLoopsRev[start];
				customLoopsRev[start] = customLoopsRev[stop];
				customLoopsRev[stop] = tmp;
				start++;
				stop--;
			}
		}
		i++;
	}
	return 0;
}

//zad15
int reverseComposition(char* cstmLoopsRevToComp, int permRevToCompSize, int cstmLoopsRevToCompSize) {
	char* reverseLoops = new char[cstmLoopsRevToCompSize + 1];
	int i = 0;
	while (cstmLoopsRevToComp[i] != '\0') {
		reverseLoops[i] = cstmLoopsRevToComp[i];
		i++;
	}
	reversePermutation(reverseLoops);

	const int R = 2;
	int C = permRevToCompSize;

	//������� �����
	int** setInput = create2dArray(R, permRevToCompSize);
	int** setReverse = create2dArray(R, permRevToCompSize);
	int** setResult = create2dArray(R, C);

	cycleToSet(cstmLoopsRevToComp, setInput);
	cycleToSet(reverseLoops, setReverse);

	if (compositionCheck(setInput, setReverse, R, C) == false) {
		std::cout << "These two permutations could not be grouped in a composition.\n";
		return 0;
	}

	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C; j++) {
			if (setInput[0][j] == setReverse[1][i]) {
				//������� ������� �� ����������
				int tmpfirstrow = setInput[0][j];
				int tmpsecondrow = setInput[1][j];
				setInput[0][j] = setInput[0][i];
				setInput[1][j] = setInput[1][i];
				setInput[0][i] = tmpfirstrow;
				setInput[1][i] = tmpsecondrow;
			}
		}
	}

	for (int i = 0; i < C; i++) {
		setResult[0][i] = setReverse[0][i];
		setResult[1][i] = setInput[1][i];
	}


	std::cout << "Composition: DONE!\n";

	printSet(setResult , R, C);

	if (isIdentity(setResult, R, C)) std::cout << "The result IS an identity!";
	else std::cout << "The result is NOT an identity!";

	//������������ �������
	delete2dArray(setInput, R);
	delete2dArray(setReverse, R);
	delete2dArray(setResult, R);

	if (reverseLoops != nullptr) {
		delete[] reverseLoops;
	}

	return 0;
}

//zad16
int zad16(char* perm1notation, char*perm2notation, int C) {
	//�������, ����� ����� �� ��������� ��� �e��������, �������� � �������� ������� � ������� �� ���������� ��
	//��������� ���� ����� �� ���������
	//��������� ���� ���������� ���������� �� ����� � ����������� 

	const unsigned R = 2;

	//������� �����
	int** set1 = create2dArray(R, C);
	int** set2 = create2dArray(R, C);
	int** composition1 = create2dArray(R, C);
	int** composition2 = create2dArray(R, C);

	cycleToSet(perm1notation, set1);
	cycleToSet(perm2notation, set2);

	if (isIdentity(set1, R, C))std::cout << "The first permutation is an identity!\n";
	else std::cout << "The first permutation is NOT an identity!\n";
	if (isIdentity(set2, R, C))std::cout << "The second permutation is an identity!\n";
	else std::cout << "The second permutation is NOT an identity!\n";

	compositionOnly(set1, set2, composition1, R, C);
	compositionOnly(set2, set1, composition2, R, C);

	if(matrixEquality(composition1, composition2, R, C)){
		std::cout << "The composition of those two permutations is commutative\n";
	}
	else {
		std::cout << "The composition of those two permutations is NONcommutative\n";
	}

	//������������ �������
	delete2dArray(composition2, R);
	delete2dArray(composition1, R);
	delete2dArray(set1, R);
	delete2dArray(set2, R);

	return 0;
}

bool matrixEquality(int** set1, int** set2, int R, int C) {
	//�������, ����� ��������� ���� ��� ������� �� ������������
	//���������:
	//set1 - ����� �������
	//set2 - ����� �������
	//R - ���� �� �������� � ���������
	//C - ���� �� �������� � ���������

	bool isEqual = true;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (set1[r][c] != set2[r][c]) {
				isEqual = false;
			}
		}
	}

	if (isEqual) return true;
	else return false;
}

int nok(int a, int b)
{
	if (b == 0)
		return a;
	return nok(b, a % b);
}

int findNOK(int* arr, int n)
{
	int ans = arr[0];

	// ������ ��������� ���� ����� ��������
	for (int i = 1; i < n; i++)
		ans = (((arr[i] * ans)) / (nok(arr[i], ans)));

	return ans;
}



int matrixcopy(int**set1, int** set2, int R, int C) {
	//�������, ����� ������ ������� 2 � ������� 1
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			set1[i][j] = set2[i][j];
		}
	}

	return 0;
}

//zad3-10Base
int zad3to10base(int choice) {
	const int R = 2;
	int C = 0;
	
	std::cout << "Enter the number of columns in the set: ";
	while (C <= 0) {
		if(C<0) std::cout << "Wrong input. Enter a positive number: ";
		std::cin >> C;
	} //������ �����

	//�������� �� ��������� �����
	int** set = create2dArray(R, C);

	fill2Set(set, R, C);//��������� �� ������
	printSet(set, R, C); //���������� �� ������ �� ��������
	
	//�������� ���� � �������
	if (isFunction(set, R, C)) std::cout << "This is a function.\n";
	else std::cout << "This is NOT a function\n";


	switch (choice) {
	case 3:
		//�������� ���� � �������
		if (isInjection(set, R, C)) std::cout << "This is an injection.\n";
		else std::cout << "This is NOT an injection.\n";
		break;

	case 4:
		//�������� ���� � ��������
		if (isSurjection(set, R, C)) std::cout << "This is a surjection.\n";
		else std::cout << "This is NOT an surjection.\n";
		break;

	case 5:
		//�������� ���� � ����������
		if (isPermutation(set, R, C, isInjection(set, R, C), isSurjection(set, R, C))) std::cout << "This is a permutaion.\n";
		else std::cout << "This is NOT  a permutation.\n";
		break;

	case 6:
		//���� �� ������������
		if (!(isPermutation(set, R, C, isInjection(set, R, C), isSurjection(set, R, C)))) std::cout << "The entered set is NOT a permutation!\n";
		else std::cout << "The number of permutations of the set is " << numberOfPermutations(set, C) << std::endl;
		break;

	case 7:
		//��� �� ��������� �����
		if (anyFixedPoints(set, R, C)) std::cout << "There are fixed points.\n";
		else std::cout << "There are NOT any fixed points.\n";
		break;

	case 8:
		//����� � ����� �� ����������� �����
		if (fixedPointsCounter(set, R, C) > 0) std::cout << "There are/is " << fixedPointsCounter(set, R, C) << " fixed point/s.\n";
		else std::cout << "There are NOT any fixed points to be counted.\n";
		break;

	case 9:
		//��������� ���� ��������� � ���������
		if (isIdentity(set, R, C)) std::cout << "The function is identity.\n";
		else std::cout << "The function is NOT identity.\n";
		break;

	case 10:
		//������� �����, � ����� �� ������� ������������ �����, ����� � ���������� �� ������� �� ���������� �����
		int loopsSize = C * 3;
		char* loops = new char[loopsSize + 1];

		//����� �� ����������� ������� � ������ � ���������� �� ���������
		cycleNotation(set, loops, C, loopsSize);
		std::cout << loops << std::endl;

		//������������ �������, � ����� ���������� ������������ �����
		if (loops != nullptr) {
			delete[] loops;
		}
		break;
	}

	//������������� �� �������, � ����� ���������� ���������
	delete2dArray(set, R);
	return 0;
}
//zad11Base
int zad11base() {
	const int R = 2;
	int C = 0;

	std::cout << "Enter the number of columns in the set: ";
	while (C <= 0) {
		if (C < 0) std::cout << "Wrong input. Enter a positive number: ";
		std::cin >> C;
	} //������ �����

	//�������� �� ��������� �����
	int** set = create2dArray(R, C);

	fill2Set(set, R, C);//��������� �� ������
	printSet(set, R, C); //���������� �� ������ �� ��������

	//�������� ���� � �������
	if (isFunction(set, R, C)) std::cout << "This is a function.\n";
	else std::cout << "This is NOT a function\n";


	//������� �����, � ����� �� ������� ������������ �����, ����� � ���������� �� ������� �� ���������� �����
	int loopsSize = C * 3;
	char* loops = new char[loopsSize + 1];

	//����� �� ����������� ������� � ������ � ���������� �� ���������
	cycleNotation(set, loops, C, loopsSize);
	std::cout << loops << std::endl;

	//������� �����, � ����� �� ������� ��������� �� ������������ �����
	int* cycleSize = new int[C]; //�� ���� ���� �� ������ �� �� ������ +1 ��� ���������� �� ������?

	//��������� ��������� �� ������������ �����
	cycleSizeCounter(loops, cycleSize);
	cycleSizePrinter(cycleSize);

	//������������ �������, � ����� ���������� ��������� �� ������������ �����
	if (cycleSize != nullptr) {
		delete[] cycleSize;
	}
	//������������ �������, � ����� ���������� ������������ �����
	if (loops != nullptr) {
		delete[] loops;
	}
	//������������� �� �������, � ����� ���������� ���������
	delete2dArray(set, R);
	return 0;
}

//zad12base
int zad12base() {
	const int R = 2;


	//������� ����� �� ���������� ������� � �����, � ����� �� ������� ���������
	int k;
	std::cout << "How many elements do you want to have in the function: ";
	std::cin >> k;

	int customLoopsSize = k * 3;
	char* customLoops = new char[customLoopsSize + 1];

	int** customSet = create2dArray(R, k);

	//�������� ������ �� ���������� �������
	fillCycleNotation(customLoops, customLoopsSize);
	//��������� ���������� �������, �� �� ���� ���� �� � �������� ��������
	printCycleNotation(customLoops);

	cycleToSet(customLoops, customSet);
	printSet(customSet, R, k);


	//������������ �������, � ����� ��������� ���������� ����� � ���������
	if (customLoops != nullptr) {
		delete[] customLoops;
	}

	delete2dArray(customSet, R);

	return 0;
}

//zad13base
int zad13base() {
	std::cout << "You have to enter two permutations. Firstly enter the number of elements in the first one:";
	int perm1size;
	std::cin >> perm1size;
	int customLoops1Size = perm1size * 3;
	char* customLoops1 = new char[customLoops1Size + 1];
	fillCycleNotation(customLoops1, customLoops1Size);


	std::cout << "Now, enter the number of elements in the second one: ";
	int perm2size;
	//cin.clear();
   // cin.ignore(1000, '\n');
	std::cin >> perm2size;
	int customLoops2Size = perm2size * 3;
	char* customLoops2 = new char[customLoops2Size + 1];
	fillCycleNotation(customLoops2, customLoops2Size);

	composition(customLoops1, perm1size, customLoops2, perm2size);

	if (customLoops2 != nullptr) {
		delete[] customLoops2;
	}
	if (customLoops1 != nullptr) {
		delete[] customLoops1;
	}

	return 0;
}

//zad14base
int zad14base() {
	std::cout << "REVERSE PERMUTATION: How many elements do you want in the permutation\n";
	std::cout << "Elements in the permutation: ";
	int permRevsize;
	std::cin >> permRevsize;
	int customLoopsRevSize = permRevsize * 3;
	char* customLoopsRev = new char[customLoopsRevSize + 1];
	fillCycleNotation(customLoopsRev, customLoopsRevSize);

	reversePermutation(customLoopsRev);
	printCycleNotation(customLoopsRev);

	if (customLoopsRev != nullptr) {
		delete[] customLoopsRev;
	}
	return 0;
}

//zad15base
int zad15base() {
	std::cout << "COMPOSITION TO REVERSE PERMUTATION OF A GIVE PERMUTAION: How many elements do you want in the permutation?\n";
	std::cout << "Elements in the permutation: ";
	int permRevToCompSize;
	std::cin >> permRevToCompSize;
	int cstmLoopsRevToCompSize = permRevToCompSize * 3;
	char* cstmLoopsRevToComp = new char[cstmLoopsRevToCompSize + 1];
	fillCycleNotation(cstmLoopsRevToComp, cstmLoopsRevToCompSize);

	reverseComposition(cstmLoopsRevToComp, permRevToCompSize, cstmLoopsRevToCompSize);

	if (cstmLoopsRevToComp != nullptr) {
		delete[] cstmLoopsRevToComp;
	}
	return 0;
}

//zad16base
int zad16base() {
	

	std::cout << "CHECK THAT TWO NON-IDENTITY PERMUTATIONS ARE NONCOMMUTATIVE\n";
	std::cout << "Enter the number of elements in the permutations: ";
	int C;
	std::cin >> C;
	int permNotationSize = C * 3;
	char* perm1notation = new char[permNotationSize + 1];
	char* perm2notation = new char[permNotationSize + 1];

	
	std::cout << "PERMUTATION 1 (in cyclic notation): \n";
	fillCycleNotation(perm1notation, permNotationSize);
	std::cout << "PERMUTATION 2 (in cyclic notation)(CLICK ENTER!): \n";// ������ �� �� ������ enter... ��� ������� ��� cin.ignore
	fillCycleNotation(perm2notation, permNotationSize);

	zad16(perm1notation, perm2notation, C);

	if (perm2notation != nullptr) {
		delete[] perm2notation;
	}
	
	if (perm1notation != nullptr) {
		delete[] perm1notation;
	}
	return 0;
}

//zad17base()
int zad17base(int option) {
	//if (option == 1) {
		int sz;
		std::cout << "How many elements do you want in the function?";
		std::cin >> sz;
		int permInputSize = sz * 3;
		char* permInput = new char[permInputSize + 1];

		fillCycleNotation(permInput, permInputSize);
		
		const unsigned R = 2;
	if (option == 1) {
		int** perm1set = create2dArray(R, sz);


		cycleToSet(permInput, perm1set);
		printSet(perm1set, R, sz);

		std::cout << "The number of iterations to reach identity (k) is: " << iterationA(perm1set, R, sz) << std::endl;
		

		delete2dArray(perm1set, R);

		if (permInput != nullptr) {
			delete[] permInput;
		}
	}
	else if (option == 2) {
		std::cout << "The number of iterations to reach identity (k) is: " << iterationB(permInput, sz) << std::endl;
		//std::cout << "The task is under construction!\n";
	}
	
	
	return 0;
}

//zad17
int iterationA(int** set , int R, int C) {
	//�������, ����� ������ ���� �� ������������ �������� �� ��������� �� ��������� ��� ������������ ��
	//���������� ���������� ��� ������ ���� ��.
	//set - ������������, ������ ���� �������� �����
	//R - ���� �� �������� � ������, ���������� ����� �� 2
	//C -  ���� �� �������� � ������ / ���� �� ���������� � ������������
	//������� ��������: k - ���� �� ����������

	int k = 1;

	int** perm1clone = create2dArray(R, C);
	int** permComposed = create2dArray(R, C);

	matrixcopy(perm1clone, set, R, C);
	matrixcopy(permComposed, set, R, C);
	

	while (isIdentity(permComposed, R, C)==false) {
		compositionOnly(set, perm1clone, permComposed, R, C);
		matrixcopy(perm1clone, permComposed, R, C);
		k++;
	}


	delete2dArray(permComposed, R);
	delete2dArray(perm1clone, R);

	return k;
}

int iterationB(char* perm, int size) {
	//�������, ����� ������ ���� �� ������������ �������� �� ��������� �� ��������� ��� ������������ ��
	//���������� ���������� ��� ������ ���� ��.
	//perm - ��������� �����, �������� ����������
	//������� ��������: k - ���� �� ����������


	//��������� ��������� ��������� �����, � ����� �� ������� ��������� �� �������
	int* cycleSizes = new int[size];
	
	//(1546)(23)
	//4, 2, \0
	//2

	cycleSizeCounter(perm, cycleSizes);
	
	//���������� ��������� �� cycleSizes. ���������� �� � �� ����������� �� ��������� �� �������� �� ���
	int cnt = 0;
	while (cycleSizes[cnt] != 0 ){
		cnt++;
	}


	int res = findNOK(cycleSizes, cnt);

	if (cycleSizes != nullptr) {
		delete[] cycleSizes;
	}

	return res;
}

int zad1and2base() {
	std::cout << "�his task is included in the project and is not designed for self-review.\n";
	return 0;
}

int** create2dArray(int R, int C) {
	
	int** arr = new int*[R];
	for (int i = 0; i < R; i++) {
		arr[i] = new int[C];
	}

	return arr;
}

int delete2dArray(int** arr, int R) {
	if (arr != nullptr) {
		for (int i = 0; i < R; i++) {
			delete[] arr[i];
		}
		delete[]arr;
	}
	return 0;
}

bool checkInput(int** set, int R, int C) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (set[i][j] < 1 || set[i][j] > 9) {
				std::cout << "Enter elements between 1 and 9!\n";
				return false;
			}
		}
	}
	return true;
}