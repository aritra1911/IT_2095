/*
 * [2] Define the following classes and implement the inheritance structure.
 *                    (All data members are private)
 */

#include <iostream>
#include <cstring>

class Publication {
    char title[32];
    float price;

    public:
    Publication(void) : title(""), price(0.0f) { }

    Publication(const char* title, float price) {
        std::strcpy(this->title, title);
        this->price = price;
    }

    Publication(const Publication& p) : Publication(p.title, p.price) { }

    void getdata(void) {
        std::cout << "Enter title: ";
        std::cin.getline(title, 32, '\n');
    }

    void display(void) {
        std::cout << "Title : " << title << std::endl
                  << "Price : " << price << std::endl;
    }
};

class Sales {
    float pub_sale[3];

    public:
    Sales(void) : pub_sale { 0.0f, 0.0f, 0.0f }  { }

    Sales(const float* sale) {
        for (int i=0; i<3; i++)
            pub_sale[i] = sale[i];
    }

    Sales(const Sales& s) : Sales(s.pub_sale) { }

    void getdata(void) {
        std::cout << "Enter history of last 3 publication sales:\n";

        for (int i=0; i<3; i++)
            std::cin >> pub_sale[i];
    }

    void display(void) {
        float sum = 0.0f;

        for (int i=0; i<3; i++)
            sum += pub_sale[i];

        std::cout << "Total sales : " << sum << std::endl;
    }
};

class Pamphlet : public Publication, public Sales {
    int size;

    public:
    Pamphlet(void) : size(0), Publication(), Sales() { }

    Pamphlet(int size, const char* title, float price, const float* sale) : size(size),
                                                                            Publication(title, price),
                                                                            Sales(sale) { }

    Pamphlet(const Pamphlet& pamphlet) : size(pamphlet.size) { }

    void getdata(void) {
        Publication::getdata();
        Sales::getdata();
        
        std::cout << "Enter size: ";
        std::cin >> size;
    }

    void display(void) {
        Publication::display();
        Sales::display();

        std::cout << "Size : " << size << std::endl;
    }
};

class Book : public Publication, public Sales {
    int pages;

    public:
    Book(void) : pages(0), Publication(), Sales() { }

    Book(int pages, const char* title, float price, const float* sale) : pages(pages),
                                                                         Publication(title, price),
                                                                         Sales(sale) { }

    Book(const Book& p) : pages(p.pages) { }

    void getdata(void) {
        Publication::getdata();
        Sales::getdata();

        std::cout << "Enter pages: ";
        std::cin >> pages;
    }

    void display(void) {
        Publication::display();
        Sales::display();

        std::cout << "Pages : " << pages << std::endl;
    }
};

class Tape : public Publication, public Sales {
    float play_time;

    public:
    Tape(void) : Publication(), Sales() { }

    Tape(float time, const char* title, float price, const float* sale) : play_time(time),
                                                                          Publication(title, price),
                                                                          Sales(sale) { }

    Tape(const Tape& tape) : play_time(tape.play_time) { }

    void getdata(void) {
        Publication::getdata();
        Sales::getdata();

        std::cout << "Enter play time: ";
        std::cin >> play_time;
    }

    void display(void) {
        Publication::display();
        Sales::display();

        std::cout << "Play time : " << play_time << std::endl;
    }
};

class Notice : public Pamphlet {
    char whom[20];

    public:
    Notice(void) : whom(""), Pamphlet() { }

    Notice(const char* whom, float time, const char* title, float price, const float* sale) : Pamphlet(
        time, title, price, sale
    ) {
        std::strcpy(this->whom, whom);
    }

    void getdata(void) {
        Pamphlet::getdata();

        std::cout << "Whom to send : ";
        std::cin.getline(whom, 20, '\n');
    }

    void display(void) {
        Pamphlet::display();

        std::cout << "Whom : " << whom << std::endl;
    }
};

int main(void) {
    float sales[] = { 40.02, 89.03, 92.78 };

    Book book1(100, "Book 1", 3.92, sales);
    book1.display();
    
    std::cout << std::endl;

    Tape tape1(40.23, "Tape 1", 13.92, sales);
    tape1.display();

    std::cout << std::endl;

    Notice notice1("Jon", 10.10, "Notice 1", 1.97, sales);
    notice1.display();

    std::cout << std::endl;

    book1.getdata();
    book1.display();

    std::cout << std::endl;

    tape1.getdata();
    tape1.display();

    std::cout << std::endl;

    notice1.getdata();
    notice1.display();

    return 0;
}
