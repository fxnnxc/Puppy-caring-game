#include<stdio.h>
#include <windows.h>//gotoxy �Լ��� �������� �������(gotoxy�Լ�:�ܼ� ȭ���� Ư�� ��ġ�� Ŀ���� �Ȱܵ��Ŀ�, �� ���������� ����ϴ� �Լ�)
#include<stdlib.h> 
#include<conio.h>
#include<time.h> //�����Լ� �������� �������
#include <process.h> //Thread �������� �������

void start_game();//strat_game�Լ�����
void check_score();//check_score�Լ�����
int opt1=1/*Choose while�� ó���� ���� �ϱ� ���ؼ� �ʱ�ȭ*/,opt2,opt3,opt4,love=0,power=0,pretty=0,train=0,result;
int time_count1=0, time_count2=0, time_count3=0, time_count4=0;//�������Լ� ������

unsigned __stdcall Thread(void *arg) //������ �Լ�
{
   while(1)//�ݺ��� ���� while��
    {
       Sleep(1000);//1000=1��
     time_count1++;//�ð� ����
     time_count2++;//�ð� ����
     time_count3++;//�ð� ����
     time_count4++;//�ð� ����
      if(time_count1==59){
       love-=3;//59���� ģ�е� 3����
            printf("\nģ�е��� 3���������. ����ּ���!\n");
          time_count1= 0;//�ð����� 0���� �ʱ�ȭ
         }

    else if(time_count2==83){
         power-=4;//83���� �� 4����
         printf("\n���� 4���������. ���� �ּ���!\n");
          time_count2= 0;//�ð����� 0���� �ʱ�ȭ
      }
    else if(time_count3==113){
      train-=5;//113���� �Ʒ����� 5����
          printf("\n�Ʒ������� 5���������. �Ʒ����ּ���!\n");
          time_count3= 0;//�ð����� 0���� �ʱ�ȭ
      }
   else if(time_count4==900){//900���Ŀ� ��������
      system("cls");//â �����ϰ�
      printf("\n������ ������ ������ ����Ǿ����! �����մϴ�~\n");
      check_score();//���� ���ھ� ���
   }
 }
}
void gotoxy(int x, int y)//��ǥ����
{
   COORD Pos;
   Pos.X = x;
   Pos.Y = y; //���ϴ� �ܼ� Ŀ�� ��ǥ�� ���� (x : ������, y : ������) COORD ����ü ������ ����
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
   //SetConsoleCursorPosition �Լ���,�����ġ�� �����ְ�,��ġ�� �����ָ� Ŀ���� �̵�
   //�ڵ�:OS ���ο��� �����ϴ� �ڷᱸ��
   //GetStdHandle(STD_OUTPUT_HANDLE):ǥ���ܼ� ��� �ڵ鰪
   //Pos:��ġ��
}

void MeunPrint()
{
   gotoxy(50,4); printf("< �� �� ��   �� �� ��>\n");//��ǥ �Է�
   gotoxy(50,5); printf("      ____________\n");
   gotoxy(50,6); printf("    _-            -_\n");
   gotoxy(50,7); printf("   l               ��\n");
   gotoxy(50,8); printf("  �� ===      ===   l \n");
   gotoxy(50,9); printf(" ��   o        o   l �� \n");
   gotoxy(50,10); printf("��        ��       l  ��\n");
   gotoxy(50,11); printf("�� �ӣ�   ��    �� l  ��\n");
   gotoxy(50,12); printf("��_��     ��      ��__��\n");
   gotoxy(50,13); printf("    ��____________��\n");
   gotoxy(50,14); printf("       l         ��\n");
   gotoxy(50,15); printf("       l l  l     �� \n");
   gotoxy(50,16); printf("       l l  l      ��\n");
   gotoxy(50,17); printf("       l l  l    (  l_____ \n");
   gotoxy(50,18); printf("      E__E__l___E___l-----l\n");   
   gotoxy(53,20); printf("-----�޴�-----\n");
   gotoxy(53,21); printf("1.�� �� �� �� \n");
   gotoxy(53,22); printf("2.�� �� �� �� \n");
   gotoxy(53,23); printf("3.�� �� �� �� \n");
   gotoxy(53,24); printf("--------------\n");
}
void Estart1()//���� �̸�Ƽ��1
{
   gotoxy(50,4); printf("     ��    ____________\n");
   gotoxy(50,5); printf("         _-            -\n");
   gotoxy(50,6); printf("        l               �� ��\n");
   gotoxy(50,7); printf("      ��   ��       ��  l �� \n");
   gotoxy(50,8); printf("     ��        ��       l  ��\n");
   gotoxy(50,9); printf("   ���� �ӣ�   ��    �� l  ��\n");
   gotoxy(50,10); printf("     ��_��     ��      ��__�Ӣ�    \n");
   gotoxy(50,11); printf("  ______��____________��______  \n");
   gotoxy(50,12); printf("��_______               ______��\n");
   gotoxy(50,13); printf("         l             l\n");
   gotoxy(50,14); printf("         l             l\n");
   gotoxy(50,15); printf("         l             l\n");
   gotoxy(50,16); printf("         l             l\n");
   gotoxy(50,17); printf("         l  _________  l\n");
   gotoxy(50,18); printf("         l l         l l\n");
   gotoxy(50,19); printf("         l l         l l\n");   
   gotoxy(50,20); printf("__________��_________��________\n");

}

void Estart2()//���� �̸�Ƽ��2
   {
   gotoxy(50,2); printf("           ____________\n");
   gotoxy(50,3); printf("   ��    _-            ��\n");
   gotoxy(50,4); printf("        l                ��  \n");
   gotoxy(50,5); printf("      ��   ��       ��  l �Ӣ� \n");
   gotoxy(50,6); printf("     ��        ��       l  ��\n");
   gotoxy(50,7); printf(" ��  �� �ӣ�   ��    �� l  ��\n");
   gotoxy(50,8); printf("     ��_��     ��      ��__��  ��  \n");
   gotoxy(50,9); printf("  ______��____________��______  \n");
   gotoxy(50,10); printf("��_______               ______��\n");
   gotoxy(50,11); printf("         l             l\n");
   gotoxy(50,12); printf("         l             l\n");
   gotoxy(50,13); printf("         l             l\n");
   gotoxy(50,14); printf("         l             l\n");
   gotoxy(50,15); printf("     ____l             l_____\n");
   gotoxy(50,16); printf("  ��________________________��\n");
   gotoxy(50,20); printf("_______________________________\n");

}

void Eend1()//���� �̸�Ƽ��1
{
   system("cls");//ȭ�� �����ϰ�
    gotoxy(50,4);printf("          ____________\n");     
    gotoxy(50,5); printf("     �� _-            -_\n");
    gotoxy(50,6); printf("       l               ��\n");
    gotoxy(50,7); printf("      �� ===      ===   l  ��\n");
    gotoxy(50,8); printf("     ��   ��       ��  l �� \n");
    gotoxy(50,9); printf("    ��        ��       l  ��   ��\n");
    gotoxy(50,10); printf("    �� �ӣ�   ��    �� l  ��\n");
    gotoxy(50,11); printf("��  ��_��     ��      ��__��     \n");        
    gotoxy(50,12); printf("  ______��____________��______        \n"); 
    gotoxy(50,13); printf("��_______               ______��\n");
    gotoxy(50,14); printf("        l             l\n");
    gotoxy(50,15); printf("        l             l     \n");                          
    gotoxy(50,16); printf("        l             l         \n");               
    gotoxy(50,17); printf("        l             l_____\n");
    gotoxy(50,18); printf("        l  _________________��\n");
    gotoxy(50,19); printf("        l l   \n");
    gotoxy(50,20); printf("        l l\n");
    gotoxy(50,21); printf("        ��\n");
}


void Eend2()//���� �̸�Ƽ��2
   {
   gotoxy(50,4); printf("          ____________\n");     
    gotoxy(50,5); printf("     �� _-            -_\n");
    gotoxy(50,6); printf("       l               ��\n");
    gotoxy(50,7); printf("      �� ===      ===   l  ��\n");
    gotoxy(50,8); printf("     ��   ��       ��  l �� \n");
    gotoxy(50,9); printf("    ��        ��       l  ��   ��\n");
    gotoxy(50,10); printf("    �� �ӣ�   ��    �� l  ��\n");
    gotoxy(50,11); printf("��  ��_��     ��      ��__��     \n");        
    gotoxy(50,12); printf("  ______��____________��______        \n"); 
    gotoxy(50,13); printf("��_______               ______��\n");
    gotoxy(50,14); printf("         l             l\n");
    gotoxy(50,15); printf("         l             l     \n");                          
    gotoxy(50,16); printf("         l             l         \n");               
    gotoxy(50,17); printf("    _____l             l\n");
    gotoxy(50,18); printf("  ��_________________  l\n");
    gotoxy(50,19); printf("                     l l   \n");
    gotoxy(50,20); printf("                     l l\n");
    gotoxy(50,21); printf("                      ��\n");
}

void Eplay()//������ �̸�Ƽ��
{
   gotoxy(30,4); printf("                      ____________     \n");
   gotoxy(30,5); printf("                    _-            -_\n");
   gotoxy(30,6); printf("                   l               ��\n");
   gotoxy(30,7); printf("                  �� ===      ===   l \n");
   gotoxy(30,8); printf("                 ��   ��       ��  l ��\n");
   gotoxy(30,9); printf("                ��        ��       l  ��\n");
   gotoxy(30,10); printf("                �� �ӣ�   ��    �� l  ��\n"); 
   gotoxy(30,11); printf("                ��_��     ��      ��__��\n");
   gotoxy(30,12); printf("              ______��___//_______��______\n");
   gotoxy(30,13); printf("            ��_______   //          ______��\n");
   gotoxy(30,14); printf("                    l             l\n");
   gotoxy(30,15); printf("                    l             l\n");
   gotoxy(30,16); printf("                    l             l\n");   
   gotoxy(33,17); printf("                 l             l\n");
   gotoxy(33,18); printf("             ____l             l_____\n");
   gotoxy(33,19); printf("           ��________________________��\n");
   gotoxy(33,20); printf("\n");
   gotoxy(33,21); printf("\n");
   gotoxy(33,22); printf("          ______________________________\n");        
}

void Eplaydisk()//���ݴ����� �̸�Ƽ��
{
   gotoxy(30,4); printf("                      ____________     \n");
   gotoxy(30,5); printf("                    _-            -_\n");
   gotoxy(30,6); printf("                   l               ��\n");
   gotoxy(30,7); printf("                  �� ===      ===   l  \n");
   gotoxy(30,8); printf("                 ��   ��       ��  l �� \n");
   gotoxy(30,9); printf("                ��        ��       l  ��   \n");
   gotoxy(30,10); printf("                �� �ӣ�   ��    �� l  ��\n");
   gotoxy(30,11); printf("                ��_��     ��      ��__��     \n");
   gotoxy(30,12); printf("                   ��____________��    \n");
   gotoxy(30,13); printf("                   ��   _�Ѥ�_    l\n");
   gotoxy(30,14); printf("                   ��  ��     ��  l\n");
   gotoxy(30,15); printf("                   ��_��       ��_��\n");
   gotoxy(30,16); printf("                    l  l      l   l  \n");   
   gotoxy(30,17); printf("                    l   -�Ѥ�-    l         \n");
   gotoxy(30,18); printf("                    l  _________  l    \n");
   gotoxy(30,19); printf("                    l l         l l\n");
   gotoxy(30,20); printf("                    l l         l l \n");
   gotoxy(30,21); printf("                     ��          �� \n"); 
}
void Etouch()//���ٵ�� �̸�Ƽ��
{
   gotoxy(30,6); printf("                      ____________     \n");
   gotoxy(30,7); printf("                    _-            -_\n");
   gotoxy(30,8); printf("             ������l               �Ӣ�����\n");
   gotoxy(30,9); printf("                  �� ===      ===   l \n");
   gotoxy(30,10); printf("                 ��   ��       ��  l ��\n");
   gotoxy(30,11); printf("                ��        ��       l  ��\n");
   gotoxy(30,12); printf("                �� �ӣ�   ��    �� l  ��\n"); 
   gotoxy(30,13); printf("                ��_��     ��      ��__��\n");
   gotoxy(30,14); printf("                   ��______________��\n");
   gotoxy(30,15); printf("                      l         ��\n");
   gotoxy(30,16); printf("                      l l  l     ��    __ \n");
   gotoxy(30,17); printf("                      l l  l      ��\  / /\n");
   gotoxy(30,18); printf("                      l l  l    (  l_/ /\n");   
   gotoxy(30,19); printf("                     E__E__l___E___l--/\n");
}
void Efoot()//�����ڸ��� �̸�Ƽ��
{
   gotoxy(30,10); printf("l        l        l        l        l        l        l\n");
   gotoxy(30,11); printf("l        l        l        l        l        l        l\n");
   gotoxy(30,12); printf("l   ��   l   ��   l   ��   l   ��   l   ��   l   ��   l\n");
   gotoxy(30,13); printf("l        l        l        l        l        l        l\n");
   gotoxy(30,14); printf(" �ѤѤѤ� �ѤѤѤ� �ѤѤѤ� �ѤѤѤ� �ѤѤѤ� �ѤѤѤ� \n");
   gotoxy(30,15); printf("    ��       ��       ��       ��       ��       ��   ���~~��\n");
}
void Ewalking()//��å�ϴ� �̸�Ƽ��
{
   gotoxy(15,1); printf("                                          / /      \n");
   gotoxy(15,2); printf("                                         / /      \n");
   gotoxy(15,3); printf("                                        / /      \n");
   gotoxy(15,4); printf("                                       / /      \n");
   gotoxy(15,5); printf("                                      / /      \n");
   gotoxy(15,6); printf("                      ____________   / /      \n");
   gotoxy(15,7); printf("                    _-            -_/ /\n");
   gotoxy(15,8); printf("                   l               ��/\n");
   gotoxy(15,9); printf("                  �� ===      ===   l    �ݢܢ�\n");
   gotoxy(15,10); printf("                 ��    o        o  l ��\n");
   gotoxy(15,11); printf("                ��        ��       l  ��\n");
   gotoxy(15,12); printf("                �� �ӣ�   ��    �� l  ��\n"); 
   gotoxy(15,13); printf("                ��_��     ��      ��__��\n");
   gotoxy(15,14); printf("                     ��__________��-------_____  \n");
   gotoxy(15,15); printf("                      l��               -----l\n");
   gotoxy(15,16); printf("                      l                 l\n");
   gotoxy(15,17); printf("                      l l  l-------l l  l\n");
   gotoxy(15,18); printf("                      l l  l      _l l  l\n");   
   gotoxy(15,19); printf("                     E__E__l     E__E___l\n");
}
void Ecut()//��¥���� �̸�Ƽ��
{
   gotoxy(30,6); printf("                      ____________\n");
   gotoxy(30,7); printf("              ��    _-            -_\n");
   gotoxy(30,8); printf("                   l               ��\n");
   gotoxy(30,9); printf("                  �� ===      ===   l  �� \n");
   gotoxy(30,10); printf("                 ��   >        <   l ��\n");
   gotoxy(30,11); printf("                ��        ��       l  ��\n");
   gotoxy(30,12); printf("                �� �ӣ�   ��    �� l  ��\n"); 
   gotoxy(30,13); printf("             �� ��_��     ��      ��__�� ��\n");
   gotoxy(30,14); printf("             ______��____________��______\n");
   gotoxy(30,15); printf("           ��_______               ______��\n");
   gotoxy(30,16); printf("              ��    l             l\n");
   gotoxy(30,17); printf("                    l             l  ��  \n");
   gotoxy(30,18); printf("                    l             l\n");   
   gotoxy(30,19); printf("            ��      l             l\n");
   gotoxy(30,20); printf("                    l  _________  l\n");
   gotoxy(30,21); printf("                    l l         l l\n");
   gotoxy(30,22); printf("                    l l         l l\n");
   gotoxy(30,23); printf("                     ��          ��\n");
}
void Efood()//���Դ� �̸�Ƽ��
{
   gotoxy(40,6); printf("         ____________     \n");
   gotoxy(40,7); printf("  ��   _-            -_   ��\n");
   gotoxy(40,8); printf("       l               ��\n");
   gotoxy(40,9); printf("      �� ===      ===   l  \n");
   gotoxy(40,10); printf("     ��   ��       ��  l �� \n");
   gotoxy(40,11); printf("    ��        ��       l  ��   \n");
   gotoxy(40,12); printf("   �� �ӣ�    ��    ��  l  ��\n"); 
   gotoxy(40,13); printf("�� ��_��     )��(       ��__�� \n");
   gotoxy(40,14); printf("       ��____________��      \n");
   gotoxy(40,15); printf("       ��   ������    l  ��\n");
   gotoxy(40,16); printf("      ��  ����������  l\n");
   gotoxy(40,17); printf("       ��_�� ��� ��_��    ��\n");
   gotoxy(40,18); printf("        l  l      l   l\n");   
   gotoxy(40,19); printf("     �� l   -�Ѥ�-    l\n");
   gotoxy(40,20); printf("        l  _________  l\n");
   gotoxy(40,21); printf("        l l         l l\n");
   gotoxy(40,22); printf("        l l         l l\n");
   gotoxy(40,23); printf("         ��          ��\n");
}
void Ewater()//���Դ� �̸�Ƽ��
{
   gotoxy(45,6); printf("         ____________     \n");
   gotoxy(45,7); printf("  ��   _-            -_   ��\n");
   gotoxy(45,8); printf("       l               ��\n");
   gotoxy(45,9); printf("      �� ===      ===   l  \n");
   gotoxy(45,10); printf("     ��   ��       ��  l �� \n");
   gotoxy(45,11); printf("    ��        ��       l  ��   \n");
   gotoxy(45,12); printf("   �� �ӣ�    ��    ��  l  ��\n"); 
   gotoxy(45,13); printf("�� ��_��     )--(       ��__�� \n");
   gotoxy(45,14); printf("       ��____________��      \n");
   gotoxy(45,15); printf("       ��   ______    l  ��\n");
   gotoxy(45,16); printf("      ��   l      l    l\n");
   gotoxy(45,17); printf("       ��_��  �� ��___��    ��\n");
   gotoxy(45,18); printf("        l  l      l   l\n");   
   gotoxy(45,19); printf("     �� l   -�Ѥ�-    l\n");
   gotoxy(45,20); printf("        l  _________  l\n");
   gotoxy(45,21); printf("        l l         l l\n");
   gotoxy(45,22); printf("        l l         l l\n");
   gotoxy(45,23); printf("         ��          ��\n");
}
void Eto()//���ϴ� �̸�Ƽ��
{
   gotoxy(30,6); printf("                      ____________\n");
   gotoxy(30,7); printf("                    _-            -_\n");
   gotoxy(30,8); printf("                   l               ��\n");
   gotoxy(30,9); printf("                  �� ===      ===    l\n");
   gotoxy(30,10); printf("                 ��   X       X    l ��\n");
   gotoxy(30,11); printf("                ��        ��       l  ��\n");
   gotoxy(30,12); printf("                �� ��   __l___     l  ��\n"); 
   gotoxy(30,13); printf("                ��_��   l_____l   ��__��\n");
   gotoxy(30,14); printf("                    ��__/@  ^ /___��  \n");
   gotoxy(30,15); printf("                   ��  /$  # /    ��\n");
   gotoxy(30,16); printf("                  ��l / %^   /     l��\n");
   gotoxy(30,17); printf("                  ��l/\  !  /      l��\n");
   gotoxy(30,18); printf("                  ��/ 3 # /       l��\n");   
   gotoxy(30,19); printf("                   /  �� /        ��\n");
   gotoxy(30,20); printf("                  / )   /________  l\n");
   gotoxy(30,21); printf("                 /? /@ / l       l l\n");
   gotoxy(30,22); printf("                / / / /l l       l l\n");
   gotoxy(30,23); printf("                       ��        ��\n");
}
void Ehumanfood()//������ĸԴ� �̸�Ƽ��
{
   gotoxy(30,6); printf("                      ____________\n");
   gotoxy(30,7); printf("             �Ф�   _-            -_\n");
   gotoxy(30,8); printf("                   l               ��\n");
   gotoxy(30,9); printf("                  �� ===      ===   l \n");
   gotoxy(30,10); printf("                 ��   ��       ��  l ��\n");
   gotoxy(30,11); printf("                ��    ��  ��   ��  l  ��\n");
   gotoxy(30,12); printf("                �� �� ��  ��   ��  l  ��\n"); 
   gotoxy(30,13); printf("                ��_��     ��      ��__��\n");
   gotoxy(30,14); printf("                    ��____________��  \n");
   gotoxy(30,15); printf("                   ��             ��\n");
   gotoxy(30,16); printf("                  ��l             l��\n");
   gotoxy(30,17); printf("                  ��l             l��\n");
   gotoxy(30,18); printf("                  ��l             l��\n");   
   gotoxy(30,19); printf("                  ��l             l��\n");
   gotoxy(30,20); printf("                    l  _________  l\n");
   gotoxy(30,21); printf("                    l l         l l\n");
   gotoxy(30,22); printf("                    l l         l l\n");
   gotoxy(30,23); printf("                     ��          ��\n");
}

void Estart()//���� �̸�Ƽ��
{
   int time=5;
   Estart1();//���� �̸�Ƽ��1
      while(time>00) //time=5�̹Ƿ� 5ȸ �ݺ�
      {
         Sleep(50);//sleep�Լ��� �� ������ ���α׷� ������ ������Ű�� �Լ�. ()���Ǽ���/1000�� �ǹ�. 0.5�� ������Ŵ
            time--;//time ���� 1����
      } //���� �̸�Ƽ��1 0.5�ʾ� 5�� ����, �� 2.5�ʰ� ���� �̸�Ƽ��1 ����
      system("cls");//���� ȭ�� �����
    Estart2();//���� �̸�Ƽ��2
     time+=5;//time�� 5����
     while(time>00) //5ȸ �ݺ�
     {
        Sleep(50);//0.5�� ����
        time--;//time ���� 1����
     }
             system("cls");//���� ȭ�� �����
   
}

void Eend()//���� �̸�Ƽ��
{
   int time=5;
   Eend1();//���� �̸�Ƽ��1
      while(time>00)//5ȸ �ݺ�
      {
         Sleep(50);//0.5�� ������Ŵ
            time--;//time �� 1����
      }
     system("cls");//���� ȭ�� �����
     Eend2();//���� �̸�Ƽ��2
     time+=5;//time�� 5����
     while(time>00) //5ȸ �ݺ�
     {
        Sleep(50);//0.5�� ������Ŵ
        time--;//time �� 1����
     }
             system("cls");//���� ȭ�� �����
   
}

void play_puppy(){
        printf("����ֱ�! �����ϼ���\n");
        printf("1.������ 2.���ݴ����� 3.���ٵ��\n");
        scanf_s("%d", &opt1,sizeof(opt1));//1.2.3.���� ����ֱ� Ȱ�� ����
          if (opt1 == 1)//1.������ ���ý�
          {
            love+=2;//ģ�е� 2����
         system("cls");
            printf("ģ�е��� 2 ����߽��ϴ�!\n");
         Eplay();//��� �̸�Ƽ��
          }
          else if(opt1 == 2)//2.���ݴ����� ���ý�
          {   
            love+=5;//ģ�е� 5����
         system("cls");
            printf("ģ�е��� 5 ����߽��ϴ�!\n");
         Eplaydisk();//���ݹ޴� �̸�Ƽ��
          }
          else//1����2���� �ƴҽ�
          {
            love+=4;//ģ�е� 4����
         system("cls");
            printf("ģ�е��� 4 ����߽��ϴ�!\n");
         Etouch();//���ٵ��� �̸�Ƽ��
          }
}
void management(){
   printf("�����ϱ�! �����ϼ���\n");
   printf("1.�������� 2. ��å�ϱ� 3.�дٵ��\n");//1.2.3.�� �����ϱ� Ȱ�� ����
   scanf_s("%d", &opt2,sizeof(opt2));
      if (opt2 == 1)//1.�������� ���ý�
      {
      pretty+=5;//�̻� 5����
      system("cls");
      printf("�̻��� 5 ����߽��ϴ�!\n");
      Efoot();//�����ڸ� �̸�Ƽ��
      }
      else if (opt2 == 2)//2.��å�ϱ� ���ý�
      {   
      pretty+=4;//�̻� 4����
      system("cls");
      printf("�̻��� 4 ����߽��ϴ�!\n");
      Ewalking();//��å�ϴ� �̸�Ƽ��
      }
      else//1.2.���� �ƴҽ�
      {
      pretty+=3;//�̻� 3����
      system("cls");
      printf("�̻��� 3 ����߽��ϴ�!\n");
      Ecut();//���ڸ� �̸�Ƽ��
      }
}
void training(){

    int num, answer;//�Էº���,���亯��      
         srand(time(NULL));//�����Լ� ��������
 
         printf("�Ʒÿ� �����Ϸ��� ������ ��� ���߼���(OX�����Դϴ�. ������ 1�� Ʋ���� 2���� ��������.)\n");
         printf("\n");
  
          switch(rand()%11)//11���Ǽ� �� 1�� �������� ��
         {
            case 0://������ 0�� ���������

               printf("�������� ������ �ð��� ������\n");
               answer=1;//���� 1��
               scanf_s("%d",&num,sizeof(num));//1.2���� �� �����ؼ� �Է�
               if(answer==num)//����� �Է��� ���ڰ� ��ġ�Ҷ�
               {
                  printf("�Ʒÿ� �����߽��ϴ�! 5�� ȹ��!\n");
                  train+=5;//�Ʒ����� 5�� ����
               }
      
               else//������ �� �Ʒý���
                  printf("�Ʒÿ� �����߽��ϴ�,\n");
   
               break;//��
            case 1://������ 1�� ���������
      
               printf("�������� �󱼷� ������ ǥ���Ѵ�\n");
               answer=1;//���� 1��
               scanf_s("%d",&num,sizeof(num));//1.2���� �� �����ؼ� �Է�
               if(answer==num)//����� �Է��� ���ڰ� ��ġ�Ҷ�
               {
                  printf("�Ʒÿ� �����߽��ϴ�! 5�� ȹ��!\n");
                  train+=5;//�Ʒ����� 5�� ����
               }
               else//������ �� �Ʒý���
                  printf("�Ʒÿ� �����߽��ϴ�,\n");
               break;//��
            case 2://������ 2�� ���������
   
               printf("�������� ����� ǥ���� ���� �� ����.\n");
               answer=2;//���� 2��
               scanf_s("%d",&num,sizeof(num));//1.2���� �� �����ؼ� �Է�
               if(answer==num)//����� �Է��� ���ڰ� ��ġ�Ҷ�
               {
                  printf("�Ʒÿ� �����߽��ϴ�! 5�� ȹ��!\n");
                  train+=5;//�Ʒ����� 5�� ����
               }
               else//������ �� �Ʒý���
                  printf("�Ʒÿ� �����߽��ϴ�,\n");
               break;//��
            case 3://������ 3�� ���������
   
               printf("�������� ���ں��� ���ڸ� �� �����Ѵ�.\n");
               answer=1;//���� 1��
                scanf_s("%d",&num,sizeof(num));//1.2���� �� �����ؼ� �Է�
               if(answer==num)//����� �Է��� ���ڰ� ��ġ�Ҷ�
               {
                  printf("�Ʒÿ� �����߽��ϴ�! 5�� ȹ��!\n");
                  train+=5;//�Ʒ����� 5�� ����
               }
               else//������ �� �Ʒý���
                  printf("�Ʒÿ� �����߽��ϴ�,\n");
               break;//��
            case 4://������ 4�� ���������
   
               printf("�ѹ� �߿� ���� ���ڱ� ���� ���� ���並 �ϸ� ��� �ؿ����� �Կ��� �ȴ�. \n");
               answer=2;//���� 2��
               scanf_s("%d",&num,sizeof(num));//1.2���� �� �����ؼ� �Է�
               if(answer==num)//����� �Է��� ���ڰ� ��ġ�Ҷ�
               {
                  printf("�Ʒÿ� �����߽��ϴ�! 5�� ȹ��!\n");
                  train+=5;//�Ʒ����� 5�� ����
               }
            else//������ �� �Ʒý���
               printf("�Ʒÿ� �����߽��ϴ�,\n");
               break;//��

            case 5://������ 5�� ���������
   
               printf("�ʼ� ���������� ������ �ʾƵ� ��å�� ������� �Ѵ�.\n ");
               answer=1;//���� 1��
                scanf_s("%d",&num,sizeof(num));//1.2���� �� �����ؼ� �Է�
               if(answer==num)//����� �Է��� ���ڰ� ��ġ�Ҷ�
               {
                  printf("�Ʒÿ� �����߽��ϴ�! 5�� ȹ��!\n");
                  train+=5;//�Ʒ����� 5�� ����
               }
               else//������ �� �Ʒý���
                  printf("�Ʒÿ� �����߽��ϴ�,\n");
               break;//��
            case 6://������ 6�� ���������
      
               printf("���������� ���̸����� ������ �����̴�.\n");
               answer=1;//���� 1��
                scanf_s("%d",&num,sizeof(num));//1.2���� �� �����ؼ� �Է�
               if(answer==num)//����� �Է��� ���ڰ� ��ġ�Ҷ�
               {
                  printf("�Ʒÿ� �����߽��ϴ�! 5�� ȹ��!\n");
                  train+=5;//�Ʒ����� 5�� ����
               }
               else//������ �� �Ʒý���
                  printf("�Ʒÿ� �����߽��ϴ�,\n");
               break;//��

            case 7://������ 7�� ���������
   
               printf("�ݷ������� �� ����� �޾��ָ� �����Ѵ�.\n");
               answer=2;//���� 2��
                scanf_s("%d",&num,sizeof(num));//1.2���� �� �����ؼ� �Է�
               if(answer==num)//����� �Է��� ���ڰ� ��ġ�Ҷ�
               {
                  printf("�Ʒÿ� �����߽��ϴ�! 5�� ȹ��!\n");
                  train+=5;//�Ʒ����� 5�� ����
               }
               else//������ �� �Ʒý���
                  printf("�Ʒÿ� �����߽��ϴ�,\n");
               break;//��
            case 8://������ 8�� ���������
   
               printf("���� ����� ���� ���� ������ ��� �� �ִ�.\n");
               answer=1;//���� 1��
                scanf_s("%d",&num,sizeof(num));//1.2���� �� �����ؼ� �Է�
               if(answer==num)//����� �Է��� ���ڰ� ��ġ�Ҷ�
               {
                  printf("�Ʒÿ� �����߽��ϴ�! 5�� ȹ��!\n");
                  train+=5;//�Ʒ����� 5�� ����
               }
               else//������ �� �Ʒý���
                  printf("�Ʒÿ� �����߽��ϴ�,\n");
               break;//��

            case 9://������ 9�� ���������
   
               printf("���� �Դ� �ͺ��� ��å�� �� ���� �Ѵ�.\n");
               answer=1;//���� 1��
               scanf_s("%d",&num,sizeof(num));//1.2���� �� �����ؼ� �Է�
               if(answer==num)//����� �Է��� ���ڰ� ��ġ�Ҷ�
               {
                  printf("�Ʒÿ� �����߽��ϴ�! 5�� ȹ��!\n");
                  train+=5;//�Ʒ����� 5�� ����
               }
               else//������ �� �Ʒý���
                  printf("�Ʒÿ� �����߽��ϴ�,\n");
               break;//��
            case 10://������ 10�� ���������
      
               printf("���� ���� ���а� �ٴϹǷ� ������ ���ϴ�.\n");
               answer=2;//���� 2��
               scanf_s("%d",&num,sizeof(num));//1.2���� �� �����ؼ� �Է�
               if(answer==num)//����� �Է��� ���ڰ� ��ġ�Ҷ�
               {
                  printf("�Ʒÿ� �����߽��ϴ�! 5�� ȹ��!\n");
                  train+=5;//�Ʒ����� 5�� ����
               }
               else//������ �� �Ʒý���
                  printf("�Ʒÿ� �����߽��ϴ�,\n");
               break;//��

            case 11://������ 11�� ���������
         
               printf("���� �ڸ� �����ָ� �����Ѵ�.\n");
               answer=2;//���� 2��
                scanf_s("%d",&num,sizeof(num));//1.2���� �� �����ؼ� �Է�
               if(answer==num)//����� �Է��� ���ڰ� ��ġ�Ҷ�
               {
                  printf("�Ʒÿ� �����߽��ϴ�! 5�� ȹ��!\n");
                  train+=5;//�Ʒ����� 5�� ����
               }
               else//������ �� �Ʒý���
               printf("�Ʒÿ� �����߽��ϴ�,\n");
               break;
            default://�ƹ��͵��ƴҽ�
               break;//��
      
            }//switch�� ����
         
}//training�Լ� ����
void Feeding(){
        printf("�����ֱ�! �����ϼ���\n"); 
        printf("1.��� 2.�� 3.���ݸ� 4.���� �Դٳ��� ����\n");
        scanf_s("%d", &opt4,sizeof(opt4));//1,2,3,4 �� �����ֱ� Ȱ�� ����
          if (opt4 ==1)//1.��� ���ý�
          {
            power+=5;// �� 5����
         system("cls");
            printf("���� 5 ����߽��ϴ�!\n");
         Efood();//���Դ� �̸�Ƽ��
          }
          else if (opt4 ==2)//2.�� ���ý�
          {   
            power+=3;// �� 3����
         system("cls");
            printf("���� 3 ����߽��ϴ�!\n");
         Ewater();//���Դ� �̸�Ƽ��
          }
          else if (opt4 ==3)//3. ���ݸ� ���ý�
          {
            power-=10;//�� 10����
         system("cls");
            printf("�������� �並�մϴ�!�Ф����� 10�����߾��.\n");
         Eto();//���ϴ� �̸�Ƽ��
          }
          else//1.2.3 ���� �� ����
          {
            power-=4;//�� 4����
         system("cls");
            printf("���������Դ� ��Ḧ �ּ���!���� 4�����߾��.\n");
         Ehumanfood();//������ĸ��� �̸�Ƽ��
          }
}
void end_game(){//������ ���� ��
   Eend();
   Eend();
   opt1 = 0;//0 �Է½�
   check_score();//�ְ����� Ȯ���� �� �ִ� �Լ��� �̵�
}
void check_score(){//�ְ����� �����ִ� �Լ�
   printf("����� �ְ� ������?\n");
   result = love + pretty + train + power;//�ְ�����=������� ���Ѱ�
   printf("ģ�е� %d! �̻� %d! �Ʒ����� %d! �� %d!\n\n", love, pretty, train, power);

   
      if(result==0)//�ְ������� 0�� ���
     {
        printf("���� ������ ���Ѱ� ������ !!? ������ �ߴµ��� 0���ϸ��� ���ڳ� ! \n");
     }
     else if(result<0)//�ְ������� 0���� ���� ���
      {
         printf("�� ������ Ű�� �ڰ��� ����!\n");
      }
      else if(result>=1 && result<30)//�ְ������� 1�̻��̰� 30���� ���� ���
      {
         printf("�������ʰ� �����༭ ����\n");
      }
      else if(result>=30)//�ְ������� 30�̻��� ���
         printf("������ Ű��� ���� �ϰ����� �ֱ���! �ʸ� �꼥�� �־��ֵ��� �Ұ�!\n");
}
void Choose()
{
   
   _beginthreadex(NULL, 0, Thread, 0, 0,NULL);//������ ����
   while(opt1){ //opt1�ݺ�
      printf("1. ����ֱ� 2. �����ϱ� 3. �Ʒ� 4. �����ֱ� 5.����Ȯ�� 6.�����޴� 0. ����\n"); 
      printf("Ȱ������?: ");
      scanf_s("%d", &opt1,sizeof(opt1));// 1,2,3,4,5,6,0 �� Ȱ�� ����

      switch(opt1)
      {
      case 1://1. ����ֱ� ���� ��
        play_puppy();//����ֱ� �Լ��� �̵�
        break;
      case 2://2. �����ϱ� ���� ��
        management();//�����ϱ� �Լ��� �̵�
        break;
      case 3://3. �Ʒ� ���� ��
       training();
        break;
      case 4://4. �����ֱ� ���� ��
        Feeding();
        break;
     case 5://5. ����Ȯ�� ���� ��
        check_score();
         break;
     case 6://6. �����޴� ���� ��
        start_game();
         break;
      case 0://0. ���� ���� ��
        end_game();
         break;
      default://�ƹ��͵� �ƴҽ�
        printf("���ڸ� �߸� �Է��߾��! �ٽ� �Է��ϼ���! \n");
      }//switch�� ����
   }//while�� ����

}// Choose�Լ� ����

void Infor()
{
   char name[20];//�̸�����
   int a;//����,���� �Է� ����
   scanf_s("%s",name,sizeof(name));//�̸��Է�
   printf("%s��(��)!! �� ������ ���� ����� �߾�. \n���� �λ��� �ʹ� ����ŵ�. \n3�� ���� �� ������ �߻߸� ������. \n�߻߰� ������ ��û ������ �����ΰ� �߾���? \n���ƿͼ� �߻� ���¸� ���� ���� �ְ� ������ ������ �ٰ�. \n%s��(��) �츮 �߻� �� ��Ź��!!\n", name, name);
    printf("\n");
    printf("�����Ϸ��� 1�� ������, �����Ϸ��� 2�� ��������\n");
    scanf_s("%d", &a,sizeof(a));//1�� ������ ����, 2�� ������ ����
   switch(a)
   {
   case 1://1�� ������
      system("cls");//â �����ϰ�
     Estart();
     Estart();
      Choose();//Choose�Լ��� �̵�
      break;//��
   case 2://2�� ������
     printf("�����Ͻ÷��� Enter�� ��������.\n");
      break;//��
   }

}

void Name()
{
   int num;//
   printf("�̸��� �Է��ϼ��� : ");
   scanf("%d" , &num);
   system("cls");//â �����ϰ�
   Infor();//Infor�Լ��� �̵�
}
void start_game(){//���ӽ���
   int select;
   system("cls");
   MeunPrint();//�޴� ���
   scanf("%d", &select);//�޴� 1.2.3.�� �� ����
   switch(select)
   {
   case 1://1�� ���ý�
      system("cls");//â �����ϰ�
      Name();//Name �Լ��� �̵�
      break;//��
   case 2://2�� ���ý�
     system("cls");//â �����ϰ�
      printf("������ �����մϴ�.\n");
      break;//����
   case 3://3�� ���ý�
     system("cls");//â �����ϰ�
   { 
      time_t now;
      struct tm *d;

      while(!kbhit())//�ƹ�Ű�� ������ �޴��� ���ư���
      {
         system("cls");//â �����ϰ�
         now=time(NULL);
         d=localtime(&now);
         printf("���糯¥�ͽð�: %s\n", asctime(d));
       }
      system("cls");//â �����ϰ�
      start_game();
   }//case3 ����

   default://�ƹ��͵� �ƴҽ�
      break;//��
   }//switch��
}//strat_game�Լ� ��
   
int main(void)
{
  start_game();//���ӽ���
}
