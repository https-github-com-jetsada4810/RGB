#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8




char key = '0';
int n;
void setup() {
  
 
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() 
{
  


    
    if (Serial.available() > 0)
    {
      key = Serial.read();
      if (key == '0')
      { 
        float frequencyR = 0;
        float frequencyG = 0;
        float frequencyB = 0;
        int Rinput = 0;
        int Ginput = 0;
        int Binput = 0;
        for (n = 0; n <= 5; n++)
          {
            
            
            
            digitalWrite(S2,LOW);
            digitalWrite(S3,LOW);                     // Reading the output frequency
            Rinput = pulseIn(sensorOut, LOW);    // Printing the value on the serial monitor
            frequencyR = frequencyR + Rinput ;
            digitalWrite(S2,HIGH);
            digitalWrite(S3,HIGH);
            Ginput = pulseIn(sensorOut, LOW);
            frequencyG = frequencyG + Ginput ;
            digitalWrite(S2,LOW);
            digitalWrite(S3,HIGH);
            Binput = pulseIn(sensorOut, LOW);
            frequencyB = frequencyB + Binput ;

            
           }  
        Serial.print("R= ");                      //printing name
        Serial.print(frequencyR/5);               //printing RED color frequency
        Serial.print("  ");
        Serial.print("G= ");                      //printing name
        Serial.print(frequencyG/5);               //printing RED color frequency
        Serial.print("  ");
        Serial.print("B= ");                      //printing name
        Serial.print(frequencyB/5);               //printing RED color frequency
        Serial.print("  ");
        Serial.println();
        if (frequencyR/5>16 && frequencyR/5<19 && frequencyG/5>16 && frequencyG/5<19 && frequencyB/5>4 && frequencyB/5<7){       // to detect normal
          Serial.println("normal");
            }
        else if (frequencyR/5>16 && frequencyR/5<21 && frequencyG/5>16 && frequencyG/5<21 && frequencyB/5>3 && frequencyB/5<7){  // to detect glucose
          Serial.println("glucose");
            }
        else if (frequencyR/5>16 && frequencyR/5<20 && frequencyG/5>16 && frequencyG/5<20 && frequencyB/5>3 && frequencyB/5<7){  // to detect protein
          Serial.println("protein");
            }
        else if (frequencyR/5>17 && frequencyR/5<21 && frequencyG/5>17 && frequencyG/5<21 && frequencyB/5>4 && frequencyB/5<8){  // to detect glucose and protein
          Serial.println("glucose and protein");
            }
         else{
          Serial.println("again pls");
          }
        
        
          
    
       }
    }
    
}
