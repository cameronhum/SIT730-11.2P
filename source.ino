
SYSTEM_THREAD(ENABLED);

SerialLogHandler logHandler;


const pin_t SENSOR_PIN = A0;

int analogvalue;
bool mail = false;


int pushButton;
char myData[40] = "";
void setup()
{
    //Time.zone(10);
    pinMode(13, OUTPUT); 
    digitalWrite(13, HIGH);
    
    pinMode(11, OUTPUT); 
    digitalWrite(11, HIGH);
    
    pinMode(A4, INPUT); 

    Particle.variable("analogvalue", analogvalue);

}



void loop()
{
    pushButton = analogRead(A4);
    analogvalue = analogRead(SENSOR_PIN);
    //Particle.publish("mail_val", String(analogvalue));
    
    
    if (analogvalue < 40){
            if (mail == false){
                mail = true;
                delay(600ms);
                Particle.publish("mail", "True");
            }
                
            
            
    }
    else{
        mail = false;
    }
  

  

    delay(600ms);
}

