#include <iostream>
using namespace std;

void *proc1()
{
    while(1)
    {
        cout << '1';
        
    }
    return 1;
}

void *proc2()
{
    while(1)
    {
        cout << '2';

    }
    return 1;
}

int main()
{
    int flag1, flag2;
    pthread_t id1, id2;
    pthread_create(&id1, NULL, proc1, NULL);
    pthread_create(&id2, NULL, proc1, NULL);
    getchar();
    flag1 = 1;
    flag2 = 1;
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
}