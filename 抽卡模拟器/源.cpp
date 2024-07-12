#include <iostream>
#include <ctime>

int A(0);
bool AA(false);
int S(0);
bool SS(false);

int countB(0);
int countA(0);
int countAA(0);
int countS(0);
int countSS(0);

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
		char mod;
		std::cin >> mod;
		std::cout << "------------------------------" << std::endl;;
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
			std::cout << "�ܳ�����" << countA + countAA + countS + countSS + countB << "��" << std::endl;
			std::cout << "B������" << countB << "��" << std::endl;
			std::cout << "A������" << countA << "��" << std::endl;
			std::cout << "AA������" << countAA << "��" << std::endl;
			std::cout << "S������" << countS << "��" << std::endl;
			std::cout << "SS������" << countSS << "��" << std::endl;
		}
		else if (mod == 'Q' || mod == 'q')
		{
			std::cout << "**********�ټ�����л����ʹ�ã�����**********";
			break;
		}
		else
			std::cout << "*****�����ѡ��������������룺";

		//std::cout << "----------����ENTER������:----------" << std::endl;
		//getchar();
		//getchar();
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	getchar();
	getchar();
	return;
}

void cardDraw(void)
{
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
				A = 0;
				AA = false;
				S = 0;
				SS = false;
			}
			else//��
			{
				++countS;
				std::cout << "S!!!!!" << std::endl;
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
					A = 0;
					AA = false;
				}
				else//��
				{
					++countA;
					std::cout << "A!" << std::endl;
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