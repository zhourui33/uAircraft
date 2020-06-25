#pragma once
#include <iostream>
#define ASSERT_TRUE(exp) do{ \
                            if(exp) \
                                {std::cout<<"[ success]"<<std::endl;} \
                            else \
                                {std::cout<<"[ failed]"<<std::endl;} \  
                            }while(0);