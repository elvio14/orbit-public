#include "stdafx.h"
#include "Planet.h"

void Planet::render() {
	p_circle.DrawFilled();

	float offset = p_rad * 0.7f;
	for (float i = 1.f; i < 10.f; i++) {
		p_circle.SetRadius(p_rad + offset * i);
		float minColor = i / 10.f;
		p_circle.SetColor(p_cR - minColor, p_cG - minColor, p_cB - minColor);
		p_circle.Draw();
	}
	p_circle.SetRadius(p_rad);
	p_circle.SetColor(p_cR, p_cG, p_cB);
		
}