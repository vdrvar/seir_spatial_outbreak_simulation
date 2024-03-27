#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<vector>
#include <ctime>
#include<iomanip>
#include <algorithm>
#include <iterator>
#include <set>
#include <fstream>

using namespace std;

typedef pair<int, int> pairs;

//random sign generator
int rand_sign() {
	double r = rand() % 2;
	return (r*2-1);
}

//random alpha distance generator
double rand_alpha(double alpha) {
	if (alpha<=1) return -1;

	double r = (double) rand()/RAND_MAX;
	return pow((1-r), 1/(1-alpha) );
}

//random exponential distributed number generator
double rand_exp(double lambda) {
	if (lambda<=0) return -1;

	double r = (double) rand()/RAND_MAX;
	return -log(1-r)/lambda;
}

//random poisson distributed number generator
int rand_poisson(const vector<double>& v) {
	double r = (double) rand()/RAND_MAX;
	return lower_bound(v.begin(), v.end(), r)-v.begin()-1;
}


//random horizontal move in the grid
int rand_a(int D) {
	return rand() % (D+1);
}

//daily_recovery_update
void daily(int n, vector< vector<int> >&  g, vector< vector<int> >& r) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if (g[i][j]&&(r[i][j]>=0)) {
				r[i][j]--;
			}

			if (r[i][j]<0) {
				g[i][j]=0;
			}
		}
	}
}

//infected_ratio_output

double ratio(int n, const vector< vector<int> >& g) {
	double cum=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cum+=g[i][j];
		}
	}
	return cum/n/n;
}


//matrix output function
void cmatrix(const vector< vector<int> >& g) {
	for(int i=0;i<g.size();i++) {
		for(int j=0;j<g[i].size();j++){
			cout <<setw(2) <<g[i][j] <<" ";
		}
		cout <<endl;
	}
	cout <<endl;
}

//matrix output function 2
void cmatrix2(const vector< vector<int> >& g) {
    for(int i=0;i<=(g.size())*3;i++) cout <<"_";
    cout <<endl;
	for(int i=0;i<g.size();i++) {
        cout <<"|";
		for(int j=0;j<g[i].size();j++){
            if (g[i][j]) {
                    cout <<setw(2) <<g[i][j] <<" ";
            } else cout <<setw(2) <<" " <<" ";
		}
		cout <<"|" <<endl;
	}

    cout <<"|";

	for(int i=0;i<(g.size())*3;i++) cout <<"_";

	cout <<"|" <<endl;
}

//matrix output function 3
void cmatrix3(const vector< vector<int> >& g, const vector< vector<int> >& m) {
    for(int i=0;i<=(g.size())*3;i++) cout <<"_";
    cout <<endl;
	for(int i=0;i<g.size();i++) {
        cout <<"|";
		for(int j=0;j<g[i].size();j++){
            if (g[i][j]) {
                    if (!(m[i][j]==-1)) cout <<setw(2) <<"e" <<" "; else cout <<setw(2) <<"i" <<" ";
            } else cout <<setw(2) <<" " <<" ";
		}
		cout <<"|" <<endl;
	}

    cout <<"|";

	for(int i=0;i<(g.size())*3;i++) cout <<"_";

	cout <<"|" <<endl;
}

//vector output function
void cvector(const vector<double>& v) {
	for(int i=0;i<v.size();i++) {
	cout <<i <<" " <<v[i] <<endl;
	}
	cout <<endl;
}

//set output function
void cset(const set<pairs>& s)
{
    bool found = false;

    // range-based for loop
    for (auto const &x : s) {
        found = true;
        cout << "(" << x.first << ", "
             << x.second << ")"
             << " ";
    }

    if (not found) {
        cout << "No valid pair\n";
    }
}

//set output function 2
void cset2(const set<pairs>& s)
{
    bool found = false;
    int it=1;

    // range-based for loop
    for (auto const &x : s) {
        found = true;
        if (it>0) {
        if (it>20) {cout <<"and " <<s.size()-10 <<" more";it=-1;}
    else {
        cout << "(" << x.first << ", "
             << x.second << ")"
             << " ";
    }
    it++;
    }
    }

    if (not found) {
        cout << "No valid pair\n";
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {

std::ofstream outfile ("TEST.txt");

vector<int> aux;
aux.resize(2);

string yn;

//CONSTANTS
const int n_d = 1000;
int n;
cout <<"Do you want to define n manually? (y/n): ";
cin >>yn;
if (yn=="y") {cout <<"n := "; cin >>n;} else {n=n_d;}


const double dist_alpha_d = 4;
double dist_alpha;
cout <<"Do you want to define dist_alpha manually? (y/n): ";
cin >>yn;
if (yn=="y") {cout <<"dist_alpha := "; cin >>dist_alpha;} else {dist_alpha=dist_alpha_d;}

const double lambda_poisson_d = 3;
double lambda_poisson;
cout <<"Do you want to define lambda_poisson manually? (y/n): ";
cin >>yn;
if (yn=="y") {cout <<"lambda_poisson := "; cin >>lambda_poisson;} else {lambda_poisson=lambda_poisson_d;}

const double lambda_exp_inc_d = 1;
double lambda_exp_inc;
cout <<"Do you want to define lambda_exp_inc manually? (y/n): ";
cin >>yn;
if (yn=="y") {cout <<"lambda_exp_inc := "; cin >>lambda_exp_inc;} else {lambda_exp_inc=lambda_exp_inc_d;}

const double lambda_exp_rec_d = 1;
double lambda_exp_rec;
cout <<"Do you want to define lambda_exp_rec manually? (y/n): ";
cin >>yn;
if (yn=="y") {cout <<"lambda_exp_rec := "; cin >>lambda_exp_rec;} else {lambda_exp_rec=lambda_exp_rec_d;}

const int days_d = 100;
int days;
cout <<"Do you want to define days manually? (y/n): ";
cin >>yn;
if (yn=="y") {cout <<"days := "; cin >>days;} else {days=days_d;}

cout <<endl;

//output of the constants
cout <<"n = " <<n <<endl <<endl <<"dist_alpha = " <<dist_alpha <<endl <<"lambda_poisson = " <<lambda_poisson <<endl <<"lambda_exp_inc = " <<lambda_exp_inc <<endl  <<"lambda_exp_rec = " <<lambda_exp_rec <<endl <<endl;

//poisson specs
const int n_poisson=33;
vector<double>  cdf_poisson;

cdf_poisson.resize(n_poisson+1);

cdf_poisson[0]=0;
cdf_poisson[1]=exp(-lambda_poisson);
cdf_poisson[n_poisson]=1;

for(int i=2;i<n_poisson;i++) {
	cdf_poisson[i]=cdf_poisson[i-1]*lambda_poisson/(i-1);
}

double cumulator=0;

for(int i=0;i<cdf_poisson.size()-1;i++) {
	cumulator+=cdf_poisson[i];
	cdf_poisson[i]=cumulator;
}

//information matrices/vectors
vector< vector<int> > grid;
vector< vector<int> > incubation;
vector< vector<int> > recovery;
set<pairs> exposed;
set<pairs> infectious;
set<pairs> rem_exposed;
set<pairs> rem_infectious;

vector< vector<int> > moves;

grid.resize(n);
incubation.resize(n);
recovery.resize(n);
moves.resize(0);

srand(time(NULL));

//initialize the grid
for(int i=0;i<n;i++) {
	grid[i].resize(n);
	for(int j=0;j<n;j++) {
		grid[i][j]=0;
	}
}

//initialize the incubation matrix
for(int i=0;i<n;i++) {
	incubation[i].resize(n);
	for(int j=0;j<n;j++) {
		incubation[i][j]=round(rand_exp(lambda_exp_inc));
	}
}

//initialize the recovery matrix
for(int i=0;i<n;i++) {
	recovery[i].resize(n);
	for(int j=0;j<n;j++) {
		recovery[i][j]=round(rand_exp(lambda_exp_rec));
	}
}

//initialize the infectious list
//int patient_zero_x=rand_a(n-1), patient_zero_y=rand_a(n-1);
int patient_zero_x=(n-1)/2, patient_zero_y=(n-1)/2;

grid[patient_zero_x][patient_zero_y]=1;
incubation[patient_zero_x][patient_zero_y]=-1;

infectious.insert(make_pair(patient_zero_x, patient_zero_y));

//output of the initial state
cout <<"Patient zero" <<" = (" <<patient_zero_x <<", " <<patient_zero_y <<")" <<endl;

cout <<endl <<"Grid at Day 0:" <<endl;



/*
cout <<endl <<"Incubation at Day 0:" <<endl;
cmatrix(incubation);

cout <<endl <<"Recovery at Day 0:" <<endl;
cmatrix(recovery);
*/

//SIMULATION

double worst = -1;
double reproduction, rep_end=0;

outfile <<n <<endl;

for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {

        char current = 's';

        if (grid[i][j]) {
            if (incubation[i][j]==-1) current='i';
            else current='e';
        }

        else if (recovery[i][j]==-1) current='r';
    outfile <<current <<" ";
    }
    outfile <<endl;
}
 outfile <<endl;


for(int day=1;day<=days;day++) {

reproduction = 0;

//moves vector setup

moves.resize(0);

for (auto const &x : infectious) {

	int l1 = rand_poisson(cdf_poisson);
	int l2 = rand_poisson(cdf_poisson);

	for(int j=0;j<l1+l2;j++) {
		aux[0]=x.first;
		aux[1]=x.second;
		moves.push_back(aux);
	}
}

random_shuffle ( moves.begin(), moves.end() );

int D, a, b, x, y, i2, j2;
int N=n;

//moves
for(int z=0;z<moves.size();z++) {

    i2 = moves[z][0];
	j2 = moves[z][1];

	D=round(rand_alpha(dist_alpha));

    a=rand_a(D);
    b=D-a;
    x=(i2+rand_sign()*a) % N;
    y=(j2+rand_sign()*b) % N;

    if (x<0) x+=N;
    if (y<0) y+=N;

    if ((grid[x][y]==0)&&(recovery[x][y]!=-1)) {
        grid[x][y]=1;
        exposed.insert(make_pair(x, y));
        reproduction+=1;
        //cout<<"I am ("  <<setw(2) <<i2 <<","  <<setw(2) <<j2 <<")" <<" and I meet " <<"(" <<setw(2) <<x <<"," <<setw(2) <<y <<")" <<endl;
    }

}

//if (infectious.size()) reproduction=reproduction/infectious.size(); else reproduction=0;

//if (((days-1) % 5)==0) {
for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {

        char current = 's';

        if (grid[i][j]) {
            if (incubation[i][j]==-1) current='i';
            else current='e';
        }

        else if (recovery[i][j]==-1) current='r';
    outfile <<current <<" ";
    }
    outfile <<endl;
}
 outfile <<endl;
//}

//update
for (auto const &x : exposed) {
    incubation[x.first][x.second]-=1;
    if (incubation[x.first][x.second]==-1) {
        rem_exposed.insert(x);
        infectious.insert(x);
    }
}

for (auto const &x : rem_exposed) {
    exposed.erase(x);
}

rem_exposed.clear();

for (auto const &x : infectious) {
    recovery[x.first][x.second]-=1;
    if (recovery[x.first][x.second]==-1) {
        rem_infectious.insert(x);
        grid[x.first][x.second]=0;
    }
}

if (rem_infectious.size()) reproduction=reproduction/rem_infectious.size(); else reproduction=reproduction;
rep_end+=reproduction;

for (auto const &x : rem_infectious) {
    infectious.erase(x);
}

rem_infectious.clear();

for(int i=0;i<50;i++) cout <<"-";

cout <<endl <<"Grid at Day " <<day <<":" <<endl;

cout <<"Exposed:" <<endl;
cset2(exposed);

cout <<endl;

cout <<"Infectious:" <<endl;
cset2(infectious);

cout <<endl <<endl;
/*
cout <<endl <<"Incubation at Day " <<day <<":" <<endl;
cmatrix(incubation);

cout <<endl <<"Recovery at Day " <<day <<":" <<endl;
cmatrix(recovery);
*/


cout <<"Sick-to-all ratio: " <<ratio(n, grid)*100 <<"%" <<endl;
worst = max(worst, ratio(n, grid));

cout <<"Worst sick-to-all ratio: " <<worst*100 <<"%" <<endl;

cout <<"Reproduction: " <<reproduction <<endl;

cout <<"Average reproduction: " <<rep_end/day <<endl;
}



return 0;
}

