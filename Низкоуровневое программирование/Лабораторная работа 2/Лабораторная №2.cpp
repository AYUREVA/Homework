#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    char y;

    _asm {
        mov al, 11110000b; al = 11110000b
        mov dl, 11110000b; dl = 11110000b
        mov cl, al; копирую al в cl
        mov bl, dl; копирую dl в bl

        and cl, 00001111b; выделил первые(младшие) 4 бита в cl
        shl cl, 4; сдвигаем выделеные биты на 4 влево, cl = 00000000b

        and bl, 11110000b; выделил последние(старшие) 4 бита
        shr bl, 4; сдвигаем выделеные биты вправо, bl = 00001111b

        and al, 11110000b; обнулил первые(младшие) 4 бита
        or al, bl; накладываем старшие биты dl(dl = bl) на младшие биты al, al = 11111111b

        and dl, 00001111b; выделил первые(младшие) 4 бита dl
        or dl, cl; кладу младшие 4 бита al(cl = al) в старшие 4 бита dl = 00000000b

        or al, dl; логическая сумма
        shr al, 3; деление на 8 (сдвинули на 3 бита 8 = 2 * *3)

        mov y, al; записали al в ответ y
    }

    cout << bitset<8>(y) << endl;
    return 0;
}