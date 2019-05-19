#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct DA{
    int length1, length2, length3, *A, *B, z, k;
    string snumber1, snumber2, c;
    char zn;
    DA(){
        cout<<"Введите первое число: ";
        cin>>snumber1;
        cout<<"Введите второе число: ";
        cin>>snumber2;
        length1=snumber1.size();
        length2=snumber2.size();
        if (length1>length2)
            length3=length1;
        else
            length3=length2;
        int *A=new int[length3+1];
        int *B=new int[length3+1];
        A[length3]=0;
        B[length3]=0;
        int j=0;
        for(int i=length3;i>0;i--){
            if((i>length1)&&(length3!=length1))
                A[i-1]=0;
            else{
                A[i-1]=(int)snumber1[j]-'0';
                j++;
            }
        }
        j=0;
        for(int i=length3;i>0;i--){
            if((i>length2)&&(length3!=length2))
                B[i-1]=0;
            else{
                B[i-1]=(int)snumber2[j]-'0';
                j++;
            }
        }
        cout<<endl<<"Введите знак операции '+,-,*': ";
        cin>>zn;
        switch(zn){
            case '+':{
                for(int i=0;i<length3+1;i++){
                    A[i]+=B[i];
                    A[i+1]+=A[i]/10;
                    A[i]=A[i]%10;
                }
                for(int i=length3;i>0;i--)
                    if(A[i]==0)
                        length3--;
                    else
                        break;
                cout<<endl<<"Результат сложение: ";
                for(int i=length3+1;i>0;i--)
                    cout<<A[i-1];
                break;
            }

            case '-':{
                k=3;
                if(length1>length2){
                    k=1;
                }
                else
                    if(length2>length1)
                        k=2;
                    else
                        for(int i=length3;i>0;i--){
                            if (A[i-1]>B[i-1]){
                                k=1;
                                break;
                            }
                            if (B[i-1]>A[i-1]){
                                k=2;
                                break;
                            }
                        }
                if (k==2)
                    difference(B, A, length3, k);
                else
                    if(k==1)
                        difference(A, B, length3, k);
                    else
                        cout<<endl<<"Результат вычитания: 0";
                break;
            }

            case '*':{
                int length4=length1+length2;
                int *C=new int[length4];
                for(int i=0;i<length4;i++)
                    C[i]=0;
                for(int i=0;i<length1;i++)
                    for(int j=0;j<length2;j++){
                        C[i+j]+=A[i]*B[j];
                    }
                for(int i=1;i<length4;i++){
                    C[i]+=C[i-1]/10;
                    C[i-1]%=10;
                }

                for(int i=length4;i>0;i--){
                    if(C[i-1]==0)
                        length4--;
                    else
                        break;
                }
                cout<<endl<<"Результат умножения: ";
                for(int i=length4;i>0;i--)
                    cout<<C[i-1];
                break;
            }

            default:
                cout<<"Ошибка."<<endl;
                break;
        }
    }
    void difference(int *a, int *b, int length, int f){
    for(int i=0;i<length;i++){
        if (a[i]-b[i]<0)
            if (a[i+1]>0){
                a[i]=a[i]-b[i]+10;
                a[i+1]-=1;
            }
            else{
                for(int z=i+1;z<length+1;z++){
                    a[z]=9;
                    if (a[z+1]==1){
                        a[z+1]--;
                        break;
                    }
                }
                    a[i]=a[i]-b[i]+10;
            }
        else
            a[i]-=b[i];
    }
    for(int i=length;i>0;i--){
        if(a[i-1]==0)
            length--;
        else
            break;
    }
    if (f==2)
        cout<<endl<<"Результат вычитания: -";
    else
        cout<<endl<<"Результат вычитания: ";
    for(int i=length;i>0;i--)
        cout<<a[i-1];
    }
};

int main(){
    setlocale(LC_ALL, "rus");
    DA DA1;
    return 0;
}

