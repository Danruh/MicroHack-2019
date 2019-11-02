#include "music.h"

#define YELLOW_LED 2

int hex_row[4] = { 5,6,7,8 };
int hex_col[4] = { 9,10,11,12 };
char key_map[4][4] = { { '1','2','3','F' },
                         { '4','5','6','E' },
                         { '7','8','9','D' },
                         { 'A','0','B','C' },
                       };
                       
char user_input[5];
int u_input_count;
int count;

int passCheck(char *arr1, char* arr2);
void Wrong();
void Right();



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Test\n");
  for ( int i=0;i<4;i++ )
  {
    pinMode( hex_row[i],OUTPUT );
    pinMode( hex_col[i],INPUT_PULLUP );
    digitalWrite( hex_row[i], HIGH );
    //digitalWrite( hex_col[i], HIGH );
  }


/////////////////////////////
//   PIN 4 IS RED LED     //
//   PIN 3 IS GREEN LED   //
//   PIN 2 IS YELLOW LED  //
//   PIN 13 IS BUZZER     //
////////////////////////////

  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);

  pinMode(YELLOW_LED, OUTPUT);
  
  user_input[4] = '\0';
}

void alarm()
{
  digitalWrite( 4,HIGH );
  int i;
  
  for(i=0; i<40; i++){
    F_s_oct();
    
  }
  
  
  for(i=0; i<40; i++){
    C_oct();
  }
  for(i=0; i<40; i++){
    F_s_oct();
    
  }
  
  
 for(i=0; i<40; i++){
    C_oct();
  }
   for(i=0; i<40; i++){
    F_s_oct();
    
  }
  
  
  for(i=0; i<40; i++){
    C_oct();
  }
     for(i=0; i<40; i++){
    F_s_oct();
    
  }
  
  
  for(i=0; i<40; i++){
    C_oct();
  }

  for(i=0; i<40; i++){
    F_s_oct();
    
  }
  
  
  for(i=0; i<40; i++){
    C_oct();
  }
  for(i=0; i<40; i++){
    F_s_oct();
    
  }
  
  
 for(i=0; i<40; i++){
    C_oct();
  }
   for(i=0; i<40; i++){
    F_s_oct();
    
  }
  
  
  for(i=0; i<40; i++){
    C_oct();
  }
     for(i=0; i<40; i++){
    F_s_oct();
    
  }
  
  
  for(i=0; i<40; i++){
    C_oct();
  }

  digitalWrite( 4,LOW );
}

void loop() {
  // put your main code here, to run repeatedly:
    for ( int i=0;i<4;i++ )
    {
      digitalWrite( hex_row[i],LOW );
      
      for ( int j=0;j<4;j++ )
      {
        
        if ( digitalRead( hex_col[j] )==LOW )
        {
          digitalWrite( YELLOW_LED, HIGH );
          user_input[u_input_count] = key_map[j][i];
          u_input_count++;

          if ( u_input_count>3 )
          {
            Serial.println(user_input);
            u_input_count = 0;

            if ( passCheck( user_input,"1234" ) )
            {
              Serial.println("Unlocked\n");
              digitalWrite( YELLOW_LED,LOW );
              Right();
              count = 0;
            }
            else
            {
              digitalWrite( YELLOW_LED,LOW );
              Serial.println("Denied\n");
              Wrong();
              count++;
              if (count == 5)
              {
                Serial.println("SCHTööP! SCHTööP it!\n");
                count = 0;
                alarm();
              }
            }
          }
          delay(400);
          digitalWrite( YELLOW_LED,LOW );
        }
      }
      delay(10);
      //Serial.println("Here\n");
      digitalWrite( hex_row[i],HIGH );
    }
}

int passCheck(char *arr1, char* arr2) 
{   
    for ( int i=0;i<4;i++ )
    {
        if ( arr1[i]!=arr2[i] )
        {
          return false;
        }
    }
    return true; 
} 

void Wrong(){
  int i;
  digitalWrite(4, HIGH);
 
  for(i=0; i<12; i++){
    E();
    A();
  }
  delay(50);
  
  for(i=0; i<12; i++){
    E();
    A();
  }
  
  digitalWrite(4, LOW);
}

void Right(){
  int i;
  digitalWrite(3, HIGH);
  
  for(i=0; i<50; i++){
    E();
    A();
  }
  
  delay(100);
  
  for(i=0; i<50; i++){
    E();
    A();
  }  
  
  delay(100);
  
  for(i=0; i<50; i++){
    E();
    A();
  } 
  
  delay(100);
  
  for(i=0; i<30; i++){
    f();
  } 
  
  delay(20);
  
  for(i=0; i<20; i++){
    C_oct();
  } 
  
  delay(20);
  
  for(i=0; i<50; i++){
    E();
    A();
  } 
  
  delay(100);
  
  for(i=0; i<30; i++){
    f();
  } 
  
  for(i=0; i<20; i++){
    C_oct();
  } 
  
  for(i=0; i<50; i++){
    E();
    A();
  } 
  
  delay(250);
  
  for(i=0; i<50; i++){
    E_oct();
    A();
  }
  
  delay(100);
  
  for(i=0; i<50; i++){
    E_oct();
    A();
  }
  
  delay(100);
  
  for(i=0; i<50; i++){
    E_oct();
    A();
  }
  
  delay(100);
  
  for(i=0; i<30; i++){
    D_oct();
  }
  
  delay(75);
  
  for(i=0; i<30; i++){
    C_oct;
  }
  
  delay(10);
  
  for(i=0; i<50; i++){
    G();
  }
  
  delay(100);
  
  for(i=0; i<30; i++){
    f();
  } 
  
  delay(60);
  
  for(i=0; i<50; i++){
    C_oct();
  }
  
  delay(10);
  
  for(i=0; i<50; i++){
    E();
    A();
  }
  
  digitalWrite(3, LOW);
  }
