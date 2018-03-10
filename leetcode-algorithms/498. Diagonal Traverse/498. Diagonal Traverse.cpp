/**
一道遍历数组的题
类似回旋数组但是稍稍有点小麻烦
规律多种，我采用的是行列和的奇偶与遍历方向关系规律
需要处理的就是走到尽头遍历的下标如何变化
找到规律后，解决很简单

更简单的思路：在遍历到行列首尾时，修改下一个遍历的坐标
我用的是超出后再判断，这里想复杂了 
**/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        if (n == 0)
            return ans;
        int m = matrix[0].size();
        int count = n*m;
        int i=0, j=0;
        int up;
        while (count) {
            ans.push_back(matrix[i][j]);
            count -= 1;
            
            if ((i+j)&1) {
                i += 1;
                j -= 1;
            } else {
                i -= 1;
                j += 1;
            }
            if (j >= m) {
                i += 2;
                j = m - 1;
            }
            if (i >= n) {
                i = n - 1;
                j += 2;
            }
            if (i < 0) {
                i = 0;
            }
            if (j < 0) {
                j = 0;
            }
        }
        return ans;
    }
};
