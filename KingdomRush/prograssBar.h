#pragma once
#include "gameNode.h"

class prograssBar :public gameNode
{
private:
	RECT _rcPrograss;			//ü�¹� ��Ʈ	
	int _x, _y;					//ü�¹� ��ġ
	int _width;					//ü�¹� ����

	image* _prograssBarFront;	//ü�¹� ���̹���
	image* _prograssBarBack;	//ü�¹� ���


public:
	//ü�¹� �ʱ�ȭ
	HRESULT init(char* frontImage, char* BackImage, float x, float y, int width, int height);
	void release(void);
	void update(void);
	void render(void);

	//���α׷����� ������ ����(�ʱ�ȭ�� �� �����)
	void setGauge(float currentGauge, float maxGauge);

	//���α׷����� ��ġ ����
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }

	//ü�¹� ��Ʈ ��������
	RECT getRect(void) { return _rcPrograss; }


	prograssBar();
	~prograssBar();
};

