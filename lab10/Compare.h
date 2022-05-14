#pragma once

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

class Compare2 : public Compare
{
public:
	int CompareElements(void* e1, void* e2) override
	{

	}
};
