#include "Snake.h"
#include <assert.h>
Snake::Snake(const Location & loc)
{
	constexpr int nBodyColours = 4;
	constexpr Color bodyColours[nBodyColours] = {
	{ 10,100,32 },
	{ 10,130,48 },
	{ 10,160,48 },
	{ 10,130,48 } 
	};
	for (int i = 0; i < nSegmentsMax; ++i) {
		segments[i].InitBody(bodyColours[i % nBodyColours]);
	}
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; --i) {
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

Location Snake::GetNextHeadLocation(const Location & delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.add(delta_loc);
	return l;
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax) {
		++nSegments;
	}
}

void Snake::Draw(Board & brd) const
{
	for (int i = 0; i < nSegments; ++i) {
		segments[i].Draw(brd);
	}
}

bool Snake::IsInTileExptEnd(const Location& target) const
{
	for (int i = 0; i < nSegments - 1; ++i) {
		if (segments[i].GetLocation() == target) {
			return true;
		}
	}
	return false;
}

bool Snake::IsInTile(const Location& target) const
{
	for (int i = 0; i < nSegments; ++i) {
		if (segments[i].GetLocation() == target) {
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(Color c_in)
{
	c = c_in;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.add(delta_loc);
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
