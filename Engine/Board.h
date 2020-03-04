#pragma once

#include "Graphics.h"
#include "Location.h"

class Board {
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	void DrawBorder();
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideGrid(const Location& loc) const;
private:
	static constexpr Color borderColor = Colors::Cyan;
	static constexpr int dimension = 20;
	static constexpr int width = 35;
	static constexpr int height = 25;
	static constexpr int borderwidth = 5;
	static constexpr int borderpadding = 4;
	static constexpr int cellpadding = 2;
	static constexpr int x = 40;
	static constexpr int y = 40;
	Graphics& gfx;
};