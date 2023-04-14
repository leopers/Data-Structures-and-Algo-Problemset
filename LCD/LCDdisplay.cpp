#include <iostream>

struct number{
    char* num = nullptr;
    std::size_t size = 0;
};

struct lcd{
    std::size_t size;
    number* numero;
    char** display;
};

number* create_number()
{
    number* numero = new number;
    return numero;
}

void destroy_number(number* numero)
{
  delete[] numero->num;
  delete numero;
}

void insert_number (number* numero, char c){
    char* new_nums = new char[numero->size + 1];

    for (std::size_t i = 0; i < numero->size; ++i)
        new_nums[i] = numero->num[i];
    new_nums[numero->size] = c;

    delete[] numero->num;

    ++numero->size;

    numero->num = new_nums;
}

void read_number(lcd lcd){
    for (char zero; std::cin>>zero;){
        if (zero != '0'){
            insert_number(lcd.numero, zero);
            break;
        }
    }

    for (char c; std::cin>>c;)
        insert_number(lcd.numero, c);
}

void insert_line1(lcd lcd, std::size_t xposition, std::size_t yposition){
    for(std::size_t j = 1; j < lcd.size + 1; j++){
        lcd.display[yposition][xposition+j] = '-';
    }
}

void insert_line2(lcd lcd, std::size_t xposition, std::size_t yposition){
    for (std::size_t j = 1; j < lcd.size + 1; ++j){
        lcd.display[yposition+j][xposition] = '|';
        lcd.display[yposition+j][xposition+lcd.size+1] = '|';
    }
}

void insert_line3(lcd lcd, std::size_t xposition, std::size_t yposition){
    for (std::size_t j = 1; j < lcd.size + 1; ++j){
        lcd.display[yposition+j][xposition+lcd.size+1] = '|';
    }
}

void insert_line4(lcd lcd, std::size_t xposition, std::size_t yposition){
    for (std::size_t j = 1; j < lcd.size + 1; ++j){
        lcd.display[yposition+j][xposition] = '|';
    }
}

void insert_display(lcd lcd){
    for (std::size_t i = 0; i < 2*lcd.size + 3; ++i){
        for (std::size_t j = 0; j < (lcd.size + 2)*lcd.numero->size; ++j)
            lcd.display[i][j] = '.';
    }

    for (std::size_t i = 0; i<lcd.numero->size; ++i){
        switch (lcd.numero->num[i]){
            case '0':
                insert_line1(lcd, i*(lcd.size + 2), 0);
                insert_line1(lcd, i*(lcd.size + 2), 2*lcd.size + 2);
                insert_line2(lcd, i*(lcd.size + 2), 0);
                insert_line2(lcd, i*(lcd.size + 2), lcd.size + 1);
                break;
            case '1':
                insert_line3(lcd, i*(lcd.size + 2), 0);
                insert_line3(lcd, i*(lcd.size + 2), lcd.size + 1);
                break;
            case '2':
                insert_line1(lcd, i*(lcd.size + 2), 0);
                insert_line1(lcd, i*(lcd.size + 2), lcd.size+1);
                insert_line1(lcd, i*(lcd.size + 2), 2*lcd.size + 2);
                insert_line3(lcd, i*(lcd.size + 2), 0);
                insert_line4(lcd, i*(lcd.size + 2), lcd.size + 1);
                break;
            case '3':
                insert_line1(lcd, i*(lcd.size + 2), 0);
                insert_line1(lcd, i*(lcd.size + 2), lcd.size+1);
                insert_line1(lcd, i*(lcd.size + 2), 2*lcd.size + 2);
                insert_line3(lcd, i*(lcd.size + 2), 0);
                insert_line3(lcd, i*(lcd.size + 2), lcd.size + 1);
                break;
            case '4':
                insert_line1(lcd, i*(lcd.size + 2), lcd.size + 1);
                insert_line2(lcd, i*(lcd.size + 2), 0);
                insert_line3(lcd, i*(lcd.size + 2), lcd.size + 1);
                break;
            case '5':
                insert_line1(lcd, i*(lcd.size + 2), 0);
                insert_line1(lcd, i*(lcd.size + 2), lcd.size+1);
                insert_line1(lcd, i*(lcd.size + 2), 2*lcd.size + 2);
                insert_line4(lcd, i*(lcd.size + 2), 0);
                insert_line3(lcd, i*(lcd.size + 2), lcd.size + 1);
                break;
            case '6':
                insert_line1(lcd, i*(lcd.size + 2), 0);
                insert_line1(lcd, i*(lcd.size + 2), lcd.size+1);
                insert_line1(lcd, i*(lcd.size + 2), 2*lcd.size + 2);
                insert_line4(lcd, i*(lcd.size + 2), 0);
                insert_line2(lcd, i*(lcd.size + 2), lcd.size + 1);
                break;
            case '7':
                insert_line1(lcd, i*(lcd.size + 2), 0);
                insert_line3(lcd, i*(lcd.size + 2), 0);
                insert_line3(lcd, i*(lcd.size + 2), lcd.size + 1);
                break;
            case '8':
                insert_line1(lcd, i*(lcd.size + 2), 0);
                insert_line1(lcd, i*(lcd.size + 2), lcd.size+1);
                insert_line1(lcd, i*(lcd.size + 2), 2*lcd.size + 2);
                insert_line2(lcd, i*(lcd.size + 2), 0);
                insert_line2(lcd, i*(lcd.size + 2), lcd.size + 1);
                break;
            case '9':
                insert_line1(lcd, i*(lcd.size + 2), 0);
                insert_line1(lcd, i*(lcd.size + 2), lcd.size+1);
                insert_line1(lcd, i*(lcd.size + 2), 2*lcd.size + 2);
                insert_line2(lcd, i*(lcd.size + 2), 0);
                insert_line3(lcd, i*(lcd.size + 2), lcd.size + 1);
                break;
            default:
                break;
        }
    }
}

void print_display (lcd lcd){
    for (std::size_t i = 0; i < 2*lcd.size + 3; ++i){
        for (std::size_t j = 0; j < (lcd.size + 2)*lcd.numero->size; ++j)
            std::cout << lcd.display[i][j];
        std::cout << '\n';
    }
}

int main(){
    lcd lcd;

    lcd.numero = create_number();

    std::cin >> lcd.size;

    read_number(lcd);

    lcd.display = new char*[2*lcd.size + 3];
    for (std::size_t i = 0; i < 2*lcd.size + 3; ++i)
        lcd.display[i] = new char[(lcd.size + 2)*lcd.numero->size];

    insert_display(lcd);

    print_display(lcd);

    for (std::size_t i = 0; i < 2*lcd.size + 3; ++i)
        delete[] lcd.display[i];
    delete[] lcd.display;

    destroy_number(lcd.numero);
}
