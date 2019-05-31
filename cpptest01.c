#include <iostream>

using namespace std;

class myclass
{
    int num;
public:
    myclass()
    {
        num = 100;
    }
    myclass(int n)
    {
        num = n;
    }
    void set_a(int n);
    int get_a();
 
};

void myclass::set_a(int n)
{
    this->num = n;
}

int myclass::get_a()
{
    return num;
}

int main()
{

    myclass m1;
    myclass *m2 = new myclass(1000);

    //m1.set_a(3);
    cout << m1.get_a() <<endl;


    //m2->set_a(5);
    cout << m2->get_a() <<endl;

    delete(m2);

    return 0;
}
