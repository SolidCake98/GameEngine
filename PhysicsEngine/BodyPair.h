#pragma once

#include "Rigidbody.h"

struct BodyPair
{
	Rigidbody* first;
	Rigidbody* second;

	BodyPair(Rigidbody* rb1, Rigidbody* rb2);

	bool operator< (const BodyPair& p) const;
};