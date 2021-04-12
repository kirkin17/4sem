#include <iostream>
#include <thread>
using namespace std;

typedef struct
{
    int flag;
    char sym;
} targs;

void* proc1(void *arg)
{
    cout << "Поток 1 начал работу\n";
    targs *args = (targs*)arg;
    while(args->flag == 0)
    {
        putchar(args->sym);
	    fflush(stdout);
        std::this_thread::sleep_for(1s);
    }
    cout << "Поток 1 закончил работу\n";
    pthread_exit((void*)1);
}

void* proc2(void *arg)
{
    cout << "Поток 2 начал работу\n";
    targs *args = (targs*)arg;
    while(args->flag == 0)
    {
        putchar(args->sym);
	    fflush(stdout);
        std::this_thread::sleep_for(1s);
    }
    cout << "Поток 2 закончил работу\n";
    pthread_exit((void*)2);
}

int main()
{
    cout << "Программа начала работу\n";

    targs arg1, arg2;
    arg1.flag = 0;
    arg1.sym = '1';
    arg2.flag = 0;
    arg2.sym = '2';

    pthread_t id1, id2;
    pthread_create(&id1, NULL, proc1, &arg1);
    pthread_create(&id2, NULL, proc2, &arg2);
    cout << "Программа ждет нажатия клавиши\n";
    getchar();
    cout << "Клавиша нажата\n";
    arg1.flag = 1;
    arg2.flag = 1;

    int *exitcode1;
    int *exitcode2;

    pthread_join(id1, (void**)&exitcode1);
    pthread_join(id2, (void**)&exitcode2);
    printf("Код завершения потока 1 = %p\n", exitcode1);
    printf("Код завершения потока 2 = %p\n", exitcode2);
    cout << "Программа закончила работу\n";
}