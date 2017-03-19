#ifndef DATA_H_
#define DATA_H_

#include <cstdint>
#include <ostream>
#include <string>

typedef char byte;

std::ostream& operator<<(std::ostream& os, const byte& b);

enum struct Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

Direction TurnLeft(Direction);
Direction TurnRight(Direction);
std::string ToString(Direction);


#endif  // DATA_H_
