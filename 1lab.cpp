#include <iostream>
using namespace std;

void* proc1(void *args)
{
    while(1)
    {
        cout << '1';
        
    }
    return 0;
}

void* proc2(void *args)
{
    while(1)
    {
        cout << '2';

    }
    return 0;
}

int main()
{
    int flag1, flag2;
    pthread_t id1, id2;
    flag1 = pthread_create(&id1, NULL, proc1, NULL);
    flag2 = pthread_create(&id2, NULL, proc1, NULL);
    getchar();
    flag1 = 1;
    flag2 = 1;
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
}