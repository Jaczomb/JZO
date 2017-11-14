#include "Object.h"

void Object::setX(int _x)
{
	m_x = _x;
}

void Object::setY(int _y)
{
	m_y = _y;
}

int Object::getX()
{
	return m_x;
}

int Object::getY()
{
	return m_y;
}

Object::Object()
{
}

Object::~Object()
{
}