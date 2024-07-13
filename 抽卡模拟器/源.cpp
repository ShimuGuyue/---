#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

int A(0);
bool AA(false);
int S(0);
bool SS(false);

int countB(0);
int countA(0);
int countAA(0);
int countS(0);
int countSS(0);

std::vector<std::vector<std::string>> gachaRecords(1);

void showMenu(void);
void cardDraw(void);

int main(void)
{
	srand(time(0));
	showMenu();
	return 0;
}

void showMenu(void)
{
	std::cout << "**********��ӭʹ�ó鿨ģ����������**********" << std::endl;
	std::cout << "\n˵�� ��B - ��ɫ  A - ��ɫ���ᣩ AA - ��ɫ��UP�� S - ��ɫ���ᣩ SS - ��ɫ��UP��\n" << std::endl;
	std::cout << "----------����ENTER������:----------" << std::endl;
	getchar();

	while (1)
	{
		std::cout << "*****��ѡ����Ҫ�鿨�Ĵ�����" << std::endl;
		std::cout << "     A)����     B)ʮ��     C)�鿴��ǰ�������     D)�鿴��ǰ�鿨���ͳ��     Q)�����鿨" << std::endl;
		std::string input;
		std::cin >> input;
		char mod('#');
		for (char c : input)
			if (c == 'a' || c == 'A' || c == 'b' || c == 'B' || c == 'c' || c == 'C' || c == 'd' || c == 'D' || c == 'q' || c == 'Q')
			{
				mod = c;
				break;
			}
		if (input.size() > 1)
		{
			std::cout << "ָ�������࣬��ִ�е�һ���Ϸ�ָ�����" << std::endl;
			std::cout << "��һ���Ϸ�ָ�" << static_cast<char>(toupper(mod)) << std::endl;
		}
		std::cout << "------------------------------" << std::endl;		
		if (mod == 'A' || mod == 'a')
			cardDraw();
		else if (mod == 'B' || mod == 'b')
			for (int i(1); i <= 10; ++i)
				cardDraw();
		else if (mod == 'C' || mod == 'c')
		{
			std::cout << "�����´γ� A ���໹��" << 10 - A << "��" << std::endl;
			if(AA)
				std::cout << "��ǰ A ��ӵ�д󱣵�" << std::endl;
			else
				std::cout << "��ǰ A ����ӵ�д󱣵�" << std::endl;

			std::cout << "�����´γ� S ���໹��" << 90 - S << "��" << std::endl;
			if (SS)
				std::cout << "��ǰ S ��ӵ�д󱣵�" << std::endl;
			else
				std::cout << "��ǰ S ����ӵ�д󱣵�" << std::endl;
		}
		else if (mod == 'D' || mod == 'd')
		{
			std::cout << "��ǰ�鿨����ͳ�ƣ�" << std::endl;
			std::cout << "�ܳ����� " << countA + countAA + countS + countSS + countB << "\t��" << std::endl;
			std::cout << "B���� �� " << countB << "\t��" << std::endl;
			std::cout << "A���� �� " << countA << "\t��" << std::endl;
			std::cout << "AA������ " << countAA << "\t��" << std::endl;
			std::cout << "S���� �� " << countS << "\t��" << std::endl;
			std::cout << "SS������ " << countSS << "\t��" << std::endl;
			std::cout << "�鿨�����" << std::endl;
			for (std::vector<std::string> vs : gachaRecords)
			{
				int count(0);
				for (std::string s : vs)
				{
					std::cout << std::setw(4) << std::left << s;
					++count;
					if (count % 10 == 0 && count && s != "SS")
						std::cout << std::endl;
				}
				std::cout << std::endl;
				std::cout << "--------------------------------------" << std::endl;
			}
		}
		else if (mod == 'Q' || mod == 'q')
		{
			std::cout << "**********�ټ�����л����ʹ�ã�����**********";
			break;
		}
		else
			std::cout << "*****�Ƿ�ָ��������������룺";

		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	getchar();
	getchar();
	return;
}

void cardDraw(void)
{
	int i(gachaRecords.size() - 1);
	bool ifS(false);
	if (S <= 72)
	{
		int randNum(rand() % 10000 + 1);
		if (randNum <= 60)
			ifS = true;
	}
	else if (73 <= S && S <= 88)
	{
		int randNum(rand() % 10000 + 1);
		if (randNum <= 60 + 600 * (S - 73))
			ifS = true;
	}
	else if (S == 89)
	{
		ifS = true;
	}

	if (ifS)//����
	{
		if (SS)//�󱣵�
		{
			++countSS;
			std::cout << "SS!!!!!!!!!!" << std::endl;
			gachaRecords[i].push_back("SS");
			std::vector<std::string> nextRecord;
			gachaRecords.push_back(nextRecord);
			++i;
			A = 0;
			AA = false;
			S = 0;
			SS = false;
		}
		else//С����
		{
			bool ifSS(false);
			int randNum(rand() % 100 + 1);
			if (randNum <= 50)
				ifSS = true;

			if (ifSS)//UP
			{
				++countSS;
				std::cout << "SS!!!!!!!!!!" << std::endl;
				gachaRecords[i].push_back("SS");
				std::vector<std::string> nextRecord;
				gachaRecords.push_back(nextRecord);
				++i;
				A = 0;
				AA = false;
				S = 0;
				SS = false;
			}
			else//��
			{
				++countS;
				std::cout << "S!!!!!" << std::endl;
				gachaRecords[i].push_back("S");
				A = 0;
				AA = false;
				S = 0;
				SS = true;
			}
		}
	}
	else//û����
	{
		++S;

		bool ifA(false);
		if (A <= 7)
		{
			int randNum(rand() % 10000 + 1);
			if (randNum <= 510)
				ifA = true;
		}
		else if (A == 8)
		{
			int randNum(rand() % 10000 + 1);
			if (randNum <= 5610)
				ifA = true;
		}
		else if (A == 9)
		{
			ifA = true;
		}

		if (ifA)//����
		{
			if (AA)//�󱣵�
			{
				++countAA;
				std::cout << "AA!!!" << std::endl;
				gachaRecords[i].push_back("AA");
				A = 0;
				AA = false;
			}
			else//С����
			{
				bool ifAA(false);
				int randNum(rand() % 100 + 1);
				if (randNum <= 50)
					ifAA = true;

				if (ifAA)//UP
				{
					++countAA;
					std::cout << "AA!!!" << std::endl;
					gachaRecords[i].push_back("AA");
					A = 0;
					AA = false;
				}
				else//��
				{
					++countA;
					std::cout << "A!" << std::endl;
					gachaRecords[i].push_back("A");
					A = 0;
					AA = true;
				}
			}
		}
		else//������
		{
			++A;
			++countB;
			std::cout << "B" << std::endl;
			gachaRecords[i].push_back("B");
		}
	}
	return;
}

#if NULL
*****************************
*                           *
*     Written               *
*          by               *
*          Shimu Guyue      *
*                           *
***************************** 
#endif