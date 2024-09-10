#include<iostream>
using namespace std;

//各抽象クラスにそれぞれの純粋仮想関数
//抽象クラスCUP
class CPU
{
public:
	virtual void calculate() = 0;
};

//抽象クラスビデオカード
class VideoCard
{
public:
	virtual void display() = 0;
};

//抽象クラスメモリ
class Memory
{
public:
	virtual	void storage() = 0;
};

//クラスコンピューター
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//ワーク関数
	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	//デストラクタ
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
	CPU* m_cpu;		//CUPのポインタ
	VideoCard* m_vc;	//ビデオカードのポインタ
	Memory* m_mem;		//メモリのポインタ
};

//インテル		各クラスはそれぞれの抽象クラスから継承する
class IntelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "IntelのCPU→計算" << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intelのビデオカード→表示" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intelのメモリ→保存" << endl;
	}
};

//レノボ		各クラスはそれぞれの抽象クラスから継承する
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "LenovoのCPU→計算" << endl;
	}
};
class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovoのビデオカード→表示" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovoのメモリ→保存" << endl;
	}
};
void test()
{
	CPU* intelcup = new IntelCPU;		//親クラスのポインタは子供クラス指向、多態
	VideoCard* intelvc = new IntelVideoCard;		//親クラスのポインタは子供クラス指向、多態
	Memory* intelmen = new IntelMemory;		//親クラスのポインタは子供クラス指向、多態
	cout << "コンピューター一号機" << endl;

	//コンピューター一号機を作る
	Computer* computer01 = new Computer(intelcup, intelvc, intelmen);
	computer01->work();
	delete computer01;
	cout << "-----------------------" << endl;

	//コンピューター二号機を作る
	cout << "コンピューター二号機" << endl;
	Computer* computer02 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer02->work();
	delete computer02;
	cout << "-----------------------" << endl;

	//コンピューター三号機を作る
	cout << "コンピューター三号機" << endl;
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