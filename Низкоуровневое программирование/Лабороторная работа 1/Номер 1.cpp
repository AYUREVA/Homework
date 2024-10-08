﻿#include <stdio.h>

int main()
{
    char y;
    _asm {
        ; Первая часть формулы : (14 * 3) / (16 / 5 - 2 * 3)

        ; Числитель: 14 * 3
        mov ax, 14; ax = 14
        mov bl, 3; bl = 3
        mul bl; 14 * 3 = 42, результат в ax

        ; Сохраняем числитель в cx
        mov cx, ax; cx = 42

        ; Знаменатель: (16 / 5) - (2 * 3)
        mov ax, 16; ax = 16
        mov bl, 5; bl = 5
        div bl; ax = 16 / 5 = 3 (результат в ax)
        mov ah, 0; обнуляем остаток
        mov dl, al; dl = 3


        ; Вычисляем вторую часть знаменателя 2 * 3
        mov ax, 2; ax = 2
        mov bl, 3; bl = 3
        mul bl; 2 * 3 = 6, результат в ax

        sub dl, al; 3 - 6 = -3, результат знаменателя - 3 в dl

        ; Первая дробь : деление числителя на знаменатель

        mov bl, dl; Сохраняем знаменатель в bl
        mov ax, cx; Восстанавливаем числитель(42)
        idiv bl; Делим 42 на - 3, результат в al(-14)
        mov ah, 0; обнуляем ah
        mov y, al; результат первой дроби y = -14

        ; Вторая часть формулы : (14 / 4) / (5 - 3)

        ; Числитель: 14 / 4
        mov ax, 14; ax = 14
        mov bl, 4; bl = 4
        div bl; 14 / 4 = 3, результат в ax(3)
        mov ah, 0; обнуляем ah
        mov cx, ax; cx = 3

        ; Знаменатель: 5 - 3
        mov ax, 5; ax = 5
        mov bx, 3; bx = 3
        sub ax, bx; ax = 2
        mov bx, ax; bx =
        mov ax, cx; ax = 3
        ; Вторая дробь : деление числителя на знаменатель
        div bl; 3 / 2 = 1, результат в ax
        mov ah, 0; обнуляем ah
        ; Вычитание второй части из первой
        sub y, al; y = -14 - 1 = -15

        end:
    }

    printf("y = %d\n", y);  // Выводим результат y
    return 0;
}