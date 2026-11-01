class StockSpanner {
public:
    vector<int> stock_prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        stock_prices.push_back(price);
        int result = 0;
        for(int i = stock_prices.size() - 1; i >= 0; i--) {
            if(stock_prices[i] <= price) {
                result++;
            } else {
                break;
            }
        }
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */