#pragma once
#include <iostream>

unsigned int success_count = 0;
unsigned int failed_count = 0;

#define ASSERT_TRUE(exp) do{ \
                            if(exp) \
                                {std::cout<<"[ SUCCESS] "<<#exp<<" assert TRUE."<<std::endl;success_count++;} \
                            else \
                                {std::cout<<"[ FAILED] "<<#exp<<" assert FALSE!"<<std::endl;failed_count++;} \  
                            }while(0);

#define RUN_ALL_TEST_CASES(exp)   do{\
                                    std::cout<<"[----- START TESTING -----]"<<std::endl;\
                                    exp;\
                                    std::cout<<"[----- END TESTING -----]"<<std::endl;\
                                    }while(0);
#define SHOW_TEST_RESULT std::cout<<"[ RESULT] "<<success_count+failed_count<<" cases runned, success "<<success_count<<" cases"<<std::endl;