/*
 * Q2)
 * Class Hour
 *       int hh
 * 
 * Class Minute
 *       int mm
 * 
 * Class Second
 *       int ss
 * 
 * Class Time inherits from the above 3 classes. Input hh, mm, ss from user where mm and ss value is > 60. Display the
 * time in proper format using object of Time class.
 */

#include <iostream>

class Hour {
    protected:
    int hh;
};

class Minute {
    protected:
    int mm;
};

class Second {
    protected:
    int ss;
};

class Time : private Hour,
             private Minute,
             private Second {

    public:
    void correct_time(void) {
        int temp = ss / 60;
        ss %= 60;

        mm += temp;
        temp = mm / 60;
        mm %= 60;

        hh += temp;
    }

    void read(void) {
        std::cout << "Enter time (hh mm ss): ";
        std::cin >> hh >> mm >> ss;
    }

    void display(void) {
        std::cout << "Time in proper format (hh:mm:ss): " << hh << ":"
                                                          << mm << ":"
                                                          << ss << std::endl;
    }
};

int main(void) {
    Time time;

    time.read();
    time.correct_time();
    time.display();

    return 0;
}
