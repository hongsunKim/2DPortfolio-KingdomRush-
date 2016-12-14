#pragma once
#include "singletonBase.h"

class effect;

class effectManager : public singletonBase<effectManager>
{
private:
	//����Ʈ�� ���� ����
	typedef vector<effect*> vEffect;
	typedef vector<effect*>::iterator viEffect;
	//����Ʈ Ŭ������ ����ִ� ���͸� ���� ��
	typedef map<string, vEffect> mEffect;
	typedef map<string, vEffect>::iterator miEffect;
	//��� ����Ʈ�� ������ ����(����  ���� ����
	typedef vector<mEffect> vTotalEffect;
	typedef vector<mEffect>::iterator viTotalEffect;

private:
	//���� ��� ����Ʈ�� ��� ����
	vTotalEffect _vTotalEffect;
	
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	
	//����Ʈ �߰�
	void addEffect(string effectKey, char* imageName, int imageW, int imageH,
		int frameW, int frameH, int fps, float elapsedTime, int buffer);

	//����Ʈ �÷���
	void play(string effectKey, int x, int y);

	effectManager();
	~effectManager();
};

