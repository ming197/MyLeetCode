/*
 * @lc app=leetcode id=1185 lang=cpp
 *
 * [1185] Day of the Week
 */

// @lc code=start
class Solution {
public:
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day_week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    string dayOfTheWeek(int day, int month, int year) {
        int base = calDays(15, 8, 1993); // "Sunday"
        int x = calDays(day, month, year);
        return day_week[mod7(x - base)];
    }

    int mod7(int x){
        if(x % 7 == 0) return 0;
        if(x > 0) return x % 7;
        int multi = (-x) / 7;
        return x + (multi + 1) * 7;
    }

    bool isLeap(int year){
        if(year % 400 == 0) return true;
        if(year % 100 != 0 && year % 4 == 0) return true;
        return false;
    }

    int calDays(int day, int month, int year){
        int res = ((year - 1) / 4) * (365 * 4 + 1);
        for(int i = 1; i <= (year - 1) % 4; i++){
            res += 365;
        }
        for(int i = 1; i < month; i++){            
            res += month_days[i-1];
            if(i == 2 && isLeap(year)) res++;
        }
        res += day;
        return res;
    }

};
// @lc code=end

