#include "BodyPair.h"

BodyPair::BodyPair(Rigidbody* rb1, Rigidbody* rb2)
{
	if (rb1 < rb2)
	{
		first = rb1;
		second = rb2;
	}
	else
	{
		first = rb2;
		second = rb1;
	}
}

bool BodyPair::operator< (const BodyPair& p) const
{
	return this->first < p.first || this->second < p.second
		|| this->first < p.second || this->second < p.first;
}