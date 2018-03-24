#pragma once

#define __D_SCREEN_WIDTH__ 1366
#define __D_SCREEN_HEIGHT__ 768
#define __D_FRAME_MAX__ 60
#define __D_ENEMY_MAX__ 10
#define __D_HEIGHT_LIMIT__ 280

typedef struct __ST_POSITION__
{
	float _xPos;
	float _yPos;

	__ST_POSITION__() {}

	__ST_POSITION__(int x, int y)
	{
		_xPos = x;
		_yPos = y;
	}
} stPos;

typedef enum __E_OBJECT_TYPE__
{
	__E_OBJ_PLAYER__ = 0,
	__E_OBJ_NORMAL_ENEMY__,
	__E_OBJ_BOSS_ENEMY__,
	__E_OBJ_PLAYER_BULLET__,
	__E_OBJ_ENEMY_BULLET__,
	__E_OBJECT_TYPE_MAX__,
} eObjType;

typedef enum __E_DIRECTION__
{
	__E_LEFT__ = -1,
	__E_RIGHT__ = 1,
} eDir;

typedef enum __E_PLAYER_STATE__
{
	__E_STOP__ = 0,
	__E_WALK__,
	__E_SHOOT__,
	__E_PLAYER_STATE_MAX__,
} eState;

typedef enum __E_ENEMY_STATE__
{
	__E_ENEMY_DOWN__ = 0,
	__E_ENEMY_WALK__,
	__E_ENEMY_DEAD__,
	__E_ENEMY_PERPECT_DEAD__,
	__E_ENEMY_STATE_MAX__,
} eEnemyState;

typedef enum __E_BULLET_STATE__
{
	__E_BULLET_MOVE__ = 0,
	__E_BULLET_DOWN__,
	__E_BULLET_DEAD__,
	__E_BULLET_STATE_MAX__,
} eBulletState;