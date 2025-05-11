#include <iostream>
#include <vector>
#include <limits>
#include <set>
#include <algorithm>

using namespace std;

struct Cell {
    int cost;
    int allocation = 0;
    bool allocated = false;
};

using Matrix = vector<vector<Cell>>;
using Path = vector<pair<int, int>>;

void printAllocation(const Matrix& matrix, const string& title) {
    cout << "\n" << title << "\n";
    for (const auto& row : matrix) {
        for (const auto& cell : row) {
            cout << (cell.allocated ? to_string(cell.allocation) : "x") << "\t";
        }
        cout << "\n";
    }
}

pair<int,int> getMinTwo(const vector<int>& vec) {
    int min1 = numeric_limits<int>::max(), min2 = numeric_limits<int>::max();
    for (int v : vec) {
        if (v < min1) { min2 = min1; min1 = v; }
        else if (v < min2) { min2 = v; }
    }
    return make_pair(min1, min2);
}

void vogelApproximation(Matrix& matrix, vector<int> supply, vector<int> demand) {
    int m = supply.size(), n = demand.size();
    vector<bool> rowDone(m,false), colDone(n,false);
    while (true) {
        vector<int> rowPenalty(m,-1), colPenalty(n,-1);
        for (int i=0;i<m;++i) if(!rowDone[i]){
                vector<int> costs;
                for(int j=0;j<n;++j) if(!colDone[j]) costs.push_back(matrix[i][j].cost);
                if(costs.size()>=2){auto mn=getMinTwo(costs); rowPenalty[i]=mn.second-mn.first;} }
        for (int j=0;j<n;++j) if(!colDone[j]){
                vector<int> costs;
                for(int i=0;i<m;++i) if(!rowDone[i]) costs.push_back(matrix[i][j].cost);
                if(costs.size()>=2){auto mn=getMinTwo(costs); colPenalty[j]=mn.second-mn.first;} }
        int maxP=-1, idx=-1; bool pickRow=true;
        for(int i=0;i<m;++i) if(!rowDone[i] && rowPenalty[i]>maxP){maxP=rowPenalty[i];idx=i;pickRow=true;}
        for(int j=0;j<n;++j) if(!colDone[j] && colPenalty[j]>maxP){maxP=colPenalty[j];idx=j;pickRow=false;}
        if(idx==-1){ // last cell
            int r=find(rowDone.begin(),rowDone.end(),false)-rowDone.begin();
            int c=find(colDone.begin(),colDone.end(),false)-colDone.begin();
            if(r<m && c<n){int q=min(supply[r],demand[c]);matrix[r][c].allocation=q;matrix[r][c].allocated=true;}
            break;
        }
        int r=-1,c=-1, bestCost=numeric_limits<int>::max();
        if(pickRow){r=idx; for(int j=0;j<n;++j) if(!colDone[j]&&matrix[r][j].cost<bestCost){bestCost=matrix[r][j].cost; c=j;}}
        else       {c=idx; for(int i=0;i<m;++i) if(!rowDone[i]&&matrix[i][c].cost<bestCost){bestCost=matrix[i][c].cost; r=i;}}
        int q=min(supply[r],demand[c]);
        matrix[r][c].allocation=q; matrix[r][c].allocated=true;
        supply[r]-=q; demand[c]-=q;
        if(supply[r]==0) rowDone[r]=true; if(demand[c]==0) colDone[c]=true;
        bool done=true; for(bool b:rowDone) if(!b)done=false; for(bool b:colDone) if(!b)done=false;
        if(done) break;
    }
}

int calculateOpportunityCost(const Matrix& matrix, const Path& loop) {
    int cost=0, len=loop.size(); if(len>1&&loop.front()==loop.back())--len;
    for(int i=0;i<len;++i){auto [r,c]=loop[i]; cost += ((i%2)==0 ? 1 : -1)*matrix[r][c].cost;}
    return cost;
}

bool findRectanglePath(int sr,int sc,const Matrix& matrix,Path& result,Path curr,set<pair<int,int>> vis,bool rowMode){
    int m=matrix.size(),n=matrix[0].size();
    int r=curr.back().first, c=curr.back().second;
    if(rowMode){
        for(int j=0;j<n;++j){auto nxt=make_pair(r,j);
            if(nxt==curr.back()||vis.count(nxt)) continue;
            if(matrix[r][j].allocated){
                if(nxt==make_pair(sr,sc)&&curr.size()>=4){result=curr;return true;}
                curr.push_back(nxt); vis.insert(nxt);
                if(findRectanglePath(sr,sc,matrix,result,curr,vis,!rowMode)) return true;
                vis.erase(nxt); curr.pop_back();
            }
        }
    } else {
        for(int i=0;i<m;++i){auto nxt=make_pair(i,c);
            if(nxt==curr.back()||vis.count(nxt)) continue;
            if(matrix[i][c].allocated){
                if(nxt==make_pair(sr,sc)&&curr.size()>=4){result=curr;return true;}
                curr.push_back(nxt); vis.insert(nxt);
                if(findRectanglePath(sr,sc,matrix,result,curr,vis,!rowMode)) return true;
                vis.erase(nxt); curr.pop_back();
            }
        }
    }
    return false;
}

void steppingStone(Matrix& matrix) {
    while(true){
        int m=matrix.size(),n=matrix[0].size(); int bestDelta=0; Path bestLoop;
        for(int i=0;i<m;++i) for(int j=0;j<n;++j) if(!matrix[i][j].allocated){
                    Path loop, curr={{i,j}}; set<pair<int,int>> vis={{i,j}};
                    if(findRectanglePath(i,j,matrix,loop,curr,vis,true)){
                        int d=calculateOpportunityCost(matrix,loop);
                        if(d<bestDelta){bestDelta=d; bestLoop=loop;}
                    }
                }
        if(bestDelta>=0) break;
        int theta=numeric_limits<int>::max();
        for(int k=1;k<bestLoop.size();k+=2){auto [r,c]=bestLoop[k]; theta=min(theta,matrix[r][c].allocation);}
        for(int k=0;k<bestLoop.size();++k){auto [r,c]=bestLoop[k];
            if(k%2==0){matrix[r][c].allocation+=theta; matrix[r][c].allocated=true;}
            else{matrix[r][c].allocation-=theta; if(matrix[r][c].allocation==0) matrix[r][c].allocated=false;}
        }
    }
}

int totalCost(const Matrix& matrix) {
    int sum=0;
    for(const auto& row:matrix) for(const auto& cell:row) if(cell.allocated) sum+=cell.cost*cell.allocation;
    return sum;
}

int main() {
    int m,n;
    cout<<"Enter number of supply sources (rows) and demand sinks (columns): ";
    if(!(cin>>m>>n)) return 0;
    vector<int> supply(m), demand(n);
    cout<<"Enter supply vector ("<<m<<" values): "; for(int i=0;i<m;++i) cin>>supply[i];
    cout<<"Enter demand vector  ("<<n<<" values): "; for(int j=0;j<n;++j) cin>>demand[j];
    Matrix costMatrix(m, vector<Cell>(n));
    cout<<"Enter cost matrix ("<<m<<"x"<<n<<" integers):\n";
    for(int i=0;i<m;++i) for(int j=0;j<n;++j) cin>>costMatrix[i][j].cost;

    vogelApproximation(costMatrix, supply, demand);
    printAllocation(costMatrix, "Initial Vogel Allocation:");
    cout<<"Initial cost: "<<totalCost(costMatrix)<<"\n";

    steppingStone(costMatrix);
    printAllocation(costMatrix, "Optimized Allocation (Stepping Stone):");
    cout<<"Final cost: "<<totalCost(costMatrix)<<"\n";
    return 0;
}
