
#include<iostream>
#include<cstring>
using namespace std;

class Vector
{
    char *name;
    int x,y,z;
public:
    Vector(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=0;
        y=0;
        z=0;
    }
    Vector(char *n, int a, int b, int c)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=a;
        y=b;
        z=c;
    }
    Vector() {};
    Vector(const Vector &V)
    {
        name= new char[strlen(V.name)+1];
        strcpy(name,V.name);
        x=V.x;
        y=V.y;
        z=V.z;

    }

    int setX(int a)
    {
        x=a;
    }

    int setY(int b)
    {
        y=b;
    }
    int setZ(int c)
    {
        z=c;
    }

    void setName(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    int getZ()
    {
        return z;
    }

    char *getName()
    {
        return name;
    }

    ~Vector()
    {
        delete []name;
    }
    friend ostream &operator<<(ostream &output, Vector &V);
    Vector operator ^(Vector v)
    {
        Vector temp("Result 1");
        temp.setX(y*v.getZ()-z*v.getY());
        temp.setY(z*v.getX()-x*v.getZ());
        temp.setZ(x*v.getY()-y*v.getX());
        return temp;
    }
    bool operator ==(Vector V)
    {
        if(x==V.x && y==V.y && z==V.z) return 1;
        else return 0;
    }
    Vector operator *(int n)
    {
        setX(x*n);
        setY(y*n);
        setZ(z*n);
        return *this;
    }
    friend Vector operator *(int n, Vector V);
    Vector operator *(Vector v)
    {
        Vector temp;
        temp.setX(x*v.getX());
        temp.setY(y*v.getY());
        temp.setZ(z*v.getZ());
        return temp;
    }
    Vector operator =(Vector V)
    {
        x=V.x;
        y=V.y;
        z=V.z;
        return *this;
    }


};

Vector operator *(int n, Vector V)
{
    Vector temp;
    temp.setX(n*V.getX());
    temp.setY(n*V.getY());
    temp.setZ(n*V.getZ());
    return temp;

}
ostream &operator<<(ostream &output, Vector &V)
{
    if(V.getX()>0 &&V.getY()>0 && V.getZ()>0)
    {
        output <<V.getName()<<": "<<V.getX()<<"x+"<<V.getY()<<"y+"<<V.getZ()<<"z"<<endl;
    }
    if(V.getX()<0 &&V.getY()>0 && V.getZ()>0)
    {
        output <<V.getName()<<": "<<V.getX()<<"x+"<<V.getY()<<"y+"<<V.getZ()<<"z"<<endl;
    }
    if(V.getX()>0 &&V.getY()<0 && V.getZ()>0)
    {
        output <<V.getName()<<": "<<V.getX()<<"x"<<V.getY()<<"y+"<<V.getZ()<<"z"<<endl;
    }
    if(V.getX()>0 &&V.getY()>0 && V.getZ()<0)
    {
        output <<V.getName()<<": "<<V.getX()<<"x+"<<V.getY()<<"y"<<V.getZ()<<"z"<<endl;
    }
    if(V.getX()<0 &&V.getY()<0 && V.getZ()>0)
    {
        output <<V.getName()<<": "<<V.getX()<<"x"<<V.getY()<<"y+"<<V.getZ()<<"z"<<endl;
    }
    if(V.getX()<0 &&V.getY()>0 && V.getZ()<0)
    {
        output <<V.getName()<<": "<<V.getX()<<"x+"<<V.getY()<<"y"<<V.getZ()<<"z"<<endl;
    }
    if(V.getX()>0 &&V.getY()<0 && V.getZ()<0)
    {
        output <<V.getName()<<": "<<V.getX()<<"x"<<V.getY()<<"y"<<V.getZ()<<"z"<<endl;
    }
    if(V.getX()<0 &&V.getY()<0 && V.getZ()<0)
    {
        output <<V.getName()<<": "<<V.getX()<<"x"<<V.getY()<<"y"<<V.getZ()<<"z"<<endl;
    }
    return output;
}



int main()
{
    Vector v1("v1", 1,2,3), v2("v2", 4, 5, -6), v3("Result1"),v4("Result2",-27,18,-3);

    cout << v1;     //Print the components of vector v1
    cout << v2;     //Print the components of vector v2

    v3=v1^v2;       //Calculate the cross product of vector v1 and vector v2 (Consider ^ as cross product for this assignment)
    cout << v3;     //Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      //Check for equality; if two vectors contain equal component values (x, y, z), then they are equal
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    v1= v1*2;       //Multiply each component of vector v1 with the given value
    cout << v1;     //Print the modified components of vector v1

    v2=2*v2;        //Multiply each component of vector v2 with the given value
    cout << v2;     //Print the modified components of vector v2

    v3=v1*v2;       //Multiply each component of vector v1 with the corresponding component of vector v2
    cout << v3;     //Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      //Check for equality; if two vectors contain equal component values (x, y, z), then they are equal
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    return 0;
}

/* Output:
v1: 1x+2y+3z
v2: 4x+5y-6z
Result1: -27x+18y-3z
Vectors are equal
v1: 2x+4y+6z
v2: 8x+10y-12z
Result1: 16x+40y-72z
Vectors are not equal
*/
