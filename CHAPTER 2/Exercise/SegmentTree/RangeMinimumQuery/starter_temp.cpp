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
            st[p] = left;
        else
        {
            build(left_p(p), left, (right + left) / 2);
            build(right_p(p), ((right + left) / 2) + 1, right);
            int p1 = st[left_p(p)];
            int p2 = st[right_p(p)];
            st[p] = (A[p1] > A[p2]) ? p2 : p1;
        }
    }
    int rmq(int p, int L, int R, int i, int j)
    {
        if (i <= L && j >= R)
            return st[p];
        if (i > R || j < L)
            return -1;
        int p1 = rmq(left_p(p), L, (R + L) / 2, i, j);
        int p2 = rmq(right_p(p), ((R + L) / 2) + 1, R, i, j);
        if (p2 == -1)
            return p1;
        else if (p2 == -1)
            return p1;
        return (A[p1] > A[p2]) ? p2 : p1;
    }

public:
    int rmq(int i, int j)
    {
        return rmq(1, 0, A.size() - 1, i, j);
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
    const vector<int> A = {18, 17, 13, 19, 15, 11, 20}; // the original array           // copy the contents to a vector
    SegmentTree st(A);

    printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
    printf("              A is {18,17,13,19,15, 11,20}\n");
    printf("RMQ(1, 3) = %d\n", st.rmq(-1000, 30000));
    printf("RMQ(4, 6) = %d\n", st.rmq(4, 6)); // answer = index 5
    printf("RMQ(3, 4) = %d\n", st.rmq(3, 4)); // answer = index 4
    printf("RMQ(0, 0) = %d\n", st.rmq(0, 0)); // answer = index 0
    printf("RMQ(0, 1) = %d\n", st.rmq(0, 1)); // answer = index 1
    printf("RMQ(0, 6) = %d\n", st.rmq(0, 6)); // answer = index 5

    printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
    printf("Now, modify A into {18,17,13,19,15,100,20}\n");
    // st.update_point(5, 100); // update A[5] from 11 to 100
    printf("These values do not change\n");
    printf("RMQ(1, 3) = %d\n", st.rmq(1, 3)); // 2
    printf("RMQ(3, 4) = %d\n", st.rmq(3, 4)); // 4
    printf("RMQ(0, 0) = %d\n", st.rmq(0, 0)); // 0
    printf("RMQ(0, 1) = %d\n", st.rmq(0, 1)); // 1
    printf("These values change\n");
    printf("RMQ(0, 6) = %d\n", st.rmq(0, 6)); // 5->2
    printf("RMQ(4, 6) = %d\n", st.rmq(4, 6)); // 5->4
    printf("RMQ(4, 5) = %d\n", st.rmq(4, 5)); // 5->4
}