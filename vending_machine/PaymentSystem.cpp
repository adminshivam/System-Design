class PaymentSystem {
    private:
        int money;
    public:
        int getMoney() const {
            return this->money;
        }
        void addMoney(const int &money) {
            this->money += money;
        }

        void subtractMoney(const int &money) {
            this->money -= money;
        }

        int settle() {
            return this->money;
        }
};