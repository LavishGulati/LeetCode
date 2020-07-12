class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(E >= A && F >= B && G <= C & H <= D){
            return (C-A)*(D-B);
        }
        else if(A >= E && B >= F && C <= G && D <= H){
            return (G-E)*(H-F);
        }
        else if(D > H){
            if(E > A){
                int si = E;
                int sj = max(B, F);
                int ei = min(C, G);
                int ej = H;
                if(ei > si && ej > sj){
                    return (C-A)*(D-B) + (G-E)*(H-F) - (ei-si)*(ej-sj);
                }
                else{
                    return (C-A)*(D-B) + (G-E)*(H-F);
                }
            }
            else{
                int si = A;
                int sj = max(B, F);
                int ei = min(G, C);
                int ej = H;
                if(ei > si && ej > sj){
                    return (C-A)*(D-B) + (G-E)*(H-F) - (ei-si)*(ej-sj);
                }
                else{
                    return (C-A)*(D-B) + (G-E)*(H-F);
                }
            }
        }
        else{
            if(E > A){
                int si = E;
                int sj = max(F, B);
                int ei = min(C, G);
                int ej = D;
                if(ei > si && ej > sj){
                    return (C-A)*(D-B) + (G-E)*(H-F) - (ei-si)*(ej-sj);
                }
                else{
                    return (C-A)*(D-B) + (G-E)*(H-F);
                }
            }
            else{
                int si = A;
                int sj = max(F, B);
                int ei = min(G, C);
                int ej = D;
                if(ei > si && ej > sj){
                    return (C-A)*(D-B) + (G-E)*(H-F) - (ei-si)*(ej-sj);
                }
                else{
                    return (C-A)*(D-B) + (G-E)*(H-F);
                }
            }
        }
    }
};
