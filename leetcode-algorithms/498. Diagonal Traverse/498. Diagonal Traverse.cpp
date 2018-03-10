/**
һ�������������
���ƻ������鵫�������е�С�鷳
���ɶ��֣��Ҳ��õ������к͵���ż����������ϵ����
��Ҫ����ľ����ߵ���ͷ�������±���α仯
�ҵ����ɺ󣬽���ܼ�

���򵥵�˼·���ڱ�����������βʱ���޸���һ������������
���õ��ǳ��������жϣ������븴���� 
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
