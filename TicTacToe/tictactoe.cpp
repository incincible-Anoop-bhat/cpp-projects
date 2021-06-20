#include<iostream>
using namespace std;
/* Programmed by K S Anoop with no help from the internet ;) */
bool play = true, choice_flag = true,win,correct_pos,is_tie;
short unsigned int ilimit;
char choice,token,position;
void show(bool ref, char *a)
{
    for(int k=0;k<3;k++)
        {
            cout<<' ';
            for(int i=0;i<ilimit;i++)
            {
                cout<<"-";
            }
            cout<<endl;
            cout<<" | ";
            for(int i=0;i<3;i++)
            {
                if(ref)
                    cout<<k*3+i+1;
                else
                    cout<<a[k*3+i];
                cout<<" | ";
            }
            cout<<endl;
        }
        cout<<' ';
        for(int i=0;i<ilimit;i++)
            {
                cout<<"-";
            }
        cout<<endl;
        if(ref)
        cout<<"These are the POSITIONS for reference...\n";
}

int main(){

    while (play)
    {
        token = 'X';
        correct_pos=false;
        win=false;
        ilimit=13;
        char a[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
        /*play code*/
        show(true,a);
        while(!win)
        {
            /*displays the current board and asks to enter the position*/
            show(false,a);
            if(a[0]==token)
            {
                if(a[1]==token && a[2]==token)
                {
                    win=true;
                }
                if(!win && a[4]==token && a[8]==token)
                {
                    win=true;
                }
                if(!win && a[3]==token && a[6]==token)
                {
                    win=true;
                }
            }
            if(!win && a[8]==token)
            {
                if(a[7]==token && a[6]==token)
                {
                    win=true;
                }
                if(!win && a[2]==token && a[5]==token)
                {
                    win=true;
                }
            }
            if(!win && a[4]==token)
            {
                if(a[3]==token && a[5]==token)
                {
                    win=true;
                }
                if(!win && a[1]==token && a[7]==token)
                {
                    win=true;
                }
                if(!win && a[2]==token && a[6]==token)
                {
                    win=true;
                }
            }
            /*finish checking*/
            if(win)
            {
             cout<<"Mr. "<<token<<" wins... Congratulations!";
            }
            else
            {
                is_tie=true;
                for(int i=0;i<9;i++)
                {
                    if(a[i]==' ')
                    {
                        is_tie=false;
                    }
                }
                if(is_tie==true)
                {
                    cout<<"Ohho MATCH TIED...";
                    win=true;
                }
                else
                {
                    if(token=='X')
                        token = 'O';
                    else
                        token = 'X';
                    cout<<"Enter your poistion Mr. "<<token<<" [1,9]: ";
                    cin>>position;
                    while(!correct_pos)
                    {                        
                        if(position>'0' && position<='9')
                        {
                            if(a[int(position)-int('0')-1]!=' ')
                           {
                                cout<<"Position already filled please enter a empty position : ";
                                cin>>position;
                            }
                            else
                            {
                                a[int(position)-int('0')-1]=token;
                                correct_pos=true;
                            }
                        }
                        else
                        {
                            cout<<"Enter a valid position [1,9] : ";
                            cin>>position;
                        }
                    }
                    correct_pos=false;
                }
            }
        }
        /*game ends once here*/
        /*ask player if they wants to play again?*/
        cout<<"\nDO you want to play again ? y/n : ";
        choice_flag=true;
        while (choice_flag)
        {
            cin>>choice;
            switch (choice)
            {
            case 'n':
                play = false;
                choice_flag = false;
                break;
            case 'y':
                play=true;
                choice_flag=false;
                break;
            default:
                cout<<"Please re-enter your choice, y/n : ";
                choice_flag = true;
                break;
            }
        }
    }

    return 0;
}
/*complete project done on 19/06/2021*/