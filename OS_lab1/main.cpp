//
//  main.cpp
//  lab2 OS
//
//  Created by MacBook Pro on 2/28/19.
//  Copyright © 2019 MacBook Pro. All rights reserved.
//
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *func1(void *temp1)
{
    int* value_ptr1 = new int;
    (*value_ptr1) = 0;
    std::cout<<"\n the thread1 started working \n";
    while(*((bool*) temp1))
    {
        std::cout << "1";
        sleep(1);
        (*value_ptr1)++;
    }
    std::cout<<" the thread1 completed working"<<std::endl;
    pthread_exit((void*)value_ptr1);
}

void *func2(void *temp2)
{
    int* value_ptr2 = new int;
    (*value_ptr2) = 0;
    std::cout<<"\n the thread2 started working \n";
    
    while(*((bool*)temp2))
    {
        std::cout << "2";
        sleep(1);
        (*value_ptr2)++;
        
    }
    std::cout<<"the thread2 completed working"<<std::endl;
    
    pthread_exit(value_ptr2);
}

int main()
{
    bool flag1(1), flag2(1);
    void* value_ptr1;
    void* value_ptr2;
    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1, NULL, &func1, &flag1);
    pthread_create(&t2, NULL, &func2, &flag2);
    std::cout<<"press button"<<std::endl;
    getchar();
    flag1 =false;
    flag2 =false;
    pthread_join(t1, &value_ptr1);
    pthread_join(t2, &value_ptr2);
    std::cout << *((int*)(value_ptr1)) << std::endl;
    std::cout << *((int*)(value_ptr2)) << std::endl;
    delete (int*)value_ptr1;
    delete (int*)value_ptr2;
    std::cout << "THe end" << std::endl;
    return 0;
    
}
