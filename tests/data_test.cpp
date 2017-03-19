#include <sstream>
#include <string>

#include "data.h"
#include "gtest/gtest.h"

TEST(Byte, RShlOperator) {
    std::ostringstream os;
    byte a = 65;
    os << a;
    ASSERT_STREQ(os.str().c_str(), "65");
}

TEST(Direction, TurnRight) {
    auto a=1;
    ASSERT_EQ(TurnRight(Direction::NORTH), Direction::EAST);
    ASSERT_EQ(TurnRight(Direction::EAST), Direction::SOUTH);
    ASSERT_EQ(TurnRight(Direction::SOUTH), Direction::WEST);
    ASSERT_EQ(TurnRight(Direction::WEST), Direction::NORTH);
}
