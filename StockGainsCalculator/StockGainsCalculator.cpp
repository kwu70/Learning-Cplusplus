#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int numTrades = 0;   //255 is estimate of 1 year (52 weeks in 1 year)
    int weeks = 0;
    int weeklyTrades = 0;
    double percent = 0.0;
    double start = 0.0;
    double sum = 0.0;
    double gains = 0.0;
    double prev = 0.0;
    int weekCount = 0;
    double untraded = 0.0;
    double weeklyGains = 0.0;
    double loss;
    double total;

    std::cout << endl;
    std::cout << "Time frame in weeks (default 50): ";
    std::cin >> weeks;
    std::cout << "# of trades per week: ";
    std::cin >> weeklyTrades;
    std::cout << "Enter the starting amount: ";
    std::cin >> start;
    std::cout << "Enter the % gained per trade (decimal): ";
    std::cin >> percent;

    numTrades = weeks * weeklyTrades;
    sum = start;

    //std::cout << "# of trading days: " << numTrades << endl;

    for (int i = 1; i <= numTrades; i++) {
        /* case where I dont withdraw untraded funds         
        if ((sum > 9000) && (sum < 25000)) {
            untraded += 2000;
            sum -= 2000;
        }*/

        if ((sum > 9000) && (sum < 25000) && (untraded < 25000)) {
            double temp = 0.0;
            if (sum > 12000) {
                untraded += (sum-9000);
                sum = 9000;
            }
            else {
                untraded += 2000;
                sum -= 2000;
            }
        }
        else if ((sum > 50000) && (sum < 60000)) {
            untraded += 10000;
            sum -= 10000;
        }
        else if (sum > 60000) {
            untraded += (sum-45000);
            sum = 45000;
        }
        else if ((untraded >= 25000) && (untraded < 28000) && (sum < 40000)) {
            sum += untraded;
            untraded = 0.0;
        }

        //sum -= 8; $8 a day on food
        prev = sum;
        gains = sum * percent;
        sum += gains;
        weeklyGains += gains;

        std::cout << fixed;
        std::cout << setprecision(2);

        if ((i-1) % weeklyTrades == 0) {
            if (i > 1) 
                std::cout << "*Profit for the week: [" << weeklyGains << "]" << endl;

            std::cout << endl;
            std::cout << "Week: " << ++weekCount << endl;
            std::cout << "----------------------------------------------" << endl;
            //std::cout << "Trade #| Start  -  Profit  -  End" << endl;
            std::cout << "Trade |";
            std::cout << " " << left << setw(10) << setfill(' ') << "Start";
            std::cout << left << setw(9) << setfill(' ') << "Profit";
            std::cout << left << setw(9) << setfill(' ') << "Sum";
            std::cout << left << setw(10) << setfill(' ') << "*untraded" << endl;

            weeklyGains = 0.0;
        }

        //std::cout << i << "   | " << prev << " | " << percentGains << " | " << gains << endl;
        
        //left allignment, setw(width_of_output), setfill(char_to_fill)
        std::cout << " " << left << setw(5) << setfill(' ') << i;
        std::cout << "  " << left << setw(10) << setfill(' ') << prev;
        std::cout << left << setw(9) << setfill(' ') << gains;
        std::cout << left << setw(10) << setfill(' ') << sum;
        std::cout << left << setw(11) << setfill(' ') << untraded << endl;
    }
    std::cout << "*Profit for the week: [" << weeklyGains << "]\n" << endl;

    total = untraded + sum;
    loss = total * 0.4;

    std::cout << left << setw(21) << setfill(' ') << "**Expected Earnings: ";
    std::cout << "[" << right << setw(11) << setfill(' ') << total << "]\n";
    std::cout << left << setw(21) << setfill(' ') << "**Total loss (40%): ";
    std::cout << "[" << right << setw(11) << setfill(' ') << loss << "]\n";
    std::cout << left << setw(21) << setfill(' ') << "**Total Earned: ";
    std::cout << "[" << right << setw(11) << setfill(' ') << total-loss << "]\n";

    std::cin.sync();
    std::cin.get();
    return 0;
}