class StockSpanner {
public:
    vector<pair<int, int>> stock_prices;
    StockSpanner() {
        
    }
    //100, 80
    int next(int price) {
        int result = 1;
        while(stock_prices.size() >= 1 && price >= stock_prices[stock_prices.size() - 1].first) {
            result += stock_prices[stock_prices.size() - 1].second;
            stock_prices.pop_back();
        }
        stock_prices.push_back({price, result});
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */