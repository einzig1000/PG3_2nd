#pragma once
#include "IShape.h"

class Triangle : public IShape
{
public:
	void Size() override;
	void Draw() override;

	void SetBase(float base) { base_ = base; }
	void SetHeight(float height) { height_ = height; }

private:
	float base_ = 0.0f;
	float height_ = 0.0f;
};

