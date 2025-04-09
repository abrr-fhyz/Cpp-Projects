#include<stdio.h>
#include<time.h>

void sort(int arr[], int length)
{
    int temp;
    for (int i = 0; i < length; i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


void print(int A[], int B[], int C[], int N)
{
    sleep(1);
    system("cls");
    printf("\n\n");
    for(int i=0; i<N; i++)
    {
        int a=A[i], b=B[i], c=C[i];
        if(a!=0)
        {
            a=(2*a)+1;
        }
        if(b!=0)
        {
            b=(2*b)+1;
        }
        if(c!=0)
        {
            c=(2*c)+1;
        }

        int V;
        //A
        //printf("%d", A[i]);
        V=(2*(N+1)-a+1)/2;
        for(int j=0; j<V; j++)
            printf(" ");
        for(int j=0; j<a; j++)
            printf("%c", 219);
        for(int j=0; j<(2*(N+1)-V-a); j++)
            printf(" ");
        printf(" | ");
        //B
        //printf("%d", B[i]);
        V=(2*(N+1)-b+1)/2;
        for(int j=0; j<V; j++)
            printf(" ");
        for(int j=0; j<b; j++)
            printf("%c", 219);
        for(int j=0; j<(2*(N+1)-V-b); j++)
            printf(" ");
        printf(" | ");
        //C
        //printf("%d", C[i]);
        V=(2*(N+1)-c+1)/2;
        for(int j=0; j<V; j++)
            printf(" ");
        for(int j=0; j<c; j++)
            printf("%c", 219);
        for(int j=0; j<(2*(N+1)-V-c); j++)
            printf(" ");
        printf(" | ");
        //end
        printf("\n");
    }
    printf("\n");
}



void H(int N, int n, char x, char y, char z, int A[], int B[], int C[])
{
    if(n>0)
    {
        H(N, n-1, x, z, y, A, B, C);
        //printf("%c to %c\n", x, y);
        if(x=='A')
        {
            if(y=='B')
            {
                int M=0;
                for(int k=0; k<N; k++)
                {
                    if(A[k]!=0)
                    {
                        M=k;
                        break;
                    }
                }
                B[0]=A[M];
                A[M]=0;
                sort(A, N);
                sort(B, N);
            }
            else //C
            {
                int M=0;
                for(int k=0; k<N; k++)
                {
                    if(A[k]!=0)
                    {
                        M=k;
                        break;
                    }
                }
                C[0]=A[M];
                A[M]=0;
                sort(A, N);
                sort(C, N);
            }
        }
        else if(x=='B')
        {
            if(y=='A')
            {
                int M=0;
                for(int k=0; k<N; k++)
                {
                    if(B[k]!=0)
                    {
                        M=k;
                        break;
                    }
                }
                A[0]=B[M];
                B[M]=0;
                sort(A, N);
                sort(B, N);
            }
            else //C
            {
                int M=0;
                for(int k=0; k<N; k++)
                {
                    if(B[k]!=0)
                    {
                        M=k;
                        break;
                    }
                }
                C[0]=B[M];
                B[M]=0;
                sort(C, N);
                sort(B, N);
            }
        }
        else
        {
            if(y=='B')
            {
                int M=0;
                for(int k=0; k<N; k++)
                {
                    if(C[k]!=0)
                    {
                        M=k;
                        break;
                    }
                }
                B[0]=C[M];
                C[M]=0;
                sort(C, N);
                sort(B, N);
            }
            else //A
            {
                int M=0;
                for(int k=0; k<N; k++)
                {
                    if(C[k]!=0)
                    {
                        M=k;
                        break;
                    }
                }
                A[0]=C[M];
                C[M]=0;
                sort(A, N);
                sort(C, N);
            }
        }
        print(A, B, C, N);
        H(N, n-1, z, y, x, A, B, C);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int store[3][n];
    for(int i=0; i<n; i++)
    {
        store[0][i]=i+1;
        store[1][i]=0;
        store[2][i]=0;
    }
    printf("\n\n\n\n");
    print(store[0], store[1], store[2], n);
    H(n, n, 'A', 'C', 'B', store[0], store[1], store[2]);
    return 0;
}
