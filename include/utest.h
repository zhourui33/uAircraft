#pragma once
#include <iostream>

#define ASSERT_TRUE(exp) do{ \
                            if(exp) \
                                {std::cout<<"[ success] "<<#exp<<" assert TRUE."<<std::endl;} \
                            else \
                                {std::cout<<"[ failed] "<<#exp<<" assert FALSE!"<<std::endl;} \  
                            }while(0);

#define TEST(test_suite, test_case) void #test_suite#test_case()