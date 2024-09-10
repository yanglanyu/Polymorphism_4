#include<iostream>
using namespace std;

//�e���ۃN���X�ɂ��ꂼ��̏������z�֐�
//���ۃN���XCUP
class CPU
{
public:
	virtual void calculate() = 0;
};

//���ۃN���X�r�f�I�J�[�h
class VideoCard
{
public:
	virtual void display() = 0;
};

//���ۃN���X������
class Memory
{
public:
	virtual	void storage() = 0;
};

//�N���X�R���s���[�^�[
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//���[�N�֐�
	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	//�f�X�g���N�^
	~Computer()
	{
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL) 
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu;		//CUP�̃|�C���^
	VideoCard* m_vc;	//�r�f�I�J�[�h�̃|�C���^
	Memory* m_mem;		//�������̃|�C���^
};

//�C���e��		�e�N���X�͂��ꂼ��̒��ۃN���X����p������
class IntelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel��CPU���v�Z" << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel�̃r�f�I�J�[�h���\��" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel�̃��������ۑ�" << endl;
	}
};

//���m�{		�e�N���X�͂��ꂼ��̒��ۃN���X����p������
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo��CPU���v�Z" << endl;
	}
};
class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo�̃r�f�I�J�[�h���\��" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo�̃��������ۑ�" << endl;
	}
};
void test()
{
	CPU* intelcup = new IntelCPU;		//�e�N���X�̃|�C���^�͎q���N���X�w���A����
	VideoCard* intelvc = new IntelVideoCard;		//�e�N���X�̃|�C���^�͎q���N���X�w���A����
	Memory* intelmen = new IntelMemory;		//�e�N���X�̃|�C���^�͎q���N���X�w���A����
	cout << "�R���s���[�^�[�ꍆ�@" << endl;

	//�R���s���[�^�[�ꍆ�@�����
	Computer* computer01 = new Computer(intelcup, intelvc, intelmen);
	computer01->work();
	delete computer01;
	cout << "-----------------------" << endl;

	//�R���s���[�^�[�񍆋@�����
	cout << "�R���s���[�^�[�񍆋@" << endl;
	Computer* computer02 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer02->work();
	delete computer02;
	cout << "-----------------------" << endl;

	//�R���s���[�^�[�O���@�����
	cout << "�R���s���[�^�[�O���@" << endl;
	Computer* computer03 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
	computer03->work();
	delete computer03;
	cout << "-----------------------" << endl;
}
int main()
{
	test();

	return 0;
}