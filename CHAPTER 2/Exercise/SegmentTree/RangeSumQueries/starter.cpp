#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
private:
    vector<int> st, A;

    int left_p(int i)
    {
        return (i << 1);
    }
    int right_p(int i)
    {
        return (i << 1) + 1;
    }
    void build(int p, int left, int right)
    {
        if (left == right)
            st[p] = A[left];
        else
        {
            build(left_p(p), left, (right + left) / 2);
            build(right_p(p), ((right + left) / 2) + 1, right);
            int p1 = st[left_p(p)];
            int p2 = st[right_p(p)];
            st[p] = p2 + p1;
        }
    }
    int rsq(int p, int L, int R, int i, int j)
    {
        if (i <= L && j >= R)
            return st[p];
        if (i > R || j < L)
            return -1;
        int p1 = rsq(left_p(p), L, (R + L) / 2, i, j);
        int p2 = rsq(right_p(p), ((R + L) / 2) + 1, R, i, j);
        if (p2 == -1)
            return p1;
        else if (p1 == -1)
            return p2;

        return p2 + p1;
    }

public:
    int rsq(int i, int j)
    {
        return rsq(1, 0, A.size() - 1, i, j);
    }
    SegmentTree(vector<int> _A)
    {
        A = _A;
        st.assign(A.size() * 4, 0);
        build(1, 0, A.size() - 1);
    }
};

int main()
{
    const vector<int> A = {1, 3, 5, 7, 9, 11};
    ; // the original array           // copy the contents to a vector
    SegmentTree st(A);
    printf("RMQ(1, 3) = %d\n", st.rsq(-1000, 30000));
    printf("RMQ(4, 6) = %d\n", st.rsq(1, 3)); // answer = index 5
}
