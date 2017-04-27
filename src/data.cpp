#include "data.h"

std::ostream& operator<<(std::ostream& os, const byte& b) {
    os << static_cast<std::int16_t>(b);
    return os;
}

Direction TurnLeft(const Direction d) {
    return static_cast<Direction>((static_cast<int>(d) + 3) % 4);
}

Direction TurnRight(const Direction d) {
    return static_cast<Direction>((static_cast<int>(d) + 1) % 4);
}

std::string ToString(const Direction d) {
    switch (d) {
        case Direction::NORTH:
            return "north";
        case Direction::EAST:
            return "east";
        case Direction::SOUTH:
            return "south";
        case Direction::WEST:
            return "west";
    }
}

int c(){s;}
