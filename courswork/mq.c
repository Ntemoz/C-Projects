#include <stdio.h>

int level_add();
int selected_entry(int*);
int bet_entry(int*, int);
int dice_drop(int, int);
int step_result(int, int, int, int);
int check_win(int, int);
main()
{
int connect, dice1, dice2, selected, sum, score=100, bet, i, circles;
srand(time(NULL));
printf("Здравствуйте! Для начала игры ознакомьтесь с правилами!\n");
printf("Вы можете загадывать число в диапозоне от 2 до 12\n");
printf("Если сумма выпавших цифр больше семи и загаданное число больше семи - вы выигрываете ставку\n");
printf("Если сумма выпавших цифр меньше семи и загаданное число меньше семи - вы выигрываете ставку\n");
printf("Если сумма выпавших цифр равна загаданному числу - вы получаете в 4 раза больше поставленного\n");
printf("При любом другом исходе ваша ставка сгорает. Начальное количество очков - 100\n");
printf("После ознакомления с правилами введите 1\n");
while(connect!=1){
    scanf("%d", &connect);
    }
system("clear");
circles=level_add();
system("clear");
    while(score>0 && circles>0){
        selected=selected_entry(selected);
        bet=bet_entry(bet, score);
        sum=dice_drop(dice1, dice2);
        score=step_result(sum, selected, bet, score);
        circles--;
        sleep(5);
        system("clear");
        }
check_win(score, circles);
}

int level_add()
{
int add;
printf("Выберите уровень сложности: 1-низкий(10), 2-средний(15), 3-высокий(20)");
scanf("%d", &add);
switch(add){
    case 1:
        return 10;
        break;
    case 2:
        return 15;
        break;
    case 3:
        return 20;
        break;
    default:
        return 30;
        break;
}
}

int selected_entry(int *selected)
{
printf("Введите загаданное число в диапазоне от 2 до 12 включительно: ");
scanf("%d", &selected);
}

int bet_entry(int *bet, int score)
{
printf("Введите ставку, сейчас у вас имеется %d очков: ", score);
scanf("%d", &bet);
return bet;
}


int dice_drop(int dice1, int dice2)
{
dice1=rand()%6+1;
printf("Первый раз выпало %d\n", dice1);
dice2=rand()%6+1;
printf("Второй раз выпало %d\n", dice2);
return dice1+dice2;
}

int step_result(int sum, int selected, int bet, int score)
{
if(sum<7 && selected<7 || sum>7 && selected>7){
    printf("Вы выиграли этот круг! Количество очков: %d\n", score+bet);
    return score+bet;
    }
else if (sum==selected){
     printf("Вы выиграли этот круг! Количество очков: %d\n", score+bet*4);
     return score+bet*4;
     }
     else{
     printf("Вы проиграли этот круг.. Количество очков: %d\n", score-bet);
     return score-bet;
     }
}

int check_win(int score, int circles)
{
if (score!=0 && circles==0)
    printf("Вы одержали победу в этой игре! Поздравляем!");
else if(score==0 && circles!=0)
        printf("Вы потерпели поражение в этой игре..");
     else
        printf("В этой игре не удалось выявить победителя..");
}
