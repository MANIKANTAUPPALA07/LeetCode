class ProductOfNumbers {
public:
    vector<int> pre;
    ProductOfNumbers() {
        pre.clear();
    }
    
    void add(int num) {
        if(num == 0) {
            pre.clear();
        }
        else {
            if(pre.size() == 0) {
                pre.push_back(num);
            }
            else{
                int prev = pre[pre.size() - 1];
                pre.push_back(prev*num);
            }
        }
    }
    
    int getProduct(int k) {
        int n = pre.size();
        if(n < k) {
            return 0;
        }
        else if(n == k){
            return pre[k-1];
        }
        else{
            return pre[n-1] / pre[n-1-k];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */