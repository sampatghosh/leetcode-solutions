class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a1 = (abs(C-A) * abs(D-B));
        int a2 = (abs(G-E) * abs(H-F));
        if(B >= H || C <= E || A >= G || F >= D)
            return a1 + a2;
        else
            return a1 - (abs(min(C, G)-max(A,E)) * abs(min(H, D) - max(B, F))) + a2;
    }
};