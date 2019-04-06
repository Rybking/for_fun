#include <iostream>
#include <cstring>
#include <random>
#define LINE "Choose type of training:\n1 - letter training\n2 - word training\n3 - number training\nh - to show these message\ne- to exit\n"
int word(int len){
    int score = 0;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string s = "", s1 = "";
    for (int i = 0; i < len; ++i){
        s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    std::cout << s <<"\nPlease repeat this word:\n";
    std::cin >> s1;

    for(int i = 0; i < len; ++i){
        if(s[i] == s1[i])
            score++;
    }
    return score;
}

int number(long long num){
    long long num1;
    int score = 0;
    std::cin >> num1;
    while(num != 0){
        if (num%10 == num1%10)
            score++;
        num /= 10;
        num1 /= 10;
    }
    return score;
}

int main(){
    char input;
    int total_score = 0, poss_score = 0;
    std::cout << LINE;
    while(std::cin >> input){
        if(input == '1'){
            total_score += word(1);
            poss_score++;
            std::cout <<"Total points: " <<total_score << "\nPossible points: " << poss_score<<'\n';
            std::cout << "You scored " <<(float)total_score*100/poss_score << " %\n";
            //std::cout << LINE;
        }
        else if(input == '2'){
            int len = rand()%20+ 2;
            //std::cout << len;
            total_score += word(len);
            poss_score += len;
            std::cout <<"Total points: " <<total_score << "\nPossible points: " << poss_score<<'\n';
            std::cout << "You scored " <<(float)total_score*100/poss_score << " %\n";
        }
        else if(input == '3'){
            long long num = rand();
            std::cout << num << '\n';
            total_score+=number(num);
            while(num != 0){
                poss_score++;
                num /= 10;
            }
            std::cout <<"Total points: " <<total_score << "\nPossible points: " << poss_score<<'\n';
            std::cout << "You scored " <<(float)total_score*100/poss_score << " %\n";
        }
        else if(input == 'e'){
            std::cout << "Congratulation!\nYou scored: " <<(float)total_score*100/poss_score << " %\n";
            return 0;
        }
        else if(input == 'h')
            std::cout << LINE;
        else
            std::cout << "Incorrect input\nPlease try again";

    }
}
