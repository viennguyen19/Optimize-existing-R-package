#include <stdlib.h>
#include <iostream>
#include <vector>
#include <Rcpp.h>
using namespace std;
using namespace Rcpp;

// [[Rcpp::export]]
List acorn1sr(int len_as, List as, NumericVector dim, int len_dim_x, List args, int len_args) {
        int a = 0;
        int b = 0;
        vector<int> myas;
        myas.clear();
        for(int i=4; i <= len_dim_x; ++i)
        {
                if(len_args >= i-3)
                {
                        a = args[i-3-1];
                }
                else
                {
                        a = 1;
                }
                b = abs(a) > dim[i-1] ? dim[i-1] : abs(a);
                a = a > 0 ? b : -b;
                if(a>=0)
                {
                        for(int k=1; k <= a; ++k)
                        {
                                myas.push_back(k);
                        }
                }
                else
                {
                        int m = abs(dim[i-1]+a);
                        for(int l=a; m >= 0; --m)
                        {
                                l += -a > dim[i-1] ? -1 : 1;
                                myas.push_back(l);
                        }
                }
                as.push_back(myas);
                myas.clear();
        }
        return as;
}
