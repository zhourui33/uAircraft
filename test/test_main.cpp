#include <iostream>
#include "pub.h"
#include "uAircraft.h"
#include "utest.h"
using namespace std;

int main()
{
    cout<<"[----- START TESTING -----]"<<endl;
    //should_init_at_0_0_0_N
    ASSERT_TRUE(Position(0,0,0,N) == UnmannedAircraft().getPosition());
    ASSERT_TRUE(Position(1,0,0,N) != UnmannedAircraft().getPosition());
    //should_position_up_a_step_given_aircraft_at_origin
    ASSERT_TRUE(Position(0,0,1,N) == UnmannedAircraft().on(UP));
    //should_position_down_a_step_given_position_is_0_0_5_N
    ASSERT_TRUE(Position(0,0,4,N) == UnmannedAircraft(Position(0,0,5,N)).on(DOWN));
    //should_position_forward_a_step_given_aircraft_at_origin
    ASSERT_TRUE(Position(0,1,0,N) == UnmannedAircraft().on(FORWARD));
    cout<<"[----- END TESTING -----]"<<endl;
    return SUCCESS;
}

#if 0

TEST(UnmannedAircraftTest, should_init_at_0_0_0_N)
{
    UnmannedAircraft ua;
    ASSERT_TRUE(Position(0,0,0,N) == ua.getPosition());
}

TEST(UnmannedAircraftTest, should_position_up_a_step_given_aircraft_at_origin)
{
    ASSERT_TRUE(Position(0,0,1,N) == UnmannedAircraft().on(UP));
}

TEST(UnmannedAircraftTest, should_position_down_a_step_given_position_is_0_0_5_N)
{
    UnmannedAircraft ua(Position(0,0,5,N));
    ASSERT_TRUE(Position(0,0,4,N) == ua.on(DOWN));
}

TEST(UnmannedAircraftTest, should_position_forward_a_step_given_aircraft_at_origin)
{
    ASSERT_TRUE(Position(0,1,0,N) == UnmannedAircraft().on(FORWARD));
}
#endif