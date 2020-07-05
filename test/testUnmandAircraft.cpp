#include <gtest/gtest.h>
#include "uAircraft.h"
#include "command.h"

struct TestUnmannedAircraft : testing::Test
{
	void WHEN_AIRCRAFT_EXECUTE_COMMAND(const Command& cmd)
	{
		unmannedAircraft.on(cmd);
	}
	void THEN_AIRCRAFT_EXECUTE_COMMAND(const Command& cmd)
	{
		WHEN_AIRCRAFT_EXECUTE_COMMAND(cmd);
	}
	void THE_AIRCRAFT_SHOULD_AT(const Position& pos)
	{
		ASSERT_TRUE(pos == unmannedAircraft.getPosition());
	}
	protected:
	UnmannedAircraft unmannedAircraft;
};

namespace
{
	#define TEST_FLY(scene_description) TEST_F(TestUnmannedAircraft, scene_description)
}

TEST_FLY(aircraft_should_init_at_0_0_0_N)
{
	ASSERT_TRUE(Position(0, 0, 0, N) == UnmannedAircraft().getPosition());
}

TEST_FLY(aircraft_should_up_a_step_given_up_command)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(UP);
	THE_AIRCRAFT_SHOULD_AT(Position(0, 0, 1, N));
}

TEST_FLY(aircraft_should_at_init_position_given_up_and_down)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(UP);
	THEN_AIRCRAFT_EXECUTE_COMMAND(DOWN);
	THE_AIRCRAFT_SHOULD_AT(Position(0, 0, 0, N));
}

TEST_FLY(aircraft_should_do_nothing_when_given_down_on_the_ground)
{
	THEN_AIRCRAFT_EXECUTE_COMMAND(DOWN);
	THE_AIRCRAFT_SHOULD_AT(Position(0, 0, 0, N));
}

TEST_FLY(aircraft_should_forward_a_step_given_forward_command)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(FORWARD);
	THE_AIRCRAFT_SHOULD_AT(Position(0, 1, 0, N));
}

TEST_FLY(aircraft_should_turn_west_given_left_command)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(LEFT);
	THE_AIRCRAFT_SHOULD_AT(Position(0, 0, 0, W));
}

TEST_FLY(aircraft_should_turn_east_given_right_command)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(RIGHT);
	THE_AIRCRAFT_SHOULD_AT(Position(0, 0, 0, E));	
}

TEST_FLY(aircraft_should_turn_south_given_round_command)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(ROUND);
	THE_AIRCRAFT_SHOULD_AT(Position(0, 0, 0, S));	
}

TEST_FLY(aircraft_should_step_10_when_given_forward_n_command)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(FORWARD_N(10));
	THE_AIRCRAFT_SHOULD_AT(Position(0, 10, 0, N));

}

TEST_FLY(aircraft_should_up_10_when_given_up_n_command)
{
	THEN_AIRCRAFT_EXECUTE_COMMAND(UP_N(10));
	THE_AIRCRAFT_SHOULD_AT(Position(0, 0, 10, N));
}

TEST_FLY(aircraft_should_z_equal_5_given_up_10_and_down_5)
{
	THEN_AIRCRAFT_EXECUTE_COMMAND(UP_N(10));
	THEN_AIRCRAFT_EXECUTE_COMMAND(DOWN_N(5));
	THE_AIRCRAFT_SHOULD_AT(Position(0, 0, 5, N));
}

TEST_FLY(aircraft_should_forward_5_when_repeat_forward_5_times)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(REPEAT(FORWARD, 5));
	THE_AIRCRAFT_SHOULD_AT(Position(0, 5, 0, N));
}

TEST_FLY(aircraft_should_turn_west_when_repeat_left_1_times)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(REPEAT(LEFT, 1));
	THE_AIRCRAFT_SHOULD_AT(Position(0, 0, 0, W));
}

TEST_FLY(aircraft_should_turn_south_when_repeat_left_2_times)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(REPEAT(LEFT, 2));
	THE_AIRCRAFT_SHOULD_AT(Position(0, 0, 0, S));
}

TEST_FLY(aircraft_should_turn_east_when_repeat_left_3_times)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(REPEAT(LEFT, 3));
	THE_AIRCRAFT_SHOULD_AT(Position(0, 0, 0, E));
}

TEST_FLY(aircraft_should_turn_north_when_repeat_left_4_times)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(REPEAT(LEFT, 4));
	THE_AIRCRAFT_SHOULD_AT(Position(0, 0, 0, N));
}

TEST_FLY(aircraft_should_go_west_when_given_left_and_forward_5)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(LEFT);
	THEN_AIRCRAFT_EXECUTE_COMMAND(REPEAT(FORWARD, 5));
	THE_AIRCRAFT_SHOULD_AT(Position(-5, 0, 0, W));
}

TEST_FLY(aircraft_should_go_south_when_given_round_and_forward_5)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(ROUND);
	THEN_AIRCRAFT_EXECUTE_COMMAND(REPEAT(FORWARD, 5));
	THE_AIRCRAFT_SHOULD_AT(Position(0, -5, 0, S));
}

TEST_FLY(aircraft_should_go_east_when_given_right_and_forward_5)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(RIGHT);
	THEN_AIRCRAFT_EXECUTE_COMMAND(REPEAT(FORWARD, 5));
	THE_AIRCRAFT_SHOULD_AT(Position(5, 0, 0, E));
}

TEST_FLY(aircraft_should_up_5_when_repeat_up_5_times)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(REPEAT(UP, 5));
	THE_AIRCRAFT_SHOULD_AT(Position(0, 0, 5, N));
}

TEST_FLY(aircraft_should_do_nothing_when_given_repeat_out_of_range)
{
	WHEN_AIRCRAFT_EXECUTE_COMMAND(REPEAT(FORWARD, 11));
	THE_AIRCRAFT_SHOULD_AT(Position(0, 0, 0, N));
}
