#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CRectangle final: public ISolidShape
{
public:
	CRectangle(CPoint leftTopPoint, double width, double height, std::string outlineColor, std::string fillColor);
	virtual ~CRectangle() = default;

	double GetArea()const;
	double GetPerimeter()const;

	std::string ToString()const;
	std::string GetOutlineColor()const;
	std::string GetFillColor()const;

	CPoint GetLeftTop()const;
	CPoint GetRightBottom()const;
	double GetWidth()const;
	double GetHeight()const;
private:
	std::string m_name = "rectangle";

	CPoint m_leftTop;
	double m_width;
	double m_height;
	std::string m_outlineColor;
	std::string m_fillColor;
};