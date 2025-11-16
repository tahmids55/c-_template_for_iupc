#include<bits/stdc++.h>
using namespace std;

void Dio_eq_solve(int aa, int b, int c, int *xx, int *yy)
{
    int a[100],q[100],x[100];
    int neg_a=0,neg_b=0;
    if(aa<0){
            neg_a++;
            aa=-aa;
    }
    if(b<0){
            neg_b++;
            b=-b;
    }

    if(aa>b){
        a[0]=aa;
        a[1]=b;
    }
    else{
        a[0]=b;
        a[1]=aa;
    }
    int n,i;
    for(i=1;;i++){
        if(i>1){
            a[i]=a[i-2]%a[i-1];
        }
        if(a[i]!=0){
            q[i]=a[i-1]/a[i];
        }

        if(a[i]==0) {
            n=i;
            break;
        }
    }
    if(n>0){
        x[n]=c;
        x[n-1]=0;
    }
    if(n>1){
        for(i=n-2;i>=0;i--){
            x[i]=x[i+2]-x[i+1]*q[i+1];
        }
    }
    if(aa>b){
        *xx=x[1];
        *yy=x[0];
    }
    else{
        *xx=x[0];
        *yy=x[1];
    }
    if(neg_a) *xx=-(*xx);
    if(neg_b) *yy=-(*yy);
}


void near_zero_solve_for_x(int a, int b, int c, int *x, int *y)
{
    Dio_eq_solve(a,b,c,x,y);
    double k= -(double)(*x)/b;
    cout<<"k="<<k<<endl;
    if(b>0){
        k=ceil(k);
    }
    else{
        k=floor(k);
    }
    *x=*x+k*b;
    *y=*y-k*a;

}

void near_zero_solve_for_y(int a, int b, int c, int *x, int *y)
{
    Dio_eq_solve(a,b,c,x,y);
    double k= -(double)(*y)/a;

    if(a>0){
        k=ceil(k);
    }
    else{
        k=floor(k);
    }
    *x=*x-k*b;
    *y=*y+k*a;

}

void input(int *a, int *b, int *c)
{
    cout<<"Form of Equation: ax + by = c"<<endl;
    cout<<"a = ";
    cin>>*a;
    cout<<"b = ";
    cin>>*b;
    cout<<"c = ";
    cin>>*c;
    cout<<endl<<"So the equation becomes :";
    cout<<*a<<"x + "<<*b<<"y = "<<*c<<endl;

}

void solution_display(int *x, int *y)
{
    cout<<endl<<"Solution: ";
    cout<<"("<<*x<<","<<*y<<")"<<endl<<endl<<endl;;
}

int main()
{
    int a,b,c,x,y;

    int choice;
    int f=1;
    while(f){
        cout<<"---------------DIOPHANTINE EQUATION SOLVE---------------"<<endl;
        cout<<endl;
        cout<<"Choose your Operation: "<<endl;
        cout<<"\t1. Diophantine Equation solve for random range"<<endl;
        cout<<"\t2. Diophantine Equation solve for x being nearest to 0(zero)"<<endl;
        cout<<"\t3. Diophantine Equation solve for y being nearest to 0(zero)"<<endl;
        cout<<"\t4. Exit"<<endl<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            input(&a,&b,&c);
            Dio_eq_solve(a,b,c,&x,&y);
            solution_display(&x,&y);
            break;
        case 2:
            input(&a,&b,&c);
            near_zero_solve_for_x(a,b,c,&x,&y);
            solution_display(&x,&y);
            break;

        case 3:
            input(&a,&b,&c);
            near_zero_solve_for_y(a,b,c,&x,&y);
            solution_display(&x,&y);
            break;

        case 4:
            f=0;
            break;
        }
    }
    //Dio_eq_solve(a,b,c,&x,&y);
    //near_zero_solve_for_x(a,b,c,&x,&y);

    return 0;
}
