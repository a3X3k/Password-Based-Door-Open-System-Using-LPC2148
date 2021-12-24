#include<lpc214x.h>

#define bit(x) (1<<x) //Macros for shifting the bits by 'x'

unsigned char pass[4] = "5555";   //Set Default Password

unsigned int i, range = 0; 

unsigned char r_loc, c_loc;

unsigned char key[4][3] = {"123","456","789","*0#"}; //Keypad Key Digits

unsigned char keypad(void); // Function Declaration

void delay () // Delay Function Definition
{
    unsigned int temp, ct;
	
    for(ct=0; ct<30; ct++) 
		{
        for(temp = 0; temp < 65000; temp ++);
    }
}

/* --------- DC Motor ----- */

void forward(void);
void reverse(void);
void stop(void);

/* --------- LCD ---------*/
 
void lcd_init(void);
void cmd(unsigned char a);
void dat(unsigned char b);
void show(unsigned char *s);
void lcd_delay(void);

/* ---------- Keypad ------*/

#define c1 (IOPIN1&1<<20)

#define c2 (IOPIN1&1<<21)

#define c3 (IOPIN1&1<<22)

/* ------- Main -------*/
int main()
{
    
    unsigned char rx_arr[4]; //Store the INPUT Password
	
    int count; //Counter to keep count of number of digits in the Password.
    
    VPBDIV = 0x01; // PCLK = 60MHz where APB bus clock (PCLK) is the same as the processor clock (CCLK)
	
    IO1DIR |= 0x0f<<16; //P1.16, P1.17, P1.18, P1.19
    
		IO0DIR |= 0xf00fc; //P0.2, P0.3, P0.4, P0.5, P0.6, P0.7, P0.16, P0.17, P0.18 - Set as OUTPUT
    
    lcd_init();

    while(1) {
        cmd(0x80); //Cursor to the Beginning of the 1st Line
			
        show("#Enter Password#"); //Print the Display
        
        cmd(0xc5); //LCD Setup
			
        for(count=0; count <4; count++) 
				{
					
            rx_arr[count] = keypad(); //Getting Input
					
            dat('*'); //Printing '*' to denote that the Password has been Typed
        }
        
        if (( pass[0] == rx_arr[0] ) && ( pass[1] == rx_arr[1] ) && 
            ( pass[2] == rx_arr[2] ) && ( pass[3] == rx_arr[3] )) 
				{
            cmd(0xc0); //Cursor to the beginning of the 2nd Line
					
            show("   Thank You!   "); //Print the TEXT
					
            forward(); 
            delay();
            stop();
					
            cmd(0xc0);
					
            show("  Come Again!!  "); //Print the TEXT
					
            delay();
            reverse();
            delay();
            stop();
						
        } 
				else 
				{
            cmd(0xc0);
					
            show("~Wrong Password~");
					
            delay();
        }
        
				cmd(0x01);
        
    }
}

/* ----- Keypad Function ----*/
unsigned char keypad()
{
    IO1PIN &= ~(0xff<<16);
	
    IO1PIN |= 0xf0<<16;

    while(c1 && c2 && c3);
	
    while(!c1 || !c2 || !c3) 
		{
        if(!c1 && c2 && c3)     c_loc=0;
        else if(c1 && !c2 && c3)    c_loc=1;
        else if(c1 && c2 && !c3)    c_loc=2;

        IO1CLR = 1<<16;
        IO1SET = 0x0e<<16;
			
        if(!c1 || !c2 || !c3) 
				{
            r_loc=0;
            break;
        }

        IO1CLR = 1<<17;
        IO1SET = 0x0d<<16;
				
        if(!c1 || !c2 || !c3) 
				{
            r_loc=1;
            break;
        }
        
        IO1CLR = 1<<18;
        IO1SET = 0x0b<<16;
				
        if(!c1 || !c2 || !c3) 
				{
            r_loc=2;
            break;
        }

        IO1CLR = 1<<19;
        IO1SET = 0x07<<16;
				
        if(!c1 || !c2 || !c3) 
				{
            r_loc=3;
            break;
        }
    }
		
    while(!c1 || !c2 || !c3);
		
    return (key[r_loc][c_loc]);
}


/* ----- LCD Functions -------*/

void lcd_init()
{
    cmd(0x02);
    cmd(0x28);
    cmd(0x0c);
    cmd(0x06);
    cmd(0x80);
}
 
void cmd(unsigned char a)
{
    IO0PIN &= 0xffffff03;
    IO0PIN |= (a & 0xf0) << 0;
    IO0CLR |= bit(2);                //rs=0
    IO0CLR |= bit(1);                //rw=0
    IO0SET |= bit(3);                 //en=1
	
    lcd_delay();
	
    IO0CLR |= bit(3);                 //en=0
    
    IO0PIN &= 0xffffff03;
    IO0PIN |= ((a << 4)  & 0xf0) << 0;
    IO0CLR |= bit(2);                //rs=0
    IO0CLR |= bit(1);                //rw=0
    IO0SET |= bit(3);                 //en=1
	
    lcd_delay();
	
    IO0CLR |= bit(3);                 //en=0
}
 
void dat(unsigned char b)
{
    IO0PIN &= 0xffffff03;
    IO0PIN |= (b & 0xf0) << 0;
    IO0SET |= bit(2);                //rs=1
    IO0CLR |= bit(1);                //rw=0
    IO0SET |= bit(3);            //en=1
    lcd_delay();
    IO0CLR |= bit(3);            //en=0
    
    IO0PIN &= 0xffffff03;
    IO0PIN |= ((b << 4)  & 0xf0) << 0;
    IO0SET |= bit(2);                //rs=1
    IO0CLR |= bit(1);                //rw=0
    IO0SET |= bit(3);            //en=1
	
    lcd_delay();
	
    IO0CLR |= bit(3);            //en=0
}
 
void show(unsigned char *s)
{
    while(*s) 
		{
        dat(*s++);
    }
}
 
void lcd_delay()
{
    unsigned int i;

    for(i=0;i<=1000;i++);
}

/* ---------- DC Motor ---------*/
void forward()
{
    
    IO0SET = bit(16) | bit(18);
    IO0CLR = bit(17);   
}

void reverse()
{
    
    IO0SET = bit(17) | bit(18);
    IO0CLR = bit(16);   
}

void stop()
{
    IO0CLR = bit(18);   
}
