#include<iostream>
#include<Windows.h>
using namespace std;
//��飺�й�����С��Ϸ��˫��Ϊ����˫����ͨ����ʼ����ֹ�������ƶ�����
//����id�涨��
//const int CHESS = 0;/*������*/
//const int Red_BING = 1;
//const int Red_PAO = 2;
//const int Red_JU = 3;
//const int Red_MA = 4;
//const int Red_XIANG = 5;
//const int Red_SHI = 6;
//const int Red_SHUAI = 7;
//const int Green_ZU = -1;
//const int Green_PAO = -2;
//const int Green_CHE = -3;
//const int Green_MA = -4;
//const int Green_XIANG = -5;
//const int Green_SHI = -6;
//const int Green_JIANG = -7;
class chess
{
protected:
	int id;
	int r;
	int c;
public:
	chess(int id, int r, int c)
	{
		this->id = id;
		this->r = r;
		this->c = c;
	}
	virtual bool possibility(int aimr, int aimc)
	{
		cout << "�˴�û�����ӿ����ƶ�";
		return false;
	}
	friend class chessboard;
};
class Red_Bing :public chess//��
{
public:
	Red_Bing(int r, int c) :chess(1, r, c) { }
	bool possibility(int aimr, int aimc)
	{
		int distance = (r - aimr) * (r - aimr) + (c - aimc) * (c - aimc);
		if (r >= aimr)
		{
			if (r >= 6)//δ����
			{
				if (distance == 1)
				{
					if (c == aimc)
					{
						return true;
					}
					else
					{
						cout << "�췽��δ����ǰ���᷽ܺ���ƶ�";
						return false;
					}
				}
				else
				{
					cout << "�췽�����ƶ����벻�ܴ���һ";
					return false;
				}
			}
			else
			{
				if (distance == 1)
				{
					return true;
				}
				else
				{
					cout << "�췽�����ƶ����벻�ܴ���һ";
					return false;
				}
			}
		}
		else
		{
			cout << "�췽�����ܺ���";
			return false;
		}
	}
};
class Green_Zu :public chess//��
{
public:
	Green_Zu(int r, int c) :chess(-1, r, c) { }
	bool possibility(int aimr, int aimc)
	{
		int distance = (r - aimr) * (r - aimr) + (c - aimc) * (c - aimc);
		if (r <= aimr)
		{
			if (r <= 5)//δ����
			{
				if (distance == 1)
				{
					if (c == aimc)
					{
						return true;
					}
					else
					{
						cout << "�̷���δ����ǰ���᷽ܺ���ƶ�";
						return false;
					}
				}
				else
				{
					cout << "�̷�����ƶ����벻�ܴ���һ";
					return false;
				}
			}
			else
			{
				if (distance == 1)
				{
					return true;
				}
				else
				{
					cout << "�̷�����ƶ����벻�ܴ���һ";
					return false;
				}
			}
		}
		else
		{
			cout << "�̷��䲻�ܺ���";
			return false;
		}
	}

};
class Red_Pao :public chess//��
{
public:
	Red_Pao(int r, int c) :chess(2, r, c) { }
	bool possibility(int aimr, int aimc)
	{
		if (r != aimr && c != aimc)
		{
			cout << "�췽��û����ֱ��";
			return false;
		}
		else return true;
	}
};
class Green_Pao :public chess//�h
{
public:
	Green_Pao(int r, int c) :chess(-2, r, c) { }
	bool possibility(int aimr, int aimc)
	{
		if (r != aimr && c != aimc)
		{
			cout << "�̷��hû����ֱ��";
			return false;
		}
		else
		{
			return true;
		}
	}
};
class Red_Ju :public chess//܇
{
public:
	Red_Ju(int r, int c) :chess(3, r, c) { }
	bool possibility(int aimr, int aimc)
	{
		if (r != aimr && c != aimc)
		{
			cout << "�췽܇û����ֱ��";
			return false;
		}
		else return true;
	}
};
class Green_Che :public chess//��
{
public:
	Green_Che(int r, int c) :chess(-3, r, c) { }
	bool possibility(int aimr, int aimc)
	{
		if (r != aimr && c != aimc)
		{
			cout << "�̷���û����ֱ��";
			return false;
		}
		else return true;
	}
};
class Red_Ma :public chess//�R
{
public:
	Red_Ma(int r, int c) :chess(4, r, c) { }
	bool possibility(int aimr, int aimc)
	{
		if ((c - aimc) * (c - aimc) + (r - aimr) * (r - aimr) != 5)
		{
			cout << "�췽�Rû��������";
			return false;
		}
		else return true;
	}
};
class Green_Ma :public chess//��
{
public:
	Green_Ma(int r, int c) :chess(-4, r, c) { }
	bool possibility(int aimr, int aimc)
	{
		if ((c - aimc) * (c - aimc) + (r - aimr) * (r - aimr) != 5)
		{
			cout << "�̷���û��������";
			return false;
		}
		else return true;
	}
};
class Red_Xiang :public chess//��
{
public:
	Red_Xiang(int r, int c) :chess(5, r, c) { }
	bool possibility(int aimr, int aimc)
	{
		if (aimr >= 6 && aimr <= 10)
		{
			if ((c - aimc) * (c - aimc) + (r - aimr) * (r - aimr) != 8)
			{
				cout << "�췽��û��������";
				return false;
			}
			else return true;
		}
		else
		{
			cout << "�췽�಻�ܹ���";
			return false;
		}
	}
};
class Green_Xiang :public chess//��
{
public:
	Green_Xiang(int r, int c) :chess(-5, r, c) { }
	bool possibility(int aimr, int aimc)
	{
		if (aimr >= 1 && aimr <= 5)
		{
			if ((c - aimc) * (c - aimc) + (r - aimr) * (r - aimr) != 8)
			{
				cout << "�̷���û��������";
				return false;
			}
			else return true;
		}
		else
		{
			cout << "�̷����ܹ���";
			return false;
		}
	}
};
class Red_Shi :public chess//��
{
public:
	Red_Shi(int r, int c) :chess(6, r, c) { }
	bool possibility(int aimr, int aimc)
	{
		if (aimr >= 8 && aimr <= 10 && aimc >= 4 && aimc <= 6)
		{
			if (r != aimr && c != aimc)
			{
				int distance = (r - aimr) * (r - aimr) + (c - aimc) * (c - aimc);
				if (distance == 2)
				{
					return true;
				}
				else
				{
					cout << "�췽��û���߶ԽǷ���";
					return false;
				}
			}
			else
			{
				cout << "�췽��û���߶ԽǷ���";
				return false;
			}

		}
		else
		{
			cout << "�췽�˲��ܳ������ƶ�����";
			return false;
		}
	}
};
class Green_Shi :public chess//ʿ
{
public:
	Green_Shi(int r, int c) :chess(-6, r, c) { }
	bool possibility(int aimr, int aimc)
	{
		if (aimr >= 1 && aimr <= 3 && aimc >= 4 && aimc <= 6)
		{
			if (r != aimr && c != aimc)
			{
				int distance = (r - aimr) * (r - aimr) + (c - aimc) * (c - aimc);
				if (distance == 2)
				{
					return true;
				}
				else
				{
					cout << "�̷�ʿû���߶ԽǷ���";
					return false;
				}
			}
			else
			{
				cout << "�̷�ʿû���߶ԽǷ���";
				return false;
			}

		}
		else
		{
			cout << "�̷�ʿ���ܳ������ƶ�����";
			return false;
		}
	}
};
class Red_Shuai :public chess//˧
{
public:
	Red_Shuai(int r, int c) :chess(7, r, c) { }
	bool possibility(int aimr, int aimc)
	{
		if (aimr >= 8 && aimr <= 10 && aimc >= 4 && aimc <= 6)
		{
			int distance = (r - aimr) * (r - aimr) + (c - aimc) * (c - aimc);
			if (distance == 1)
			{
				return true;
			}
			else
			{
				cout << "�췽˧�ƶ����벻�ܴ���һ";
				return false;
			}
		}
		else
		{
			return false;
		}
	}
};
class Green_Jiang :public chess//��
{
public:
	Green_Jiang(int r, int c) :chess(-7, r, c) { }
	bool possibility(int aimr, int aimc)
	{
		if (aimr >= 1 && aimr <= 3 && aimc >= 4 && aimc <= 6)
		{
			int distance = (r - aimr) * (r - aimr) + (c - aimc) * (c - aimc);
			if (distance == 1)
			{
				return true;
			}
			else
			{
				cout << "�̷����ƶ����벻�ܴ���һ";
				return false;
			}
		}
		else
		{
			return false;
		}
	}
};


class chessboard
{
private:
	chess* Qi[10][9];
	static int frequency;//��¼���ӵĴ���˳����Ϊ�췽����Ϊ�̷�
public:
	chessboard();//��ʼ��chessboard�е����ݳ�Ա
	void show();//�˺���������������
	bool Final_possibility(int startr, int startc, int aimr, int aimc);//�˺������������ж��ܷ�����
	void record(int rc1, int rc2, int rc3, int rc4, int rc5, int rc6);
	void move(int startr, int startc, int aimr, int aimc);//�˺�������ִ������������һ��
	void over();//�˺��������ж���Ϸ�Ƿ���������ж��ķ���ʤ
	void play();//�˺��������ۺ����Ϻ�����ʵ�����й�������Ϸ
};
int chessboard::frequency = 1;//������¼���ӷ��ı�־
int rc[6]; // ������¼ÿһ�����ӵľ�����Ϣ
int result = 0;//����������Ϸ�ı�־
chessboard::chessboard()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			Qi[i][j] = new chess(0, i + 1, j + 1);
		}
	}
	for (int j = 0; j < 9; j++)
	{
		delete Qi[9][j];
		switch (j)
		{
		case 0:Qi[9][j] = new Red_Ju(10, j + 1); break;
		case 1:Qi[9][j] = new Red_Ma(10, j + 1); break;
		case 2:Qi[9][j] = new Red_Xiang(10, j + 1); break;
		case 3:Qi[9][j] = new Red_Shi(10, j + 1); break;
		case 4:Qi[9][j] = new Red_Shuai(10, j + 1); break;
		case 5:Qi[9][j] = new Red_Shi(10, j + 1); break;
		case 6:Qi[9][j] = new Red_Xiang(10, j + 1); break;
		case 7:Qi[9][j] = new Red_Ma(10, j + 1); break;
		case 8:Qi[9][j] = new Red_Ju(10, j + 1); break;
		}
	}
	delete Qi[2][1]; delete Qi[2][7]; Qi[2][1] = new Green_Pao(3, 2); Qi[2][7] = new Green_Pao(3, 8);
	delete Qi[7][1]; delete Qi[7][7]; Qi[7][1] = new Red_Pao(8, 2); Qi[7][7] = new Red_Pao(8, 8);
	for (int j = 0; j < 9; j += 2)
	{
		delete Qi[3][j];
		Qi[3][j] = new Green_Zu(4, j + 1);
	}
	for (int j = 0; j < 9; j += 2)
	{
		delete Qi[6][j];
		Qi[6][j] = new Red_Bing(7, j + 1);
	}
	for (int j = 0; j < 9; j++)
	{
		delete Qi[0][j];
		switch (j)
		{
		case 0:Qi[0][j] = new Green_Che(1, j + 1); break;
		case 1:Qi[0][j] = new Green_Ma(1, j + 1); break;
		case 2:Qi[0][j] = new Green_Xiang(1, j + 1); break;
		case 3:Qi[0][j] = new Green_Shi(1, j + 1); break;
		case 4:Qi[0][j] = new Green_Jiang(1, j + 1); break;
		case 5:Qi[0][j] = new Green_Shi(1, j + 1); break;
		case 6:Qi[0][j] = new Green_Xiang(1, j + 1); break;
		case 7:Qi[0][j] = new Green_Ma(1, j + 1); break;
		case 8:Qi[0][j] = new Green_Che(1, j + 1); break;
		}
	}
}
void chessboard::show()//��������
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					cout << "0---";
				}
				else
				{
					cout << j;
					if (j != 9)
					{
						cout << "----";
					}
				}
			}
			else if (j == 0)
			{
				if (i == 10)
				{
					cout << "10  ";
				}
				else
				{
					cout << i << "   ";
				}
			}
			//�����������"������"
			else
			{
				switch (Qi[i - 1][j - 1]->id)
				{
				case 0:cout << "+-"; break;
				case 1:cout << "��"; break;
				case 2:cout << "��"; break;
				case 3:cout << "܇"; break;
				case 4:cout << "�R"; break;
				case 5:cout << "��"; break;
				case 6:cout << "��"; break;
				case 7:cout << "˧"; break;
				case -1:cout << "��"; break;
				case -2:cout << "�h"; break;
				case -3:cout << "��"; break;
				case -4:cout << "��"; break;
				case -5:cout << "��"; break;
				case -6:cout << "ʿ"; break;
				case -7:cout << "��"; break;
				}
				if (j != 9)
				{
					cout << "---";
				}
			}
			//else��������������������
		}
		cout << endl;
		if (i == 0)
		{
			cout << "|";
		}
		else
		{
			if (i == 5)
			{
				cout << "            ��   ��            ��   ��          ";
			}
			else
			{
				if (i == 10)
				{
					continue;
				}
				for (int m = 0; m < 10; m++)
				{
					cout << "|";
					if (m == 0)
					{
						cout << "   ";
					}
					else if (m == 4 || m == 5)
					{
						if (i == 1 || i == 2 || i == 8 || i == 9)
						{
							if (i == 1 && m == 4 || i == 2 && m == 5 || i == 8 && m == 4 || i == 9 && m == 5)
							{
								cout << "  \\ ";
							}
							else
							{
								cout << "  / ";
							}
						}
						else
						{
							cout << "    ";
						}
					}
					else
					{
						cout << "    ";
					}
				}
			}
		}
		cout << endl;
	}
	cout << endl;
}
bool chessboard::Final_possibility(int startr, int startc, int aimr, int aimc)
{
	if (startr >= 1 && startr <= 10 && startc >= 1 && startc <= 9 && aimr >= 1 && aimr <= 10 && aimc >= 1 && aimc <= 9)//����������������
	{
		if (Qi[startr - 1][startc - 1]->id * frequency >= 0)//��������
		{
			if (Qi[startr - 1][startc - 1]->id * Qi[aimr - 1][aimc - 1]->id <= 0)//�����Լ�������
			{
				if (Qi[startr - 1][startc - 1]->possibility(aimr, aimc))//�����߷������������
				{
					if (Qi[startr - 1][startc - 1]->id == 2 || Qi[startr - 1][startc - 1]->id == -2)//������ 
					{
						int f = 0;
						if (startr == aimr)
						{
							int t = 0;
							if (startc > aimc)
							{
								for (int i = aimc; i < startc - 1; i++)
								{
									if (Qi[startr - 1][i]->id != 0)t++;
								}
								if (Qi[aimr - 1][aimc - 1]->id == 0 && t == 0)f = 1;
								if (Qi[aimr - 1][aimc - 1]->id != 0 && t == 1)f = 1;
							}
							else
							{
								for (int i = startc; i < aimc - 1; i++)
								{
									if (Qi[startr - 1][i]->id != 0)t++;
								}
								if (Qi[aimr - 1][aimc - 1]->id == 0 && t == 0)f = 1;
								if (Qi[aimr - 1][aimc - 1]->id != 0 && t == 1)f = 1;
							}
						}
						if (startc == aimc)
						{
							int t = 0;
							if (startr > aimr)
							{
								for (int i = aimr; i < startr - 1; i++)
								{
									if (Qi[i][startc - 1]->id != 0)t++;
								}
								if (Qi[aimr - 1][aimc - 1]->id == 0 && t == 0)f = 1;
								if (Qi[aimr - 1][aimc - 1]->id != 0 && t == 1)f = 1;
							}
							else
							{
								for (int i = startr; i < aimr - 1; i++)
								{
									if (Qi[i][startc - 1]->id != 0)t++;
								}
								if (Qi[aimr - 1][aimc - 1]->id == 0 && t == 0)f = 1;
								if (Qi[aimr - 1][aimc - 1]->id != 0 && t == 1)f = 1;
							}
						}

						if (f == 1)
						{
							return true;
						}
						else
						{
							cout << "���������߷�����";
							if (frequency > 0)
							{
								cout << "�췽";
							}
							else
							{
								cout << "�̷�";
							}
							cout << "�������ӣ�" << endl;
							return false;
						}
					}
					else if (Qi[startr - 1][startc - 1]->id == 3 || Qi[startr - 1][startc - 1]->id == -3)//���̳� 
					{
						int f = 0;
						if (startr == aimr)
						{
							int t = 0;
							if (startc > aimc)
							{
								for (int i = aimc; i < startc - 1; i++)
								{
									if (Qi[startr - 1][i]->id != 0)
									{
										t++;
										break;
									}
								}
								if (t == 0)
								{
									f = 1;
								}
							}
							else
							{
								for (int i = startc; i < aimc - 1; i++)
								{
									if (Qi[startr - 1][i]->id != 0)
									{
										t++; break;
									}
								}
								if (t == 0)
								{
									f = 1;
								}
							}
						}
						if (startc == aimc)
						{
							int t = 0;
							if (startr > aimr)
							{
								for (int i = aimr; i < startr - 1; i++)
								{
									if (Qi[i][startc - 1]->id != 0)
									{
										t++; break;
									}
								}
								if (t == 0)
								{
									f = 1;
								}
							}
							else
							{
								for (int i = startr; i < aimr - 1; i++)
								{
									if (Qi[i][startc - 1]->id != 0)
									{
										t++; break;
									}
								}
								if (t == 0)
								{
									f = 1;
								}
							}
						}
						if (f == 1)
						{
							return true;
						}
						else
						{
							cout << "�����ƶ�·�������������ӣ���";
							if (frequency > 0)
							{
								cout << "�췽";
							}
							else
							{
								cout << "�̷�";
							}
							cout << "�������ӣ�" << endl;
							return false;
						}
					}
					else if (Qi[startr - 1][startc - 1]->id == 4 || Qi[startr - 1][startc - 1]->id == -4)//������
					{
						if ((aimc - startc) * (aimc - startc) == 1)
						{
							if (aimc > startc)
							{
								if (Qi[(startr + aimr) / 2 - 1][(startc + aimc) / 2 - 1]->id == 0)
								{
									return true;
								}
							}
							else if (aimc < startc)
							{
								if (Qi[(startr + aimr) / 2 - 1][(startc + aimc) / 2]->id == 0)
								{
									return true;
								}
							}
						}
						else if ((aimr - startr) * (aimr - startr) == 1)
						{
							if (aimr > startr)
							{
								if (Qi[(startr + aimr) / 2 - 1][(startc + aimc) / 2 - 1]->id == 0)
								{
									return true;
								}
							}
							else if (aimr < startr)
							{
								if (Qi[(startr + aimr) / 2][(startc + aimc) / 2 - 1]->id == 0)
								{
									return true;
								}
							}
						}
						else
						{
							cout << "�����ȣ���";
							if (frequency > 0)
							{
								cout << "�췽";
							}
							else
							{
								cout << "�̷�";
							}
							cout << "�������ӣ�" << endl;
						}
					}
					else if (Qi[startr - 1][startc - 1]->id == 5 || Qi[startr - 1][startc - 1]->id == -5)//������ 
					{
						if (Qi[(startr + aimr) / 2 - 1][(startc + aimc) / 2 - 1]->id == 0)
						{
							return true;
						}
						else
						{
							cout << "�����ۣ���";
							if (frequency > 0)
							{
								cout << "�췽";
							}
							else
							{
								cout << "�̷�";
							}
							cout << "�������ӣ�" << endl;
							return false;
						}
					}
					else
					{
						return true;
					}
				}
				else if (Qi[startr - 1][startc - 1]->id == 7)
				{
					if (startc == aimc && Qi[aimr - 1][aimc - 1]->id == -7)
					{
						int flag = 1;
						for (int i = aimr; i < startr - 1; i++)
						{
							if (Qi[i][startc - 1]->id != 0)
							{
								flag = 0;
							}
						}
						if (flag)
						{
							return true;
						}
						else
						{
							cout << "�췽˧���ܳ������ƶ�������";
							if (frequency > 0)
							{
								cout << "�췽";
							}
							else
							{
								cout << "�̷�";
							}
							cout << "�������ӣ�" << endl;
							return false;
						}
					}
					else
					{
						if (aimr >= 8 && aimr <= 10 && aimc >= 4 && aimc <= 6)
						{
							cout << "����";
						}
						else
						{
							cout << "�췽˧���ܳ������ƶ�������";
						}
						if (frequency > 0)
						{
							cout << "�췽";
						}
						else
						{
							cout << "�̷�";
						}
						cout << "�������ӣ�" << endl;
						return false;
					}
				}
				else if (Qi[startr - 1][startc - 1]->id == -7)
				{
					if (startc == aimc && Qi[aimr - 1][aimc - 1]->id == 7)
					{
						int flag = 1;
						for (int i = startr; i < aimr - 1; i++)
						{
							if (Qi[i][startc - 1]->id != 0)
							{
								flag = 0;
							}
						}
						if (flag)
						{
							return true;
						}
						else
						{
							cout << "�̷������ܳ������ƶ�������";
							if (frequency > 0)
							{
								cout << "�췽";
							}
							else
							{
								cout << "�̷�";
							}
							cout << "�������ӣ�" << endl;
							return false;
						}
					}
					else
					{
						if (aimr >= 1 && aimr <= 3 && aimc >= 4 && aimc <= 6)
						{
							cout << "����";
						}
						else
						{
							cout << "�̷������ܳ������ƶ�������";
						}
						if (frequency > 0)
						{
							cout << "�췽";
						}
						else
						{
							cout << "�̷�";
						}
						cout << "�������ӣ�" << endl;
						return false;

					}
				}
				else
				{
					cout << "����";
					if (frequency > 0)
					{
						cout << "�췽";
					}
					else
					{
						cout << "�̷�";
					}
					cout << "�������ӣ�" << endl;
					return false;
				}
			}
			else
			{
				cout << "���ܳ��ҷ����ӣ���";
				if (frequency > 0)
				{
					cout << "�췽";
				}
				else
				{
					cout << "�̷�";
				}
				cout << "�������ӣ�" << endl;
				return false;
			}
		}
		else
		{
			cout << "�����ƶ��з����ӣ���";
			if (frequency > 0)
			{
				cout << "�췽";
			}
			else
			{
				cout << "�̷�";
			}
			cout << "�������ӣ�" << endl;
			return false;
		}
	}
	else if (startr == 0 && startc == 0 && aimr == 0 && aimc == 0)//Ͷ��
	{
		result = frequency * 2;
		return false;
	}
	else if (startr == -1 && startc == -1 && aimr == -1 && aimc == -1)//����
	{
		frequency *= -1;
		delete[]Qi[rc[1] - 1][rc[2] - 1];
		switch (rc[0])
		{
		case 1:Qi[rc[1] - 1][rc[2] - 1] = new Red_Bing(rc[1], rc[2]); break;
		case 2:Qi[rc[1] - 1][rc[2] - 1] = new Red_Pao(rc[1], rc[2]); break;
		case 3:Qi[rc[1] - 1][rc[2] - 1] = new Red_Ju(rc[1], rc[2]); break;
		case 4:Qi[rc[1] - 1][rc[2] - 1] = new Red_Ma(rc[1], rc[2]); break;
		case 5:Qi[rc[1] - 1][rc[2] - 1] = new Red_Xiang(rc[1], rc[2]); break;
		case 6:Qi[rc[1] - 1][rc[2] - 1] = new Red_Shi(rc[1], rc[2]); break;
		case 7:Qi[rc[1] - 1][rc[2] - 1] = new Red_Shuai(rc[1], rc[2]); break;
		case -1:Qi[rc[1] - 1][rc[2] - 1] = new Green_Zu(rc[1], rc[2]); break;
		case -2:Qi[rc[1] - 1][rc[2] - 1] = new Green_Pao(rc[1], rc[2]); break;
		case -3:Qi[rc[1] - 1][rc[2] - 1] = new Green_Che(rc[1], rc[2]); break;
		case -4:Qi[rc[1] - 1][rc[2] - 1] = new Green_Ma(rc[1], rc[2]); break;
		case -5:Qi[rc[1] - 1][rc[2] - 1] = new Green_Xiang(rc[1], rc[2]); break;
		case -6:Qi[rc[1] - 1][rc[2] - 1] = new Green_Shi(rc[1], rc[2]); break;
		case -7:Qi[rc[1] - 1][rc[2] - 1] = new Green_Jiang(rc[1], rc[2]); break;
		}
		delete[]Qi[rc[4] - 1][rc[5] - 1];
		switch (rc[3])
		{
		case 0:Qi[rc[4] - 1][rc[5] - 1] = new chess(rc[3], rc[4], rc[5]); break;
		case 1:Qi[rc[4] - 1][rc[5] - 1] = new Red_Bing(rc[4], rc[5]); break;
		case 2:Qi[rc[4] - 1][rc[5] - 1] = new Red_Pao(rc[4], rc[5]); break;
		case 3:Qi[rc[4] - 1][rc[5] - 1] = new Red_Ju(rc[4], rc[5]); break;
		case 4:Qi[rc[4] - 1][rc[5] - 1] = new Red_Ma(rc[4], rc[5]); break;
		case 5:Qi[rc[4] - 1][rc[5] - 1] = new Red_Xiang(rc[4], rc[5]); break;
		case 6:Qi[rc[4] - 1][rc[5] - 1] = new Red_Shi(rc[4], rc[5]); break;
		case 7:Qi[rc[4] - 1][rc[5] - 1] = new Red_Shuai(rc[4], rc[5]); break;
		case -1:Qi[rc[4] - 1][rc[5] - 1] = new Green_Zu(rc[4], rc[5]); break;
		case -2:Qi[rc[4] - 1][rc[5] - 1] = new Green_Pao(rc[4], rc[5]); break;
		case -3:Qi[rc[4] - 1][rc[5] - 1] = new Green_Che(rc[4], rc[5]); break;
		case -4:Qi[rc[4] - 1][rc[5] - 1] = new Green_Ma(rc[4], rc[5]); break;
		case -5:Qi[rc[4] - 1][rc[5] - 1] = new Green_Xiang(rc[4], rc[5]); break;
		case -6:Qi[rc[4] - 1][rc[5] - 1] = new Green_Shi(rc[4], rc[5]); break;
		case -7:Qi[rc[4] - 1][rc[5] - 1] = new Green_Jiang(rc[4], rc[5]); break;
		}
		if (frequency > 0)
		{
			cout << "�췽";
		}
		else
		{
			cout << "�̷�";
		}
		cout << "����ɹ�" << endl;
		return false;
	}
	else
	{
		cout << "�����ƶ��������⣬��";
		if (frequency > 0)
		{
			cout << "�췽";
		}
		else
		{
			cout << "�̷�";
		}
		cout << "�������ӣ�" << endl;
		return false;
	}
}
void chessboard::record(int rc1, int rc2, int rc3, int rc4, int rc5, int rc6)
{
	rc[0] = rc1;
	rc[1] = rc2;
	rc[2] = rc3;
	rc[3] = rc4;
	rc[4] = rc5;
	rc[5] = rc6;
}
void chessboard::move(int startr, int startc, int aimr, int aimc)
{
	if (Final_possibility(startr, startc, aimr, aimc))
	{
		record(Qi[startr - 1][startc - 1]->id, startr, startc, Qi[aimr - 1][aimc - 1]->id, aimr, aimc);
		frequency *= -1;
		int idx = Qi[startr - 1][startc - 1]->id;
		delete[]Qi[startr - 1][startc - 1]; delete[]Qi[aimr - 1][aimc - 1];
		Qi[startr - 1][startc - 1] = new chess(0, startr, startc);
		switch (idx)
		{
		case 1:Qi[aimr - 1][aimc - 1] = new Red_Bing(aimr, aimc); break;
		case 2:Qi[aimr - 1][aimc - 1] = new Red_Pao(aimr, aimc); break;
		case 3:Qi[aimr - 1][aimc - 1] = new Red_Ju(aimr, aimc); break;
		case 4:Qi[aimr - 1][aimc - 1] = new Red_Ma(aimr, aimc); break;
		case 5:Qi[aimr - 1][aimc - 1] = new Red_Xiang(aimr, aimc); break;
		case 6:Qi[aimr - 1][aimc - 1] = new Red_Shi(aimr, aimc); break;
		case 7:Qi[aimr - 1][aimc - 1] = new Red_Shuai(aimr, aimc); break;
		case -1:Qi[aimr - 1][aimc - 1] = new Green_Zu(aimr, aimc); break;
		case -2:Qi[aimr - 1][aimc - 1] = new Green_Pao(aimr, aimc); break;
		case -3:Qi[aimr - 1][aimc - 1] = new Green_Che(aimr, aimc); break;
		case -4:Qi[aimr - 1][aimc - 1] = new Green_Ma(aimr, aimc); break;
		case -5:Qi[aimr - 1][aimc - 1] = new Green_Xiang(aimr, aimc); break;
		case -6:Qi[aimr - 1][aimc - 1] = new Green_Shi(aimr, aimc); break;
		case -7:Qi[aimr - 1][aimc - 1] = new Green_Jiang(aimr, aimc); break;
		}
	}
}
void chessboard::play()
{
	cout << "                  �й�����" << endl;
	cout << "��Ϸ˵����" << endl << "�ٳ��Ӻ����Ϸ�Ϊ�̷������Ӻ����·�Ϊ�췽" << endl;
	cout << "�ں췽ִ��,˫���������ӣ�ֱ���Ե��з���˧ȡ��ʤ��" << endl;
	cout << "�����ӷ���Ϊ�����ĸ����֣���ʾ����x��x�е������ƶ���x��x��" << endl;
	cout << "����������0 0 0 0��ʾͶ������" << endl;
	cout << "����������-1 -1 -1 -1��ʾ�ҷ�ͬ����壬�ص���һ��" << endl;
	cout << "���������������߷�������ڴ˴�������ʾ��" << endl;
	cout << "�����ڵ����ӷ�Ϊ��";
	if (frequency > 0)
	{
		cout << "�췽" << endl;
	}
	else
	{
		cout << "�̷�" << endl;
	}
	show();
	while (result == 0)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		system("cls");
		cout << "                  �й�����" << endl;
		cout << "��Ϸ˵����" << endl << "�ٳ��Ӻ����Ϸ�Ϊ�̷������Ӻ����·�Ϊ�췽" << endl;
		cout << "�ں췽ִ��,˫���������ӣ�ֱ���Ե��з���˧ȡ��ʤ��" << endl;
		cout << "�����ӷ���Ϊ�����ĸ����֣���ʾ����x��x�е������ƶ���x��x��" << endl;
		cout << "����������0 0 0 0��ʾͶ������" << endl;
		cout << "����������-1 -1 -1 -1��ʾ�ҷ�ͬ����壬�ص���һ��" << endl;
		cout << "���������������߷�������ڴ˴�������ʾ��" << endl;
		move(a, b, c, d);
		cout << "�����ڵ����ӷ�Ϊ��";
		if (frequency > 0)
		{
			cout << "�췽" << endl;
		}
		else
		{
			cout << "�̷�" << endl;
		}
		show();
		if (result == 0)
		{
			over();
		}
	}
	if (result == 1)
	{
		cout << endl;
		cout << "�췽��ɱ���췽ʤ��";
		cout << endl;
	}
	else if (result == -1)
	{
		cout << endl;
		cout << "�̷���ɱ���̷�ʤ��";
		cout << endl;
	}
	else if (result == 2)
	{
		cout << endl;
		cout << "�췽Ͷ�����̷�ʤ��";
		cout << endl;
	}
	else if (result == -2)
	{
		cout << endl;
		cout << "�̷�Ͷ�����췽ʤ��";
		cout << endl;
	}
}
void chessboard::over()
{
	int RedWin = 0; int GreenWin = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (Qi[i][j]->id == 7)
			{
				RedWin = 1;
			}
			if (Qi[i][j]->id == -7)
			{
				GreenWin = -1;
			}
		}
	}
	result = RedWin + GreenWin;
}
void SetFont(int size = 15) //��������
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = size;  //���������С
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_BOLD; //�����ϸ FW_BOLD
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
int main()
{
	SetFont();
	system("color e0");
	chessboard C;
	C.play();
	return 0;
}
