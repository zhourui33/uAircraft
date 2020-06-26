#include <iostream>
#include "pub.h"
#include "uAircraft.h"
#include "utest.h"

using namespace std;

void RUN_TEST_CASE_STAGE_1()
{
    //should_init_at_0_0_0_N
    ASSERT_TRUE(Position(0,0,0,N) == UnmannedAircraft().getPosition());
    ASSERT_TRUE(Position(1,0,0,N) != UnmannedAircraft().getPosition());
    //should_position_up_a_step_given_aircraft_at_origin
    ASSERT_TRUE(Position(0,0,1,N) == UnmannedAircraft().on(UP));
    //should_position_down_a_step_given_position_is_0_0_5_N
    ASSERT_TRUE(Position(0,0,4,N) == UnmannedAircraft(Position(0,0,5,N)).on(DOWN));
    //should_position_forward_a_step_given_aircraft_at_origin
    ASSERT_TRUE(Position(0,1,0,N) == UnmannedAircraft().on(FORWARD));
}

void RUN_TEST_CASE_STAGE_2()
{
    ASSERT_TRUE(Position(0,0,0,W) == UnmannedAircraft().on(LEFT));
    ASSERT_TRUE(Position(0,0,0,E) == UnmannedAircraft().on(RIGHT));
    ASSERT_TRUE(Position(0,0,0,S) == UnmannedAircraft().on(ROUND));
}
int main()
{
    cout<<"[----- START TESTING -----]"<<endl;
    RUN_TEST_CASE_STAGE_1();
    RUN_TEST_CASE_STAGE_2();
    cout<<"[----- END TESTING -----]"<<endl;
    return SUCCESS;
}

