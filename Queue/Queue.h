#pragma once

template <typename ELEM>
class Queue
{
private:
	size_t lLoc,rLoc;
	ELEM *mass;
	size_t sizeMax;
public:
	Queue(size_t size) :sizeMax(size), lLoc(0), rLoc(0)
	{
		if (size == 0)
			throw 1;
		mass = new ELEM[size];
	}

	void replace()
	{
		size_t merge = (rLoc - lLoc);
		lLoc = 0;
		rLoc = merge;

		for (size_t i = 0; i < this->sizeMax; i++)
		{
			this->mass[i] = this->mass[i + rLoc-merge];
		}
	}
	
	bool isEven()
	{
		try
		{
			if(mass[lLoc] % 2 == 0)
				return true;
		}
		catch (...)
		{}
		return false;
		
	}
		
			

	void push(const ELEM& el)
	{
		if (this->rLoc == this->sizeMax && this->lLoc == 0)
			throw 2;

		if (this->rLoc == this->sizeMax && this->lLoc > 0)
			this->replace();
		
		this->mass[rLoc++] = el;
	}
	ELEM next()
	{
		if (this->lLoc == this->rLoc)
			throw 3;

		return this->mass[lLoc];
	}

	ELEM pop()
	{
		if (this->lLoc == this->rLoc)
			throw 3;

		return this->mass[lLoc++];
	}

	void resize(size_t newSize)
	{
		ELEM *tmp;
		size_t tmpMS = sizeMax;
		sizeMax = newSize;
		this->replace();
		if (rLoc > sizeMax)
			rLoc = sizeMax;
		tmp = new ELEM[sizeMax];
		for (size_t i = 0; i < sizeMax && i < tmpMS; i++)
		{
			tmp[i] = mass[i];
		}
	}
};	
