#include<iostream>
#include<string>
using namespace std;

double array[100][101]; //setting the cap at 100 variable linear equations
double solution[100]; //saves the solutions
double store[100][101]; //storing the equations for calculating the other solutions
int cnt=0;

void soln() //finds out the other n-2 solutions
{
	int sol=2;
	for(int i=cnt-1; i>=0; i--)
	{
		solution[sol]=store[i][sol+1];
		for(int j=0; j<sol; j++)
			solution[sol]-=(store[i][j]*solution[j]);
		solution[sol]/=store[i][sol];
		printf("\n%.3lf", solution[sol]);
		sol++;
	}
}

void solve(int n)
{
	if(n>2)
	{
		for(int i=0; i<n+1; i++)
			store[cnt][i]=array[0][i];
		cnt++;
		for(int i=0; i<n-1; i++) //will change 0 to n-2 equations
		{
			for(int j=0; j<n-1; j++) //will change a1 to a(n-1)
				array[i][j]-=((array[i][n-1]/array[n-1][n-1])*array[n-1][j]);
			//will change constant
			array[i][n]-=((array[i][n-1]/array[n-1][n-1])*array[n-1][n]);
			//removing the redundant variable
			swap(array[i][n], array[i][n-1]);
		}
		solve(n-1);
	}
	else
	{
		double a1=array[0][0], a2=array[1][0];
		double b1=array[0][1], b2=array[1][1];
		double c1=array[0][2], c2=array[1][2];
		if((a1/a2)==(b1/b2)){
			cout << "Error evaluating the equations. Solution either doesn't exist or are infinite in number.\n";
			return;
		}
		double x, y;
		y=(c1-(a1/a2)*c2)/(b1-(a1/a2)*b2);
		x= (1/a1) * (c1-b1*y);
		solution[0]=x;
		solution[1]=y;
		printf("The solutions are\n%.3lf\n%.3lf", x, y);
		soln();
		return;
	}
}


int main()
{
	int n;
	cout << "Please Input the number of variables: ";
	cin >> n;
	cout << "Enter the coefficients following the format; a1x1 + a2x2 + ... + anxn = c\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=n; j++)
		{
			cin >> array[i][j];
		}
	}
	solve(n);
	return 0;
}
