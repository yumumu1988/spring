/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef LIGHTNING_PROJECTILE_H
#define LIGHTNING_PROJECTILE_H

#include "WeaponProjectile.h"

class CWeapon;

class CLightningProjectile : public CWeaponProjectile
{
	CR_DECLARE(CLightningProjectile);
public:
	CLightningProjectile(const ProjectileParams& params, const float3& color);
	~CLightningProjectile();

	void Update();
	void Draw();
	virtual void DrawOnMinimap(CVertexArray& lines, CVertexArray& points);
	void DependentDied(CObject* o);

private:
	float3 color;
	CWeapon* weapon;

	#define displacements_size 10
	float displacements[displacements_size];
	float displacements2[displacements_size];
};

#endif /* LIGHTNING_PROJECTILE_H */
