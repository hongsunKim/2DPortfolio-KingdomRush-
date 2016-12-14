#pragma once
#include "gameObject.h"

enum class UNIT_STATE
{
	READY,
	MOVE,
	ATTACK,
	STAY,
	DEAD,
	ARRIVED,
	COUNTED
};

enum class ATK_TYPE
{
	PHYSICAL,
	PHYSICAL_PIERCING,
	MAGICAL,
	MAGICAL_PIERCING
};

enum class ARMOR
{
	NONE,
	LOW,
	MEDIUM,
	HIGH
};

enum class MAGIC_RESISTENCE
{
	NONE,
	LOW,
	MEDIUM,
	HIGH
};

enum class TEAM
{
	PLAYER,
	ENEMY
};

enum class TYPE
{
	GROUND,
	AIR
};

enum class ATTACKABLE
{
	ABLE,
	UNABLE
};

class unitBase :
	public gameObject
{
protected:
	UNIT_STATE _unitState;

	ATK_TYPE _atkType;
	ARMOR _armor;
	MAGIC_RESISTENCE _magicResistence;
	float _speed;
	TEAM _team;
	TYPE _type;
	ATTACKABLE _atkAble;

	float _atkSpeed;
	int _atk;
	int _atkMin;
	int _atkMax;
	float _atkRange;
	bool _atkCheck;
	int _fullHp;
	int _currentHp;

	bool _slowed;
	float _normalSpeed;
	float _slowedSpeed;
	int _slowTime;

	image* _unitImage;
	animation _unitAni;

	unitBase* _target;
public:
	inline float atkSpeed() { return _atkSpeed; }
	inline unitBase* getTarget() { return _target; }
	inline ARMOR getArmor() { return _armor; }
	inline MAGIC_RESISTENCE getMagicResist() { return _magicResistence; }
	inline TEAM getTeam() { return _team; }
	inline TYPE getType() { return _type; }
	inline ATTACKABLE getAttackable() { return _atkAble; }
	inline int getAtkMin() { return _atkMin; }
	inline int getAtkMax() { return _atkMax; }
	inline int getAtk() { return _atk; }
	inline float getAtkRange() { return _atkRange; }
	inline int getFullHp() { return _fullHp; }
	inline int getCurHp() { return _currentHp; }
	inline UNIT_STATE getUnitState() { return _unitState; }
	inline ATK_TYPE getAtkType() { return _atkType; }
	inline float getSpeed() { return _speed; }

	inline void setSlow(bool slow) { _slowed = slow; }
	inline void setAtkMin(int atkMin) { _atkMin = atkMin; }
	inline void setAtkMax(int atkMax) { _atkMax = atkMax; }
	inline void setArmor(ARMOR armor) { _armor = armor; }
	inline void setAtkType(ATK_TYPE atkType) { _atkType = atkType; }
	inline void setAtk(int atk) { _atk = atk; }
	inline void setAtkRange(float atkRange) { _atkRange = atkRange; }
	inline void setFullHp(int fullHp) { _fullHp = fullHp; }
	inline void setCurHp(int currentHp) { _currentHp = currentHp; }
	inline void setTarget(unitBase* target) { _target = target; }
	inline void setUnitState(UNIT_STATE unitState) { _unitState = unitState; }

	unitBase();
	~unitBase();

	HRESULT init(void) = 0;
	void release(void) = 0;
	void updateNormal(void) = 0;
	void updateOnceUp(void) = 0;
	void updateOnceDn(void) = 0;
	void updateStayDn(void) = 0;
	void renderObject(HDC getMemDC) = 0;
	void renderUI(HDC getMemDC) = 0;

	void attackTarget(void);
};

