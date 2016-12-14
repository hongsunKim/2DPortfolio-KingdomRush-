#pragma once
#include "singletonBase.h"
class txtData : public singletonBase<txtData>
{
public:
	HRESULT init(void);

	//세이브
	void txtSave(char* saveFileName, vector<string> vStr);
	char* vectorArrayCombine(vector<string> vArray);

	//로드
	vector<string> txtLoad(char* loadFileName);
	vector<string> charArraySeparation(char charArray[]);

	txtData();
	~txtData();
};

