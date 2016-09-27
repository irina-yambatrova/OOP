#pragma once
#include "ISolidShape.h"
#include "Point.h"

class CRectangle final : public ISolidShape
{
public:
	CRectangle(int x, int y, int width, int height, std::string const& borderColor, std::string const& color);

	
	double GetPerimeter()const override;
	double GetArea()const override;
	std::string GetBorderColor()const override;
	std::string GetColor()const override;
	std::string ToString()const override;
private:
	CPoint m_vertex;
	int m_width;
	int m_height;
	std::string m_borderColor;
	std::string m_color;
};
