#include "FcMatematicas.h"
int selecsimp ()
{
    int o;
    do
    {
        printf("Ej:\nOperaciones matematicas:\n1- Factorial\n2- Numero combinatorio\n3- e^x\n4- Raiz cuadrada\n5- Fibonacci\n\
        \ \r6- Sen(x)\n7- Clasificar natural\n8- Prod. sumas sucesivas\n9- Coc. entero y resto\n\
        \ \r10- Suma prim. N numeros\n11- Suma prim. N numeros pares\n12- Suma prim N menor N\n\
        \ \r13- Natural Primo\n0- Salir\n");
        printf("Ingrese el numero del ejercicio deseado y presione Enter: ");
        scanf("%d",&o);
        system("cls");
    }
    while(o<0||o>13);
    return o;
}

int factorial(int n)
{
    int acum=1;
    while(n!=0)
    {
        acum*=n;
        n--;
    }
    return acum;
}

int combinatoria (int m, int n)
{
    return factorial(m)/(factorial(n)*factorial(m-n));
}
float potenciar (float x,int n)
{
    float r=1;
    int f=0;
    if (n<0)
    {
        n=-n;
        f=1;
    }
    while(n!=0)
    {
        r*=x;
        n--;
    }
    return f==0?r:1/r;
}

float exponencial (int x, float TOL)
{
    float res=TOL, resf=1,nume=1;
    int n=1,fn=0,denom=1;
    if (x<0)
    {
        x=-x;
        fn=1;
    }
    while (res>=TOL)
    {
        nume*=x;
        denom*=n;
        res=(nume/denom);
        resf+=res;
        n++;
    }
    return fn==0?resf:1/resf;
}
float raizcuadrada(float a,float TOL)
{
    float res=0,resf=1;
    if(a==0)
        return 0;
    while((resf-res)>=TOL||(res-resf)>=TOL)
    {
        res=resf;
        resf=((0.5)*(res+(a/res)));
    }
    return resf;
}

int fibonacci (int val)
{
    int a=1,b=1;
    while(val!=a&&val!=b&&a<=val&&b<=val)
    {
        a=a+b;
        b=a+b;
    }
    return (val==a||val==b?1:0);
}

float seno(float a, float TOL)
{
    float res=a,resf=a;
    int fn=-1,n=3;
    while (absol(res)>=TOL)
    {
        //printf("res: %f | resf: %f | n: %d | fn: %d\n",res,resf,n,fn); linea de testeo
        res=((fn*potenciar(a,n))/factorial(n));
        fn=(fn==-1?1:-1);
        n+=2;
        resf+=res;
        //getch(); linea de testeo
    }
    return resf;
}

void clasifnatural (int n)
{
    int sum=0,i;
    if(n==1) //Esto se debe a que, si uso el n/2, 1 es deficiente porque 1>0.5
        printf("El numero %d es perfecto",n); //y si quito el n/2 pierdo eficiencia
    else
    {
        for(i=1; i<=n/2; i++)
            sum+=(n%i==0?i:0);
        printf("El numero %d es %s",n,sum>n?"abundante":sum<n?"deficiente":"perfecto");
    }
}

int prodsumsuces(int may,int men)
{int j=0;
 for (men;men!=0;men--)
    j+=may;
 return j;
}

int cocentero (int a, int b,int* c, int* r)
{
    *c=a/b;
    *r=a%b;
}

int sumprimn (int a)
{
    int p=0,i=0;
    while(i<=a)
    {
        p+=i;
        i++;
    }
    return p;
}

int sumprimnpar (int a)
{
    int p=0,i=1;
    while(i<=a)
    {
        if(i%2==0)
            p+=i;
        i++;
    }
    return p;
}

int sumprimnmenorn (int a)
{
    int p=0,i=1;
    while(i<a)
    {
        p+=i;
        i++;
    }
    return p;
}

int esprimo (int n)
{return (n==2||n==3||(n%2!=0&&n%3!=0&&n!=1));
}
