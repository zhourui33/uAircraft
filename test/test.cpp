#include <gtest/gtest.h>
#include "uAircraft.h"

TEST(unmanedAircraft, should_init_at_0_0_0_N) 
{
	ASSERT_TRUE(Position(0, 0, 0, N) == UnmannedAircraft().getPosition());
}

TEST(unmanedAircraft, should_position_up_a_step_given_aircraft_at_origin) 
{
	ASSERT_TRUE(Position(0, 0, 1, N) == UnmannedAircraft().on(UP));
}

TEST(unmanedAircraft, should_position_down_a_step_given_position_is_0_0_5_N)
{
	ASSERT_TRUE(Position(0, 0, 4, N) == UnmannedAircraft(Position(0, 0, 5, N)).on(DOWN));
}

TEST(unmanedAircraft, should_position_forward_a_step_given_aircraft_at_origin)
{
	ASSERT_TRUE(Position(0, 1, 0, N) == UnmannedAircraft().on(FORWARD));
}
TEST(unmanedAircraft, should_position_turn_west_given_aircratf_at_origin)
{
	ASSERT_TRUE(Position(0, 0, 0, W) == UnmannedAircraft().on(LEFT));
}
TEST(unmanedAircraft, should_position_turn_east_given_aircratf_at_origin)
{
	ASSERT_TRUE(Position(0, 0, 0, E) == UnmannedAircraft().on(RIGHT));
	
}
TEST(unmanedAircraft, should_position_turn_south_given_aircratf_at_origin)
{
	ASSERT_TRUE(Position(0, 0, 0, S) == UnmannedAircraft().on(ROUND));
}
TEST(unmanedAircraft, should_position_y_equal_10_when_forward_10_given_aicraft_at_origin)
{
	ASSERT_TRUE(Position(0, 10, 0, N) == UnmannedAircraft().on(FORWARD_N(10)));

}
TEST(unmanedAircraft, should_position_z_equal_10_when_up_10_given_aircraft_at_0_10_0_n)
{
	ASSERT_TRUE(Position(0, 10, 10, N) == UnmannedAircraft(Position(0, 10, 0, N)).on(UP_N(10)));

}
TEST(unmanedAircraft, should_position_z_equal_5_when_down_5_given_aircraft_at_0_10_10_n)
{
	ASSERT_TRUE(Position(0, 10, 5, N) == UnmannedAircraft(Position(0, 10, 10, N)).on(DOWN_N(5)));
}
TEST(unmanedAircraft, should_position_y_equal_5_when_repeat_forward_5_given_aicraft_at_origin)
{
	ASSERT_TRUE(Position(0, 5, 0, N) == UnmannedAircraft().on(REPEAT(FORWARD, 5)));
}
TEST(unmanedAircraft, should_position_turn_west_when_repeat_left_1_given_aircraft_at_0_5_0_n)
{
	ASSERT_TRUE(Position(0, 5, 0, W) == UnmannedAircraft(Position(0, 5, 0, N)).on(REPEAT(LEFT, 1)));
}
TEST(unmanedAircraft, should_position_at_minus5_5_0_w_when_repeat_forward_5_given_aircraft_at_0_5_0_w)
{
	ASSERT_TRUE(Position(-5, 5, 0, W) == UnmannedAircraft(Position(0, 5, 0, W)).on(REPEAT(FORWARD, 5)));
}
TEST(unmanedAircraft, should_position_at_minus5_5_5_w_when_repeat_up_5_given_aircraft_at_minus5_5_0_w)
{
	ASSERT_TRUE(Position(-5, 5, 5, W) == UnmannedAircraft(Position(-5, 5, 0, W)).on(REPEAT(UP, 5)));
}