// To rotate the rings of a matrix by r units anticlockwise
// matrix such that:
// dimensions: m x n
// min(m, n) % 2 = 0
// m, n >=2

#include <iostream>
#include <string>
#include <vector>

void matrixRotation(std::vector<std::vector<int>> matrix, int r) {
    int r_len = matrix[0].size();
    int r_num = matrix.size();
    int c_len = r_num;
    int c_num = r_len;

    int dim;
    if(r_len < c_len){
        dim = r_len/2;
    }
    else{
        dim = c_len/2;
    }

    for(int rotate=0; rotate < r; rotate++){
        for(int m=0; m<dim; m++){
            int i=m+1, j=m;
            std::string direction = "down";

            int replacement = matrix[m][m];
            matrix[m][m] = matrix[m][m+1];

            while(i!=m || j!=m){
                int temp = matrix[i][j];
                matrix[i][j] = replacement;
                replacement = temp;
                
                if(direction == "down"){
                    if(i == c_len-1-m){
                        j++;
                        direction = "right";
                    }
                    else{
                        i++;
                    }
                    
                }
                else if(direction == "up"){
                    if(i == m){
                        j--;
                        direction = "left";
                    }
                    else{
                        i--;
                    }
                }
                else if(direction == "left"){
                    j--;
                }
                else if(direction == "right"){
                    if(j == r_len-1-m){
                        i--;
                        direction = "up";
                    }
                    else{
                        j++;
                    }
                }
            }
        }
    }

    for(int i=0; i<r_num; i++){
        for(int j=0; j<c_num; j++){
            if(matrix[i][j]<10){std::cout << "0";}
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

}

int main()
{
  std::vector<std::vector<int>> a;
  int fill = 0;
  for(int i=0; i<8; i++){
      std::vector<int> temp;
      a.push_back(temp);
      for(int j=0; j<8; j++){
          a[i].push_back(++fill);
      }
  }
  
  for(int i=0; i<(int)a.size(); i++){
      for(int j=0; j<(int)a[i].size(); j++){
          if(a[i][j]<10){std::cout << "0";}
         std::cout << a[i][j] << " ";
      }
      std::cout << "\n";
  }
  std::cout << "\n";
  
  matrixRotation(a, 2);
}
