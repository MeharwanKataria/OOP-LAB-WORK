#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
class matrix{
	private:
		int rows;
		int cols;
		int **grid;
	public:
		matrix(){
			rows=0;
			cols=0;
		}
		matrix(int a,int b){
			rows=a;
			cols=b;
			grid=new int*[rows];
			for(int i=0;i<rows;i++){
				grid[i]=new int[cols];
			}
		}
		int getrows(){
			return rows;
		}
		int getcols(){
			return cols;
		}
		matrix(matrix &arr){
			this->rows=arr.rows;
			this->cols=arr.cols;
			grid=new int*[rows];
			for(int i=0;i<rows;i++){
				grid[i]=new int[cols];
			}
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
					this->grid[i][j]=arr.grid[i][j];
				}
			}
		}//move matrix
		matrix(matrix &&arr)noexcept: grid(arr.grid){
			arr.grid=nullptr;
		}
		int at(int r, int c,matrix &mat){
			if(r<=rows && c<=cols&& r>=0 && c>=0){
				return grid[r][c];
			}
			return 1;
		}
		void fill(double value){
			for(int i=0;i<rows;i++){
				for(int j=0;j<cols;j++){
				grid[i][j]=value;
			}
		}}
		void transpose() {
        int** temp = new int*[cols];
        for (int i = 0; i < cols; i++) {
            temp[i] = new int[rows];
            for (int j = 0; j < rows; j++) {
                temp[i][j] = grid[j][i];
            }
        }

        cout << "Transpose matrix:" << endl;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                cout << temp[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < cols; i++) {
            delete[] temp[i];
        }
        delete[] temp;
    }
    void print(){
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
	~matrix(){
			for(int i=0;i<rows;i++){
				delete []grid[i];}
				delete []grid;
		}
		
};
int main(int argc, char*argv[]){
	matrix mat(2,3);
	mat.fill(4);
	matrix m1=mat;
	cout<<"Original Object"<<endl;
	mat.print();
	matrix m2=std::move(mat);
	cout<<"Object2 after copying."<<endl;
	m1.print();
	cout<<"Object3 after moving"<<endl;
	m1.print();
	m1.transpose();
	cout<<"Element found:"<<m1.at(1,1,m1);
}

