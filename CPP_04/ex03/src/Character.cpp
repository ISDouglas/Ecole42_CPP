#include "../includes/Character.hpp"
#include <iostream>

// 默认构造
Character::Character() : _name("Unnamed")
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = nullptr;
}

// 带参构造
Character::Character(std::string const& name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = nullptr;
}

// 拷贝构造
Character::Character(const Character& other)
{
	_name = other._name;
	for (int i = 0; i < 4; ++i)
		_inventory[i] = nullptr;
	_copyInventory(other);
}

// 拷贝赋值
Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		_clearInventory();
		_copyInventory(other);
	}
	return *this;
}

// 析构
Character::~Character()
{
	_clearInventory();
}

// 获取名字
std::string const& Character::getName() const
{
	return _name;
}

// 装备
void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			return;
		}
	}
}

// 卸下：不 delete
void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		_inventory[idx] = nullptr;
}

// 使用某一格的 materia
void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}

// 清理库存（用于析构和赋值）
void Character::_clearInventory()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = nullptr;
		}
	}
}

// 深拷贝库存（用于复制构造和赋值）
void Character::_copyInventory(const Character& other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}
